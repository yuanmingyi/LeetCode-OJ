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
    int search(int A[], int s, int e, int t) {
        if (s >= e) {
            return s - 1;
        }
        
        int m = s + (e - s) / 2;
        if (A[m] > t) {
            return search(A, m+1, e, t);
        } else if (A[m] < t) {
            return search(A, s, m, t);
        } else {
            int left = search(A, s, m, t);
            int right = search(A, m+1, e, t);
            if (left >= 0 && A[left] != t) {
                return left;
            } else if (A[right] != t) {
                return right;
            }
            return m;
        }
    }
    
    bool search(int A[], int n, int target) {        
        if (n < 1) return false;
        int bound = search(A, 0, n, A[0]) + 1;
        
        int start = 0, end = bound;
        while (start < end) {
            int middle = start + (end - start) / 2;
            if (A[middle] > target) {
                end = middle;
            } else if (A[middle] < target) {
                start = middle + 1;
            } else {
                return true;
            }
        }
        if (start > 0) return false;
        
        start = bound, end = n;
        while (start < end) {
            int middle = start + (end - start) / 2;
            if (A[middle] > target) {
                end = middle;
            } else if (A[middle] < target) {
                start = middle + 1;
            } else {
                return true;
            }
        }
        return false;
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
        cout << (s.search(A.data(), A.size(), d) ? "true" : "false") << endl;
    }
    return 0;
}