/*今天是星期几
￼
定义枚举
enum Weekday { MON = 1, TUE, WED, THU, FRI, SAT, SUN };
已知 2026 年 1 月 1 日是星期四。输入 2026 年的一个日期（month 月 day 日）， 以及 x 和 y，表示从这一天起再过 x 个星期零 y 天，输出那一天是星期几。
￼
输入一行四个整数 x、y、month、day。
• 0 ≤ x ≤ 13，0 ≤ y ≤ 6
• 2026 年 month 月 day 日是一个合法日期
• 数据保证推算结果仍在 2026 年内
￼
输出一个单词表示星期几，首字母大写，其余小写：
Monday、Tuesday、Wednesday、Thursday、Friday、Saturday、Sunday
￼
样例 1 输入
1 2 1 1
样例 1 输出
Saturday
样例 2 输入
0 3 1 1
样例 2 输出
Sunday*/
#include<stdio.h>
int main(void){
   enum Weekday { MON = 1, TUE, WED, THU, FRI, SAT, SUN };
   int d[12]={31,28,31,30,31,30,31,31,30,31,30,31};
   int x,y,month,day;
   scanf("%d %d %d %d",&x,&y,&month,&day);
   int total=0;
   int i=0;
   total=day-1+y;
   while(i<month-1){
      total+=d[i];
      i++;
   }
   int weekday=THU+(total%7);
   if(weekday>SUN){
      weekday-=7;
   }
   switch(weekday){
      case MON: puts("Monday");
      break;
     case TUE: puts("Tuesday");   break;
      case WED: puts("Wednesday"); break;
      case THU: puts("Thursday");  break;
      case FRI: puts("Friday");    break;
      case SAT: puts("Saturday");  break;
      case SUN: puts("Sunday");    break;
   }
   return 0;
}  
   

   


