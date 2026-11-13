/*
题目：输入 n（0 到 100）和 n 个整数，输出所有奇数的和。没有奇数时输出 0。
示例输入：
5
-3 2 7 -4 0
示例输出：
4
*/
#include <stdio.h>

static long long OddSum(const int list[], int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        // 负奇数的余数可能是 -1，因此用非零判断奇数。
        if (list[i] % 2 != 0) sum += list[i];
    }
    return sum;
}

int main(void) {
    int n, list[100];
    if (scanf("%d", &n) != 1 || n < 0 || n > 100) return 0;
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &list[i]) != 1) return 0;
    }
    printf("%lld\n", OddSum(list, n));
    return 0;
}
