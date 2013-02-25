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

vector<vector<int> > fourSum(vector<int>& arr, int target) {
	vector<vector<int> > ret;
	int len = arr.size();
	sort(arr.begin(), arr.end());
	for (int i = 0; i < len; ) {
		for (int j = i+1; j < len; ) {
			int s1 = arr[i] + arr[j];
			for (int k = j+1, m = len-1; k < m; ) {
				int s = s1 + arr[k] + arr[m];
				if (s == target) {
					int q[4] = {arr[i], arr[j], arr[k], arr[m]};
					ret.push_back(vector<int>(q,q+4));
					while (++k < m && arr[k] == arr[k-1]);
					while (--m > k && arr[m] == arr[m+1]);
				} else if (s < target) {
					while (++k < m && arr[k] == arr[k-1]);				
				} else {
					while (--m > k && arr[m] == arr[m+1]);
				}
			}
			while (++j < len && arr[j] == arr[j-1]);
		}
		while (++i < len && arr[i] == arr[i-1]);
	}
	return ret;
}

int main(void) {
	int n, x;
	while (cin >> n >> x) {
		vector<int> arr;
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			arr.push_back(tmp);
		}
		vector<vector<int> > q = fourSum(arr, x);
		cout << q.size() << ":" << endl;
		for (int i = 0; i < q.size(); i++) {
			for (int j = 0; j < 4; j++) {
				cout << q[i][j] << ", ";
			}
			cout << endl;
		}
	}
	return 0;
}