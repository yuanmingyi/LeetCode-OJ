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
    void sortColors(int A[], int n) {
        int i = 0, j = n - 1;
        while (i < j && A[i] == 0) {
            i++;
        }
        
        for (int k = i; k <= j; k++) {
            if (A[k] == 2) {                
                while (j > k && A[j] == 2) {
                    j--;
                }
                if (k < j) swap(A[k], A[j]);
            } 
            if (A[k] == 0) {
                if (k > i) swap(A[k], A[i]);
                i++;
            }
        }
    }
};

int main(void) {
    Solution s;
    string line;
    while (getline(cin, line)) {
        vector<int> A;
        int d;
        char ch;
        istringstream iss(line);
        while (iss >> ch >> d) {
            A.push_back(d);
        }
        s.sortColors(A.data(), A.size());
        for (size_t i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
    return 0;
}