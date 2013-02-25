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
/*
 * Definition for singly-linked list.
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
	int c = 0;
	ListNode *p = 0, *sum = 0;
	while (l1 || l2 || c > 0) {
		int tmp = c;
		if (l1) {
			tmp += l1->val;
			l1 = l1->next;
		}
		if (l2) {
			tmp += l2->val;
			l2 = l2->next;
		}
		ListNode *q = new ListNode(tmp % 10);
		if (p) {
			p->next = q;
			p = q;
		} else {
			sum = p = q;
		}
		c = tmp / 10;
	}
	return sum;
}

ListNode *createList(int n) {
	if (n == 0) {
		return new ListNode(0);
	}
	ListNode *list = 0, *p = 0;
	while (n > 0) {
		ListNode *q = new ListNode(n % 10);
		if (p) {
			p->next = q;
			p = q;
		} else {
			list = p = q;
		}
		n /= 10;
	}
	return list;
}

void deleteList(ListNode *list) {
	while (list) {
		ListNode *p = list->next;
		delete list;
		list = p;
	}
}

void printList(ListNode *list) {
	while (list->next) {
		cout << list->val << ",";
		list = list->next;
	}
	cout << list->val << endl;
}

int main(void) {
	ListNode *l1 = 0, *l2 = 0;
	int n1, n2;
	while (cin >> n1 >> n2) {
		ListNode *l1 = createList(n1);
		ListNode *l2 = createList(n2);
		ListNode *l3 = addTwoNumbers(l1, l2);
		printList(l3);
		deleteList(l1);
		deleteList(l2);
		deleteList(l3);
	}
	return 0;
}