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
    int searchInsert(int A[], int n, int target) {
        int start = 0, end = n;
        while (start < end) {
            int middle = start + (end - start) / 2;
            if (A[middle] < target) {
                start = middle + 1;
            } else {
                end = middle;
            }
        }
        return start;
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
        cout << s.searchInsert(A.data(), A.size(), d) << endl;
    }
    return 0;
}