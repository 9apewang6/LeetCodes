#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;
class Solution
{
public:

	int myAtoi(string str) {
		// [-2^31,2^31-1]
		if (str.size() == 0)return 0;
		int *ans = new int[str.size()]{ 0 };

		int size = 0;

		int x_symbol = 1;
		for (auto iter = str.cbegin(); iter != str.cend(); iter++)
		{
			if (*iter == ' '&&size == 0)continue;
			if (*iter >= '0' && *iter <= '9')
			{
				ans[size] = *iter - '0';
				size = size + 1;
			}
			else if ((*iter >= 'a'&&*iter <= 'z') || (*iter >= 'A'&&*iter <= 'Z'))
			{
				break;
			}
			else if (*iter == '-'&&size==0 && (*(iter + 1) >= '0'&&*(iter + 1) <= '9'))
			{
				x_symbol = -1;
			}
			else if (*iter == '+'&&size==0 && (*(iter + 1) >= '0'&&*(iter + 1) <= '9'))
			{
				x_symbol = 1;
			}
			else
			{
				break;
			}

		}
		if (size == 0) return 0;
		else if (size > 0)
		{
			long long val = 0;
			for (auto i = 0; i < size&& fabs(val) <= INT_MAX; i++)
			{
				if (ans[i] > 0 && (size - i - 1) >= log10(INT_MAX))
				{
					val = INT_MAX;
					if (x_symbol > 0)
					{
						return INT_MAX;
					}
					else
					{
						return INT_MIN;
					}
					break;
				}
				val += ans[i] * pow(10, (size - i - 1));
			}
			val = x_symbol*val;
			if (val > INT_MAX)val = INT_MAX;
			if (val < INT_MIN)val = INT_MIN;
			return val;
		}
		return 0;
	}

};

int main(int args, char* argv[])
{
	
	string input_string;
	Solution s;
	cout << "INT MAX is :" << INT_MAX << endl;
	cout << " log10 INT_MAX is :" << log10(INT_MAX) << endl;
	while (cin >> input_string)
	{
		cin.clear();
		if (input_string.size() > 0)
		{
			cout<<s.myAtoi(input_string)<<endl;
		}
	}
	system("pause");
	return 0;
}