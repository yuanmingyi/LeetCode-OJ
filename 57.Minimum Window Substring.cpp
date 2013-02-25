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
    string minWindow(string S, string T) {
        int s = 0, e = 0;
        string minWindow;
        
        vector<int> count(256, 0);
        vector<int> gt(256, 0);
        
        int total = 0, num = 0;
        for (size_t i = 0; i < T.length(); i++) {
            gt[T[i]]++;
            if (gt[T[i]] == 1) {
                total++;
            }
        }
        
        while (e < S.length()) {
            count[S[e]]++;
            if (count[S[e]] == gt[S[e]]) {
                num++;
            }
            e++;
            while (s < S.length() && num >= total) {
                count[S[s]]--;
                if (count[S[s]] < gt[S[s]]) {
                    num--;
                    if (minWindow.empty() || minWindow.length() > e - s) {
                        minWindow = S.substr(s, e - s);
                    }                        
                }
                s++;
            }
        }
        
        return minWindow;
    }
};

int main(void) {
    Solution s;    
    char buff[1024];
    
    while (cin.getline(buff, 1024)) {
        char _S[1024], _T[1024];
        sscanf(buff, "\"%[^\"]\", \"%[^\"]\"", _S, _T);
        cout << s.minWindow(_S, _T) << endl;
    }
    return 0;
}