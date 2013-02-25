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
    static int compare(const Interval& a, const Interval& b) {
        return a.start < b.start;
    }
    
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(intervals.begin(), intervals.end(), compare);
        vector<Interval> merged;
        Interval current;
        for (size_t i = 0; i < intervals.size(); i++) {
            if (i == 0 || intervals[i].start > current.end) {
                if (i > 0) {
                    merged.push_back(current);
                }
                current = intervals[i];
            } else if (current.end < intervals[i].end) {
                current.end = intervals[i].end;
            }
        }
        if (intervals.size() > 0) {
            merged.push_back(current);
        }
        return merged;
    }
};

int main(void) {
    return 0;
}