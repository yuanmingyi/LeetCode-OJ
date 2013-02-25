#include <iostream>
#include <algorithm>

class Solution {
    std::vector<std::string> ret;
    
public:
    void recurComb(const char *in, std::vector<char>& out) {
        std::string startc("adgjmptw");
        startc.push_back('z'+1);
        
        if (*in == 0) {
            out.push_back(0);
            ret.push_back(out.data());
            out.pop_back();
        } else if (*in == '1') {
            recurComb(in + 1, out);
        } else if (*in == '0') {
            out.push_back(' ');
            recurComb(in + 1, out);
            out.pop_back();
        } else {
            int p = *in - '2';
            for (char c = startc[p]; c < startc[p+1]; c++) {
                out.push_back(c);
                recurComb(in+1, out);
                out.pop_back();
            }
        }
    }
    
    std::vector<std::string> letterCombinations(std::string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        std::vector<char> out;
        recurComb(digits.c_str(), out);
        return ret;
    }
};

int main(void) {
    Solution s;
    std::string input;
    while (std::getline(std::cin, input)) {
        std::vector<std::string> comb = s.letterCombinations(input.substr(1, input.length()-2));
        std::for_each(comb.begin(), comb.end(), [](std::string& str) {
            std::cout << "\"" << str << "\" ";
        });
        std::cout << std::endl;
    }
    return 0;
}