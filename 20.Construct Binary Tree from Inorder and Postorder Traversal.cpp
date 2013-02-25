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
    TreeNode *build(const int *inorder, const int *postorder, int size) {
        if (size < 1) {
            return 0;
        }
        int val = postorder[size - 1];
        TreeNode *root = new TreeNode(val);
        for (int i = 0; i < size; i++) {
            if (inorder[i] == val) {
                root->left = build(inorder, postorder, i);
                root->right = build(inorder + i + 1, postorder + i, size - i - 1);
                break;
            }
        }
        return root;
    }
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return build(inorder.data(), postorder.data(), inorder.size());
    }
};

int main(void) {
    return 0;
}