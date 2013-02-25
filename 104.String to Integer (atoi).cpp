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
    int atoi(const char *str) {
        // assertt(str);        
        static int min_neg = 1 << (sizeof(int)*8 - 1);
        static int max_pos = ~min_neg;
        
        int d = 0;
        bool sign = true;
        while (isspace(*str)) {
            str++; 
        }
        
        if (*str == '+') {
            str++;
        } else if (*str == '-') {
            str++;
            sign = false;
        } 
                
        while (*str <= '9' && *str >= '0') {
            int dig = *str - '0';
            if (sign) {
                if (d > (max_pos - dig) / 10) {
                    d = max_pos;
                    break;
                }
                d = d * 10 + dig;
            } else {
                if (d < (min_neg + dig) / 10) {
                    d = min_neg;
                    break;
                }
                d = d * 10 - dig;
            }            
            str++;
        }
        
        return d;
    }  
};

int main(void) {
    Solution s;
    string buff;
    while (cin >> buff) {
        cout << s.atoi(buff.substr(1, buff.length()-2).c_str()) << endl;
    }
    return 0;
}