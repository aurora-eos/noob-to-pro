/*
题目要求：输入一个大写字母，打印字母金字塔（居中）：每行先输出从A到当前字母的递增序列，再输出从当前字母的前一个字母递减回A的序列。
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
