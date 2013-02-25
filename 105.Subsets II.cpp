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
    void getSubsets(const int *data, size_t len, vector<int>& subset, vector<vector<int> >& subsets) {
        if (len > 0) {
            size_t i = 1;
            while (i < len && data[i] == data[0]) i++;
            getSubsets(data+i, len - i, subset, subsets);
            subset.push_back(data[0]);
            getSubsets(data+1, len - 1, subset, subsets);
            subset.pop_back();
        } else {
            subsets.push_back(subset);
        }
    }
    
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > subsets;        
        vector<int> subset;
        sort(S.begin(), S.end());        
        getSubsets(S.data(), S.size(), subset, subsets);
        return subsets;
    }
};

int main(void) {
    Solution s;
    string line;
    while (getline(cin, line)) {
        vector<int> S;
        int d;
        char ch;
        istringstream iss(line);
        while (iss >> ch >> d) {
            S.push_back(d);
        }
        vector<vector<int> > subsets = s.subsetsWithDup(S);
        for (size_t i = 0; i < subsets.size(); i++) {
            cout << "[";
            for (size_t j = 0; j < subsets[i].size(); j++) {
                cout << subsets[i][j];
                if (j < subsets[i].size() - 1) cout << " ";
            }
            cout << "]" << endl;
        }
        cout << endl;
    }
    return 0;
}