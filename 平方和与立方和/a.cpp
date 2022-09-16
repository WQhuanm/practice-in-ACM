#include<stdio.h>
using namespace std;
int main()
{

int m,n; 
while(scanf("%d %d",&m,&n)==2)
{if(m>n){
    int b=m;m=n;n=b;
}
    int sum1=0,sum2=0;
for(int i=m;i<=n;++i){
    if(i%2!=0)
    sum1+=i*i*i;
    if(i%2==0)
    sum2+=i*i;
}
printf("%d %d\n",sum2,sum1);


}

    return 0;
}