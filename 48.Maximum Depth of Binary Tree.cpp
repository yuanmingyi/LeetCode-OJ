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

/*
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
    int maxDepth(TreeNode *root) {
        if (root) {
            return max(maxDepth(root->left), maxDepth(root->right)) + 1;
        } else {
            return 0;
        }
    }
};

int main(void) {
    return 0;
}