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

bool isBalanced(TreeNode *root, int *h) {
	int h1 = 0, h2 = 0;
	if (root) {
		if (!isBalanced(root->left, &h1)) {
			return false;
		}
		if (!isBalanced(root->right, &h2)) {
			return false;
		}
		if (h1 - h2 > 1 || h1 - h2 < -1) {
			return false;
		}
		*h = (h1 > h2 ? h1 : h2) + 1;
	}
	return true;
}
    
bool isBalanced(TreeNode *root) {
	int h = 0;
	return isBalanced(root, &h);
}

int main(void) {
    return 0;
}