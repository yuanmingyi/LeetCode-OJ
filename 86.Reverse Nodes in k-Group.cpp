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
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *p = head;
        int n = 0;
        while (p) {
            p = p->next;
            n++;
        }
        
        ListNode *pre = 0, *q = head;        
        for (int i = 0; i < n/k; i++) {
            p = 0;
            for (int j = 0; j < k; j++) {
                ListNode *r = q->next;
                q->next = p;
                p = q;
                q = r;
            }
            if (pre) {                
                pre->next->next = q;
                ListNode *r = pre->next;
                pre->next = p;
                pre = r;
            } else {
                pre = head;
                head->next = q;                
                head = p;
            }
        }
        
        return head;
    }
};

int main(void) {
    return 0;
}