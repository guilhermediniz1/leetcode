/*
Given an array of integers nums and an integer target, return indices of the
two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not
use the same element twice.

You can return the answer in any order.
*/

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
  vector<int> res;
  int valueToBeFound = 0;

  for (int i = 0; i < nums.size(); i++) {
    valueToBeFound = target - nums[i];

    for (int j = 0; j < nums.size(); j++) {
      if (nums[j] == valueToBeFound && i != j) {
        res.push_back(i);
        res.push_back(j);
        return res;
      }
    }
  }
  return res;
}

int main() {
  vector<int> arr = {15, 11, 7, 2};
  vector<int> result = twoSum(arr, 9);
  cout << "[" << result[0] << ", " << result[1] << "]" << endl;
  return 0;
}
