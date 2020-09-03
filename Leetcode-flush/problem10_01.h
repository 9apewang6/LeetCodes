#pragma once
#include "public_def.h"
namespace p1001
{
	class Solution {
	public:
		void merge(vector<int>& A, int m, vector<int>& B, int n) {
			A.resize(m);
			A.insert(A.end(), B.begin(), B.end());
			sort(A.begin(),A.end());
		}
	};
}