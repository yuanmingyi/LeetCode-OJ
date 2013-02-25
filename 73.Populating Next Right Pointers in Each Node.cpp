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
 * Definition for binary tree with next pointer.
 */
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        vector<TreeLinkNode*> qu;
        int head = 0;
        if (root) {
            qu.push_back(root);
        }
        while (head < qu.size()) {
            TreeLinkNode* root = qu[head++];
            if (root->left) {
                qu.push_back(root->left);
            }
            if (root->right) {
                qu.push_back(root->right);
            }
        }
        for (size_t i = 0; i < qu.size(); i++) {
            if ((i+2)&(i+1)) {
                qu[i]->next = qu[i+1];
            }
        }
    }
};

int main(void) {
    return 0;
}