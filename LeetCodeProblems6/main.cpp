/************************************************************************/
/*				Z���α任             

��һ�������ַ������ݸ������������Դ������¡������ҽ��� Z �������С�

���������ַ���Ϊ "LEETCODEISHIRING" ����Ϊ 3 ʱ���������£�

֮����������Ҫ�����������ж�ȡ��������һ���µ��ַ��������磺"LCIRETOESIIGEDHN"��

����ʵ��������ַ�������ָ�������任�ĺ�����

����Z��

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
		// �ּ�����Ǽ��� 
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
				//�����϶������  Column/2
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