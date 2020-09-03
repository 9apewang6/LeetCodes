/*
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
*/



/*
双指针，哈希表 ， sliding window 


*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <math.h>
using std::endl;
using std::cout;
using std::cin;
using std::string;
using std::unordered_map;
using std::make_pair;

class SolutionLengthOfLongestSubString {
public:
	int lengthOfLongestSubstring(string s) 
	{
		if (s.size() <= 1)
		{
			return s.size();
		}
		int left = 0;
		int right =0;
		int res = 0;
		std::unordered_map<char,int> valuePair;
		//左右指针，窗口大小不固定， 快慢指针。
		while (left <= right&&right<=(s.length()-1))
		{
			if (!valuePair.count(s[right]))
			{
				valuePair.insert(make_pair(s[right],right));
				res = std::max(res,right-left+1);   //找最大窗口
				right++;
			}
			else
			{
				valuePair.erase(s[left]);
				left++;
			}
		}
		return res;


// 		Set<Character> set = new HashSet<>();
// 		int ans = 0, i = 0, j = 0;//i为滑动窗口的左边，j为右边
// 		while (i < s.length() && j < s.length()) {
// 			if (!set.contains(s.charAt(j))) {//如果没有重复
// 				set.add(s.charAt(j++));
// 				ans = Math.max(ans, j - i);
// 			}
// 			else {//如果出现重复
// 				set.remove(s.charAt(i++));
// 			}
// 		}
// 		return ans;

	







	}
};

void main()
{
	string inputStr;
	SolutionLengthOfLongestSubString Sol;
	while (getline(cin, inputStr))
	{
		if (inputStr.size() > 0)
		{
			cout << Sol.lengthOfLongestSubstring(inputStr) << endl;
		}
	}	
	system("pause");
	return;
}