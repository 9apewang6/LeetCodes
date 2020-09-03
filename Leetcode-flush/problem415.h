#ifndef PROBLEM415_H_INCLUDED
#define PROBLEM415_H_INCLUDED
#include "public_def.h"
// ""
namespace solution415
{
	class Solution_problem415 {
	public:
		string addStrings(string num1, string num2) {
			int n1_length = num1.length();
			int n2_length = num2.length();
			if (n1_length == 0 && n2_length > 0)return num2;
			if (num1.length() > 0 && num2.length() == 0)return num1;
			vector<int> ans{0};
			int anssize = 0;
			int temp_val=0;
			while (n2_length > 0 && n1_length > 0)
			{
				n2_length--;
				n1_length--;
				anssize = ans.size();
				temp_val = num1[n1_length] - '0' + num2[n2_length] - '0'+ans[anssize-1];

				ans[anssize - 1] =temp_val % 10;
				ans.push_back(temp_val/10);
			}
			if (n1_length > 0&&n2_length==0)
			{
				while (n1_length > 0)
				{
					n1_length--;
					anssize = ans.size();
					temp_val = num1[n1_length] - '0'+ans[anssize-1];
					ans[anssize - 1] = temp_val % 10;
					ans.push_back(temp_val/10);
				}
			}
			else if (n2_length > 0 && n1_length == 0)
			{
				while (n2_length > 0)
				{
					n2_length--;
					anssize = ans.size();
					temp_val = num2[n2_length] - '0' + ans[anssize - 1];
					ans[anssize - 1] = temp_val % 10;
					ans.push_back(temp_val / 10);
				}
			}
			anssize = ans.size();
			for (int j = anssize - 1; j >= 0; --j)
			{
				if (ans[j] == 0) {
					if (j == 1)ans.resize(1);
					continue;
				}
				if (ans[j] > 0)
				{
					ans.resize((j+1));
					break;
				}
			}
			reverse(ans.begin(), ans.end());
			return vectorTostring(ans);
		}



		void testaddstrings()
		{
			string m_str1, m_str2;
			cout << "please input two numstring " << endl;
			while (getline(cin, m_str1) && getline(cin, m_str2)) {
				trimLeftTrailingSpaces(m_str1);
				trimRightTrailingSpaces(m_str1);
				trimLeftTrailingSpaces(m_str2);
				trimRightTrailingSpaces(m_str2);
				find(m_str2.begin(),m_str2.end(),'-');
				if (find(m_str1.begin(), m_str2.end(), '-') != m_str1.end() || find(m_str2.begin(), m_str2.end(), '-') != m_str2.end())break;
				cout << addStrings(m_str1, m_str2) << endl;
				

			}



			system("pause");

		}
	};
}
#endif //PROBLEM415_H_INCLUDED