#include <iostream>
#include <math.h>
// problem07.cpp -- 对有符号整数进行反转
#define getsymbol(x)  ((signed char*)&x)[sizeof(x)-1]>>7 == 0 ? 1:-1
class Solution {
public:
	int reverse(int x) {
		if (x == 0) return 0;
		long long rx = fabs(x);
		int x_symbol = x>=0 ? 1:-1;
		int size = log10(rx);
		int remainder = 0;
		long long temp = 0;
		do {	
			remainder = rx % 10;
			temp += remainder*(pow(10,size));
			
			rx = rx / 10;
			size--;
		} while (rx);
		temp = x_symbol*temp;
		if (temp > (pow(2, 31) - 1) || temp < -1 * (pow(2, 31))) temp = 0;
		return temp;
	}
};

void main()
{
	{
	int inputnumber;
	std::cout << "please input a integer" << std::endl;
	std::cout << INT_MAX << std::endl;
	Solution s;
	while (std::cin >> inputnumber) {
		

		std::cout << s.reverse(inputnumber) << std::endl;
	}
	}
	system("pause");
}