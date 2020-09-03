#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using std::distance;
using std::cout;
using std::endl;
using std::cin;
using std::vector;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result;

		if (nums.size() <= 1)
		{
			result.push_back(0);
			return result;
		}

		auto iter = nums.begin();
		for (; iter != nums.end(); iter++)
		{
			auto iterSecond = std::find((iter + 1), nums.end(), (target - *iter));
			if (iterSecond != nums.end())
			{
				//	std::distance(nums.begin(), iterSecond);
				result.push_back(std::distance(nums.begin(), iter));
				result.push_back(std::distance(nums.begin(), iterSecond));

				break;
			}
			//	cout << iter << endl;
		}
		return result;

	}
};
