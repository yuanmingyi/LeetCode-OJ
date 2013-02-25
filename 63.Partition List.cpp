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
    ListNode *partition(ListNode *head, int x) {
        ListNode *less = 0, *greater = 0, *p, *q;
        while (head) {
            if (head->val < x) {
                if (less == 0) {
                    less = p = head;
                } else {
                    p->next = head;
                    p = p->next;
                }
            } else {
                if (greater == 0) {
                    greater = q = head;
                } else {
                    q->next = head;
                    q = q->next;
                }
            }
            head = head->next;
        }
        if (greater) {
            q->next = 0;
        }
        if (less) {
            p->next = greater;
        } else {
            less = greater;
        }
        
        return less;
    }
};

int main(void) {
    return 0;
}