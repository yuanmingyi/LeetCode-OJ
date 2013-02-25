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

/**
 * Definition for an interval.
 */
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int begin = 0, end = intervals.size();
        while (begin < end) {
            int mid = begin + (end - begin) / 2;
            if (intervals[mid].start <= newInterval.start) {
                begin = mid + 1;
            } else {
                end = mid;
            }
        }
        // intervals[begin].start >= newInterval.start
        // intervals[begin-1].start < newInterval.start
        vector<Interval> ret;        
        for (int i = 0; i < begin; i++) {
            ret.push_back(intervals[i]);
        }
        if (ret.size() == 0 || ret.back().end < newInterval.start) {
            ret.push_back(newInterval);
        } else if (ret.back().end < newInterval.end) {
            ret.back().end = newInterval.end;
        }
        
        end = intervals.size();
        while (begin < end) {
            int mid = begin + (end - begin) / 2;
            if (intervals[mid].start <= ret.back().end) {
                begin = mid + 1;
            } else {
                end = mid;
            }
        }
        
        if (begin > 0 && ret.back().end < intervals[begin-1].end) {
            ret.back().end = intervals[begin-1].end;
        }
        
        for (int i = begin; i < intervals.size(); i++) {
            ret.push_back(intervals[i]);
        }
        
        return ret;
    }
};

int main(void) {
    Solution s;
    char ch = 0;
    string buff;
    while (cin >> ch) {
        vector<Interval> intervals;
        int b, e;
        while (ch != ']') {
            while (scanf("[%d,%d]", &b, &e) == 2) {
                intervals.push_back(Interval(b,e));
            }
            cin >> ch;
        }
        scanf(", [%d,%d]", &b, &e);
        Interval newInterval(b, e);
        vector<Interval> result = s.insert(intervals, newInterval);
        for (int i = 0; i < result.size(); i++) {
            cout << "[" << result[i].start << "," << result[i].end << "] ";
        }
        cout << endl;
        getline(cin, buff);
    }
    return 0;
}