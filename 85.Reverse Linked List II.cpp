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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *pre = 0, *first = head, *last, *tmp = 0;
        for (int i = 1; i < m; i++) {
            pre = first;
            first = first->next;
        }
        while (m <= n) {
            last = first->next;
            first->next = tmp;
            tmp = first;
            first = last;
            m++;
        }
        
        if (pre == 0) {
            head->next = first;
            head = tmp;            
        } else {
            pre->next->next = first;            
            pre->next = tmp;
        }
        
        return head;
    }
};

int main(void) {
    return 0;
}