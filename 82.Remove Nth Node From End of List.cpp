#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *tail = head, *pre = 0, *cur = head;
        for (int i = 0; i < n; i++) {
            if (0 == tail) {
                return head;
            }
            tail = tail->next;            
        }
        
        while (tail) {
            pre = cur;
            cur = cur->next;
            tail = tail->next;
        }
        
        if (cur) {
            if (pre) {
                pre->next = cur->next;
            } else {
                head = cur->next;
            }
            delete cur;
        }
        
        return head;
    }
};

int main(void) {
    return 0;
}