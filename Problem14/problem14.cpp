//编写一个函数来查找字符串数组中的最长公共前缀
// 如果不存在则返回"";
#include <iostream>
#include <string>

#include <vector>
using namespace std;
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0)return "";
		if (strs.size() == 1)return strs.at(0);
		int first_size = strs.at(0).size();
		int match_size = 0;
		for (int i = 0; i < first_size; i++)
		{
			for (int j = 0; j < strs.size(); j++)
			{
				if ((i<strs.at(j).size())&&(strs.at(0).at(i) != strs.at(j).at(i)) )
				{
					return strs.at(0).substr(0,match_size);
				}
				else if((i>=strs.at(j).size()) )
				{
					return strs.at(j);
				}
			}
			match_size++;
		}
		return strs.at(0);
	}
};
int main(int mgr, char* mgrv[])
{
	vector<string> testvec;
	Solution s;
	char a;
// 	while (cin >> a&& a != 'a')
// 	{
// 		getchar();
// 		
// 
// 	}
	testvec.push_back("flack");
	testvec.push_back("fleee");
	cout << s.longestCommonPrefix(testvec) << endl;
	system("pause");
	return 0;
}