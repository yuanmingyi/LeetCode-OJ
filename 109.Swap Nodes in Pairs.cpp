#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode *first = head, *second = 0, *pre = 0;
        
        while (first) {
            second = first->next;                        
            if (second) {
                if (pre) {
                    pre->next = second; 
                } else {
                    head = second;
                }
                first->next = second->next;
                second->next = first;                
            }
            pre = first;
            first = first->next;
        }
        
        return head;
    }
};

int main(void) {
    return 0;
}