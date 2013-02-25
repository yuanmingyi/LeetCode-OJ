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

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if (haystack == 0 || needle == 0) {
            return 0;
        }
        int len1 = strlen(haystack);
        int len2 = strlen(needle);
    
        for (int i = 0; i <= len1-len2; i++) {
            int j = 0;
            for (; j < len2 && haystack[i+j] == needle[j]; j++) {
            }
            if (j == len2) {
                return haystack + i;
            }
        }
        
        return 0;
    }
};

int main(void) {
    Solution s;
    char haystack[512], needle[512];
    while (cin >> haystack >> needle) {
        haystack[strlen(haystack)-1] = 0;
        needle[strlen(needle)-1] = 0;
        char *p = s.strStr(haystack+1, needle+1);
        printf("%s\n", p ? p: "NULL");
    }
    return 0;
}