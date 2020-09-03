#pragma once
#include "public_def.h"
/************************************************************************/
/* 

给定一个字符串 s，计算具有相同数量0和1的非空(连续)子字符串的数量，并且这些子字符串中的所有0和所有1都是组合在一起的。

重复出现的子串要计算它们出现的次数。
input : 10101
output: 4   10 ,01 , 10,01
input: 00110011
output : 6
有6个子串具有相同数量的连续1和0：“0011”，“01”，“1100”，“10”，“0011” 和 “01”。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-binary-substrings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
// 			int m_collect = 0;
// 			judge(s[leftindex], m_collect);
// 			while (leftindex <= rightindex&&leftindex<n)
// 			{
// 				if (rightindex<n)	judge(s[rightindex], m_collect);
// 				if (m_collect == 0)
// 				{
// 					leftindex++;
// 					rightindex = leftindex + 1;
// 					ans++;
// 					if (leftindex<n)	judge(s[leftindex], m_collect);
// 					continue;
// 				}
// 				rightindex++;
// 				if (rightindex == n)
// 				{
// 					leftindex++;
// 					rightindex = leftindex+1;
// 					m_collect = 0;
// 				if(leftindex<n)	judge(s[leftindex], m_collect);
// 				}
// 			}
// 			return ans;

O(n^2)
0110011
int bottom=1;
int m_col =0;
int ans;
while(bottom<n)
{
	if(s[bottom]!=s[bottom-1])ans++;
}
*/
/************************************************************************/
namespace p696
{
	class Solution_p696 {
	public:
		void judge(const char &c, int & inde)
		{
			if (c == '0')inde--;
			else if (c == '1') inde++;
		}
		int countbinarysubstrings(string s) {
			int n = s.length();
			if (n < 2)return 0;
			int ans = 0;
			int m_collect = 1;
			int explorer = 0;
			int matched = 0;
			while (explorer <= n-1)
			{
				explorer++;
				if (s[explorer - m_collect] == s[explorer])
				{
					m_collect++;
					continue;
				}
				if (s[explorer -  m_collect] != s[explorer])
				{
					ans++;
					matched++;
					if (matched == m_collect)
					{
						m_collect = matched;
						matched = 0;
					}
					else if (matched < m_collect && (explorer + 1 < n&&s[explorer] != s[explorer + 1]))
					{
						m_collect = matched;
						matched = 0;
					}
					continue;
				}
				
				
			}
			return ans;
		}
		int countBinarySubstrings(string s) {
			int n = s.size();
			if (n < 2)return 0;
// 			int leftindex = 0;
// 			int rightindex = 1;
// 			int ans = 0;
// 			unordered_map<char, int> m_collector;
// 			m_collector[s[leftindex]]++;
// 			while (leftindex <= rightindex&&rightindex < n)
// 			{
// 				m_collector[s[rightindex]]++;
// 				if (m_collector['0'] == m_collector['1'])
// 				{
// 					leftindex++;
// 					rightindex = leftindex + 1;
// 					ans++;
// 					m_collector.clear();
// 					m_collector[s[leftindex]]++;
// 					continue;
// 				}
// 				if (rightindex + abs(m_collector['0'] - m_collector['1']) >= n)
// 				{
// 					leftindex++;
// 					rightindex = leftindex + 1;
// 					m_collector.clear();
// 					m_collector[s[leftindex]]++;
// 					continue;
// 				}
// 				rightindex++;
// 			}
// 			return ans;
			
			int ans=0;
			int interval = 0;
			int left = 0;
			int right = 0;
			while (left <= right&&right < n)
			{
				if (s[left] != s[right])
				{
					interval--;
					right++;
					if (interval == 0) {
						ans++;
						left++;
						
						right = left;
						continue;
					}
					if (right  < n)
					{
						if (interval > 0 && s[left] == s[right])
						{
							left++;
							right = left;
							interval = 0;
							continue;
						}
					}
					else if (right == n)
					{
						if (interval > 0)
						{
							left++;
							right = left;
							interval = 0;
							continue;
						}
					}
					continue;
				}
				if (s[right] == s[left])
				{
					interval++;
					right++;
					continue;
				}
			}
			return ans;
		}
		void test696()
		{
			string input_String;
			while (getline(cin, input_String))
			{
				cout << countbinarysubstrings(input_String) << endl;

			}
		}
	};
}