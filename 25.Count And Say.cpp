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

void addNum(string& s, int n) {
	string v;
	while (n > 0) {
	        v.push_back(n % 10 + '0');
	        n /= 10;
	}
	for (int i = v.length() - 1; i >= 0; i--) {
		s.push_back(v[i]);
	}
}

string countAndSay(int n) {
	string s = "1";
	while (--n > 0) {
		string t = s;
		s = "";
		for (int i = 0; i < t.length(); i++) {
			int cnt = 1;
			while (t[i] == t[i+1]) {
				i++;
				cnt++;
			}
			addNum(s, cnt);
			s.push_back(t[i]);
		}
	}
	return s;
}

int main(void) {
	int n;
	while (cin >> n) {
		cout << countAndSay(n) << endl;
	}
	return 0;
}