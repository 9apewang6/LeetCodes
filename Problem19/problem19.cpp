// 删除链表第N个节点
/************************************************************************/
/* 
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点

*/
/************************************************************************/
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
 struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
// 	int get_len(ListNode* head)
// 	{
// 		ListNode *p = head->next;
// 		int len = 0;
// 		while (p)
// 		{
// 			len++;
// 			p = p->next;
// 		}
// 		return len;
// 	}
};
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *temp = new ListNode(NULL);
		// temp 指向 将要删除的节点
		temp->next = head;
		ListNode* fastpoint;
		ListNode* slowpoint;
		fastpoint = slowpoint = temp->next;
		for (int i = 0; i < n; i++)
		{
			fastpoint = fastpoint->next;
		}
		while (fastpoint)
		{
			fastpoint = fastpoint->next;
			slowpoint = slowpoint->next;
		}
		slowpoint->next = slowpoint->next->next;
		return temp->next;
	}
	ListNode* removeNthFromEnd2(ListNode* head, int n)
	{
		if (head == nullptr || head->next == nullptr) return nullptr;
		ListNode tmp = ListNode(0);
		ListNode* fast = &tmp;
		ListNode* slow = &tmp;
		fast->next = head;
		slow->next = head;
		int cnt = 0;
		while (fast != nullptr) {
			fast = fast->next;
			if (cnt > n) slow = slow->next;
			cnt++;
		}
		ListNode* rm = move(slow->next);
		slow->next = rm->next;
		delete rm;
		return tmp.next;
	}
};
int main(int mgv, char* mgr)
{
	ListNode *head = new ListNode(0);
	ListNode *p1 = new ListNode(1);
	ListNode *p2 = new ListNode(2);
	ListNode *p3 = new ListNode(3);
	ListNode *p4 = new ListNode(4);
	head->next = p1;
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	Solution s;
	s.removeNthFromEnd2(head, 2);

	system("pause");
	return 0;
}