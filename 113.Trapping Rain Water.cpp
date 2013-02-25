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

class Solution {
public:
    int trap(int A[], int n) {
        int maxp = -1;
        for (int i = 0; i < n; i++) {
            if (maxp < 0 || A[i] > A[maxp]) {
                maxp = i;                
            }
        }
        
        int water = 0;        
        int h;
        for (int i = 0; i < maxp; i++) {            
            if (i > 0 && A[i] < h) {
                water += h - A[i];
            } else {
                h = A[i];
            }
        }     
        for (int i = n - 1; i > maxp; i--) {
            if (i < n - 1 && A[i] < h) {
                water += h - A[i];
            } else {
                h = A[i];
            }
        }
        
        return water;
    }
};

int main(void) {
    Solution s;
    string buff;
    while (getline(cin, buff)) {
        vector<int> A;
        istringstream iss(buff);
        int d;
        char ch;    
        while (iss >> ch >> d) {
            A.push_back(d);
        }
        cout << s.trap(A.data(), A.size()) << endl;
    }
    return 0;
}