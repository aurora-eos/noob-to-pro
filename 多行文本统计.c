/*
功能：统计 n 行文本中的英文字母总数、单词数和最长单词长度。单词由连续的英文字母组成。
*/
#include <stdio.h>
int main(void) {
    int n, w = 0, q = 0, m = 0, len = 0;
    if (scanf("%d", &n) != 1 || n < 0) return 0;
    int c;
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
