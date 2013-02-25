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
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        vector<pair<string, int> > finished;
        int hf = 0;
        int len = start.length();
        char *buff = new char[len+1];
        
        finished.push_back(pair<string, int>(start, 1));
        while (hf < finished.size()) {
            pair<string,int> cur = finished[hf++];
            strcpy(buff, cur.first.c_str());
            
            for (size_t i = 0; i < len; i++) {
                char p = buff[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    int diff = (c == p ? 0:1);
                    buff[i] = c;
                    if (end == buff) {
                        delete[] buff;
                        return cur.second+diff;
                    } 
                    if (dict.find(buff) != dict.end()) {
                        finished.push_back(pair<string,int>(buff,cur.second+diff));
                        dict.erase(buff);
                    }           
                }
                buff[i] = p;
            }
        }

        delete[] buff;
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