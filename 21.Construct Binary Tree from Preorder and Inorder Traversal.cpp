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
    TreeNode *buildTree(const int *pre, const int *in, int size) {
        if (size < 1) {
            return 0;
        }
        int val = pre[0];
        TreeNode *root = new TreeNode(val);
        for (int i = 0; i < size; i++) {
            if (in[i] == val) {
                root->left = buildTree(pre+1, in, i);
                root->right = buildTree(pre + i + 1, in + i + 1, size - i - 1);
                break;
            }
        }
        return root;
    }
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return buildTree(preorder.data(), inorder.data(), preorder.size());
    }
};

int main(void) {
    return 0;
}