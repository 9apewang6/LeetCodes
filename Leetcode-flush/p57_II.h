#pragma once
#include "public_def.h"
namespace p57_II
{

	class Solution_p57_ii {
	public:
		
		vector<vector<int>> findContinuousSequence(int target) {
			int sum = 0;
			vector<int > temp;
			vector<vector<int>> ans;
			if (target < 2)return ans;
// 			int mid = target / 2;
// 			int key = 3;
// 			if (target % 2 == 1)
// 			{
// 				temp.push_back(target / 2);
// 				temp.push_back(target / 2 + 1);
// 				ans.push_back(temp);
// 				temp.clear();
// 			}
// 			while (key <= mid)
// 			{
// 				if (target%key == 0)
// 				{
// 					sum = target / key;
// 					if (sum > (key / 2))
// 					{
// 						for (int j = -(key / 2); j <= (key / 2); j++)
// 						{
// 							temp.push_back(sum + j);
// 						}
// 						ans.push_back(temp);
// 						temp.clear();
// 					}
// 				}
// 				key = key + 2;
// 			}	
// 			key = 2;
// 			while (key <= mid)
// 			{
// 				float val = (float)target / key;
// 				if ((val- (key / 2)) >0 )
// 				{
// 					if ((int)((double)(target / key+1) - (double)(target / key-1)) > 1)
// 					{
// 						key += 2;
// 						continue;
// 					}
// 					else
// 					{
// 						for (int j = -(key / 2); j <= (key / 2); j++)
// 						{
// 							temp.push_back((target/key) + j);
// 						}
// 						ans.push_back(temp);
// 						temp.clear();
// 					}
// 				}
// 				key += 2;
// 			}
			int m = sqrt(2 * target);
			
			for (int i = 0; i<= m; i++)
			{
				sum += i;
				if ((target - sum) % (i + 1) == 0)
				{
					int tempval = (target - sum) / (i + 1);
					if (tempval == 0 || tempval == target)continue;
					for (int j = 0; j < (i + 1); j++)
					{
						temp.push_back(tempval + j);
					}
					ans.push_back(temp);
					temp.clear();
				}
			}
			sort(ans.begin(),ans.end());
			 return ans;
		}

		void testp57()
		{
			int testvalue = 2;
			vector<vector<int>> ans;
			while (cin >> testvalue)
			{
				if (testvalue <= 1)break;
				ans = findContinuousSequence(testvalue);
				for (auto iter : ans)
				{
					cout << vectorTostring(iter) << endl;
				}
			}
		}
	};
}