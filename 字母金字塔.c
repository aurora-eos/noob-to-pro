/*
功能：读入一个大写字母，打印居中的字母金字塔——每行先从A递增输出到当前字母，再从前一个字母递减输出回A。
*/
#include<stdio.h>
int main(void){
    char m;
    scanf("%c",&m);
    for(int i=65;i<=m;i++){
        // 1. 打印空格
        for(int j=0;j<m-i;j++){
            printf(" ");
        }
        // 2. 递增：A 到 i
        for(int j=65;j<=i;j++){
            printf("%c",j);
        }
        // 3. 递减：i-1 到 A
        for(int j=i-1;j>=65;j--){
            printf("%c",j);
        }
        // 4. 不是最后一行才换行
        if(i<m){
            printf("\n");
        }
    }
    return 0;
}
/*
运行结果（输入：E）
    A
   ABA
  ABCBA
 ABCDCBA
ABCDEDCBA
*/
