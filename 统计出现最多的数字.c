/*
题目：输入正整数 n 及 n 个非负整数。统计所有十进制数位，按升序输出出现次数最多的数字，并列项用空格分隔。
示例输入：
3
10 20 12
示例输出：
0 1 2
*/
#include <stdio.h>
int main(void) {
    int n, x;
    long long t[10] = {0};
    if (scanf("%d", &n) != 1 || n <= 0) return 0;
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &x) != 1 || x < 0) return 0;
        // 用数位做下标；输入 0 时也统计一位。
        do {
            t[x % 10]++;
            x /= 10;
        } while (x > 0);
    }
    long long max = t[0];
    for (int j = 1; j < 10; j++) {
        if (t[j] > max) max = t[j];
    }
    int first = 1;
    for (int m = 0; m < 10; m++) {
        if (t[m] == max) {
            if (!first) printf(" ");
            printf("%d", m);
            first = 0;
        }
    }
    printf("\n");
    return 0;
}
