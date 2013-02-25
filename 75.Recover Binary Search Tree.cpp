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
    void recoverTree(TreeNode *root) {
        vector<TreeNode*> st;
        
        TreeNode *pre = 0, *first = 0, *second = 0;
        while (root || !st.empty()) {
            while (root) {
                st.push_back(root);
                root = root->left;                
            }
            root = st.back();
            st.pop_back();
            if (pre && pre->val > root->val) {
                if (first) {
                    swap(first->val, root->val);
                    return;
                }
                first = pre;
                second = root;
            }
            pre = root;
            root = root->right;
        }
        if (first && second) {
            swap(first->val, second->val);
        }
    }
};

int main(void) {
    return 0;
}