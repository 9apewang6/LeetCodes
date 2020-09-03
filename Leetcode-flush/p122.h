#ifndef _P122_H_
#define _P122_H_
#include "public_def.h"

class Solution_p122 {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		if (n <= 1)return 0;
		int left = 0;
		int right = 1;
		int maxprofit = 0;
		while (left <= right&& right < n)
		{
			if (prices[left] > prices[right])
			{
				left = right;
				continue;
			}
			if (prices[left] <= prices[right])
			{
				maxprofit = max(maxprofit, prices[right] - prices[left]);
				right++;
			}
		}
		return maxprofit;
	}
};

#endif //_P122_H_