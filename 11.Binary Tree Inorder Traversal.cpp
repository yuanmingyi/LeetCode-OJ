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
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<TreeNode*> st;
        vector<int> inorder;
        while (1) {
            while (root) {
                st.push_back(root);
                root = root->left;
            }
            if (st.size() == 0) {
                break;
            }
            root = st.back();
            inorder.push_back(root->val);
            st.pop_back();
            root = root->right;
        }
        return inorder;
    }
};

int main(void) {
    return 0;
}