#include<stdio.h>
#include <algorithm>
using namespace std;
// 由图可见，这层楼中间是走廊，两侧各有200个房间，编号如上图。

// 最近，丁爸信奥培训中心做了内部机构的调整，需要把一些桌子从一个房间搬到另外的房间。因为走廊很窄，但是桌子很大，所以同一段走廊每次只能通过一个桌子。
// 假设不论远近，每趟搬桌子都需要10分钟。同时，当你从房间i搬桌子到房间j的过程中，房间i到房间j之间的走廊都被占用，也就是说，在每个10分钟内，不能有多个任务共享同一段走廊。

// 现在，丁爸想知道：要完成所有的搬运任务，最少需要多少时间？

// 输入包含T组测试用例。
// 每组测试用例首先是一个正整数N（1<=N<=200），表示需要搬运的桌子数量。
// 接下来N行，每行包含2个正整数s和t,表示需要将一个桌子从房间s搬到房间t。
int main()
{int T;
scanf("%d",&T);
for(int h=0;h<T;++h){
int N;
scanf("%d",&N);    //总时间，即重叠部分最多的那部分，他每重叠一次，则必须多跑一趟，所以只需要统计重复最多
int s,t;
int arr[250]={0};
for(int i=0;i<N;i++){
    scanf("%d %d",&s,&t);
s=(s+1)/2;t=(t+1)/2;  //使面对面的房间进入数组arr的同一位置
if(s>t){
    swap(s,t);    //s不是一定比t小，使s比t小，方便后面数组填入
}
for(int k=s;k<=t;++k){
    arr[k]++;  //经过一次，对应数组位置（走廊被进过次数）加一
}
}
int max=-2e9;
for(int i=1;i<=200;++i){
    if(max<arr[i])
    max=arr[i];
}
printf("%d\n",max*10);







}


return 0;
}









