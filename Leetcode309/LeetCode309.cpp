//  ���������Ʊʱ���������е�i������i��Ĺ�Ʊ�۸� 
//�䶳�ڣ� ������Ʊ�ڶ��첻���ٹ����Ʊ�� �䶳��Ϊ1�졣

// ����ͬʱ���ж�ν��ף� �������


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