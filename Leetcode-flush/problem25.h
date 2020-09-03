#pragma once
#include "public_def.h"
namespace solution25
{
	class Solution_problem25 {
	public:
		ListNode* reverseK(ListNode*& temp1, ListNode*& temp2)
		{
			ListNode temp_ans, *tempTail = &temp_ans ;
			tempTail->next = temp1;
			ListNode *lastTail = new ListNode();
			ListNode *seclastTail = new ListNode();
			int id=0;
			while (temp1&&temp2&&temp1 != temp2)
			{
				id++;
				if (id >= 2)
				{
					lastTail->next->next = temp1->next;
					temp1->next = lastTail->next;
					if (seclastTail->next)seclastTail->next->next = temp1;
					if (id == 2)tempTail->next = temp1;

					seclastTail->next = temp1;
					lastTail->next = temp1->next;


					temp1 = lastTail->next->next;
				}
				else
				{
					seclastTail->next = lastTail->next;
					lastTail->next = temp1;
					temp1 = temp1->next;
				}
			}
			
			return temp_ans.next;

		}
		ListNode* reverseKGroup(ListNode* head, int k) {
			// 每k个节点 倒序一次
			ListNode ans, *tail = &ans, *firsttail=head, *lasttail= head ;
			tail->next = head;
			int id_index = 0;
			while (head)
			{
				id_index++;
				if (id_index%k == 0)
				{
				//	id_index = 0;
					if(id_index==k)tail->next = reverseK(firsttail, lasttail);
					else reverseK(firsttail, lasttail);
					lasttail = lasttail->next;firsttail = lasttail;
					// 反转一次
				}
				head = head->next;
				lasttail = head;
			}
			return ans.next;

		}
		void testreverse()
		{
			string line;
			int key = 0;
			getline(cin, line);
		/*	while (getline(cin, line)) {*/
			ListNode* l1 = stringToListNode(line);
			cout << "please input the k number : " << endl;
			cin >> key;
			ListNode* ret = reverseKGroup(l1, key);

			string out = listNodeToString(ret);
			cout << out << endl;
			cin.clear();


			system("pause");
		//	}
		}

	};
}