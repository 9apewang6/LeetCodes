//��Ч����
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <assert.h>
// '(' , ') ', '{' , '}' , '['  , ']'
// ջ �ַ���
// ջ ����ȳ� LIFO ���Ƚ������  �����ҽ���ƥ��
using namespace std;
class Solution {
public:
	bool isValid(string s) {
		int n = s.size();
		if (n % 2 != 0)return false;
		stack<char> _stack;
		char _top;
		//map<char, int> key{ {'(',0} ,{')',0},{'[',0},{']',0},{'{',0},{'}',0} };
		
		for (int i = 0; i < n; i++)
		{
			_top = '?';
			switch (s[i])
			{
			case '(':
				_stack.push('(');
				break;
			case ')':
				if (!_stack.empty())	_top = _stack.top();
				if (_top != '(')return false;
				_stack.pop();

				break;
			case '[':
				_stack.push('[');


				break;
			case ']':
				if (!_stack.empty())	_top = _stack.top();
				if (_top != '[')return false;
				_stack.pop();

				break;
			case '{':
				_stack.push('{');

				break;
			case '}':
				if (!_stack.empty())	_top = _stack.top();
				if (_top != '{')return false;
				_stack.pop();
				break;
			default:
				break;
			}
		}
		if (_stack.empty())return true;
		return false;

	}
};

string stringToString(string input) {
	assert(input.length() >= 2);
	string result;
	for (int i = 1; i < input.length() - 1; i++) {
		char currentChar = input[i];
		if (input[i] == '\\') {
			char nextChar = input[i + 1];
			switch (nextChar) {
			case '\"': result.push_back('\"'); break;
			case '/': result.push_back('/'); break;
			case '\\': result.push_back('\\'); break;
			case 'b': result.push_back('\b'); break;
			case 'f': result.push_back('\f'); break;
			case 'r': result.push_back('\r'); break;
			case 'n': result.push_back('\n'); break;
			case 't': result.push_back('\t'); break;
			default: break;
			}
			i++;
		}
		else {
			result.push_back(currentChar);
		}
	}
	return result;
}

string boolToString(bool input) {
	return input ? "True" : "False";
}

int main() {
	string line;
	while (getline(cin, line)) {
// 		string s = stringToString(line);

		bool ret = Solution().isValid(line);

		string out = boolToString(ret);
		cout << out << endl;
	}
	return 0;
}