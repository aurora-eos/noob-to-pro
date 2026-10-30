/*
功能：读入 m、n、t，先输出第 t 个斐波那契数，再输出闭区间 [m, n] 内的所有斐波那契数（以空格分隔）；若区间内没有斐波那契数，则输出 "No Fibonacci number"。
*/
#include <stdio.h>
int fib( int n );
void PrintFN( int m, int n );
int main(void){
    int m, n, t;
    scanf("%d %d %d", &m, &n, &t);
    printf("%d\n", fib(t));
    PrintFN(m, n);
    return 0;
}
int fib( int n ){
    if (n <= 2) return 1;
    int a = 1, b = 1, c = 1;
    for (int i = 3; i <= n; i++){
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}
void PrintFN( int m, int n ){
    int a = 1, b = 1, c = 1;
    int first = 1;
    while (c <= n){
        if (c >= m){
            if (!first) printf(" ");
            printf("%d", c);
            first = 0;
        }
        c = a + b;
        a = b;
        b = c;
    }
    if (first) printf("No Fibonacci number");
    printf("\n");
}
/*
运行结果（输入：20 100 7）
13
21 34 55 89
*/
