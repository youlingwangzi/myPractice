#include<stdio.h>
#include<stdlib.h>
int main()
{
	double s = 100, h = 100;
	for (int i = 2; i <= 10; i++)
	{
		s += h;
		h = h / 2;
	}
	printf("共经过%g米。", s);
	printf("最后一次反弹%g米。", h / 2);
	system("pause");
	return 0;
}