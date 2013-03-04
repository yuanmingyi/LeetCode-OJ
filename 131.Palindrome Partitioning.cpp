class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > part;
        for (size_t i = 1; i <= s.length(); i++) {
            size_t j = 0, k = i-1;
            while (j < k && s[j] == s[k]) {
                j++;
                k--;                
            }
            if (j >= k) {
                string pre = s.substr(0,i);                
                vector<vector<string> > p = partition(s.substr(i));
                if (p.empty()) {
                    part.push_back(vector<string>(1, pre));
                }
                for (size_t m = 0; m < p.size(); m++) {
                    vector<string> full(1, pre);
                    for (size_t n = 0; n < p[m].size(); n++) {
                        full.push_back(p[m][n]);
                    }
                    part.push_back(full);
                }                
            }
        }
        return part;
    }
};
