#pragma once
#include "public_def.h"
namespace offer03
{
	class soffer03 {
	public:
		int find2(vector<int>& nums)
		{
			while (true) {
				int candidate = nums[rand() % nums.size()];
				int count = 0;
				for (int num : nums)
					if (num == candidate)
						++count;
				if (count>=2)
					return candidate;
			}
			return 0;
		}
		int findRepeatNumber(vector<int>& nums) {
// 			map<int, int> counts;
// 			for (int iter : nums)
// 			{
// 				++counts[iter];
// 				if (counts[iter] >= 2)
// 				{
// 					return iter;
// 				}
// 			}
// 			return 0;
			
			sort(nums.begin(), nums.end());
// 			int left = 0;
// 			int right = 1;
// 			int n = nums.size();
// 			while (left <= right&&right < n)
// 			{
// 				if (nums[left] != nums[right])
// 				{
// 					left++;
// 					right++;
// 					continue;
// 				}
// 				if (nums[left] == nums[right])
// 					return nums[left];
// 			}
// 			return 0;
			for (int i = 0; i < nums.size() - 1; i++)
			{
				if (nums[i] == nums[i + 1])return nums[i];
			}
			return 0;
		}
		void testfind()
		{
			string input_string;
			vector<int> testvec;
			while (getline(cin, input_string))
			{
				trimLeftTrailingSpaces(input_string);
				trimRightTrailingSpaces(input_string);
				testvec = stringToIntegerVector(input_string);
				cout<<findRepeatNumber(testvec)<<endl;
				
			}
		}
	};
}