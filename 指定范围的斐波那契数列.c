/*
功能：读入 m、n、t（1 ≤ t ≤ 46），先输出第 t 个斐波那契数，再输出闭区间 [m, n] 内的所有斐波那契数（以空格分隔）；若区间内没有斐波那契数，则输出 "No Fibonacci number"。
*/
#include <stdio.h>
int fib( int n );
void PrintFN( int m, int n );
int main(void){
    int m, n, t;
    if (scanf("%d %d %d", &m, &n, &t) != 3 || t < 1 || t > 46) return 0;
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
    // 区间上界可达到 INT_MAX，下一项需要更宽的整数类型。
    long long a = 1, b = 1, c = 1;
    int first = 1;
    while (c <= n){
        if (c >= m){
            if (!first) printf(" ");
            printf("%lld", c);
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
