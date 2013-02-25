#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
using namespace std;

class Solution {
public:
    void genLadders(vector<pair<string,vector<int> > >& queue, int k, vector<string>& ladder, vector<vector<string> >& ladders) {
        if (k < 0) {
            ladders.push_back(ladder);
            return;
        }
        pair<string, vector<int> >& cur = queue[k];
        ladder.push_back(cur.first);
        for (size_t i = 0; i < cur.second.size(); i++) {
            genLadders(queue, cur.second[i], ladder, ladders);
        }
        ladder.pop_back();
    }
    
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<pair<string, vector<int> > > finished;
        int hf = 0, count = 0;
        int len = end.length();
        char *buff = new char[len+1];
        
        unordered_map<string, pair<int,int> > dictmap;
        for (unordered_set<string>::iterator it = dict.begin(); it != dict.end(); it++) {
            if (*it != start && *it != end) dictmap[*it] = pair<int,int>(0,0);
        }
        
        int dist = 0, mindist = 0;
        finished.push_back(pair<string, vector<int> >(end, vector<int>(1,-1)));
        
        while (hf < finished.size()) {
            pair<string, vector<int> >& cur = finished[hf];
            if (hf >= count) {
                dist++;
                if (mindist > 0) {
                    break;
                }
                count = finished.size();
            }
            
            strcpy(buff, cur.first.c_str());
            
            for (int i = 0; i < len; i++) {
                char p = buff[i];
                for (char c = 'a'; c <= 'z'; c++) {                    
                    if (p == c) continue;
                    buff[i] = c;
                    if (start == buff) {
                        mindist = dist;
                        if (finished.back().first != start) {
                            finished.push_back(pair<string,vector<int> >(start, vector<int>(1,hf)));
                        } else {
                            finished.back().second.push_back(hf);
                        }
                    } 
                    if (mindist > 0) continue;
                    unordered_map<string, pair<int,int> >::iterator it = dictmap.find(buff);
                    if (it != dictmap.end()) {
                        if (it->second.first == 0) {
                            it->second.first = dist;
                            it->second.second = finished.size();
                            finished.push_back(pair<string,vector<int> >(buff, vector<int>(1,hf)));
                        } else if (it->second.first == dist) {
                            finished[it->second.second].second.push_back(hf);
                        }
                    }
                }
                buff[i] = p;
            }
            
            hf++;
        }
 
        vector<vector<string> > ladders;
        vector<string> ladder;
        if (mindist > 0) {
            genLadders(finished, finished.size()-1, ladder, ladders);
        }
        delete[] buff;
        return ladders;        
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
       vector<vector<string> > ladders = s.findLadders(start, end, dict);
       cout << "[" << endl;
       for_each(ladders.begin(), ladders.end(), [&](vector<string>& s) { 
           cout << " [";
           copy(s.begin(), s.end(), ostream_iterator<string>(cout, ", "));
           cout << "]" << endl;
       });
       cout << "]" << endl;
    }
    return 0;
}