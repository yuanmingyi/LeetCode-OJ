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

class Solution {
public:
    bool isSymmetric(TreeNode *t1, TreeNode *t2) {
        if (t1 && t2) {
            return t1->val == t2->val && isSymmetric(t1->left, t2->right) && isSymmetric(t1->right, t2->left);
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