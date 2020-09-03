#pragma once
#include "public_def.h"
namespace p283
{
	class solution283
	{
	public:
		// 将0 全部移动到末尾
		// 保持相对顺序
		void moveZeroes(vector<int>& nums)
		{
			int n = nums.size();
			if (n <= 1) return;
			int left = 0;
			int right = 0;
			while (left <= right&&right < n)
			{
				if (nums[right] == 0)
				{
					right++;
					continue;
				}
				else if (nums[right] != 0)
				{
					nums[left] = nums[right];
					left++;
					right++;
				}
			}
			for (int j = left; j < n; j++)
			{
				nums[j] = 0;
			}
		}
		void testmoveZeros()
		{
			string input_string;
			vector<int> testvec;
			while (getline(cin, input_string))
			{
				trimLeftTrailingSpaces(input_string);
				trimRightTrailingSpaces(input_string);
				testvec = stringToIntegerVector(input_string);
				moveZeroes(testvec);
				input_string = vectorTostring(testvec);
				cout << input_string << endl;
			}
		}

	};
}