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
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
        vector<vector<bool> > status(len1+1, vector<bool>(len2+1,false));
        vector<pair<int,int> > st;
        
        int p1 = 0, p2 = 0, p3 = 0;
        while (p3 < len3) {
            status[p1][p2] = true;
            if (s2[p2] == s3[p3] && !status[p1][p2+1]) {
                st.push_back(pair<int,int>(p1,p2+1));
            }
            if (s1[p1] == s3[p3]) {
                p1++;
                p3++;
            } else if (st.size()) {
                p1 = st.back().first;
                p2 = st.back().second;
                p3 = p1 + p2;
                st.pop_back();
            } else {
                break;
            }
        }
        
        return p1 == len1 && p2 == len2 && p3 == len3;
    }
};

int main(void) {
    Solution s;
    string s1, s2, s3;
    while (cin >> s1 >> s2 >> s3) {        
        cout << (s.isInterleave(s1.substr(1,s1.length()-2), s2.substr(1,s2.length()-2), s3.substr(1,s3.length()-2)) ? 
                "true" : "false")
             << endl;
    }
    return 0;
}