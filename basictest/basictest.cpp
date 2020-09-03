#include <string>
#include <iostream>
#include <io.h>
#include <vector>
using namespace std;
void ptrswap(int* &a, int* & b) {
// 	int p = *a;
// 	*a = *b;
// 	*b =p;
	int *p = a;
	a = b;
	b = p;

}
int& geta(int* p, int a)
{
	return p[a];
}
void test7_8()
{
	int ia[10];
	for (int i = 0; i != 10; ++i)
	{
		geta(ia,i)=0;
	}
	cout << ia<<endl;
}

void test7_1()
{
	int *a1, *a2;
	int A1 = 3, A2 = 4;
	a1 = &A1;
	a2 = &A2;
	cout << "before swap the address a1 = " << a1 << "a2 =" << a2 << endl;
	cout << "a1:" << *a1 << "a2:" << *a2 << endl;
	ptrswap(a1, a2);
	cout << "after swap  the addr a1 = " << a1 << "a2 = " << a2<<endl;
	cout << "a1:" << *a1 << "a2:" << *a2 << endl;
	
}

// vector<int>::const_iterator find_val(vector<int>::const_iterator beg,
// 	vector<int>::const_iterator end,
// 	int value,
// 	vector<int>::size_type &occurs)
// {
// 	// res_iter will hold first 
// 	vector<int>
// }
int main(int mgr, char* mgrv)
{
	int ret = -1;
	ret = _access("./config/defalut.ccf",0);
	cout << ret << endl;
	test7_8();
	system("pause");
	return 0;
}