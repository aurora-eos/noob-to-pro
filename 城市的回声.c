/*
题目：输入一个可用 long long 表示的非负整数。输出十进制各位数字之和。
示例输入：
9876543210
示例输出：
45
*/
#include <stdio.h>
int main(void) {
    long long n;
    int sum = 0;
    if (scanf("%lld", &n) != 1 || n < 0) return 0;
    // %lld 对应 long long；每次取最低位后用整除去掉它。
    do {
        sum += (int)(n % 10);
        n /= 10;
    } while (n > 0);
    printf("%d\n", sum);
    return 0;
}
