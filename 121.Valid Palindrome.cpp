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
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            while (i < j && !isalnum(s[i])) {
                i++;
            }
            while (i < j && !isalnum(s[j])) {
                j--;
            }            
            if (toupper(s[i]) != toupper(s[j])) {
                break;
            }
            i++;
            j--;
        }
        
        return i >= j;
    }
};

int main(void) {
    Solution s;
    string buff;
    while (getline(cin,buff)) {
        string str;
        istringstream iss(buff);
        char ch;        
        while (iss >> ch && ch != '"');
        while (iss >> ch && ch != '"') {
            str.push_back(ch);
        }
        cout << (s.isPalindrome(str) ? "true" : "false") << endl;
    }
    return 0;
}