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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *p = head, *q = head;
        while (q) {
            if (p->val != q->val) {
                p->next = q;                                
                p = p->next;
            }
            ListNode *r = q->next;
            if (p != q) {                
                delete q;
            }  
            q = r;
        }
        if (p) {
            p->next = 0;
        }
        return head;
    }
};

int main(void) {
    return 0;
}