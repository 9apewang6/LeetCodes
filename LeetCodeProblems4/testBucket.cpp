#include "SortCommon.h"
void main()
{

	int book[1001] = {0}, i, j, t, n;
	
	cin>>n;//����һ����n����ʾ��������n����
	for (i = 1; i <= n; i++)//ѭ������n������������Ͱ����
	{
		scanf("%d", &t);  //��ÿһ������������t��
		book[t]++;  //���м������Ա��Ϊt��Ͱ��һ��С����
	}
	for (i = 1000; i >= 0; i--)  //�����жϱ��1000~0��Ͱ
		for (j = 1; j <= book[i]; j++)  //�����˼��ξͽ�Ͱ�ı�Ŵ�ӡ����
			printf("%d ", i);
	getchar(); getchar();
	system("pause");
}