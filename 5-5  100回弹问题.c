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
	printf("������%g�ס�", s);
	printf("���һ�η���%g�ס�", h / 2);
	system("pause");
	return 0;
}