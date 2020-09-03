#include "p101.h"
#include "p1103.h"
#include "p125.h"
#include "p696.h"
#include "p141.h"
#include "p486.h"
void testp696()
{
	p696::Solution_p696 _p696;
	_p696.test696();
}
void testp125()
{
	p125::Solution_p125 _p125;
	_p125.testpalindrome();
}
void testp1103()
{
	p1103::Solution_p1103 _p1103;
	_p1103.testcandies();
}
void testp101()
{
	p101::solutionp101 _p101;
	_p101.testTree();
}
void testp141()
{
	Solution_p141 _p141;
	_p141.testp141();
}
void testp486()
{
	Solution_p486 _p486;
	_p486.testp486();
}
int main(int mgr, char* mgv)
{
	//testp101();
	//testp1103();
//	testp125();
	//testp696();
	testp486();
	system("pause");
	return 0;
}