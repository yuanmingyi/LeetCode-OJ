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
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(),num.end());
        vector<vector<int> > ret;
        vector<int> solution(3);
        for (size_t i = 0; i < num.size(); i++) {
            int target = -num[i];
            if (i > 0 && num[i] == num[i-1]) continue;
            for (size_t j = i + 1, k = num.size() - 1; j < k;) {                
                if (num[j] + num[k] == target) {
                    solution[0] = num[i];
                    solution[1] = num[j];
                    solution[2] = num[k];
                    ret.push_back(solution);
                    do {
                        j++;
                    } while (j < k && num[j] == num[j-1]);
                    do {
                        k--;
                    } while (j < k && num[k] == num[k+1]);
                } else if (num[j] + num[k] < target) {
                    j++;
                } else {
                    k--;
                }                
            }
        } 
        
        return ret;
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
        vector<vector<int> > s = threeSum(array);
        for (size_t i = 0; i < s.size(); i++) {
            cout << "[" << s[i][0] << "," << s[i][1] << "," << s[i][2] << "]" << endl;            
        }
    }
    return 0;
}