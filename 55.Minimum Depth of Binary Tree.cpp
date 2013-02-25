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
    int minDepth(TreeNode *root) {      
        if (root) {
            int ld = minDepth(root->left);
            int rd = minDepth(root->right);
            return (ld > 0 && rd > 0 ? min(ld, rd) : max(ld, rd)) + 1;
        } else {
            return 0;
        }
    }
};

int main(void) {
    return 0;
}