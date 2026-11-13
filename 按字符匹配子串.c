/*
题目：输入不超过 9 字节的单词及 ch1、ch2。找到首个 ch1 后，第一行输出从 ch1 到其后第一个 ch2 的片段，缺少 ch2 则输出到末尾。第二行输出从 ch1 起的后缀。缺少 ch1 时仅输出空行。
示例输入：
abcdb b d
示例输出：
bcd
bcdb
*/
#include <stdio.h>

char *match(char *s, char ch1, char ch2) {
    char *p = s;

    while (*p != ch1 && *p != '\0') {
        p++;
    }

    // 保存起点，扫描终点时仍可返回完整后缀。
    char *start = p;
    if (*p == '\0') return start;  // 没找到 ch1

    printf("%c", *p);  // 先输出 ch1
    p++;               // 从下一个字符开始找 ch2

    while (*p != '\0') {
        printf("%c", *p);
        if (*p == ch2) break;
        p++;
    }

    printf("\n");
    return start;
}

int main(void) {
    char s[10], ch1, ch2;
    if (scanf("%9s %c %c", s, &ch1, &ch2) != 3) return 0;
    printf("%s\n", match(s, ch1, ch2));
    return 0;
}
