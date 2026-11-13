/*
题目：首行给出非负整数 n，接下来是 n 行文本，每行最多 200 字节。连续的英文字母算一个单词，其他字符均为分隔符。
输出：依次输出英文字母总数、单词数和最长单词长度，每项一行。没有单词时最长长度为 0。
*/
#include <stdio.h>
int main(void) {
    int n, w = 0, q = 0, m = 0, len = 0;
    if (scanf("%d", &n) != 1 || n < 0) return 0;
    int c;
    // 丢弃首行剩余字符，避免把 n 后面的换行读成正文。
    while ((c = getchar()) != '\n' && c != EOF) {}

    char a[202];
    for (int t = 0; t < n; t++) {
        if (fgets(a, sizeof a, stdin) == NULL) break;
        int j = 0;
        while (a[j] != '\0') {
            char c = a[j];
            if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
                q++;
                len++;
            } else {
                if (len > 0) {
                    w++;
                    if (len > m) m = len;
                    len = 0;
                }
            }
            j++;
        }
        // 行尾也要结算，以覆盖最后一行没有换行的输入。
        if (len > 0) {
            w++;
            if (len > m) m = len;
            len = 0;
        }
    }
    printf("%d\n%d\n%d\n", q, w, m);
    return 0;
}

/*
示例输入：
3
Hello, C!
a12bc
!!!
示例输出：
9
4
5
*/
