/*
题目：输入 n（0 到 100）、n 个整数和目标值 x。输出 x 第一次出现的下标（从 0 开始），找不到输出 -1。
示例输入：
5
7 2 7 3 7
7
示例输出：
0
*/
#include <stdio.h>

static int search(int list[], int n, int x) {
    for (int i = 0; i < n; i++) {
        // 从左向右扫描，第一次命中就是最小下标。
        if (list[i] == x) return i;
    }
    return -1;
}

int main(void) {
    int n, x, list[100];
    if (scanf("%d", &n) != 1 || n < 0 || n > 100) return 0;
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &list[i]) != 1) return 0;
    }
    if (scanf("%d", &x) != 1) return 0;
    printf("%d\n", search(list, n, x));
    return 0;
}
