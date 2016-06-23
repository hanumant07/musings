/*
 * Given an integer array nums, find the sum of the elements between indices i
 * and j (i ≤ j), inclusive.
 *
 * The update(i, val) function modifies nums by updating the element at index i
 * to val.
 * Example:
 * Given nums = [1, 3, 5]
 *
 * sumRange(0, 2) -> 9
 * update(1, 2)
 * sumRange(0, 2) -> 8
 * Note:
 * The array is only modifiable by the update function.
 * You may assume the number of calls to update and sumRange function is
 * distributed evenly.
 *
 * Author: Hanumant Singh <hanumant07@gmail.com>
 * https://leetcode.com/problems/range-sum-query-mutable/
 *
 * Run Time: Beats 78.55 % of submissions.
 */

#include <iostream>
#include <vector>
using namespace std;

class NumArray {
       public:
	NumArray(vector<int> &nums) {
		bit.resize(nums.size() + 1);
		nums_ref.resize(nums.size());
		for (int i = 0; i < nums.size(); i++) {
			updateBIT(i, nums[i]);
			nums_ref[i] = nums[i];
		}
	}

	void update(int i, int val) {
		updateBIT(i, val - nums_ref[i]);
		nums_ref[i] = val;
	}

	int sumRange(int i, int j) {
		int sum1 = 0;
		int sum2 = 0;
		if (i) sum1 = searchBIT(i - 1);
		sum2 = searchBIT(j);
		return sum2 - sum1;
	}

       private:
	void updateBIT(int i, int diff) {
		i++;
		while (i < bit.size()) {
			bit[i] += diff;
			i = getNext(i);
		}
	}
	int searchBIT(int i) {
		i++;
		int sum = 0;
		while (i > 0) {
			sum += bit[i];
			i = getParent(i);
		}
		return sum;
	}
	vector<int> bit;
	vector<int> nums_ref;
	int getParent(int i) { return i - (i & -i); }
	int getNext(int i) { return i + (i & -i); }
};

#if 0
class NumArray {
	vector<int> bit;
	int getParent(int i) { return i - (i & -i); }
	int getNext(int i) { return i + (i & -i); }

       public:
	NumArray(vector<int> &nums) {
		bit.resize(nums.size() + 1);
		for (int i = 0; i < nums.size(); i++) update(i, nums[i]);
	}

	void update(int i, int val) {
		// cout << "starting with " << i << endl;
		i++;
		while (i < bit.size()) {
			//	cout << "updating index " << i << endl;
			bit[i] += val;
			i = getNext(i);
			//	cout << "getNext returned " << i << endl;
		}
	}

	int sumRange(int i, int j) {
		int sum1 = 0;
		int sum2 = 0;
		i = i != 0 ? i : 0;
		j++;
		// cout << "Prefix sum to " << i << " ";
		while (i > 0) {
			sum1 += bit[i];
			i = getParent(i);
		}
		cout << "sum 1 " << sum1 << endl;
		while (j > 0) {
			sum2 += bit[j];
			j = getParent(j);
		}
		cout << "sum 2 " << sum2 << endl;
		return sum2 - sum1;
	}
};
#endif

int main() {
	vector<int> nums = {1, 3, 5};
	NumArray numArr(nums);
	cout << "Sum between 0, 1 " << numArr.sumRange(0, 1) << endl;
	cout << "Sum between 1, 2 " << numArr.sumRange(1, 2) << endl;
	numArr.update(1, 10);
	cout << "Sum between 1, 2 " << numArr.sumRange(1, 2) << endl;
}
