// 整数转换为罗马数字 
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

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	char conver(int num)
	{
		
	}
	string intToRoman(int num) {
		if (num < 0 || num>3999)return "invalid";
		string ans;
		unsigned int a[7+6]{0};
		int index = 0;
		a[0] = num / 1000;
		num = num % 1000;
		ans.insert(0,a[0],'M');
		a[1] = num / 900;
		num = num % 900;
		if (a[1]>0)
		{
			ans.insert(a[0], "CM");
		}

		a[2] = num / 500 ;
		num = num % 500;
		ans.insert(ans.size(),a[2],'D');

		a[3] = num / 400;
		num = num % 400;
		if(a[3]>0)ans.insert(ans.size(),"CD");

		a[4] = num / 100 ;
		num = num % 100;
		ans.insert(ans.size(),a[4],'C');

		a[5] = num / 90;
		num = num % 90;
		if(a[5]>0)ans.insert(ans.size(),"XC");


		a[6] = num / 50 ;
		num = num % 50;
		ans.insert(ans.size(),a[6],'L');

		a[7] = num / 40;
		num = num % 40;
		if(a[7]>0)ans.insert(ans.size(),"XL");

		a[8] = num / 10;
		num = num % 10;
		ans.insert(ans.size(),a[8],'X');

		a[9] = num / 9;
		num = num % 9;
	if(a[9]>0)	ans.insert(ans.size(),"IX");

		a[10] = num / 5;
		num = num % 5;
		ans.insert(ans.size(),a[10],'V');

		a[11] = num / 4;
		num = num % 4;
	if(a[11]>0)	ans.insert(ans.size(), "IV");

		a[12] = num;
		ans.insert(ans.size(), a[12], 'I');
		return ans;
	}
};
int main(int argv, char* argc)
{
	Solution s;
	char key;
	cout << "please input a char to continue or quit : ('q' to quit, others to continue)" << endl;
	int nums;
	while (cin >> key)
	{
		if (key == 'q')
			break;
		cin.clear();
		cout << "input a integer to convert to roman str,  the number should be in  (0-3999)" << endl;
		cin >> nums;
		cout<<s.intToRoman(nums)<<endl;
		cin.clear();
	}

	system("pause");
	return 0;
}
