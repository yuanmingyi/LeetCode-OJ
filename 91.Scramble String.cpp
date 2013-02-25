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
    vector<pair<int,int> > checkScramble(const vector<int>& seq) {
        vector<pair<int,int> > st;
        for (int i = 0; i < seq.size(); i++) {
            pair<int, int> p(seq[i], seq[i]);
            while (!st.empty()) {
                pair<int, int> q = st.back();
                if (q.first == p.second + 1) {
                    p.second = q.second;
                } else if (q.second == p.first - 1) {
                    p.first = q.first;
                } else {
                    break;
                }
                st.pop_back();
            }
            st.push_back(p);
        }
        return st;
    }
    
    bool isScramble(string s1, string s2) {
        int len = s1.length();
        vector<int> seq(len,0);
        vector<int> moves(len,0);
        vector<pair<int,int> > st;
        int p = 0, q = 0;
        while (p < len) {
            while (q < len && (seq[q] || s1[p] != s2[q])) {
                q++;
            }
            if (q >= len) {
                p--;
                if (p < 0 || st.empty()) {
                    break;
                }
                seq[moves[p]] = 0;                
                q = 0;                
                for (int i = 0; i < st.size(); i++) {
                    q += st[i].second - st[i].first + 1;
                    if (st[i].first <= p + 1 && st[i].second >= p + 1) {
                        break;
                    }                
                }                
                continue;
            }
            moves[p] = q;
            p++;
            seq[q] = p;
            q = 0;
            if (p == len) {
                st = checkScramble(seq);
                if (st.size() <= 1) break;
                p--;
                seq[moves[p]] = 0;               
                for (int i = 0; i < st.size(); i++) {
                    q += st[i].second - st[i].first + 1;
                    if (st[i].first <= p + 1 && st[i].second >= p + 1) {
                        break;
                    }                
                }
            }
        }
        
        return p == len;
    }
};

int main(void) {
    Solution s;
    string buff;
    while (getline(cin, buff)) {
        char s1[1024], s2[1024];
        sscanf(buff.c_str(), "\"%[^\"]\", \"%[^\"]\"", s1, s2);
        cout << (s.isScramble(s1, s2) ? "true" : "false") << endl;
    }
    return 0;
}