// 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
//  字符串 回溯算法 , 递归 
// e.g.  
//  input 3 : 
// output : { "()()()", "((()))","(()())","()(())","(())()"}
//  生成 n  对有效括号
#pragma once
#include "public_def.h"

class Solution_problem22 {
	enum   sloway
	{
		VIOLENCEWAY,
		BACKTRACKINGMETHOD,
		RECUSIVEMETHOD,
		ALL_COUNT,
	};
// private:
// 	int sol_way = 1;
private: 
	sloway id = BACKTRACKINGMETHOD;
private:
	vector<string > ans;
protected:
	Solution_problem22() {};

public:
	static Solution_problem22& getInstance()
	{
		static Solution_problem22 _instance;
		return _instance;
	}

	void setway(const sloway &way)
	{
		id = way;
	}
	// 暴力法
	 // 先生成全部的组合，然后判断是否合理  时间复杂度 2^2n , 控件复杂度 n  
	
	bool isValid(string& str)
	{
		int _match = 0;
		for (auto iter : str)
		{
			switch (iter)
			{
			case '(':
				_match++;
				break;
			case ')':
				_match--;
				if (_match < 0)return false;
				break;
			default:
				break;
			}
			

		}
		return _match == 0;
	}
	void generateall(string & str,int& n)
	{
		if (str.size() ==  n)
		{
			if (isValid(str))ans.push_back(str);
			return;
		}

		str += '(';
		generateall(str, n);
		str.pop_back();
		str += ')';
		generateall(str, n);
		str.pop_back();
	}

	// 回溯法  , 内到外  ,传引用，避免拷贝
	// 时间复杂度 4^n/sqrt(n) , 空间复杂度 n     , 深度优先

	void backtrack(string& current, int open, int close, int& n)
	{
		if (current.size() == 2 * n)
		{
			ans.push_back(current);
			return;
		}
		if (open < n)
		{
			current.push_back('(');
			backtrack(current, open + 1, close, n);

			current.pop_back();
		}
		if (close < open)
		{
			current.push_back(')');
			backtrack(current, open, close + 1, n);

			current.pop_back();
		}
	}


	vector<string> generateParenthesis(int n) {
		switch (id)
		{
		case Solution_problem22::sloway::VIOLENCEWAY:
		{
			string cur;
			n = 2 * n;
			generateall(cur,n);
			return ans;
		}
			break;
		case Solution_problem22::sloway::BACKTRACKINGMETHOD:
		{
			if (n == 0)return ans;
			string cur;
			backtrack(cur, 0, 0, n);
			return ans;
		}
			break;
		case Solution_problem22::sloway::RECUSIVEMETHOD:
		{
			return *generate(n);	
		}
			break;
		default:
			break;
		}
		return ans;
		

	}
	//按括号序列的长度递归 
	// 时间复杂度 O(  4^n/sqrt(n) ) , 空间复杂度 O(4^n/sqrt(n))   , 动态规划   , 状态方程
private:
		shared_ptr<vector<string>> cache[100] = { nullptr };
	public:
		shared_ptr<vector<string>> generate(int n) {
			if (cache[n] != nullptr)
				return cache[n];
			if (n == 0) {
				cache[0] = shared_ptr<vector<string>>(new vector<string>{ "" });
			}
			else {
				auto result = shared_ptr<vector<string>>(new vector<string>);
				for (int i = 0; i != n; ++i) {
					auto lefts = generate(i);
					auto rights = generate(n - i - 1);
					for (const string& left : *lefts)
						for (const string& right : *rights)
							result->push_back("(" + left + ")" + right);
				}
				cache[n] = result;
			}
			return cache[n];
		}

	void test()
	{
		int n;
		int id_way=1;

		while ((cout << " please input the n number of generated parenthese that u want " << endl) && cin >> n &&n > 0)
		{
			cout << "please choose the solution way :" << endl;
			cout << "1 : 暴力法" << endl;
			cout << "2 : 回溯 递归" << endl;
			cout << "3 : 根据长度递归" << endl;
			
			cin >> id_way;
			id_way = id_way % sloway::ALL_COUNT;
			
			switch (id_way)
			{
			case 1:
				setway(sloway::VIOLENCEWAY);
				break;
			case 2:
				setway(sloway::BACKTRACKINGMETHOD);
				break;
			case 3:
				setway(sloway::RECUSIVEMETHOD);
				break;

			default:
				setway(sloway::BACKTRACKINGMETHOD);
				break;
			}
			for (auto iter : generateParenthesis(n))
			{
				cout << iter << endl;
			}

		}
	}
};