#pragma once
#include "public_def.h"
namespace p1103
{
	class Solution_p1103 {
	public:
		vector<int> distributeCandies(int candies, int num_people) {
			vector<int> ans;
			double a = sqrt((2 * candies + 0.25)) - 0.5;
			int A = ceil(sqrt((2 * candies + 0.25))-0.5);
			int sum = 0;
			if (A < num_people)
			{
				for (int j = 0; j < A; j++)
				{
					if (sum < candies)
					{
						sum += (j + 1);
						ans.push_back((j + 1));
						if (sum > candies)
						{
							ans[ans.size() - 1] -= sum - candies;
						}
					}

				}
				if(sum<candies)ans.push_back(candies - sum);
			}
			else if (A == num_people)
			{
				for (int j = 0; j < A; j++)
				{
					if (sum < candies)
					{
						sum += (j + 1);
						ans.push_back((j + 1));
						if (sum > candies)
						{
							ans[ans.size() - 1] -= sum - candies;
						}
					}
				}
				if (sum < candies)
				{
					ans[0] += candies - sum;
				}
			}
			else if (A > num_people)
			{
				for (int j = 0; j < num_people; j++)
				{
					if (sum < candies)
					{
						sum += (j + 1);
						ans.push_back((j + 1));
						if (sum > candies)
						{
							ans[ans.size() - 1] -= sum - candies;
						}
					}
				}
				for (int k = 0; k < ceil(A - num_people+0.5) / num_people; k++)
				{
					int m = A - num_people - k*num_people;
					m = m >= num_people ? num_people : m;
					for (int i = 0; i < m; i++)
					{
						if (sum < candies)
						{

							sum += (num_people + i + 1+k*num_people);
							ans[i] += (num_people + i + 1+k*num_people);
							if (sum > candies)
							{
								ans[i] -= sum - candies;
							}
						}
					}
				}
				if (sum < candies)
				{
					int temp = A%num_people;
					temp = temp > 0 ? (temp - 1) : 0;
					ans[temp] +=candies-sum;
				}
			}
			ans.resize(num_people);
			return ans;
		}

		void testcandies()
		{
			int candies = 0;
			int numpeople = 0;
			vector<int> ans;
			while (cin >> candies&&cin >> numpeople)
			{
				ans = distributeCandies(candies,numpeople);
				cout << "******the answer is ********" << endl;
				for (int iter : ans)
				{
					cout << "----" << iter << endl;
				}
			}
		}
	};
}