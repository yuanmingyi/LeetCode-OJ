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
 * Definition for binary tree
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
    TreeNode *sortedArrayToBST(const int* num, int size) {
        TreeNode *root = 0;
        if (size > 0) {
            int mid = size / 2;
            root = new TreeNode(num[mid]);
            root->left = sortedArrayToBST(num, mid);
            root->right = sortedArrayToBST(num + mid + 1, size - mid - 1);
        }
        return root;
    }
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return sortedArrayToBST(num.data(), num.size());        
    }
};

int main(void) {
    return 0;
}