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
    string convert(string s, int nRows) {        
        string output;
        int gap = 2 * nRows - 2;
        if (gap <= 0) gap = 1;
        int len = s.length();
        for (int i = 0; i < nRows; i++) {
            for (int j = i, inc = j*2; j < len; j += inc) {
                if (inc < gap) {
                    inc = gap - inc;
                }
                output.push_back(s[j]);
            }
        }
        return output;
    }
};

string getString(istream& is) {
    string str;
    char ch;
    while (is >> ch && ch != '"');
    while (is >> ch && ch != '"') {
        str.push_back(ch);
    }
    return str;
}

int main(void) {
    Solution s;
    string buff;
    while (getline(cin,buff)) {
        istringstream iss(buff);
        string str = getString(iss);
        int rows;
        char ch;
        iss >> ch >> rows;
        cout << s.convert(str, rows) << endl;
    }
    return 0;
}