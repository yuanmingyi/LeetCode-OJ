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
    vector<int> searchRange(int A[], int n, int target) {     
        int start = 0, end = n;
        while (start < end) {
            int middle = start + (end - start) / 2;
            if (A[middle] < target) {
                start = middle + 1;
            } else if (A[middle] > target) {
                end = middle;
            } else {
                break;
            }
        }
        if (start >= end) {
            return vector<int>(2,-1);
        }
        
        vector<int> range;        
        int s = start, e = end;
        while (s < e) {
            int m = s + (e - s) / 2;
            if (A[m] < target) {
                s = m + 1;
            } else {
                e = m;
            }
        }
        range.push_back(s);
        s = start, e = end;
        while (s < e) {
            int m = s + (e - s) / 2;
            if (A[m] <= target) {
                s = m + 1;
            } else {
                e = m;
            }
        }
        range.push_back(s-1);
        return range;
    }
};

int main(void) {
    Solution s;
    string buff;
    while (getline(cin, buff)) {
        vector<int> A;
        int d;
        char ch;
        istringstream iss(buff);
        while (iss >> ch >> d) {
            A.push_back(d);
        }
        iss.clear();
        iss >> ch >> d;
        vector<int> ret = s.searchRange(A.data(), A.size(), d);
        cout << "[" << ret[0] << "," << ret[1] << "]\n";
    }
    return 0;
}