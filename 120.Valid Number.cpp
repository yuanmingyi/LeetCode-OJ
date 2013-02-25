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
    bool isNumber(const char *s) {
        bool num = false;
        bool point = false;
        bool exp = false;
        while (*s && isspace(*s)) {
            s++;
        }
        if (*s == '+' || *s == '-') {
            s++;
        }
        while (*s && !isspace(*s)) {
            if (isdigit(*s)) {                
                num = true;
            } else if (*s == '.') {
                if (point || exp) {
                    return false;
                }
                point = true;
            } else if (toupper(*s) == 'E') {
                if (exp || !num) {
                    return false;
                }
                exp = true;
                num = false;
            } else if (*s == '+' || *s == '-') {
                if (toupper(s[-1]) != 'E') {
                    return false;
                }
            } else {
                return false;
            }
            s++;
        }
        while (*s && isspace(*s)) {
            s++;
        }
        
        return *s == 0 && num;
    }
};

int main(void) {
    Solution s;
    string buff;
    while (getline(cin,buff)) {
        string str;
        char ch;
        istringstream iss(buff);
        while (iss >> ch && ch != '"');
        while (iss >> ch && ch != '"') {
            str.push_back(ch);
        }
        cout << (s.isNumber(str.c_str()) ? "true" : "false") << endl;
    }
    
    return 0;
}