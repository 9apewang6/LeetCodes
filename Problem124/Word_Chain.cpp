/************************************************************************/
/* 
�����������ʣ�beginWord �� endWord����һ���ֵ� wordList���ҳ����д� beginWord �� endWord �����ת�����С�ת������ѭ���¹���

ÿ��ת��ֻ�ܸı�һ����ĸ��
ת����õ��ĵ��ʱ������ֵ��еĵ��ʡ�
˵��:

���������������ת�����У�����һ�����б�
���е��ʾ�����ͬ�ĳ��ȡ�
���е���ֻ��Сд��ĸ��ɡ�
�ֵ��в������ظ��ĵ��ʡ�
����Լ��� beginWord �� endWord �Ƿǿյģ��Ҷ��߲���ͬ��



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