
/*给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
约定:
3 <= nums.length <= 10^3
-10^3 <= nums[i] <= 10^3
-10^4 <= target <= 10^4
提示:
数组， 双指针


找 |∑(Am+An+Ak) - T| 最小值,先排序

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define WAY1 0
#define WAY2 1
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::max;
using std::min;
using std::vector;

class Solution {
public:

	int threeSumClosest(vector<int>& nums, int target) {
// 		if ((nums.size() > 1000) || (abs(target) > 10000) || (nums.size() < 3))
// 		{
// 			return NULL;
// 		}
// 		unsigned int first = 0;
// 		unsigned int second = 1;
// 		unsigned int third = 2;
// 
// 		int MINVALUE = INT_MAX;
// 		int temp = 0;
// 		for (int i = 0; i < nums.size() - 2; i++)
// 		{
// 			for (int j = i + 1; j < nums.size() - 1; j++)
// 			{
// 
// 				for (int k = j + 1; k < nums.size(); k++)
// 				{
// 					temp = nums.at(i) + nums.at(j) + nums.at(k);
// 					if (MINVALUE >= abs(temp - target))
// 					{
// 						first = i;
// 						second = j;
// 						third = k;
// 						MINVALUE = abs(temp - target);
// 					}
// 					if (MINVALUE == 0)
// 					{
// 						return temp;
// 					}
// 
// 				}
// 			}
// 
// 		}
// 		return (nums.at(first) + nums.at(second) + nums.at(third));
#if WAY1
		if ((nums.size() > 1000) || (abs(target) > 10000) || (nums.size() < 3))
		{
			return NULL;
		}
		unsigned int first = 0;
		unsigned int second = 1;
		unsigned int third = 2;
		
		int MINVALUE = INT_MAX;
		int temp = 0;
		for (int i = 0; i < nums.size()-2; i++)
		{
			for (int j = i + 1; j < nums.size() - 1; j++)
			{

				for (int k = j + 1; k < nums.size(); k++)
				{
					temp = nums.at(i) + nums.at(j) + nums.at(k);
					if (MINVALUE >= abs(temp - target))
					{
						first = i;
						second = j;
						third = k;
						MINVALUE = abs(temp-target);
					}
					if (MINVALUE == 0)
					{
						return temp;
					}

				}
			}

		}
		return (nums.at(first) + nums.at(second) + nums.at(third));
#endif

#if WAY2 
		if ((nums.size() > 1000) || (abs(target) > 10000) || (nums.size() < 3))
		{
			return NULL;
		}
		sort(nums.begin(),nums.end());
		int n = nums.size();
		unsigned int first = 0;
		unsigned int second = 1;
		unsigned int third = n-1;

		int MINVALUE = INT_MAX;
		int res;
		int temp = 0;
		int temptarget = target;
		for ( first = 0; first < nums.size() - 2; first++)
		{
			temptarget = target - nums[first];
			third = n - 1;
			for (second  = first + 1; second < nums.size() - 1; second++)
			{
				while (second<third&&nums[second] + nums[third]>temptarget)
					third--;
				if (second < third)
				{
					temp = nums[first] + nums[second] + nums[third] - target;
					if (MINVALUE >= abs(temp))
					{
						MINVALUE = abs(temp);
						res = temp + target;
					}
				}
				if (third + 1 < n) {
					third++;
					temp = nums[first] + nums[second] + nums[third] - target;
					if (MINVALUE >= abs(temp))
					{
						MINVALUE = abs(temp);
						res = temp + target;
					}
					third--;
				}
			
				if (second == third)break;
				
				if (nums[second] + nums[third] == temptarget)return target;
				
			}

		}
		return res;
#endif
	};
};
void main()
{
	vector<int > srcVec{-1,2,1,4};
	int targetNum = 1;
	Solution sol;
	cout<<sol.threeSumClosest(srcVec, targetNum)<<endl;
	system("pause");
	return;
}