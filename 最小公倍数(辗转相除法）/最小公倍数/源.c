#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
int main()
{
	int m, n,r;                //最小公倍数等于乘积除最大公约数
	while (scanf("%d %d", &m, &n) != EOF)
	{
		int a = m, b = n;
		while (n != 0)  //b为0，则任意数均为其公约数，所以最大公约数是另一个数
		{
			r =m%n;      //假设x为最大公约数，则m%n也是（因为m%n==m-x倍的n)
			m = n;    //所以等价求n与r的公约数，而n肯定大于r，因为余数小于除数
			n = r;     //使得后面要打印的m是相较n更大的那一个

	}  //循环执行到n为0，即m%n的余数为0为止，此时m（较大的那个）是最大公约数（相当于0（即n）与另一个数（即m）的公约数
		printf("%d\n", (a / m) * b);


	}

	return 0;
}



















