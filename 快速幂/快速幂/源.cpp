#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>

                         //基本原理，取模(a * b) % p = (a % p * b % p) % p 
                         //求A的B次方


//                 //方法一，每次*的时候顺便取模，eg:(2^5)%6==(2%6*2%6*2%6*2%6*2%6*2%6)%6,   //时间复杂度O(n)
//long long mi(long long base, long long power)//base为底数，power为指数
//{
//    long long result = 1;  //result是最终求幂的余数的结果，
//    for (int i = 1; i <= power; ++i) {
//        result = (result * base)%1000;//每次*便取余
//    }
//    return result % 1000;   //不要忘了括号外面还有一个取余
//}
//
//int main() {
//    long long base, power;
//    while (scanf("%lld %lld", &base, &power)==2&&base&&power) {
//         printf("%lld\n", mi(base, power));
//
//    }
//}

//
//                   //方法二，快速幂初步
//             //快速幂算法的核心思想就是每一步都把指数分成两半，而相应的底数做平方运算
//            //eg:3^10=(3*3)*(3*3)*(3*3)*(3*3)*(3*3)=(3*3)^5=(3*3)^5=（9^4）*（9^1）=（9^4）*（9^1）=（6561^1）*(9^1)最后变成都是指数为1的，然后存入
//long long mi(long long base, long long power) {
//    long long result=1;
//    while (power >0) {//只要指数大于1，就可以继续分
//        if (power % 2 != 0) {
//            result =result*base % 1000;//把指数为1的存入result中，剩余偶数幂去二分，这里的取余，一是使每个指数1的base取余了，二是使最后的结果取余（不是对base，因为最后的base是取余后过来的
//        }
//        power = power / 2;  //无论你奇数还是偶数，除2结果一样（因为整型会把奇数除2得的0.5去掉
//        base = (base*base) % 1000;  //底数变为原来的平方
//    }
//    return result;  //这里不用取余，因为最后指数为1时，取余了
//}
//
//int main() {
//    long long base, power;
//    while (scanf("%lld %lld", &base, &power) == 2 && base && power) {
//        printf("%lld\n", mi(base, power));
//
//    }
//}



                //快速幂终极优化
        //power%2==1可以用更快的“位运算”来代替，例如：power&1。因为如果power为偶数，则其二进制表示的最后一位一定是0；
          //如果power是奇数，则其二进制表示的最后一位一定是1。将他们分别与1的二进制做“与”运算，得到的就是power二进制最后一位的数字了，是0则为偶数，是1则为奇数。
               //同样，对于power = power / 2来说，也可以用更快的“位运算”进行替代，我们只要把power的二进制表示向右移动1位就能变成原来的一半了。
long long mi(long long base, long long power) {
    long long result = 1;
    while (power > 0) {
        if(power&1)  //等价于power为奇数
            result = result * base % 1000;
        power >>= 1;//二进制右移一位，等价除2
            base = (base * base) % 1000;
    }
    return result;
}
int main() {
    long long base, power;
    while (scanf("%lld %lld", &base, &power) == 2 && base && power) {
        printf("%lld\n", mi(base, power));

    }
}
