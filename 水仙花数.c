/*
题目要求：输入正整数N，输出所有N位水仙花数（各位数字的N次幂之和等于它本身的数），每个数占一行。
*/
#include<stdio.h>
#include<math.h>
int main(void){    
int s,e,N,i,temp,sum;    
sum=0;    
scanf("%d",&N);    
s=pow(10,N-1);    
e=pow(10,N);    
for(i=s;i<=e;i++){        
temp=i;    
while(temp>0){        
int a=temp%10;        
sum+=pow(a,N);         
temp=temp/10;       
}        
if(sum==i){            
printf("%d\n",sum);        
}        
sum=0;    
}    
return 0;
    }
/*
运行结果（输入：3）
153
370
371
407
*/
