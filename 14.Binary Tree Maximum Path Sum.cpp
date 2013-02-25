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
    int maxPathSum(TreeNode *root, int *maxSum) {
        if (root) {
            int leftSum = maxPathSum(root->left, maxSum);
            int rightSum = maxPathSum(root->right, maxSum);
            if (leftSum + rightSum + root->val > *maxSum) {
                *maxSum = leftSum + rightSum + root->val;
            }
            int ret = (leftSum > rightSum ? leftSum : rightSum) + root->val;
            return ret > 0 ? ret : 0;
        }
        return 0;
    }
    
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root) {
            return 0;
        }
        int maxSum = root->val;
        maxPathSum(root, &maxSum);
        return maxSum;
    }
};

int main(void) {
    return 0;
}