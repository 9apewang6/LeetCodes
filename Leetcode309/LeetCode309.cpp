//  最佳买卖股票时机，数组中第i项代表第i天的股票价格， 
//冷冻期， 卖出股票第二天不可再购买股票， 冷冻期为1天。

// 不能同时进行多次交易， 不能买多


#include <iostream>
#include <vector>
#include <array>
using std::cout;
using std::endl;
using std::array;

using std::vector;


class Solution {
	enum class StockOperation
	{
		SO_BUG,
		SO_SOLD,
		SO_WAIT,
		SO_UNKNOWN,
	};

public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() == 0)
		{
			//operations.push_back(StockOperation::SO_UNKNOWN);
			return 0;
		}
		else if (prices.size() == 1)
		{
			operations.push_back(StockOperation::SO_UNKNOWN);
			return 0;
		}
		else if (prices.size() == 2)
		{

		}
		
	}
private:
	vector<StockOperation> operations;
};

void main()
{
	Solution buyStock;
	vector<int> testVec{2,5};
	cout << buyStock.maxProfit(testVec) << endl;
	system("pause");
	return;
}