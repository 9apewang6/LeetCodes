// �绰�����������
// 1 - NULL
// 2-  abc
// 3 - def
//4 - ghi
//5 - jkl
//6- mno
//7 - pqrs
// 8 -tuv
//9 wxyz
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	struct  node{
		char matchchar;
		node* next;
	};
private:
	string lettermap[10] = {
		"",
		"",
		"abc",
		"def",
		"ghi",
		"jkl",
		"mno",
		"pqrs",
		"tuv",
		"wxyz"
	};
	vector<string> res;
public:

	void dfs(int id,string digits,string s)
	{
		if (id == digits.size())
		{
			res.push_back(s);
			return;
		}
		string letters = lettermap[digits.at(id) - '0'];
		if (letters.size() > 0)
		{
			for (int i = 0; i < letters.size(); i++)
				dfs(id + 1, digits, s + letters.at(i));
		}
		else
		{
			dfs(id + 1, digits, s);

		}

	}
	vector<string> letterCombinations(string digits) {
		
		if (digits.size() == 0)return res;
		dfs(0,digits,"");
		
		for (auto iter : res)
		{
			cout << iter << endl;
		}
		return res;
	}
};
// ���ֵ���ĸӳ��
// ���label  �ַ��� ������ 
//	��̬�滮�� ״̬ת�Ʒ���
// ����  ��ѡ���� 
//���� Ӧ����Ҫ�õ������
// ������� 
// ��
// �ݹ�
//* �Զ��� 
//* (�� Q �� q,F) DFA

int main(int mgr, char* mrv[])
{
	vector<string> answer;
	string input_string;
	char key;
	Solution S;
	while (cin >> key&&key != 'q')
	{
		cin.clear();
		getchar();
		
		cout << "please input the number" << endl;
		cin >> input_string;
		S.letterCombinations(input_string);
	}
	system("pause");
	return 0;
}