#pragma once
#include "public_def.h"
namespace solution26
{
	class Solution_problem26 {
	public:
		int removeDuplicates(vector<int>& nums) {
// 			int _size = nums.size();
// 			if (_size <= 1) return _size;
// 			int _n = 1;
// 			int lastvalue=nums[0];
// 			for (int j = 1; j <= (_size - 1); j++)
// 			{
// 				if (lastvalue == nums[j])
// 				{
// 					continue;
// 				}
// 				else
// 				{
// 					lastvalue = nums[j];
// 					nums[_n] = nums[j];
// 					_n++;
// 				}
// 			}
// 			nums.resize(_n);
// 			return _n;
			int _size = nums.size();
			if (_size <= 1) return _size;
			int fast = 0;
			int slow = 0;
			while (slow <= (_size - 1) && slow <= fast&&(fast<=(_size-1)))
			{
				if (nums[slow] == nums[fast])
				{
					fast++;
				}
				else
				{
					slow++;
					nums[slow] = nums[fast];
					fast++;
				}
			}
			nums.resize(slow + 1);
			return (slow+1);
		}
		vector<int> stringTovector(string input)
		{
			vector<int> ans;
			trimLeftTrailingSpaces(input);
			trimRightTrailingSpaces(input);
			input = input.substr(1, input.length() - 2);
			stringstream ss;
			ss.str(input);
			char splitchar = ',';
			string item;
			while (getline(ss, item, splitchar))
			{
				trimLeftTrailingSpaces(item);
				trimRightTrailingSpaces(item);
				ans.push_back(stoi(item));
			}
			return ans;
		}
		template<typename T>
		string vectorTostring(vector<T> vec)
		{
			string str;
			for (auto iter : vec)
			{
				str += " ";
				str += to_string(iter);
				str += " ";
			}
			return str;
		}
		void testproblem26()
		{
			string input_string;
			int _input_key=0;
			vector<int> testvec;
			
			while ((cout << "please intput a integer vector , e.g. [1,2,3]" << endl) && getline(cin, input_string))
			{
				testvec = stringTovector(input_string);
				cout << " invoke : answer is :" << removeDuplicates(testvec) << endl;
				string out = vectorTostring(testvec);
				cout << out << endl;
// 				cout << " to continue: please input a integer : -1 to quit, others to continue" << endl;
// 				cin >> _input_key;
// 				if (_input_key == -1)break;
// 				else {
// 					cin.clear();
// 					continue;
// 				}
			}
			system("pause");
		}
	};

}