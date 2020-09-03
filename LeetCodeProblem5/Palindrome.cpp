/*

LeetCode  第五题
最长回文字符串
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例1:
输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例2:
输入: "cbbd"
输出: "bb"
substr会重新创建string ,重复内存申请释放操作
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#define WAY1 0
#define WAY2 0
#define WAY3 0
#define WAY4 1
#define WAY5 0
#define WAY6 0
#define WAY7 0
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::pair;
using std::min;
/*
处理思想  :
方法一:一步步缩小判断区域
对短子串判断， 耗时间长
if (s.length() <= 1)
{
return s;
}
int left = 0;
int _StrLength = s.length();
int right = _StrLength;
string temp;
while (right >= 0)
{
for (int i = 0; i <= (_StrLength - right); i++)
{
//temp = s.substr(i, right);
if (CheckPalindrome(s, i, (right + i)))

return s.substr(i, right);
}
right--;
}

return s.substr(0, 1);

*/
/************************************************************************/
/* 
way1:
if (s == "")return "";
int len = s.length();
int index = 0, maxL = 0, begin = 0;
while (index < len) {
	int right = index, left = index;
	while (index < len&&s[index + 1] == s[index]) {
		index++;
		right++;
	}
	while (right < len&&left >= 0 && s[right] == s[left]) {
		right++;
		left--;
	}
	right--, left++;
	if (right - left + 1 > maxL) {
		maxL = right - left + 1;
		begin = left;
	}
	index++;
}
return s.substr(begin, maxL);
*/
/************************************************************************/

/************************************************************************/
/* 
bool CheckPalindrome(string s, int left, int right)
{
int _strLength = right - left;
if (_strLength <= 1)
{
return false;
}

for (int i = left; i <= (floor)((left+right) / 2); i++)
{
if (s[i] != s[right - i-1  + left])
{
return false;
}
}
return true;
}
string longestPalindrome(string s) {

if (s.length() <= 1)
{
return s;
}

int _StrLength = s.length();
int right = _StrLength;
int begin = 0;
int end = 1;
string temp;
bool isPalindrome = true;
while (right >= 1)
{


for (int i = 0; i <= (_StrLength - right); i++)
{

for (int j = i; j <= (floor)((i*2 + right) / 2); j++)
{

if (s[j] != s[right+2*i - 1-j])
{
isPalindrome = false;
break;
}
}
if (isPalindrome)
{
begin = i; end = right;
return s.substr(begin, end);

}
isPalindrome = true;
}
right--;
}

return s.substr(0,	1);

*/
/************************************************************************/

class SolutionPalindrome {
public:
	bool CheckPalindrome(string s, int left, int right)
	{
		int _strLength = right - left;
		if (_strLength <= 1)
		{
			return false;
		}
	
		for (int i = left; i <= (floor)((left+right) / 2); i++)
		{
			if (s[i] != s[right - i-1  + left])
			{
				return false;
			}
		}
		return true;
	}
	pair<int, int> expandAroundCenter(const string& s, int left, int right) {
		while (left >= 0 && right < s.size() && s[left] == s[right]) {
			--left;
			++right;
		}
		return{ left + 1, right - 1 };
	}


	int expand(const string& s, int left, int right) {
		while (left >= 0 && right < s.size() && s[left] == s[right]) {
			--left;
			++right;
		}
		return (right - left - 2) / 2;
	}

	

	string longestPalindrome(string s) {
#if WAY1
		if (s.length() <= 1)
		{
			return s;
		}
	
		int _StrLength = s.length();
		int right = _StrLength;
		int begin = 0;
		int end = 1;
		string temp;
		bool isPalindrome = true;
		while (right >= 1)
		{
		

			for (int i = 0; i <= (_StrLength - right); i++)
			{
		
				for (int j = i; j <= (floor)((i*2 + right) / 2); j++)
				{
			
					if (s[j] != s[right+2*i - 1-j])
					{
						isPalindrome = false;
						 break;
					}
				}
				if (isPalindrome)
				{
					begin = i; end = right;
					return s.substr(begin, end);

				}
				isPalindrome = true;
			}
			right--;
		}

		return s.substr(0,	1);
#endif 

#if WAY2
		if (s == "")return "";
		int len = s.length();
		int index = 0, maxL = 0, begin = 0;
		while (index < len) {
			int right = index, left = index;
			while (index < len&&s[index + 1] == s[index]) {
				index++;
				right++;
			}
			while (right < len&&left >= 0 && s[right] == s[left]) {
				right++;
				left--;
			}
			right--, left++;
			if (right - left + 1 > maxL) {
				maxL = right - left + 1;
				begin = left;
			}
			index++;
		}
		return s.substr(begin, maxL);

#endif
#if WAY3
		int n = s.size();
		vector<vector<int>> dp(n, vector<int>(n));
		string ans;
		for (int l = 0; l < n; ++l) {
			for (int i = 0; i + l < n; ++i) {
				int j = i + l;
				if (l == 0) {
					dp[i][j] = 1;
				}
				else if (l == 1) {
					dp[i][j] = (s[i] == s[j]);
				}
				else {
					dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
				}
				if (dp[i][j] && l + 1 > ans.size()) {
					ans = s.substr(i, l + 1);
				}
			}
		}
		return ans;


#endif
#if WAY4
		int start = 0, end = -1;
		string t = "#";
		for (char c : s) {
			t += c;
			t += '#';
		}
		t += '#';
		s = t;

		vector<int> arm_len;
		int right = -1, j = -1;
		for (int i = 0; i < s.size(); ++i) {
			int cur_arm_len;
			if (right >= i) {
				int i_sym = j * 2 - i;
				int min_arm_len = min(arm_len[i_sym], right - i);
				cur_arm_len = expand(s, i - min_arm_len, i + min_arm_len);
			}
			else {
				cur_arm_len = expand(s, i, i);
			}
			arm_len.push_back(cur_arm_len);
			if (i + cur_arm_len > right) {
				j = i;
				right = i + cur_arm_len;
			}
			if (cur_arm_len * 2 + 1 > end - start) {
				start = i - cur_arm_len;
				end = i + cur_arm_len;
			}
		}

		string ans;
		for (int i = start; i <= end; ++i) {
			if (s[i] != '#') {
				ans += s[i];
			}
		}
		return ans;

#endif
	}
};
void main()
{
	string _inputString;
	//	cout << "Please input a num :\t\b";
	// 	int _inputNum;
	// 	cin >> _inputNum;
	string _inputStr[100];
	SolutionPalindrome _DealPalind;
	while (getline(cin, _inputString) && _inputString.length() > 0)
	{
		cout << _DealPalind.longestPalindrome(_inputString) << endl;

	}
	system("pause");
}