// ºÏ²¢Á´±í
#include "Problem21.h"
#include "problem22.h"
#include "problem23.h"
#include "problem24.h"
#include "Magic_guide.h"
#include "problem25.h"
#include "problem26.h"
#include "problem206.h"
#include "problem415.h"
#include "problem205.h"
#include "p121.h"
#include "p57_II.h"
#include "p104.h"
#include "p169.h"
#include "p283.h"
#include "offer03.h"
void stringtoimagename(string& str)
{
	char rename[20]{ '\0' };
	int id = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '-' || str[i] == ' ' || str[i] == ':' || str[i] == '.')continue;
		else {
			if (id < 20)rename[id] = str[i];
			id++;
		}
	}
	str = rename;
}

int checksum(const char* da,int size)
{
	unsigned int ret = 0;
	for (int i = 0; i < size; i++)
	{
		ret ^= da[i];
	}
	return ret;
}
int chartoHex(const char t)
{
	return 0;
}
void testp104()
{
	p104::Solution _p104;
	_p104.testtreenode();
}
void testp169()
{
	p169::solution169 _p169;
	_p169.testmajority();
}
void test283()
{
	p283::solution283 _p283;
	_p283.testmoveZeros();
}
void testoffer03()
{
	offer03::soffer03 _offer03;
	_offer03.testfind();
}
int main() {

// 	Solution_problem21 _s21;
// 	_s21.test_solution();
	//Solution_problem22::getInstance().test();
// 	solution23::Solution_problem23 _s23;
// 	_s23.test_merge();
// 	solution24::Solution_problem24 _s24;
// 	_s24.test_swap();
// 	solution_magicguide::Solution_Magicguide _magicguide;
// 	_magicguide.testmagic();
// 	solution25::Solution_problem25 _s25;
// 	_s25.testreverse();
// 	solution26::Solution_problem26 _s26;
// 	_s26.testproblem26();
// 	string str = "";
// 	stringtoimagename(str);
// 	cout << str << endl;
// 	solution415::Solution_problem415 _s415;
// 	_s415.testaddstrings();
// 	solution206::Solution_problem206 _s206;
// 	_s206.testreverselist();
// 	solution205::MyStack _stack;
// 	_stack.push(1);
// 	_stack.push(2);
// 	_stack.push(3);
// 	_stack.push(5);
// 	int n_size = _stack.getsize();
// 	cout <<"the size is :"<< n_size<< endl;
// 	for (int j = 0; j < n_size; j++)
// 	{
// 		cout << _stack.top() << endl;
// 	
// 	}

// 	char data[6];
// 	data[0] = 0x31;
// 	data[1] = 0x00;
// 	data[2] = 0x02;
// 	data[3] = 0x01;
// 	data[4] = 0x01;
// 	data[5] = checksum(data,5);
// 	string str(data);
// 	string str{0x31,0x00,0x02,0x01,0x01};
// 	p121::Solution_p121 _s121;
// 	_s121.testprofit();
// 	str[0] = 0x31;
// 	str[1] = 0x00;
// 	str[2] = 0x02;
// 	str[3] = 0x01;
// 	str[4] = 0x01;
// 	p57_II::Solution_p57_ii _p57ii;
// 	_p57ii.testp57();
//	testp104();
	//testp169();
//	test283();
	testoffer03();
	getchar();
	getchar();
	return 0;
}

