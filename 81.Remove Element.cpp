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
    int removeElement(int A[], int n, int elem) {
        int i = 0, j = 0;
        while (j < n) {
            if (A[j] != elem) {
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
    while (getline(cin, buff, ']')) {
        int A[1024];
        int n = 0;
        int elem;
        char ch;
        istringstream iss(buff);
        while (iss >> ch >> elem) {
            A[n++] = elem;
        }
        cin >> ch >> elem;
        n = s.removeElement(A, n, elem);
        for (int i = 0; i < n; i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
    return 0;
}