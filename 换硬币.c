/*
功能：把输入的金额（单位：分）拆成5分、2分、1分硬币的所有组合（每种硬币至少一枚），按5分硬币从多到少输出每种组合及硬币总数，最后统计组合总数。
*/
#include<stdio.h>
int main(void){    
int a,b,c,m,n,t,p,i,q;    
int total=0;    
int count=0;    
scanf("%d",&m);    
t=m/5;    
for(i=t;i>=1;i--){        
n=m-i*5;        
p=n/2;        
for(q=p;q>=1;q--){            
c=n-q*2;            
a=i;            
b=q;            
total=a+b+c;            
if(a>0&&b>0&&c>0){            
printf("fen5:%d, fen2:%d, fen1:%d, total:%d\n",a,b,c,total);            
count++;}        
}    
}    
printf("count = %d",count);    
return 0;
}
/*
运行结果（输入：13）
fen5:2, fen2:1, fen1:1, total:4
fen5:1, fen2:3, fen1:2, total:6
fen5:1, fen2:2, fen1:4, total:7
fen5:1, fen2:1, fen1:6, total:8
count = 4
*/
