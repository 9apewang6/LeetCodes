#include <iostream>
#include <string>
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::max;
using std::min;
class SolutionBinary {
public:
	string addBinary(string a, string b) {
		string ans = "";
		reverse(a.begin(),a.end());
		reverse(b.begin(),b.end());
		bool flag = false;
		int ASize = a.size();
		int BSize = b.size();

		for (int i = 0; i < min(ASize, BSize); i++)
		{
			if ((flag + a[i] - '0' + b[i] - '0') % 2 == 0)
			{
				ans.push_back('0');
			}
			else
			{
				ans.push_back('1');
			}
			flag = (a[i] - '0' + b[i] - '0'+flag) / 2;


		}
		for (int j = min(ASize, BSize); j < max(ASize, BSize); j++)
		{
			if (ASize >= BSize)
			{
				if ((flag + a[j] - '0') % 2 == 0)
				{
					ans.push_back('0');
				}
				else
				{
					ans.push_back('1');
				}
				flag = (a[j] - '0' + flag) / 2;
			}
			else
			{
				if ((flag + b[j] - '0') % 2 == 0)
				{
					ans.push_back('0');
				}
				else
				{
					ans.push_back('1');
				}
				flag = (b[j] - '0' + flag) / 2;

			}

		}
		if (flag)
		{
			ans.push_back('1');
		}
		
		reverse(ans.begin(),ans.end());
		return ans;
	}
};
int main()
{
	SolutionBinary Sol;
	string operatorA;
	string operatorB;
	while (getline(cin, operatorA)&& getline(cin, operatorB))
	{
		cout<<Sol.addBinary(operatorA, operatorB)<<endl;
	}


	
	system("pause");
	return 0;


}