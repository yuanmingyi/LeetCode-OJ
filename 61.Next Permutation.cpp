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
    void nextPermutation(vector<int> &num) {
        int n = num.size();
        int p = n - 1;
        while (p > 0 && num[p-1] >= num[p]) p--;
        for (int i = p, j = n - 1; i < j; i++, j--) {
            int tmp = num[i];
            num[i] = num[j];
            num[j] = tmp;
        }
        if (p > 0) {            
            for (int i = p; i < n; i++) {
                if (num[i] > num[p-1]) {
                    int tmp = num[p-1];
                    num[p-1] = num[i];
                    num[i] = tmp;
                    break;
                }
            }
        }
    }
};

int main(void) {
    Solution s;
    string buff;
    
    while (getline(cin, buff)) {
        istringstream iss(buff);
        vector<int> perm;
        int num;
        char ch;
        while (iss >> ch >> num) {
            perm.push_back(num);
        }
        s.nextPermutation(perm);
        for (int i = 0; i < perm.size(); i++) {
            cout << perm[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}