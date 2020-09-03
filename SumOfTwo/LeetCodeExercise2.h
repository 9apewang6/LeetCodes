#pragma once
#include <iostream>
#include <list>
#include <algorithm>
using std::list;
using std::cout;
using std::endl;
using std::cin;
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class SolutionAddSumNumbers {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		 
		ListNode *results = new ListNode(0);
		ListNode *result2 = results;
		int temp=0;
		do
		{
			temp = results->val + (l1 != NULL ? l1->val : 0) + (l2 != NULL ? l2->val : 0);
			results->val =temp % 10;
			if (((l1!=NULL&&l1->next != NULL) || (l2!=NULL&&l2->next != NULL) || (temp >= 10)))
			{
				results->next = new ListNode(temp/ 10);
				results = results->next;
			}
			if (l1 != NULL)
			{
				l1 = l1->next;
			}
			if (l2 != NULL)
			{
				l2 = l2->next;
			}

		} while (l1 != NULL || l2 != NULL);
	

		return result2;
	}
};

