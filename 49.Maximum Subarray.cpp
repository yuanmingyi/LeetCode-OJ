#include <iostream>
#include <vector>
#include <string>
#include <sstream>
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
    int maxSubArray(int A[], int n, int* left, int* right, int *sum) {
        if (n == 1) {
            *left = *right = *sum = A[0];            
            return A[0];
        } else {
            int m = n / 2;
            int lmax, rmax, ll, lr, rl, rr, lsum, rsum;            
            lmax = maxSubArray(A, m, &ll, &lr, &lsum);
            rmax = maxSubArray(A+m, n-m, &rl, &rr, &rsum);
            *left = max(ll, lsum + rl);
            *right = max(rr, rsum + lr);
            *sum = lsum + rsum;
            return max(max(lmax, rmax), lr + rl);
        }        
    }
    
    int maxSubArray(int A[], int n) {
        int left, right, sum;        
        return maxSubArray(A, n, &left, &right, &sum);
    }
};

int main(void) {
    Solution s;
    string input;
    while (getline(cin, input)) {
        istringstream iss(input);
        vector<int> a;
        char ch;
        int num;
        while (iss >> ch >> num) {
            a.push_back(num);
        }
        cout << s.maxSubArray(a.data(), a.size()) << endl;
    }
    return 0;
}