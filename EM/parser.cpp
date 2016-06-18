#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

/*
 * hastable of all unevaluated variables
 * and their corresponding evaluation expression
 */
unordered_map<string, string> equations;
/*
 * hashtable indexed by name and contains
 * values of all variables evaluated
 */
unordered_map<string, int> variables;

static void usage() { cout << "./parser <file name>" << endl; }

/* @@Get Left hand side of equation
 * @equation:  Complete equation string
 * @rStart: Return position after '='
 */
static string getLHS(string equation, int *rStart) {
  string LHS;
  int LHSlen = equation.find_first_of("=", 0);
  LHS = equation.substr(0, LHSlen);
  *rStart = LHSlen + 1;
  return LHS;
}

/* @@Get right hand side of equation
 * @equation: Compliete equation string
 * @pos: Starting position after '='
 */
static string getRHS(string equation, int pos) {
  string RHS = equation.substr(pos, equation.length() - pos);
  return RHS;
}

/*
 * @@getOperand: Get the operand in the RHS
 * @RHS: Complete RHS of the equation
 * @pos: Starting position within RHS to look for operand
 * @delimit: Delimiter string used to separte operand. '+'
 */
static string getOperand(string RHS, int pos, string delimit) {
  string operand;
  size_t found = RHS.find_first_of(delimit, pos);
  operand = RHS.substr(pos, found - pos);
  return operand;
}

/*
 * @@processEquation: Either finds value of LHS and adds it to the list of
 *                    evaluated variables, or creates a new equation that
 *                    partially solves the original equation and contains the
 *                    variables that have not yet been resolved
 * @leftVar: LHS variable that needs to evaluates
 * @RHS: RHS side of the equation.
 */
static void processEquation(string leftVar, string RHS) {
  int len = 0;
  int sum = 0;
  int pos = 0;
  string equation;

  equations[leftVar] = RHS;

  while (pos < RHS.length()) {
    string operand = getOperand(RHS, pos, "+");
    /* If we have reached the right most operand */
    if (operand.empty()) {
      operand = RHS.substr(pos, RHS.length() - pos);
      if (isalpha(operand[0])) {
        /* if right most operand is a variable */
        if (variables.count(operand))
          /* if variable has already been evaluated use its value*/
          sum += variables[operand];
        else {
          /* Add variable to new equation string */
          if (equation.empty())
            equation = operand;
          else
            equation += '+' + operand;
        }
      } else
        sum += stoul(operand, NULL, 10);
      pos += operand.length();
    }
    /* If we have encountered a variable */
    else if (isalpha(operand[0])) {
      if (variables.count(operand))
        /* if variable has already been evaluated use its value*/
        sum += variables[operand];
      else {
        /*Add variable to new equation string */
        if (equation.empty())
          equation = operand;
        else
          equation += '+' + operand;
      }
    } /* If we have encountered a value */
    else
      sum += stoul(operand, NULL, 10);
    pos += operand.length() + 1;
  }
  /* If no new equation was formed we have evaluated LHS*/
  if (equation.empty()) {
    variables[leftVar] = sum;
    return;
  }
  /* New Equation */
  equations[leftVar] = sum != 0 ? (equation + "+" + to_string(sum)) : equation;
}

int main(int argc, char *argv[]) {
  string line;
  if (argc != 2) {
    cout << "invalid input" << endl;
    usage();
    exit(1);
  }
  ifstream myfile(argv[1]);
  if (myfile.is_open()) {
    while (!myfile.eof()) {
      int rStart = 0;
      getline(myfile, line);
      line.erase(remove(line.begin(), line.end(), ' '), line.end());
      string leftVar = getLHS(line, &rStart);
      if (leftVar.empty()) continue;
      string RHS = getRHS(line, rStart);

      processEquation(leftVar, RHS);
    }
    myfile.close();
    /*
     * Evaluate all unevaluated expressions
     */
    while (!equations.empty()) {
      for (auto it = equations.begin(); it != equations.end();) {
        string LHS = it->first;
        processEquation(it->first, it->second);
        if (variables.count(it->first))
          it = equations.erase(it);
        else
          ++it;
      }
    }
  } else {
    cout << "Unable to open file" << endl;
    exit(1);
  }
  map<string, int> res(variables.begin(), variables.end());
  for (auto it = res.begin(); it != res.end(); ++it)
    cout << it->first << " = " << it->second << endl;
  return 0;
}
