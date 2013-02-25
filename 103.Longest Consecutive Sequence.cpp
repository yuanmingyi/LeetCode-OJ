#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <unordered_set>
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
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> sec;
        for (size_t i = 0; i < num.size(); i++) {
            sec.insert(num[i]);
        }
        int maxlen = 0;
        unordered_set<int>::iterator it = sec.begin();
        while (it != sec.end()) {
            int len = 1;
            unordered_set<int>::iterator next = sec.find(*it+1);
            while (next != sec.end()) {
                len++;
                int x = *next;
                sec.erase(next);
                next = sec.find(x+1);
            }
            next = sec.find(*it-1);
            while (next != sec.end()) {
                len++;
                int x = *next;
                sec.erase(next);
                next = sec.find(x-1);                
            }
            if (len > maxlen) {
                maxlen = len;
            }
            it = sec.erase(it);
        }
        
        return maxlen;
    }
};

int main(void) {
    Solution s;
    string buff;
    while (getline(cin,buff)) {
        istringstream iss(buff);
        vector<int> array;
        char ch;
        int d;
        while (iss >> ch >> d) {
            array.push_back(d);
        }
        cout << s.longestConsecutive(array) << endl;
    }
    return 0;
}