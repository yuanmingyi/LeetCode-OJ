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
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<pair<TreeNode*, int> > qu;
        int head = 0, level = 0;
        vector<vector<int> > ret;
        vector<int> current;
        if (root) {
            qu.push_back(pair<TreeNode*, int>(root, 0));
        }
        while (head < qu.size()) {
            pair<TreeNode*, int> p = qu[head++];
            root = p.first;
            if (p.second > level) {
                ret.push_back(current);
                current = vector<int>();
                level = p.second;            
            }
            current.push_back(root->val);
            if (root->left) {
                qu.push_back(pair<TreeNode*, int>(root->left, level+1));
            }
            if (root->right) {
                qu.push_back(pair<TreeNode*, int>(root->right, level+1));
            }
        }
        if (current.size()) {
            ret.push_back(current);
        }
        return ret;
    }
};

int main(void) {
    return 0;
}