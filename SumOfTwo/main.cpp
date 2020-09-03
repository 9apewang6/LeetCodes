/*
题目描述:
LeetCode  1.两数之和
*/

#include "LeetCodeExercise1.h"
#include "LeetCodeExercise2.h"
#define LEETCODEXERCISE2
int main()
{
#ifdef  LEETCODEXERCISE1
	vector<int> _TestArray{3,2,4};

	
	Solution _FindTarget;
	 int _valueTarget=0;
	cin >> _valueTarget;
	vector<int> _DestArray;
	_DestArray = _FindTarget.twoSum(_TestArray, _valueTarget);
	if (_DestArray.size() > 0)
	{
		for (auto iter : _DestArray)
		{
			cout << iter << endl;
		}
	}
	else
	{
		cout << "No matching value" << endl;
	}
#endif

#ifdef LEETCODEXERCISE2
	ListNode* _TestList = new ListNode(1);
//	ListNode* _TestList1value2 = new ListNode(8);
	//ListNode* _TestList1value3 = new ListNode(4);
	//_TestList->next = _TestList1value2;
	//_TestList1value2->next = _TestList1value3;


	ListNode* _TestList2 = new ListNode(9);
	ListNode* _TestList2value2 = new ListNode(9);
	//ListNode* _TestList2value3 = new ListNode(3);
	_TestList2->next = _TestList2value2;
//	_TestList2value2->next = _TestList2value3;
	
	ListNode* _TestList3 = nullptr;
	SolutionAddSumNumbers SolutionAdd;
	_TestList3 = SolutionAdd.addTwoNumbers(_TestList, _TestList2);

#endif

	system("pause");
	return 0;
}