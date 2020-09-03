// 罗马转数字
// I	1
// V	5
// X	10
// L	50
// C	100
// D	500
// M	1000
// 给定一个整数 ，限定输入1-3999 转换为 罗马数字
//  左边为减，右边为加  
//  特殊规则  I 可以 在 V或X 左右;  X可以在 L 或 C 左右 ，C可以在 D或M 左右
// label  数学， 字符串
// 整数转换罗马数 ， 首先确定数字范围 ； 也许可以尝试递归。
//  1,4,5,6,9,10,11,15,20，
//  累加
//900,400,90,40,9,4,
//  'M', 'CM','D','CD','C','XC','L','XL','X','IX',,'V','IV','I'

#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <vector>
#include <numeric>
using namespace std;
//"MCMXCIV"
class Solution
{
public:
	int romanToInt(string s) {
		if (s.size() == 0)return 0;
		unsigned int a[13]{ 0 };
		int ans = 0;
//  'M', 'CM','D','CD','C','XC','L','XL','IX','X','V','IV','I'
		char lastchar=s.at(0);
		for (auto iter : s)
		{
			switch (iter)
			{
			case 'M':
				a[0]++;  
				if (lastchar == 'C') { a[1]++; a[0]--; a[4]--; }
				lastchar = iter;
				break;
			case 'D':
				a[2]++;  
				if (lastchar == 'C') { a[3]++; a[2]--; a[4]--; }
				lastchar = iter;
				break;
			case 'C':			
				a[4]++; 
				if (lastchar == 'X') { a[5]++; a[4]--; a[8]--; }
				lastchar = iter;
				break;
			case 'L':
				 a[6]++;  
				 if (lastchar == 'X') { a[7]++; a[6]--; a[8]--; }
				lastchar = iter;
				break;
			case 'X':
				 a[8]++;  
				 if (lastchar == 'I') { a[9]++; a[12]--; a[8]--; }
				lastchar = iter;
				break;
			case 'V':
				 a[10]++;  
				 if (lastchar == 'I') { a[11]++;  a[10]--; a[12]--; }
				lastchar = iter;
				break;
			case 'I':
				a[12]++;
				lastchar = iter;
				break;

			default:
				break;

			}
		}
		ans = a[0] * 1000 + a[1] * 900 + a[2] * 500 +
			a[3] * 400 + a[4] * 100 + a[5] * 90 + a[6] * 50 + a[7] * 40 +
			a[8] * 10 + a[9] * 9 + a[10] * 5
			+ a[11] * 4 + a[12];
		return ans;
	}

};

int main(int mgr, char* mrgv[])
{
	Solution s;
	char key;
	cout << "please input a char to continue or quit : ('q' to quit, others to continue)" << endl;
	string  input_string;
	while (cin >> key)
	{
		if (key == 'q')
			break;
		//cin.clear();
		cout << "input a integer to convert to roman str,  the number should be in  (0-3999)" << endl;
		getchar();
		getline(cin, input_string);	
		cout << s.romanToInt(input_string) << endl;
		cin.clear();
	}

	system("pause");
	return 0;
}