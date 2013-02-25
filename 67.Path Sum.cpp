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
    bool hasPathSum(TreeNode *root, int sum) {
        if (root) {
            if (root->left == 0 && root->right == 0) {
                return sum == root->val;
            }
            if (hasPathSum(root->left, sum - root->val)) return true;
            if (hasPathSum(root->right, sum - root->val)) return true;
        }
        return false;
    }
};

int main(void) {
    return 0;
}