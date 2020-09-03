#ifndef _P141_H_
#define _P141_H_
#include "public_def.h"

//  环形链表 , input ,链表 ， pos ， 索引 从0 开始, pos为-1 则没有环

class Solution_p141 {
public:
	bool hasCycle(ListNode *head) {
		if (head == nullptr || head->next == nullptr)return false;
		ListNode* fastnode = head;
		ListNode* slownode = head;

		while ((fastnode != nullptr || slownode != nullptr))
		{
				
			if (slownode->next == nullptr || fastnode->next == nullptr || fastnode->next->next == nullptr)
			{
				return false;
			}
			slownode = slownode->next;
			fastnode = fastnode->next->next;
			if (fastnode == slownode)
			{
				return true;
			}
		}
		
		return false;	
	}

	void deletelist(ListNode* head)
	{		
		while (head != nullptr)
		{
			ListNode* v1 = head;
			head = head->next;
			delete v1;
		}
	}
	void testp141()
	{
		ListNode *list = new ListNode(1);
		list->next = new ListNode(2);
		list->next->next = new ListNode(3);
	
		cout << hasCycle(list) << endl;
		deletelist(list);
	}
};





#endif // _P141_H_