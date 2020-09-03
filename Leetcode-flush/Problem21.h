#pragma once
#include "public_def.h"
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode() : val(0), next(nullptr) {}
*     ListNode(int x) : val(x), next(nullptr) {}
*     ListNode(int x, ListNode *next) : val(x), next(next) {}
* };
*/
// struct ListNode {
// 	int val;
// 	ListNode*  next;
// 	ListNode() :val(0), next(nullptr) {};
// 	ListNode(int x) :val(x), next(nullptr) {};
// 	ListNode(int x, ListNode* next) :val(x), next(next) {};
// };


class Solution_problem21 {
public:
// 	inline void trimLeftTrailingSpaces(string &input) {
// 		input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
// 			return !isspace(ch);
// 		}));
// 	}
// 	inline void trimRightTrailingSpaces(string &input) {
// 		input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
// 			return !isspace(ch);
// 		}).base(), input.end());
// 	}
// 	vector<int> stringToIntegerVector(string input) {
// 		vector<int> output;
// 		trimLeftTrailingSpaces(input);
// 		trimRightTrailingSpaces(input);
// 		input = input.substr(1, input.length() - 2);
// 		stringstream ss;
// 		ss.str(input);
// 		string item;
// 		char delim = ',';
// 		while (getline(ss, item, delim)) {
// 			output.push_back(stoi(item));
// 		}
// 		return output;
// 	}
// 
// 	ListNode* stringToListNode(string input) {
// 		// Generate list from the input
// 		vector<int> list = stringToIntegerVector(input);
// 
// 		// Now convert that list into linked list
// 		ListNode* dummyRoot = new ListNode(0);
// 		ListNode* ptr = dummyRoot;
// 		for (int item : list) {
// 			ptr->next = new ListNode(item);
// 			ptr = ptr->next;
// 		}
// 		ptr = dummyRoot->next;
// 		delete dummyRoot;
// 		return ptr;
// 	}
// 
// 	string listNodeToString(ListNode* node) {
// 		if (node == nullptr) {
// 			return "[]";
// 		}
// 
// 		string result;
// 		while (node) {
// 			result += to_string(node->val) + ", ";
// 			node = node->next;
// 		}
// 		return "[" + result.substr(0, result.length() - 2) + "]";
// 	}
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
// 		if (l1 || l2) return l1 ? l1 : l2;
// 		ListNode* ans = new ListNode();
// 		ListNode* real_ans = new ListNode(0, ans);
// 		ans->next = l1;
// 		while (l1 && l2)
// 		{
// 				if (l1->val <= l2->val)
// 				{
// 					ans->next = l1;
// 					ans = ans->next;
// 					l1 = l1->next;
// 				}
// 				else if (l1->val > l2->val)
// 				{
// 					ans->next = l2;
// 					ans = ans->next;
// 					l2 = l2->next;
// 				}
// 
// 		}
// 		ans->next = l1 ? l1 : l2;
// 		return real_ans->next->next;
		if ((!l1) || (!l2)) return l1 ? l1 : l2;
		ListNode head, *tail = &head;
		while (l1 && l2) {
			if (l1->val <= l2->val) {
				tail->next = l1; l1 = l1->next;
			}
			else {
				tail->next = l2; l2 = l2->next;
			}
			tail = tail->next;
		}
		tail->next = (l1 ? l1 : l2);
		return head.next;
	}

	void test_solution()
	{
		string line;
		while (getline(cin, line)) {
			ListNode* l1 = stringToListNode(line);
			getline(cin, line);
			ListNode* l2 = stringToListNode(line);

			ListNode* ret = mergeTwoLists(l1, l2);

			string out = listNodeToString(ret);
			cout << out << endl;
		}
	}
};





