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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        vector<pair<TreeNode*, int> > st;
        int level = 0;
        while (1) {
            while (root) {              
                if (level >= ret.size()) {
                    ret.push_back(vector<int>());
                }
                ret[level].push_back(root->val);
                st.push_back(pair<TreeNode*, int>(root, level++));
                root = root->left;
            }
            if (st.size() < 1) {
                break;
            }
            pair<TreeNode*, int> node = st.back();
            st.pop_back();
            root = node.first->right;
            level = node.second + 1;
        }
        for (int i = 0, size = ret.size(); i < size/2; i++) {
            vector<int> tmp = ret[i];
            ret[i] = ret[size - i - 1];
            ret[size - i - 1] = tmp;
        }
        return ret;
    }
};

int main(void) {
    return 0;
}