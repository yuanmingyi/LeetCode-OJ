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
    
string addBinary(string a, string b) {
	string tmp;
	int i, j;
	char c = '0';
	for (i = a.length()-1, j = b.length()-1; i >= 0 || j >= 0; i--, j--) {		
		char t = c;
		if (i >= 0) t += a[i] - '0';
		if (j >= 0) t += b[j] - '0';
		if (t > '1') {
			t -= 2;
			c = '1';
		} else {
			c = '0';
		}
		tmp.push_back(t);
	}
	if (c > '0') tmp.push_back(c);
	string sum;
	for (i = tmp.length()-1; i >= 0; i--) {
		sum.push_back(tmp[i]);
	}
	return sum;
}

int main(void) {
	string a, b;
	while(cin >> a >> b) {
		cout << addBinary(a, b) << endl;
	}
	return 0;
}