/************************************************************************/
/*				Z字形变换             

将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

请你实现这个将字符串进行指定行数变换的函数：

几个Z字

*/
/************************************************************************/

#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
class SolutionZChars {
public:


	string convert(string s, int numRows) {
		// 分几组就是几行 
		if (numRows <= 1)
		{
			return s;
		}
		unsigned int STRING_LENGTH = s.size();
		unsigned int ColumnNum = (STRING_LENGTH - 1) / (numRows - 1);	
		unsigned int Surplus = (STRING_LENGTH - 1) % (numRows - 1);
		string recombinationstring;
		if (s.size() <= numRows)
		{
			return s;
		}
		else
		{

			for(int i=0;i<numRows;i++)
			{
				//计算上顶点个数  Column/2
				recombinationstring.push_back(s.at(i));
				
				for (int j = 1; j < ColumnNum; j++)
				{
					if (i == 0)
					{
						if (j % 2 == 0)
						{
							recombinationstring.push_back(s.at(j*(numRows-1)));
						}
					}
					else if (i == (numRows - 1))
					{
						if ((j>1&&j%2==1))
						{
							recombinationstring.push_back(s.at((j)*(numRows-1)));
						}
					
					}
					else if(i>0&&i<(numRows-1))
					{
						if (j % 2 == 1)
						{
							int index = (j + 1) / 2 * 2*(numRows - 1);
							recombinationstring.push_back(s.at( index-i));
						}
						else if (j % 2 == 0)
						{
							int index = (j + 1) / 2 * 2 * (numRows - 1);
							recombinationstring.push_back(s.at(index + i));
						}		
							
					

					}

					
					
				}
				if (i>=1&&i<(numRows-1))
				{
					if ((ColumnNum%2==0 &&(i<=Surplus))||((ColumnNum%2==1)&&(numRows-1-i)<=Surplus) )
					{

						if ((ColumnNum) % 2 == 0)
						{
							recombinationstring.push_back(s.at((ColumnNum + 1) / 2 * 2 * (numRows - 1) + i));

						}
						else
						{
							recombinationstring.push_back(s.at((ColumnNum + 1) / 2 * 2 * (numRows - 1) - i));
						}
					}
				}
				else if(i==0)
				{
					if (ColumnNum % 2 == 0)
					{
						recombinationstring.push_back(s.at(ColumnNum*(numRows - 1)));
					}
				}
				else if (i == (numRows - 1) )
				{
					if (ColumnNum > 1 && ColumnNum % 2 == 1)
					{
						recombinationstring.push_back(s.at((ColumnNum)*(numRows - 1)));
					}
				}
			}
		}
		return recombinationstring;
	}
};
void main()
{
	string _inputString;
	//	cout << "Please input a num :\t\b";
	// 	int _inputNum;
	// 	cin >> _inputNum; 
	SolutionZChars _DealPalind;
	cout << "Please input a string " << endl;
	while (getline(cin, _inputString) && _inputString.length() > 0)
	{

		cout << _DealPalind.convert(_inputString,5) << endl;

	}
	system("pause");
}