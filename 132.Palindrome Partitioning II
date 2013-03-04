class Solution {
    vector<int> mincut;
public:
    void minCut(const string& s, int i) {        
        if (mincut[i] < 0) {                    
            for (int n = s.length(), j = n - 1; j >= 0; j--) {
                int k = i, m = j;
                while (k < m && s[k] == s[m]) {
                    k++;
                    m--;
                }
                if (k >= m) {
                    if (j == n - 1) {
                        mincut[i] = 0;                        
                    } else {
                        minCut(s, j+1);
                        if (mincut[i] < 0 || mincut[i] > mincut[j+1] + 1) {
                            mincut[i] = mincut[j+1] + 1;
                        }                        
                    }
                    if (mincut[i] <= 1) {
                        break;
                    }
                }
            }
        }
    }
    
    int minCut(string s) {                
        mincut = vector<int>(s.length()+1, -1);
        if (s.length() == 0) {
            return 0;
        }
        minCut(s, 0);
        return mincut[0];
    }
};
