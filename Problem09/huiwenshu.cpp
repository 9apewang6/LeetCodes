// huiwenshu.cpp -- �ж�һ�������Ƿ��ǻ���������������ָ���򣨴������ң��͵��򣨴������󣩶�����һ����������
// ��������ת��Ϊ�ַ���������������
// �����ݴ浽
#include <iostream>
using namespace std;
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) return false;
		else if (x == 0)return true;
		else if (x > 0)
		{
			int remainder = 0;//ȡÿһλ����
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