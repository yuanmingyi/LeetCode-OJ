class Solution {
public:
    void solve(vector<vector<char>> &board) {
        int rows = board.size();
        int cols = rows ? board[0].size() : 0;
        vector<int> st;
        int r = 0, c = 0;
        while (1) {
            if (r >= 0 && r < rows && c >= 0 && c < cols && board[r][c] == 'O') {
                board[r][c] = '-';
                st.push_back(0);
                r++;
            } else {
                while (!st.empty() && st.back() == 3) {
                    st.pop_back();
                    c++;
                }
                if (st.empty()) {
                    if (r == 0 && c < cols - 1) {
                        c++;
                    } else if (c == cols - 1 && r < rows - 1) {                        
                        r++;
                    } else if (r == rows - 1 && c > 0) {
                        c--;
                    } else {
                        r--;
                    }
                    if (r <= 0 && c == 0) {
                        break;
                    }
                } else {
                    switch(st.back()) {
                        case 0:
                            r--;
                            c++;
                            break;
                        case 1:
                            c--;
                            r--;
                            break;
                        case 2:
                            r++;
                            c--;
                            break;
                        default:
                            break;
                    }
                    st.back()++;
                }                
            }
        }
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                } else if (board[r][c] == '-') {
                    board[r][c] = 'O';
                }
            }
        }
    }
};
