#pragma once
// �����������ڵ�
//����һ���������������������ڵĽڵ㣬�����ؽ����������

//�㲻��ֻ�ǵ����ĸı�ڵ��ڲ���ֵ��������Ҫʵ�ʵĽ��нڵ㽻����
// 1->2->3->4 
// ���� 2->1->4->3
#include "public_def.h"
namespace solution24
{

	class Solution_problem24 {
	public:
		ListNode* swapPairs(ListNode* head) {
			// ��������
			ListNode ans,*tail=&ans;
			tail->next = head;
			ListNode *lasttail = new ListNode();
			ListNode *seclasttail = new ListNode();
			int id = 0;
			while (head)
			{
				id++;
				if (id % 2 == 0)
				{
					lasttail->next->next = head->next;
					head->next = lasttail->next;
					if(seclasttail->next)seclasttail->next->next = head;
					if(id==2)tail->next = head;
					head = lasttail->next->next;

				}
				else
				{

					seclasttail->next = lasttail->next;
					lasttail->next = head;
					head = head->next;
				}
			
			}
			return ans.next;
		}

		void test_swap()
		{
			string line;
			while (getline(cin, line)) {
				ListNode* l1 = stringToListNode(line);

				ListNode* ret = swapPairs(l1);

				string out = listNodeToString(ret);
				cout << out << endl;
			}
		}


	};

}