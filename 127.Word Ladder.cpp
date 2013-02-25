#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <unordered_set>
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
    int comp(const string& s1, const string& s2) {
        int diff = 0;
        for (size_t i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) diff++;
        }
        return diff;
    }
    
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        vector<pair<string, int> > finished;
        list<string> wait;
        int hf = 0;
        
        for (unordered_set<string>::iterator it = dict.begin(); it != dict.end(); it++) {
            wait.push_back(*it);
        }
        
        finished.push_back(pair<string, int>(start, 1));
        while (hf < finished.size()) {
            pair<string,int> cur = finished[hf++];
            int diff = comp(end, cur.first);
            if (diff <= 1) {
                return cur.second + diff;
            }
            for (list<string>::iterator it = wait.begin(); it != wait.end(); it++) {
                string str = *it;
                int d = comp(str, cur.first);
                if (d <= 1) {
                    finished.push_back(pair<string,int>(str, cur.second+d));
                    it = wait.erase(it);
                }
            }
        }

        return 0;
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
        unordered_set<string> dict;
        istringstream iss(buff);
        string start = getString(iss);
        string end = getString(iss);
        char ch;
        while (iss >> ch && ch != ']') {
            string word = getString(iss);
            dict.insert(word);
        }
        cout << s.ladderLength(start, end, dict) << endl;
    }
    return 0;
}