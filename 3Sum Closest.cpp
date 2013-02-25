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
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int closest = 0, flag = 1;
        for (size_t i = 0; i < num.size(); i++) {
            for (size_t j = i+1, k = num.size() - 1; j < k;) {
                int s = num[i] + num[j] + num[k];
                if (flag || abs(closest - target) > abs(s - target)) {
                    closest = s;
                    flag = 0;
                }
                if (s > target) {
                    k--;
                } else if (s < target) {
                    j++;
                } else {
                    return target;
                }
            }
        }        
        return closest;
    }
};

int main(void) {
    Solution s;
    string buff;
    while (getline(cin,buff)) {
        istringstream iss(buff);
        vector<int> array;
        char ch;
        int d;
        while (iss >> ch >> d) {
            array.push_back(d);
        }
        iss.clear();
        iss >> ch >> d;
        cout << s.threeSumClosest(array, d) << endl;
    }
    return 0;
}