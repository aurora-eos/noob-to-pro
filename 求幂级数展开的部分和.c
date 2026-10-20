/*
题目要求：输入x，计算e^x的幂级数展开的部分和，直到最后一项的绝对值小于0.00001，保留4位小数输出。
*/
#include<stdio.h>
#include<math.h>
int main(void){    
double x,m,sum=0,t=1.0;    
int i,n=0;    
scanf("%lf",&x);    
m=1.0;    
while(m>=0.00001){        
sum+=m;        
n++;        
for(i=1;i<=n;i++){            
t*=i;        
}                
m=pow(x,n)/t;        
t=1.0;    
}    
sum+=m;    
printf("%.4f",sum);    
return 0;        
}
/*
运行结果（输入：1.2）
3.3201
*/
