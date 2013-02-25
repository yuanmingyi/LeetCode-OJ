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
    int removeDuplicates(int A[], int n) {
        int i = 0, j = 0;
        while (j < n) {            
            if (i < 2 || A[i-2] != A[j] || A[j] != A[j-1]) {
                if (i < j) {
                    A[i] = A[j];
                }
                i++;
            }
            j++;
        }
        return i;
    }
};

int main(void) {
    Solution s;
    string buff;
    while (getline(cin,buff)) {
        int A[1024], n = 0;
        int d;
        char ch;
        istringstream iss(buff);
        while (iss >> ch >> d) {            
            A[n++] = d;
        }
        n = s.removeDuplicates(A, n);
        for (int i = 0; i < n; i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
    return 0;
}