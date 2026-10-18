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
