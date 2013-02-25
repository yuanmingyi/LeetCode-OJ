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
    class Comp {
    public:
        vector<int> data;
        Comp(vector<int>& numbers):data(numbers) {}
        bool operator() (int a, int b) {
            return data[a-1] < data[b-1];
        }
    };
        
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> indice;
        for (size_t i = 0; i < numbers.size(); i++) {
            indice.push_back(i+1);
        }
                
        sort(indice.begin(), indice.end(), Comp(numbers));
        
        int i = 0, j = numbers.size() - 1;
        while (i < j) {
            int sum = numbers[indice[i]-1] + numbers[indice[j]-1];
            if (sum < target) {
                i++;
            } else if (sum > target) {
                j--;
            } else {
                break;
            }
        }
        vector<int> ans;
        if (i == j) {
            return ans;
        }
        if (indice[i] > indice[j]) {
            swap(i,j);
        }
        ans.push_back(indice[i]);
        ans.push_back(indice[j]);
        
        return ans;
    }
};

int main(void) {
    Solution s;
    string buff;
    while (getline(cin, buff)) {
        vector<int> data;
        int target;
        char ch;
        istringstream iss(buff);
        while (iss >> ch >> target) {
            data.push_back(target);
        }
        iss.clear();
        iss >> ch >> target;
        vector<int> ret = s.twoSum(data, target);
        cout << "[" << ret[0] << ", " << ret[1] << "]" << endl;        
    }
    
    return 0;
}