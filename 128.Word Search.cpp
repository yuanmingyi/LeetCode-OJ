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
    bool exist(vector<vector<char> > &board, string word) {
        int rows = board.size();
        int cols = rows > 0 ? board[0].size() : 0;
        vector<vector<bool> > visit(rows, vector<bool>(cols, false));
        
        int r = 0, c = 0, p = 0, flag = 0;
        vector<int> st;
        while (1) {
            if (flag || r < 0 || r >= rows || c < 0 || c >= cols || visit[r][c] || board[r][c] != word[p]) {
                flag = 0;
                if (st.empty()) {
                    c++;
                    if (c >= cols) {
                        r++;
                        c = 0;
                        if (r >= rows) {
                            break;
                        }
                    }
                    continue;
                }                                
                switch (st.back()) {
                    case 0:
                        r+=2;
                        break;
                    case 1:
                        r--;
                        c--;
                        break;
                    case 2:
                        c+=2;
                        break;
                    case 3:
                        c--;
                        visit[r][c] = false;
                        st.pop_back();
                        p--;
                        flag = 1;
                        continue;
                        break;
                    default:
                        break;
                }
                if (st.size()) {
                    st.back()++;    
                }                
            } else {
                visit[r][c] = true;
                p++;
                if (p == word.length()) {
                    return true;
                }                
                r--;
                st.push_back(0);
            }
        }
        
        return false;
    }
};

string getString(istream& is) {
    char ch;
    string str;
    while (is >> ch && ch != '"');
    while (is >> ch && ch != '"') {
        str.push_back(ch);
    }
    return str;
}

int main(void) {
    Solution s;
    string buff;
    while (getline(cin,buff)) {
        istringstream iss(buff);
        char ch;
        vector<vector<char> > board;
        while (iss >> ch && ch != ']') {
            string str = getString(iss);
            vector<char> row(str.begin(), str.end());
            board.push_back(row);
        }
        string word = getString(iss);
        cout << (s.exist(board, word) ? "true" : "false") << endl;
    }
    return 0;
}