/* You are given a string, s, and a list of words, words, that are all of the
same length. Find all starting indices of substring(s) in s that is a
concatenation of each word in words exactly once and without any intervening
characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/

class Solution {
  struct ValidationResult {
    bool is_valid;
    int invalid_sequence_index;
    ValidationResult() : is_valid(true), invalid_sequence_index(-1){};
  };
  struct Occurence {
    int count;
    size_t first_index;
    Occurence(int c) : count(c), first_index(-1){};
    Occurence() : count(0), first_index(-1){};
  };

  size_t word_length;
  size_t expected_seq_length;
  unordered_map<string, int> dictionary;

  void getDictionary(const vector<string> &input) {
    for (int i = 0; i < input.size(); i++) {
      dictionary[input[i]]++;
    }
  }
  void getRequiredLengths() {
    word_length = (dictionary.begin())->first.length();
    size_t seq_length = 0;
    for (auto it = dictionary.begin(); it != dictionary.end(); ++it) {
      seq_length += word_length * (it->second);
    }
    expected_seq_length = seq_length;
  }

  ValidationResult isValidSequence(const string &seq) {

    unordered_map<string, Occurence> word_occurence;

    for (auto it = dictionary.begin(); it != dictionary.end(); ++it) {
      word_occurence.insert(make_pair(it->first, Occurence(it->second)));
    }

    ValidationResult result;

    for (int i = 0; i < expected_seq_length;) {
      string curr_word = seq.substr(i, word_length);

      if (dictionary.find(curr_word) == dictionary.end()) {
        result.is_valid = false;
        result.invalid_sequence_index = 1;
        return result;
      }

      if (word_occurence[curr_word].first_index == -1) {
        word_occurence[curr_word].first_index = i;
      }
      word_occurence[curr_word].count--;

      if (word_occurence[curr_word].count < 0) {
        result.is_valid = false;
        result.invalid_sequence_index =
            word_occurence[curr_word].first_index + 1;
        return result;
      }
      i += word_length;
    }
    return result;
  }

  size_t findFirstDictionaryWord(const string &orig_input,
                                 const size_t start_pos) {

    for (size_t i = start_pos; i + word_length <= orig_input.length(); i++) {
      string curr_word = orig_input.substr(i, word_length);
      if (dictionary.find(curr_word) != dictionary.end()) {
        return i;
      }
    }
    return string::npos;
  }

  size_t trimValidSequence(const string &orig_input, size_t valid_seq_start) {
    size_t valid_seq_end;
    string valid_seq;

    valid_seq_end = valid_seq_start + expected_seq_length;

    // Maybe move this check outside
    if (valid_seq_end + word_length > orig_input.length()) {
      return valid_seq_end;
    }
    valid_seq = orig_input.substr(valid_seq_start, expected_seq_length);

    string new_word = orig_input.substr(valid_seq_end, word_length);

    if (dictionary.find(new_word) == dictionary.end()) {
      return valid_seq_end;
    }

    // new word is a valid word, trim the valid sequence to the point after the
    // occurnce of the new word
    // in the valid sequence
    return valid_seq_start + valid_seq.find(new_word) + word_length;
  }

public:
  vector<int> findSubstring(string s, vector<string> &words) {
    size_t start_pos = 0;
    vector<int> result;

    getDictionary(words);
    getRequiredLengths();

    for (; start_pos + expected_seq_length <= s.length();) {
      start_pos = findFirstDictionaryWord(s, start_pos);
      if (start_pos == string::npos) {
        break;
      }
      if (start_pos + expected_seq_length > s.length()) {
        break;
      }
      ValidationResult vr =
          isValidSequence(s.substr(start_pos, expected_seq_length));
      if (vr.is_valid) {
        result.push_back(start_pos);
        // trim the valid sequence to start next search
        // start_pos = trimValidSequence(s, start_pos);
        start_pos++;
      } else {
        // find the point where the sequence became invalid and start search
        // from there.
        start_pos = vr.invalid_sequence_index + start_pos;
      }
    }
    return result;
  }
};
