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
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> s(word2.length()+1);
        for (int i = 0; i < s.size(); i++) {
            s[i] = i;
        }
        for (int i = 0; i < word1.length(); i++) {
            int last_s = s[0];
            s[0] = i+1;
            for (int j = 1; j <= word2.length(); j++) {
                int tmp = s[j];
                if (word1[i] == word2[j-1]) {
                    tmp = last_s;
                } else {
                    tmp = (last_s > s[j] ? (s[j] > s[j-1] ? s[j-1] : s[j]) : (last_s > s[j-1] ? s[j-1] : last_s)) + 1;
                }
                last_s = s[j];
                s[j] = tmp;          
            }
        }
        
        return s[word2.length()];
    }
};

int main(void) {
    Solution s;
    string w1, w2;
    while (cin >> w1 >> w2) {
        cout << s.minDistance(w1.substr(1,w1.size()-2), w2.substr(1,w2.size()-2)) << endl;
    }
    return 0;
}