#include <cmath>
#include <iostream>
#include <math.h>
#include <sys/types.h>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void appendToList(ListNode *&ln, int value) {
  ListNode *newNode = new ListNode(value);

  if (ln == nullptr) {
    ln = newNode;
  } else {
    ListNode *current = ln;
    while (current->next != nullptr) {
      current = current->next;
    }

    current->next = newNode;
  }
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
  ListNode *tmp = new ListNode(0); // Temporary node
  ListNode *current = tmp; // We will use this to run through the list
  int carry = 0; // We'll use this to keep the "overflow" value of the sum between two digits
  /*
    Ex.: 
      6
    + 6
    -----
      2

    In this case, we have carry = 1. Then, we can start the sum of the next digit, with the value that "left" from the past one.
  */

  while (l1 != nullptr || l2 != nullptr || carry != 0) {
    int sum = carry;

    if (l1 != nullptr) {
      sum += l1->val;
      l1 = l1->next;
    }

    if (l2 != nullptr) {
      sum += l2->val;
      l2 = l2->next;
    }

    carry = sum / 10;
    int digit = sum % 10;

    current->next = new ListNode(digit);
    current = current->next;
  }

  ListNode *result = tmp->next; // In the line 62, we started adding values to list, but we need to ignore the first position. That't why it is 'tmp->next' instead of 'tmp'. This way, we are passing the reference of the '2' position, to our 'result' list.
  
  delete tmp; 

  return result;
}

int main() {
  vector<int> l1Nums = {1,6,8}, l2Nums = {7, 9, 1};
  ListNode *l1 = nullptr;
  ListNode *l2 = nullptr;

  for (int i = 0; i < (int)l1Nums.size(); i++) {
    appendToList(l1, l1Nums[i]);
  }

  for (int i = 0; i < (int)l2Nums.size(); i++) {
    appendToList(l2, l2Nums[i]);
  }

  ListNode *result = addTwoNumbers(l1, l2);

  while(result != nullptr) {
    cout<< result->val << endl;
    result = result->next;
  }

  return 0;
}
