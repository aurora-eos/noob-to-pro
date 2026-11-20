/*学生成绩排名
时间限制
512 ms
内存限制
64 MB
总分
100
￼
定义结构体
struct Student {
    char name[16];
    int  score;
};
给定 n 名学生的姓名和成绩，请按成绩从高到低输出所有学生； 成绩相同时，按姓名的字典顺序从小到大输出。
￼
第 1 行一个整数 n（1 ≤ n ≤ 1000）。
接下来 n 行，每行一个字符串 name 和一个整数 score，中间用空格隔开。
• name 仅由大写字母和数字组成，长度不超过 10，且互不相同；
• 0 ≤ score ≤ 100。
￼
输出 n 行，每行为 姓名 成绩，用一个空格隔开，按题目要求排序。
￼
样例 1 输入
3
Amy 90
Bob 95
Cate 90
样例 1 输出
Bob 95
Amy 90
Cate 90
￼
允许使用strcmp库函数*/

#include<stdio.h>
#include<string.h>
int main(void){
   struct Student {
    char name[16];
    int  score;
};
int n;
scanf("%d",&n);
struct Student g[n];
for(int i=0;i<n;i++){
   scanf("%15s %d", g[i].name, &g[i].score);
}
for(int i=0;i<n-1;i++){
   for(int j=i+1;j<n;j++){
      if(g[i].score<g[j].score||((g[i].score==g[j].score)&&(strcmp(g[i].name,g[j].name)>0))){
            struct Student temp;
            temp=g[i];
            g[i]=g[j];
            g[j]=temp;
      }
   }}
   for(int t=0;t<n;t++){
      printf("%s %d\n",g[t].name,g[t].score);
   }
return 0;
   

}
