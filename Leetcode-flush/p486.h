#ifndef _P486_H_
#define _P486_H_
#include "public_def.h"
//  1. vector.size()<=20  ;  2. vector.at(i)<=10000000;3 . ПаµИ

class Solution_p486 {
public:
	//  Sum(n)= Sum(n-1) + max(nums)
	
// 	int	planning(int &sum1, int &sum2, vector<int>& vec)
// 	{
// 		if (vec.size() == 0)
// 		{
// 			return 0;
// 		}
// 		if (vec.size() == 1)
// 		{
// 			sum1 += vec.front();
// 			sum2 += 0;
// 			vec.pop_back();
// 		}
// 		else if (vec.size() == 2)
// 		{
// 			sum1 += max(vec.at(0),vec.at(1));
// 			sum2 += min(vec.at(0), vec.at(1));
// 			vec.clear();
// 		}
// 		else if (vec.size() > 2)
// 		{
// 			if ((vec.at(0)+vec.at(vec.size()-2))>= (vec.at(1)+vec.at(vec.size()-1)))
// 			{
// 				sum1 += vec.at(0);
// 				vec.erase(vec.begin());
// 
// 
// 				if ((vec.at(0) + vec.at(vec.size() - 2)) >= (vec.at(1) + vec.at(vec.size() - 1)))
// 				{
// 					sum2 += vec.at(0);
// 					vec.erase(vec.begin());
// 				}
// 				else
// 				{
// 					sum2 += vec.at(vec.size()-1);
// 					vec.pop_back();
// 				}
// 
// 			}
// 			else if ((vec.at(0) + vec.at(vec.size() - 2)) < (vec.at(1) + vec.at(vec.size() - 1)))
// 			{
// 				sum1 += vec.at(vec.size()-1);
// 				vec.pop_back();
// 
// 				if ((vec.at(0) + vec.at(vec.size() - 2)) >= (vec.at(1) + vec.at(vec.size() - 1)))
// 				{
// 					sum2 += vec.at(0);
// 					vec.erase(vec.begin());
// 				}
// 				else
// 				{
// 					sum2 += vec.at(vec.size() - 1);
// 					vec.pop_back();
// 				}
// 			}
// 		}
// 
// 		planning(sum1, sum2, vec);
// 
// 
// 	}





		bool PredictTheWinner(vector<int>& nums) {
			int length = nums.size();
			auto dp = vector<vector<int>>(length, vector<int>(length));
			for (int i = 0; i < length; i++) {
				dp[i][i] = nums[i];
			}
			for (int i = length - 2; i >= 0; i--) {
				for (int j = i + 1; j < length; j++) {
					dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
				}
			}
			return dp[0][length - 1] >= 0;
		}

	

	




	void testp486()
	{
		string input;
		vector<int> vec;
		cout << " please input a integer vector list [1,2,3]:" << endl;
		while (getline(cin, input))
		{
			if (input.size() == 0)break;
			trimLeftTrailingSpaces(input);
			trimRightTrailingSpaces(input);
			if (input.size() == 0)break;
			vec = stringToIntegerVector(input);

			cout << boolTostring(PredictTheWinner(vec)) << endl;
			cout << " please input a interger vector list [1,3,2], or input null string to break" << endl;
		}
	}
};



#endif //_P486_H_