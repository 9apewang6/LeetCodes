#pragma once
#include "public_def.h"
namespace p121
{
	class Solution_p121 {
	public:
		int maxProfit(vector<int>& prices) {
			int n = prices.size();
			if (n <= 1)return 0;
			int left =0;
			int right =1;
			int maxprofit = 0;
			while (left <= right&& right < n)
			{
				if (prices[left] > prices[right])
				{
					left=right;
					continue;
				}
				if (prices[left] <= prices[right])
				{
					maxprofit=max(maxprofit, prices[right] - prices[left]);
					right++;
				}
			}
			return maxprofit;
		}
		void testprofit()
		{
			string input_string;
			vector<int> prices;
			while (getline(cin, input_string)) {
				trimLeftTrailingSpaces(input_string);
				trimRightTrailingSpaces(input_string);
				prices = stringToIntegerVector(input_string);
				cout << maxProfit(prices) << endl;

			}
		}
	};
}