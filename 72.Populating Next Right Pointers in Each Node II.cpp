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
        int count = 0;
        int head = 0;
        int lnode = 0;
        if (root) {
            qu.push_back(root);
            count = 1;
        }
        TreeLinkNode* p = 0;
        while (head < qu.size()) {
            root = qu[head++];
            if (p) {
                p->next = root;
            }
            p = root;
            if (root->left) {
                qu.push_back(root->left);
                lnode++;
            }
            if (root->right) {
                qu.push_back(root->right);
                lnode++;
            }            
            if (--count <= 0) {
                count = lnode;
                lnode = 0; 
                p = 0;
            }
        }
    }
};

int main(void) {
    return 0;
}