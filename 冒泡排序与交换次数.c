/*
题目：输入 n（1 至 1000）和 n 个整数。第一行输出升序序列，第二行输出实际交换次数。
示例输入：
4
4 3 2 1
示例输出：
1 2 3 4
6
*/
#include <stdio.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1 || n < 1 || n > 1000) return 0;

    int a[1000];
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1) return 0;
    }

    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                // 仅在真正交换时计数，相等元素不交换。
                count++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n%d\n", count);

    return 0;
}
