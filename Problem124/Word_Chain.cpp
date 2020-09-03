/************************************************************************/
/* 
给定两个单词（beginWord 和 endWord）和一个字典 wordList，找出所有从 beginWord 到 endWord 的最短转换序列。转换需遵循如下规则：

每次转换只能改变一个字母。
转换后得到的单词必须是字典中的单词。
说明:

如果不存在这样的转换序列，返回一个空列表。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。



*/
/************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::max;
using std::min;
using std::vector;
class Solution {
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		vector<vector<string>> vec;
		auto iter = find(wordList.begin(),wordList.end(),endWord);
		if (iter != wordList.end())
		{

			return vec;
		}
		else
		{
			vec.resize(0);
			return vec;
		}
		
	}
};
int main()
{
	string beginWord = "";
	string endWord = "";
	vector<string> wordlist;
	Solution sol; 
	sol.findLadders(beginWord,endWord,wordlist);

}