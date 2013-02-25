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

class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxarea = 0, i = 0, j = height.size() - 1;
        while (i < j) {
            while (i < j && height[i] <= height[j]) {
                int area = (j - i) * height[i];
                if (area > maxarea) {
                    maxarea = area;
                }
                i++;
            }
            while (i < j && height[i] > height[j]) {
                int area = (j - i) * height[j];
                if (area > maxarea) {
                    maxarea = area;
                }
                j--;
            }
        }
        return maxarea;
    }
};

int main(void) {
    char sep;
    char buff[300];
    Solution s;
    while (cin >> sep) {
        vector<int> height;
        while (sep != ']') {
            int tmp;
            cin >> tmp >> sep;
            height.push_back(tmp);
        }
        cin.getline(buff, sizeof(buff));
        cout << s.maxArea(height) << endl;
    }
    return 0;
}