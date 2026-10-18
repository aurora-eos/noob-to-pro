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
