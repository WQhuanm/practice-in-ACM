#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>

                         //约数个数定理
                           //首先，n可以分解质因数：
                         //由约数定义可知的约数有:p10, p11, p12, ..., ，共（a1 + 1）个；同理的约数有（a2 + 1）个；……；的约数有（ak + 1）个。
                                //故根据乘法原理：n的约数的个数就是(a1 + 1)(a2 + 1)(a3 + 1)…(ak + 1)。
                           //例题：正整数378000共有多少个正约数？
                          //解：将378000分解质因数378000 = 2^4×3^3×5^3×7^1
                           //由约数个数定理可知378000共有正约数(4 + 1)×(3 + 1)×(3 + 1)×(1 + 1) = 160个。           //从指数0开始，所以是最高次加1

int main()
{
    long long n;
    while (scanf("%lld", &n) == 1 && n != 0)
    {
        
        int two = 0, three = 0, five = 0, seven = 0;
        while (n % 2 == 0)
        {
            n = n / 2;
            two++;
        }
        while (n %3 == 0)
        {
            n = n / 3;
           three++;
        }
        while (n % 5 == 0)
        {
            n = n / 5;
            five++;
        }
        while (n % 7 == 0)
        {
            n = n / 7;
           seven++;
        }
        int sum = (++two) * (++three) * (++five) * (++seven);
        printf("%d\n", sum);

    }

    return 0;
}








































