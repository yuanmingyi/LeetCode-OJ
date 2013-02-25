#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0) return "";
        for (size_t i = 0; ; i++) {
            char c;
            size_t j = 0;
            for (; j < strs.size(); j++) {                                
                if (i >= strs[j].length()) {
                    return strs[j].substr(0,i);
                }
                if (j == 0) {
                    c = strs[j][i];
                } else if (strs[j][i] != c) {
                    return strs[j].substr(0,i);
                }         
            }            
        }        
    }
};

int main(void) {
    
    return 0;
}