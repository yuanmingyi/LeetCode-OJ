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
    int maxArea(const vector<int>& height) {
        vector<int> st;
        int max_area = 0;
        st.push_back(-1);
        for (int i = 0; i <= height.size(); i++) {
            while (st.back() > -1 && (i == height.size() || height[st.back()] > height[i])) {
                int t = st.back();
                st.pop_back();
                int area = (i - st.back() - 1) * height[t];
                if (area > max_area) {
                    max_area = area;
                }                
            }
            st.push_back(i);
        }
        return max_area;
    }
    
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int rows = matrix.size();
        if (rows == 0) {
            return 0;
        }
        
        int cols = matrix[0].size();
        vector<int> height(cols, 0);
        
        int max_area = 0;
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < cols; j++) {
                height[j] = (matrix[i][j] == '1') ? height[j] + 1 : 0;
            }
            int area = maxArea(height);
            if (area > max_area) {
                max_area = area;
            }
        }
        
        return max_area;
    }
};

int main(void) {
    
    return 0;
}