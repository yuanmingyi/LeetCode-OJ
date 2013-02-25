#include <iostream>


class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int count = 0;
        for (const char *p = s; *p; p++) {
            if (*p != ' ') {
                count ++;
                if (p > s && *(p - 1) == ' ') {
                    count = 1;
                }
            } 
        }
        return count;
    }
};

int main(void) {
    Solution s;
    std::string input;
    while (std::getline(std::cin, input)) {
        int length = s.lengthOfLastWord(input.substr(1, input.length()-2).c_str());
        std::cout << length << std::endl;
    }
    return 0;
}