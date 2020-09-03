#pragma once
// 多个有序链表合并
#include "public_def.h"

namespace solution23 
{
	class Solution_problem23 {
	
	public:
		void  mergeList(ListNode* &A, ListNode*& B)
		{
			ListNode* temp = new ListNode();
			temp->next = A ? A : B;
			ListNode* temp_2 = new ListNode();
			temp_2->next = temp->next;
			while (A && B)
			{
					if (A->val <= B->val)
					{
						temp->next = A;
						temp = temp->next;
						A = A->next;

					}
					else if (A->val > B->val)
					{
						temp->next = B;
						temp = temp->next;
						B = B->next;
					}
				
			}
			temp->next = A ? A : B;
			A = temp_2;

		}
		ListNode* mergeKLists(vector<ListNode*>& lists)
		{
			ListNode* ans = new ListNode(INT_MIN);
			int n = lists.size();
			if (n== 0) return nullptr;
			if (n == 1) return lists[0];
		
			for (auto iter: lists)
			{
				if (!(iter))continue;
				if(iter && ans->next==nullptr) 
				{ 
					ans->next = iter;
					continue;
				}
			//	ans = mergeTwoLists(ans, iter);
				mergeList(ans, iter);
				ans = ans->next;
			}
			
			return ans->val== INT_MIN ? ans->next : ans;
			return merge(lists,0,lists.size()-1);
		}

		ListNode* mergeTwoLists(ListNode *a, ListNode *b) {
			if ((!a) || (!b)) return a ? a : b;
			ListNode head, *tail = &head, *aPtr = a, *bPtr = b;
			while (aPtr && bPtr) {
				if (aPtr->val < bPtr->val) {
					tail->next = aPtr; aPtr = aPtr->next;
				}
				else {
					tail->next = bPtr; bPtr = bPtr->next;
				}
				tail = tail->next;
			}
			tail->next = (aPtr ? aPtr : bPtr);
			return head.next;
		}
		// 分治算法
		ListNode* merge(vector <ListNode*> &lists, int l, int r) {
			if (l == r) return lists[l];
			if (l > r) return nullptr;
			int mid = (l + r) >> 1;
			return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
		}

	





	
		void test_merge()
		{
			string line;
			vector<ListNode*> lists;
			while (getline(cin, line)) {
				ListNode* l1 = stringToListNode(line);
				lists.push_back(l1);

				getline(cin, line);
				ListNode* l2 = stringToListNode(line);
				lists.push_back(l2);

				getline(cin, line);
	
				ListNode* l3 = stringToListNode(line);
				lists.push_back(l3);

				ListNode* ret = mergeKLists(lists);

				string out = listNodeToString(ret);
				cout << out << endl;
				cin.clear();
			}
		}
	};


}