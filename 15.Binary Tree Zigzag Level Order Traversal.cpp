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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<TreeNode*> > qu;
        vector<vector<int> > ret;
        int level = 0;
        
        if (root) {
            qu.push_back(vector<TreeNode*>());
            ret.push_back(vector<int>());
            qu[0].push_back(root);
            ret[0].push_back(root->val);
        }
        while (level < qu.size()) {
            vector<TreeNode*> tmp1;
            vector<int> tmp2;
            for (int i = qu[level].size() - 1; i >= 0; i--) {
                root = qu[level][i];                
                if (level % 2) {
                    if (root->left) {
                        tmp1.push_back(root->left);
                        tmp2.push_back(root->left->val);
                    }
                    if (root->right) {
                        tmp1.push_back(root->right);    
                        tmp2.push_back(root->right->val);
                    }
                } else {
                    if (root->right) {
                        tmp1.push_back(root->right);    
                        tmp2.push_back(root->right->val);
                    }
                    if (root->left) {
                        tmp1.push_back(root->left);                        
                        tmp2.push_back(root->left->val);
                    }   
                }
            }
            if (tmp1.size() > 0) {
                qu.push_back(tmp1);
                ret.push_back(tmp2);
            }
            level++;
        }
        
        return ret;
    }
};

int main(void) {
    return 0;
}