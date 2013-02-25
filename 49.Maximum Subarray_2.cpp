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
    int maxSubArray(int A[], int n) {
        int s = 0;
        int maxS = 0;
        for (int i = 0; i < n; i++) {
            s = s > 0 ? s + A[i] : A[i];
            if (i == 0 || s > maxS) {
                maxS = s;
            }
        }
        return maxS;
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