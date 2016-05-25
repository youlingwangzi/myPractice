#include<stdio.h>
#include<stdlib.h>

int a[10][10];

void snake_a(int n)
{
	int x = -1, y = n-1, k = 1, count = 2;
	for (int i = n; i > 0;)
	{
		//printf("i:%d,%d\n",i, count);
		for (int j = 0; j < i; j++, k++)
		{
			if (count == 2)
			{
				if (i % 2 != 0)
					n % 2 != 0 ? x++ : x--;
				else 
					n % 2 == 0 ? x++ : x--;
			}
			else
			{
				if (i % 2 != 0) 	
					n % 2 != 0 ? y++ : y--;
				else
					n % 2 == 0 ? y++ : y--;
			}
			//printf("%d,%d\n", x, y);
			a[x][y] = k;
		}
		//printf("\n");
		if (count == 2)
		{
			count = 0;
			i--;
		}
		count++;
	}
}

void print_a(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%4d", a[i][j]);
		printf("\n");
	}
}

int main()
{
	int b;
	printf("请输入一个数：");
	scanf("%d", &b);

	snake_a(b);
	print_a(b);

	system("pause");
	return 0;
}