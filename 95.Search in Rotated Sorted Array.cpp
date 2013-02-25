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
    int search(int A[], int n, int target) {
        if (n < 1) return -1;
        
        int start = 0, end = n, key = A[0];
        while (start < end) {
            int middle = start + (end - start) / 2;
            if (A[middle] < key) {
                end = middle;
            } else {
                start = middle + 1;
            }
        }
        
        int bound = start;
        end = n;
        while (start < end) {
            int middle = start + (end - start) / 2;
            if (A[middle] < target) {
                start = middle + 1;
            } else  if (A[middle] > target) {
                end = middle;
            } else {
                return middle;
            }
        }
        
        if (start < n) {
            return -1;
        }
        
        start = 0, end = bound;
        while (start < end) {
            int middle = start + (end - start) / 2;
            if (A[middle] < target) {
                start = middle + 1;
            } else if (A[middle] > target) {
                end = middle;
            } else {
                return middle;
            }
        }
        return -1;
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
        cout << s.search(A.data(), A.size(), d) << endl;
    }
    return 0;
}