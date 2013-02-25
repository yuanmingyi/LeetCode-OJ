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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > paths;
        vector<pair<TreeNode*, int> > st;        
        
        while (!st.empty() || root) {
            int s = st.empty() ? 0 : st.back().second; 
            while (root) {
                s += root->val;
                st.push_back(pair<TreeNode*, int>(root, s));
                root = root->left;
            }
            pair<TreeNode*,int> node = st.back();
            root = node.first;
            
            if (root->left == 0 && root->right == 0 && node.second == sum) {
                vector<int> path;
                for (size_t i = 0; i < st.size(); i++) {
                    path.push_back(st[i].first->val);
                }
                paths.push_back(path);
            }
            
            TreeNode *p = 0;
            root = root->right;
            while (root == p) {
                p = st.back().first;
                st.pop_back();
                if (st.empty()) {
                    root = 0;
                    break;
                }
                root = st.back().first->right;
            }
        }
        
        return paths;
    }
};

int main(void) {
    return 0;
}