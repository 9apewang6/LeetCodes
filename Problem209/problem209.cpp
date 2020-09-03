/**
给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组，并返回其长度。如果不存在符合条件的连续子数组，返回 0。

输入: s = 7, nums = [2,3,1,2,4,3]
输出: 2
解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。

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

class SolutionGetMinArray {
public:
	int minSubArrayLen(int s, vector<int>& nums) {

		return 0;
	}
};
void main()
{
	SolutionGetMinArray sol;
	int target = 0;
	int result = 0;
	vector<int> srcVec{0,1,2,-1,3,4};
	cout << " the source vector is :" << endl;
	for (auto iter : srcVec)
	{
		cout << iter << endl;
	}
	cout << " please input a number 0-9 :" << endl;
	cin >> target;
	if (!cin)
	{
	result = sol.minSubArrayLen(target, srcVec);
	}
	cout << " the result value is : \n";
	cout << result << endl;
	system("pause");
	return; 
}