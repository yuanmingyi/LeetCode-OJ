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
    string multiply(string num1, string num2) {
        int l1 = num1.length();
        int l2 = num2.length();
        vector<int> res(l1+l2, 0);        
        
        for (int i = l1 - 1; i >= 0; i--) {
            for (int j = l2 - 1; j >= 0; j--) {
                int c = (num1[i] - '0') * (num2[j] - '0');
                for (int k = i+j+1; c > 0; k--) {
                    int sum = c + res[k];
                    res[k] = sum % 10;
                    c = sum / 10;
                }
            }
        }
        string ret;
        int prezero = 0;
        for (; prezero < l1 + l2 && res[prezero] == 0; prezero++);
        if (prezero == l1+l2) {
            ret = "0";
        } else {
            while (prezero < l1 + l2) {
                ret.push_back(res[prezero++] + '0');
            }
        }
        
        return ret;
    }
};

int main(void) {
    Solution s;
    char buff[1024];    
    while (cin.getline(buff, 1024)) {
        char num1[1024], num2[1024];
        sscanf(buff, "\"%[0-9]\", \"%[0-9]\"", num1, num2);
        cout << s.multiply(num1, num2) << endl;
    }
    
    return 0;
}