/*
题目：输入 n（0 到 10）及 n 个最多 99 字节的单词。输出最长长度，n 为 0 时输出 0。
示例输入：
3
apple pear cat
示例输出：
5
*/
#include <stdio.h>

int max_len(char *s[], int n);

int main(void) {
    int n;
    char str[10][100];
    char *s[10];

    if (scanf("%d", &n) != 1 || n < 0 || n > 10) return 0;

    for (int i = 0; i < n; i++) {
        if (scanf("%99s", str[i]) != 1) return 0;
        // 指针指向二维数组中对应一行的起始位置。
        s[i] = str[i];
    }

    printf("%d\n", max_len(s, n));
    return 0;
}

int max_len(char *s[], int n) {
    int max = 0;

    for (int i = 0; i < n; i++) {
        char *p = s[i];
        int len = 0;

        while (*p != '\0') {
            len++;
            p++;
        }

        if (len > max) {
            max = len;
        }
    }

    return max;
}
