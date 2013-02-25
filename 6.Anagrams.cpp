#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
using namespace std;

vector<string> anagrams(vector<string> &strs) {
	map<string, int> codemap;
	vector<string> codes, anags;
	for (int i = 0; i < strs.size(); i++) {
		string t = strs[i];
		vector<int> count(26,0);
		for (int j = 0; j < t.size(); j++) {
			count[t[j]-'a']++;
		}
		string code;
		for (int j = 0; j < count.size(); j++) {
			if (count[j] > 0) {
				code.push_back(j+'a');
				char b[12];
				sprintf(b, "%d", count[j]);
				code.append(b);
			}
		}
		codes.push_back(code);
		if (codemap.find(code) != codemap.end()) {
			codemap[code] ++;
		} else {
			codemap[code] = 1;
		}
	}
        for (int i = 0; i < codes.size(); i++) {
		if (codemap[codes[i]] > 1) {
			anags.push_back(strs[i]);
		}
	}
	return anags;
}

int main(void) {
	int n;
	while (cin >> n) {
		vector<string> strs;
		for (int i = 0; i < n; i++) {
			string tmp;
			cin >> tmp;
			strs.push_back(tmp);
		}
		vector<string> anags = anagrams(strs);
		for (int i = 0; i < anags.size(); i++) {
			cout << anags[i] << ", ";
		}
		cout << endl;
	}
	return 0;
}