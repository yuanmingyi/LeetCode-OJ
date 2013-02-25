#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <sstream>
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

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode *t1, TreeNode *t2) {
        vector<TreeNode*> st1, st2;
        while (t1 || st1.size()) {
            while (t1 && t2 && t1->val == t2->val) {
                st1.push_back(t1);
                st2.push_back(t2);
                t1 = t1->left;
                t2 = t2->right;
            }
            if (t1 != t2) {
                return false;
            }
            t1 = st1.back()->right;
            t2 = st2.back()->left;
            st1.pop_back();
            st2.pop_back();
        }
        
        return t1 == t2;
    }
    
    bool isSymmetric(TreeNode *root) {
        return !root || isSymmetric(root->left, root->right);
    }
};

int main(void) {
    return 0;
}