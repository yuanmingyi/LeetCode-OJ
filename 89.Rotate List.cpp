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
    ListNode *rotateRight(ListNode *head, int k) {
        int len = 1;
        ListNode *tail;
        for (tail = head; tail && tail->next; tail = tail->next) len++;
        if (tail) {
            tail->next = head;
            k = len - k % len;
            while (k-->0) {
                tail = tail->next;
            }
            head = tail->next;
            tail->next = 0;
        }
        return head;
    }
};

int main(void) {
    return 0;
}