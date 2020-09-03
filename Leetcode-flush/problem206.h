#ifndef PROBLEM206_H_INCLUDED
#define PROBLEM206_H_INCLUDED
#include "public_def.h"

namespace solution206
{
	class Solution_problem206 {
	public:


		ListNode* reverseList(ListNode* head) {
// 			ListNode ans, *tail = &ans;
// 			tail->next = head;
// 			
// 			ListNode *lasttail = new ListNode();
			ListNode ans, *tail=&ans,*Tail = tail;
			stack<ListNode*> _stack;
			while (head)
			{
				_stack.push(head);
				head = head->next;
			}
			while (!_stack.empty())
			{
				Tail->next = _stack.top();
				Tail->next->next = nullptr;
				_stack.pop();
				Tail = Tail->next;
			}

			return ans.next;
// 			while (head)
// 			{
// 
// 
// 
// 			//	head = head->next;
// 			}
// 			int id_index = 0;
// 			while (head)
// 			{
// 				id_index++;
// 				if (id_index > 1)
// 				{
// 					lasttail->next->next = head->next;
// 					head->next = lasttail->next;
// 					
// 				}
// 				else {
// 					lasttail->next = head;
// 					head = head->next;
// 				}
// 
// 			}
// 			int id_index = 0;
// 			while (head)
// 			{
// 				id_index++;
// 				tail->next = head;
// 				lasttail->next = head;
// 				head = head->next;
// 
// 			if(id_index>1)	head->next = lasttail->next;
// 			}

			return ans.next;



		}
		void testreverselist()
		{
			string input_vec;
			
			while (getline(cin, input_vec)) {
				trimLeftTrailingSpaces(input_vec);
				trimRightTrailingSpaces(input_vec);
				ListNode *testlist = stringToListNode(input_vec);
				string str = listNodeToString(reverseList(testlist));
				cout << str << endl;
			}

		}
	};
}


#endif //PROBLEM206_H_INCLUDED