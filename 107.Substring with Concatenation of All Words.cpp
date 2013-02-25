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
    vector<int> findSubstring(string S, vector<string> &L) {
        sort(L.begin(), L.end());
        vector<string> words;
        vector<int> count;
        
        for (size_t i = 0; i < L.size(); i++) {
            if (words.empty() || L[i] != words.back()) {
                words.push_back(L[i]);
                count.push_back(1);
            } else {
                count.back()++;
            }
        }
        
        vector<int> ret;
        int len = S.length();
        int nword = words.size();
        int wordlen = L.empty() ? 0 : L[0].length();
        int sublen = L.size() * wordlen;
        vector<vector<int> > store(wordlen, vector<int>(nword, 0));
        vector<int> lastidx(sublen, -1);
        
        for (int i = 0; i <= len - wordlen; i++) {
            int p = i % wordlen;
            int q = i % sublen;
            
            if (lastidx[q] >= 0) {
                store[p][lastidx[q]]--;
            }
            lastidx[q] = -1;
            
            string w = S.substr(i, wordlen);
            int idx = lower_bound(words.begin(), words.end(), w) - words.begin();
            if (idx < nword && !(words[idx] > w)) {
                lastidx[q] = idx;
                store[p][idx]++;
                
                int j = 0;
                while (j < nword && store[p][j] == count[j]) j++;
                if (j == nword) {
                    ret.push_back(i - sublen + wordlen);
                }
            }
        }
        
        return ret;
    }
};

int main(void) {
    Solution s;
    string buff;
    while (getline(cin, buff)) {
        string S;
        vector<string> L;
        istringstream iss(buff);
        char ch;        
        while (iss >> ch && ch != '"') {
        }
                
        while (iss >> ch && ch != '"') {
            S.push_back(ch);            
        }
                
        while (iss >> ch && ch != ']') {
            while (iss >> ch && ch != '"') {                
            }
            
            string word;
            while (iss >> ch && ch != '"') {
                word.push_back(ch);
            }
            L.push_back(word);            
        }
        
        vector<int> ret = s.findSubstring(S, L);
        cout << "[";
        for (size_t i = 0; i < ret.size(); i++) {
            cout << ret[i];
            if (i + 1 < ret.size()) {
                cout << " ";
            }
        }
        cout << "]" << endl;
    }
    return 0;
}