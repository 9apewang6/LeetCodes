// huiwenshu.cpp -- 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
// 不将整数转换为字符串来解决这个问题
// 将数据存到
#include <iostream>
using namespace std;
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) return false;
		else if (x == 0)return true;
		else if (x > 0)
		{
			int remainder = 0;//取每一位数字
			int* nums = new int[1 + log10(x)]{0};
			int index = 0;
			do 
			{
				remainder = x % 10;
				nums[index] = remainder;
				index++;
				x = x / 10;
			} while (x);
			for (int i = 0; i < index; i++)
			{
				if (nums[i] != nums[index - i - 1])
				{
					return false;
				}
			}
			
		}
		return true;
	}
};
int main(int argc, char* argv[])
{
	int input_value;
	Solution s;
	cout << "please input a integer:" << endl;
	while (cin >> input_value)
	{
		
		if (s.isPalindrome(input_value))
		{
			cout << "true" << endl;
		}
		else
		{
			cout << "false" << endl;
		}

	}
	system("pause");
	return 0;
}