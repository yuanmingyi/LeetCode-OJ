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
        bool flag = true;
        ListNode *p = 0, *q = head;
        head = 0;
        while (q) {
            ListNode *r = q->next;
            if (r == 0 || q->val != r->val) {
                if (flag) {
                    if (p == 0) {
                        head = q;
                    } else {
                        p->next = q;
                    }
                    p = q;
                } else {
                    delete q;
                }                
                flag = true;                
            } else {
                delete q;
                flag = false;
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