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
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<TreeNode*> st;
        TreeNode *p = 0;
        while (root || st.size()) {
            while (root) {
                p = root;
                st.push_back(root);
                root = root->left;
            }
            if (st.size()) {
                root = st.back();
                st.pop_back();
                if (p != root) {
                    p->right = root->right;                    
                    root->right = root->left;
                    root->left = 0;
                }
                root = p->right;
            }
        }
    }
};

int main(void) {
    return 0;
}