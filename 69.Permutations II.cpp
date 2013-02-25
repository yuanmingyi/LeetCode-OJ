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
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        int n = num.size();
        vector<vector<int> > ret;
        
        while (1) {            
            ret.push_back(num);
            
            int p = n - 1;            
            while (p > 0 && num[p-1] >= num[p]) p--;
            if (p == 0) break;
            
            for (int i = p, j = n - 1; i < j; i++, j--) {
                swap(num[i], num[j]);
            }
            for (int i = p; i < n; i++) {
                if (num[i] > num[p-1]) {
                    swap(num[i], num[p-1]);
                    break;
                }
            }                        
        }
        
        return ret;
    }
};

int main(void) {
    Solution s;
    string buff;
    while (getline(cin, buff)) {
        istringstream iss(buff);
        vector<int> num;
        int d;
        char ch;
        while (iss >> ch >> d) {
            num.push_back(d);
        }
        vector<vector<int> > ret = s.permuteUnique(num);
        for (size_t i = 0; i < ret.size(); i++) {
            for (size_t j = 0; j < ret[i].size(); j++) {
                cout << ret[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}