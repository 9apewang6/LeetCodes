#pragma once
#include "public_def.h"
namespace solution_magicguide
{

	class Solution_Magicguide {
	public:
		int findMagicIndex(vector<int>& nums) {
			
			int n = nums.size();
			for (int j = 0; j < n; j++)
			{
				if (j == nums[j])return j;		
			}

			return -1;
		}

// 		int getAnswer(vector<int>& nums, int left, int right) {
// 			if (left > right) {
// 				return -1;
// 			}
// 			int mid = (right - left) / 2 + left;
// 			int leftAnswer = getAnswer(nums, left, mid - 1);
// 			if (leftAnswer != -1) {
// 				return leftAnswer;
// 			}
// 			else if (nums[mid] == mid) {
// 				return mid;
// 			}
// 			return getAnswer(nums, mid + 1, right);
// 		}

		int getAnswer(vector<int>& nums, int left, int right)
		{
			if (left > right)
			{
				return -1;
			}
			int mid = (right-left) / 2+left;
			int leftanswer = getAnswer(nums, left, mid - 1);
			if (leftanswer != -1)return leftanswer;
			else if (mid == nums[mid])return mid;
			return getAnswer(nums, mid + 1, right)
				;
		}
// 		int findMagicIndex(vector<int>& nums) {
// 			return getAnswer(nums, 0, (int)nums.size() - 1);
// 		}

		void testmagic()
		{
			vector<int> testvec{0,2,3,4,5};
			int key=0;
			
			while ((cout << "please input a integer to continue :  -1 to quit"<<endl) && cin >> key)
			{
				if (key == -1) break;
				cout << "the answer is :"<<findMagicIndex(testvec) << endl;
			}

		}
	};

}