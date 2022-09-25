#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>


               //FatMouse准备了M磅的猫粮，准备与守卫仓库的猫交易，里面装着他最喜欢的食物JavaBean。
//仓库有N个房间。i - th 房间包含 J[i] 磅爪哇豆， 需要一磅猫粮。FatMouse不必用房间里所有的爪哇豆来交换，
//相反，如果他付给F[i]1 % 磅的猫粮，他可能会得到J[i]1 % 磅的爪哇豆。这里有一个真实的数字。现在，他正在给你分配这个作业：告诉他能得到的最大数量的爪哇豆。

#include<algorithm>  //使用sort函数的头文件
using namespace std; //避免发生命名冲突，优先使用库函数，这样sort才可以用
const int W = 1e4 + 5; //数组开大，保证能存下全部输入
int M, N;   //M为猫粮数，N为房间数
double tot; //换取奶酪数
struct room     //用结构体包含一个整体，方便提取与转换
{
    double catfood;
    double cheese;

}arr[W];    //相当与room类型的数组（即room arr[max])这样一个数组）

bool emp(room x, room y)    //定义sort从大到小排序的函数   //bool是返回真或者假的类型，可以通过return条件来表示真假，当x与y比较时，x比值大，条件成立，返回真。sort不用交换他们，相反，返回假，sort交换使变为真
{
    return (x.cheese) / (x.catfood) > (y.cheese) / (y.catfood);   //奶酪/猫粮比值越大，越划算    //x.cheese表示room x这个结构体数组中的cheese这一项，点号.就是连接这个的
}

int main()
{
    while (scanf("%d %d", &M, &N) == 2 &&（M!=-1&&N!=-1）)   //M,N均为-1，输入结束，进入判断回合
    {
        for (int i = 1; i <= N; ++i)  //i表示第i间房间,i从1开始，因为房间没有第0间
        {
            scanf("%lf %lf", &arr[i].cheese, &arr[i].catfood);     //输入每间房间的奶酪与猫粮
        }
        sort(arr + 1, arr + 1 + N, emp);  //使用排序，将性价比高的房间排在前面，这样按顺序换最划算，sort取的是地址，arr+1表示arr[1]的地址，不可以写（arr,arr+N)这样是从arr[0]开始，而我们的房间从arr[1]开始
        for (int i = 1; i <= N; ++i)
        {
            if (M - arr[i].catfood >= 0)
            {
                tot += arr[i].cheese * 1.0;   //交换后奶酪tot增加，猫粮减少
                M -= arr[i].catfood;
            }
            else //即猫粮不够换取全部奶酪了，就按比例换
            {
                double bi = M / arr[i].catfood;
                    tot += bi * arr[i].cheese * 1.0;
                    break;  //此时猫粮完了，跳出循环
            }
           
        }
        printf("%.3lf\n", tot);
        tot = 0;//重置tot，防止与下一组数据叠加
    }


    return 0;
}
