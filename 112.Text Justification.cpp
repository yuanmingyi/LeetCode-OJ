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
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> ret;
        int length = 0;
        int i, j;
        for (i = 0, j = 0; i < words.size(); i++) {
            int inc = words[i].length();
            if (i - j > 0) {
                inc++;
            }
            if (inc + length <= L) {
                length += inc;
            } else {
                int extra = L - length;
                int nsep = i - j - 1;
                int pad = nsep ? extra / nsep : extra;
                int bound = pad * nsep + nsep - extra;
                
                string line;
                
                while (j < i) {                    
                    line += words[j];
                    if (j < i - 1 || nsep == 0) {                        
                        for (int k = 0; k < pad; k++) {
                            line.push_back(' ');
                        }
                        if (nsep > 0 && i - j - 1 > bound) {
                            line.push_back(' ');
                        }
                        if (nsep > 0) {
                            line.push_back(' ');
                        }
                    }
                    j++;
                }
                
                ret.push_back(line);
                length = 0;
                i--;
            }            
        }
        
        string line = words[j];
        while (++j < i) {
            line.push_back(' ');
            line += words[j];
        }
        while (line.length() < L) {
            line.push_back(' ');
        }
        ret.push_back(line);
        
        return ret;
    }
};

int main(void) {
    Solution s;
    string buff;
    while (getline(cin, buff)) {
        vector<string> words;
        int L;
        istringstream iss(buff);
        char ch;
        while (iss >> ch && ch != ']') {
            string word;
            while (iss >> ch && ch != '"');
            while (iss >> ch && ch != '"') {
                word.push_back(ch);
            }
            words.push_back(word);
        }
        iss >> ch >> L;
        vector<string> ret = s.fullJustify(words, L);
        
        cout << "[" << endl;
        for (size_t i = 0; i < ret.size(); i++) {
            cout << " \"" << ret[i] << "\"" << endl;
        }
        cout << "]" << endl;
    }
    
    return 0;
}