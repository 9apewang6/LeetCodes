#pragma once
#include "public_def.h"
namespace p125
{
	class Solution_p125 {
	public:
		bool isvalid(const char var)
		{
			if (var >= '0'&&var <= '9'
				|| var <= 'z'&&var >= 'a'
				|| var <= 'Z'&&var >= 'A'
				)return true;
			return false;

		}
		void CharTochar(char& var)
		{
			if (var >= 'A'&&var <= 'Z')
				var = var + 32;
		}
		bool isPalindrome(string s) {
			int n = s.size();
			if (n <=1)return true;
			int left = 0;
			int right = n - 1;
			
			while (left < right)
			{
				if (isvalid(s[left]))
				{
					CharTochar(s[left]);
					if (isvalid(s[right]))
					{
						CharTochar(s[right]);
						if (s[left] == s[right])
						{
							left++;
							right--;
						}
						else
						{
							return false;
						}
					}
					else {
						right--;
					}
				}
				else
				{
					left++;
				}
			}
			return true;
		}
		void testpalindrome()
		{
			string input_String;
			while (getline(cin, input_String))
			{
				cout << boolTostring(isPalindrome(input_String)) << endl;
			}
		}
	};
}