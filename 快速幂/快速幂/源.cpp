#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>

                         //����ԭ��ȡģ(a * b) % p = (a % p * b % p) % p 
                         //��A��B�η�


//                 //����һ��ÿ��*��ʱ��˳��ȡģ��eg:(2^5)%6==(2%6*2%6*2%6*2%6*2%6*2%6)%6,   //ʱ�临�Ӷ�O(n)
//long long mi(long long base, long long power)//baseΪ������powerΪָ��
//{
//    long long result = 1;  //result���������ݵ������Ľ����
//    for (int i = 1; i <= power; ++i) {
//        result = (result * base)%1000;//ÿ��*��ȡ��
//    }
//    return result % 1000;   //��Ҫ�����������滹��һ��ȡ��
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
//                   //�������������ݳ���
//             //�������㷨�ĺ���˼�����ÿһ������ָ���ֳ����룬����Ӧ�ĵ�����ƽ������
//            //eg:3^10=(3*3)*(3*3)*(3*3)*(3*3)*(3*3)=(3*3)^5=(3*3)^5=��9^4��*��9^1��=��9^4��*��9^1��=��6561^1��*(9^1)����ɶ���ָ��Ϊ1�ģ�Ȼ�����
//long long mi(long long base, long long power) {
//    long long result=1;
//    while (power >0) {//ֻҪָ������1���Ϳ��Լ�����
//        if (power % 2 != 0) {
//            result =result*base % 1000;//��ָ��Ϊ1�Ĵ���result�У�ʣ��ż����ȥ���֣������ȡ�࣬һ��ʹÿ��ָ��1��baseȡ���ˣ�����ʹ���Ľ��ȡ�ࣨ���Ƕ�base����Ϊ����base��ȡ��������
//        }
//        power = power / 2;  //��������������ż������2���һ������Ϊ���ͻ��������2�õ�0.5ȥ��
//        base = (base*base) % 1000;  //������Ϊԭ����ƽ��
//    }
//    return result;  //���ﲻ��ȡ�࣬��Ϊ���ָ��Ϊ1ʱ��ȡ����
//}
//
//int main() {
//    long long base, power;
//    while (scanf("%lld %lld", &base, &power) == 2 && base && power) {
//        printf("%lld\n", mi(base, power));
//
//    }
//}



                //�������ռ��Ż�
        //power%2==1�����ø���ġ�λ���㡱�����棬���磺power&1����Ϊ���powerΪż������������Ʊ�ʾ�����һλһ����0��
          //���power����������������Ʊ�ʾ�����һλһ����1�������Ƿֱ���1�Ķ����������롱���㣬�õ��ľ���power���������һλ�������ˣ���0��Ϊż������1��Ϊ������
               //ͬ��������power = power / 2��˵��Ҳ�����ø���ġ�λ���㡱�������������ֻҪ��power�Ķ����Ʊ�ʾ�����ƶ�1λ���ܱ��ԭ����һ���ˡ�
long long mi(long long base, long long power) {
    long long result = 1;
    while (power > 0) {
        if(power&1)  //�ȼ���powerΪ����
            result = result * base % 1000;
        power >>= 1;//����������һλ���ȼ۳�2
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
