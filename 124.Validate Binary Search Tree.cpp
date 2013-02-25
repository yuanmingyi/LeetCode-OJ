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
    bool traverseBST(TreeNode *root, int *minval, int *maxval) {
        return !root || ((!minval || root->val > *minval) && (!maxval || root->val < *maxval) 
            && traverseBST(root->left, minval, &root->val) && traverseBST(root->right, &root->val, maxval));            
    }
    
    bool isValidBST(TreeNode *root) {        
        return traverseBST(root, 0, 0);
    }
};

TreeNode *genTree(const string& str) {
    istringstream iss(str);
    char ch;
    int d;
    vector<TreeNode*> qu;
    int head = 0;
    
    if (iss >> ch >> d) {
        qu.push_back(new TreeNode(d));
    }
    
    int child = 1;
    while (iss >> ch && ch != '}') {
        if (iss >> d) {
            TreeNode *t = new TreeNode(d);
            if (child) {
                qu[head]->left = t;
            } else {
                qu[head]->right = t;
            }            
            qu.push_back(t);
        } else {
            iss.clear();
            iss >> ch;  // '#'
            
        }
        child ^= 1;
        if (child) head++;
    }
    
    return qu.empty() ? 0 : qu[0];
}

void releaseTree(TreeNode* t) {
    if (t) {
        releaseTree(t->left);
        releaseTree(t->right);
        delete t;
    }
}

int main(void) {
    Solution s;
    string buff;
    while (getline(cin,buff)) {
        TreeNode *t = genTree(buff);
        cout << (s.isValidBST(t) ? "true" : "false") << endl;
        releaseTree(t);
    }
    return 0;
}