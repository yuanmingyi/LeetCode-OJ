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
    vector<string> restoreIpAddresses(string s) {
        vector<string> ips;
        
        for (int i = 1; i < s.length() && i <= 3; i++) {
            string a = s.substr(0,i);
            if (atoi(a.c_str()) > 255) {
                break;
            }
            for (int j = i + 1; j < s.length() && j <= i+3; j++) {
                string b = s.substr(i,j-i);
                if (atoi(b.c_str()) > 255) {
                    break;
                }
                for (int k = j + 1; k < s.length() && k <= j+3; k++) {
                    string c = s.substr(j,k-j);
                    string d = s.substr(k);
                    if (atoi(c.c_str()) > 255) {
                        break;
                    }
                    if (atoi(d.c_str()) < 256 && d[0] != '0' || d.length() == 1 ) {
                        string ip = a + '.' + b + '.' + c + '.' + d;
                        ips.push_back(ip);
                    }
                    if (c[0] == '0') break;
                }
                if (b[0] == '0') break;
            } 
            if (a[0] == '0') break;
        }
        
        return ips;
    }
};

int main(void) {
    Solution s;
    string buff;
    while (cin >> buff) {
        vector<string> ips = s.restoreIpAddresses(buff.substr(1,buff.length()-2));
        for (size_t i = 0; i < ips.size(); i++) {
            cout << ips[i] << endl;
        }
        cout << endl;
    }
    return 0;
}