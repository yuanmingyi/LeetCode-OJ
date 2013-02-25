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
    TreeNode* cloneTree(TreeNode *t) {
        TreeNode *clone = 0;
        if (t) {
            clone = new TreeNode(t->val);
            clone->left = cloneTree(t->left);
            clone->right = cloneTree(t->right);
        }
        return clone;
    }
    
    void releaseTree(TreeNode *t) {
        if (t) {
            releaseTree(t->left);
            releaseTree(t->right);
            delete t;
        }
    }
    
    vector<TreeNode*> genTrees(int begin, int end) {
        if (begin > end) {
            return vector<TreeNode*>(1,(TreeNode*)0);
        }
        vector<TreeNode*> trees;
        for (int i = begin; i <= end; i++) {
            vector<TreeNode*> leftChildren = genTrees(begin, i-1);
            vector<TreeNode*> rightChildren = genTrees(i+1, end);
            for (size_t j = 0; j < leftChildren.size(); j++) {
                for (size_t k = 0; k < rightChildren.size(); k++) {
                    TreeNode *root = new TreeNode(i);
                    root->left = cloneTree(leftChildren[j]);
                    root->right = cloneTree(rightChildren[k]);
                    trees.push_back(root);
                }
            }
            for (size_t j = 0; j < leftChildren.size(); j++) {
                releaseTree(leftChildren[j]);
            }
            for (size_t j = 0; j < rightChildren.size(); j++) {
                releaseTree(rightChildren[j]);
            }
        }
        return trees;
    }
    
    vector<TreeNode *> generateTrees(int n) {        
        return genTrees(1, n);
    }
};

void printTree(TreeNode* t) {
    vector<TreeNode*> qu;
    int head = 0;
    if (t) {
        qu.push_back(t);
    }
    while (head < qu.size()) {
        TreeNode *p = qu[head++];
        if (!p) continue;
        qu.push_back(p->left);    
        qu.push_back(p->right);
    }
    cout << "{";
    for (size_t i = 0; i < qu.size(); i++) {
        if (qu[i]) {
            cout << qu[i]->val;
        } else {
            cout << '#';
        }
        if (i < qu.size() - 1) {
            cout << ',';
        }
    }
    cout << "}";
}

int main(void) {
    Solution s;
    int n;
    while (cin >> n) {
        vector<TreeNode*> trees = s.generateTrees(n);
        cout << "[";
        for (size_t i = 0; i < trees.size(); i++) {
            printTree(trees[i]);
            if (i < trees.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
    return 0;
}