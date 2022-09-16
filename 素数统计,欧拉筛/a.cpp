#include<stdio.h>
#include <string.h> 

                   //统计N以内的素数数量

    //首先，每个合数都可以由一个素数和另一个数乘积获得
//1：任何一个合数都可以分解成一个素数×一个数

//2：i = m * n，m是最小质因子(素数=质数)

//若n为合数，n= x*y，x是一个质数，且x>m

//则i = mn = mxy = xmy，且my = k.

//则i = x*k，且 x>m
bool arr[100010];   //大数组要在全局定义，,bool只有0和1，而且全局会默认赋值他们为0
int target[100010];  //这里储存素数

int main()
{int C;
scanf("%d",&C);
for(int k=0;k<C;k++){
memset(arr,false,sizeof(arr));//全部为0，表示没有访问过
int N;
scanf("%d",&N);
arr[1]=true;  //1表示素数，先赋值1，不访问
for(int i=2;i<=N;++i){
if(!arr[i])//即arr[i]为0，没有访问过时进入循环,而且能访问进来的都是素数
{
    arr[i]=true;  //进来就是访问了，赋值1    
    target[++target[0]]=i;//存入素数，target[0]来统计
}
for(int j=1;j<=target[0]&&i*target[j]<=N;++j)//j表示第几个素数,所以j小于target[0]，目前已经统计的素数的量
{
arr[target[j]*i]=true; //素数的倍数全部是合数，直接改为1（表示访问过，不让进入）
if(i%target[j]==0)   //如果i是target[j]的倍数，跳出，不然会重复记录素数，因为如果不跳target[j+1]*i==target[j+1]*target[j]*t(t为i/target[j])，保证了每个合数都是由最小质数得到的
break;           //结果还是target[j]的倍数,虽然这次跳出，但是后面i会以target[j]的倍数出现，如果这里访问，后面就是重复标记了
}
}
printf("%d\n",target[0]);  //用于统计的量，每一组数据都要打印后重新归零
memset(target,0,sizeof(target));
}

    return 0;
}
