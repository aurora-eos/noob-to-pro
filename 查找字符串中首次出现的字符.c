/*
题目：首行给出目标字符，第二行为最多 998 字节的文本。输出首次匹配的下标（从 0 开始），找不到输出 -1。
示例输入：
l
hello world
示例输出：
2
*/
#include <stdio.h>

static int my_find_char(const char *text, int target) {
    // 换行属于输入格式；正文里的空格也参与匹配。
    for (int i = 0; text[i] != '\0' && text[i] != '\n'; i++) {
        if ((unsigned char)text[i] == target) return i;
    }
    return -1;
}

int main(void) {
    char text[1000];
    int target = getchar();
    if (target == EOF || target == '\n') return 0;
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {}
    if (fgets(text, sizeof text, stdin) == NULL) return 0;
    printf("%d\n", my_find_char(text, target));
    return 0;
}
