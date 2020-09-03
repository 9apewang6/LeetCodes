//四数之和
// 转化为 三数之和 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
private:
	vector<vector<int>> res;
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		if (nums.size() < 4)return res;
		sort(nums.begin(),nums.end());
		int prefix_first = 0;
		int prefix_second = 1;
		int n = nums.size();
		int suffix_second = n - 1;
		int temp_target = 0;
		for (prefix_first = 0; prefix_first < n - 3; prefix_first++)
		{
			if(prefix_first>=1&&nums[prefix_first-1]==nums[prefix_first]) continue;
			for (prefix_second = prefix_first+1; prefix_second < n - 2; prefix_second++)
			{
				if (prefix_second > (prefix_first + 1) && nums[prefix_second] == nums[prefix_second - 1])continue;
				temp_target = target - nums[prefix_second] - nums[prefix_first];
	
				suffix_second = n - 1;
				for (int i = prefix_second + 1; i < n - 1; i++)
				{
					if (i > (prefix_second + 1) && nums[i] == nums[i - 1])continue;
					while (i<suffix_second&&nums[i] + nums[suffix_second]>temp_target)
						suffix_second--;
					if (i == suffix_second)
						break;
					if (nums[i] + nums[suffix_second] == temp_target)
					{
						res.push_back({ nums[prefix_first],nums[prefix_second],nums[i],nums[suffix_second] });	
					}
				}
			}
		}

		return res;



	}
};
int main(int mgr, char* mgv[])
{
	Solution s;
	vector<int> nums{ 5,0,2,-5,-5,4,-5,1,-1
		
		
		
};
	vector<vector<int>> res1;
	res1=s.fourSum(nums, -5);
	for (auto iter : res1)
	{
		for (auto iter2 : iter)
		{
			cout << " " << iter2;
		}
		cout << endl;
	}
	system("pause");
	return 0;
}