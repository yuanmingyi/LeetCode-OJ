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
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> st;
        st.push_back(-1);
        int maxarea = 0;
        for (int i = 0; i < height.size(); i++) {
            while (st.size() > 1 && height[st.back()] > height[i]) {
                int j = st.back();
                st.pop_back();
                int area = height[j] * (i - st.back() - 1);
                if (area > maxarea) {
                    maxarea = area;
                }
            }
            st.push_back(i);
        }
        while (st.size() > 1) {
            int j = st.back();
            st.pop_back();
            int area = height[j] * (height.size() - st.back() - 1);
            if (area > maxarea) {
                maxarea = area;
            }
        }
        
        return maxarea;
    }
};

int main(void) {
    Solution s;
    char ch;
    string buf;
    while (cin >> ch) {
        vector<int> A;
        while (ch != ']') {
            int d;
            if (scanf("%d", &d)) {
                A.push_back(d);
            }
            cin >> ch;
        }
        getline(cin, buf);
        cout << s.largestRectangleArea(A) << endl;        
    }
    return 0;
}