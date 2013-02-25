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
    void sumNumbers(TreeNode *root, int sum, int &total) {
        sum = sum * 10 + root->val;
        if (root->left) {
            sumNumbers(root->left, sum, total);
        }
        if (root->right) {
            sumNumbers(root->right, sum, total);
        }
        if (root->left == 0 && root->right == 0) {
            total += sum;
        }
    }
    
    int sumNumbers(TreeNode *root) {
        int total = 0;
        if (root) {
            sumNumbers(root, 0, total);
        }
        return total;
    }
};

int main(void) {
    return 0;
}