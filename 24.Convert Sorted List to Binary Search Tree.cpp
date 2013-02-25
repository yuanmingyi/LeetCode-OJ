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

/**
 * Definition for binary tree
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
    TreeNode *sortedListToBST(ListNode *&head, int size) {
        TreeNode *root = 0;
        if (size > 0) {
            int mid = size/2;
            TreeNode *left = sortedListToBST(head, mid);
            root = new TreeNode(head->val);
            root->left = left;
            head = head->next;
            root->right = sortedListToBST(head, size-mid-1);            
        }
        return root;
    }
public:
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size = 0;
        for (ListNode *p = head; p; p = p->next) {
            size++;
        }
        
        return sortedListToBST(head, size);
    }
};

int main(void) {
    return 0;
}