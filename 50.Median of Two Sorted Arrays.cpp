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
    int findK(int A[], int m, int B[], int n, int k) {
        while (k > 1 && m > 0 && n > 0) {
            int ka = k * m / (m + n);
            int kb = k * n / (m + n);
            if (ka + kb < k) {
                if (ka < kb) ka++;
                else kb++;
            }
            if (A[ka - 1] < B[kb - 1]) {
                A += ka;
                m -= ka;
                n = kb;
                k -= ka;
            } else if (A[ka - 1] > B[kb - 1]) {
                B += kb;
                n -= kb;
                m = ka;
                k -= kb;
            } else {
                return A[ka - 1];
            }
        }
        if (m > 0 && n > 0) {
            return min(A[0], B[0]);
        } else if (m > 0) {
            return A[k - 1];
        } else if (n > 0) {
            return B[k - 1];
        } else {
            return 0;
        }
    }
    
    double findMedianSortedArrays(int A[], int m, int B[], int n) {        
        int k1 = (m + n + 1) / 2, k2 = (m + n) / 2 + 1;
        return (findK(A, m, B, n, k1) + findK(A, m, B, n, k2)) / 2.0;    
    }
};

int main(void) {
    
    return 0;
}