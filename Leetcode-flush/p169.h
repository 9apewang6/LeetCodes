#pragma once
#include "public_def.h"

namespace p169
{
	class solution169
	{
		
		public:
			//位运算 ，分
			// 哈希表法O(n)
			int majorityElement_0(vector<int>& nums)
			{
				unordered_map<int, int> counts;
				int majority = 0, cnt = 0;
				for (int num : nums) {
					++counts[num];
					if (counts[num] > cnt) {
						majority = num;
						cnt = counts[num];
					}
				}
				return majority;

			}
			//随机数
			int majorityElement_1(vector<int>& nums)
			{
				while (true) {
					int candidate = nums[rand() % nums.size()];
					int count = 0;
					for (int num : nums)
						if (num == candidate)
							++count;
					if (count > nums.size() / 2)
						return candidate;
				}
				return -1;
			}
			//排序O(nlogn)
			int majorityElement(vector<int>& nums) {
				sort(nums.begin(), nums.end());
				return nums[nums.size() / 2];
				
				int left = 0;
				int right = 0;
				int n = nums.size();
				while (left <= right&&right < n)
				{
					if (nums[left] == nums[right])
					{
						right++;
						if ((right - left) > n / 2)return nums[left];
					}
					else if (nums[left] != nums[right])
					{
						left = right;
						continue;
					}
				}
				return nums[left];
			//	find(nums.begin(),nums.end(),1);
				

			}
			void testmajority()
			{
				string input_str;
				vector<int> testvec;
				while (getline(cin, input_str))
				{
					trimLeftTrailingSpaces(input_str);
					trimRightTrailingSpaces(input_str);
					testvec = stringToIntegerVector(input_str);
					cout << majorityElement(testvec)<<endl;
				}
			}
	};
}