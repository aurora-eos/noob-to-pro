/*
题目：首行输入正整数 m，第二行输入最多 998 字节的文本。输出从第 m 个字符开始的后缀，超出长度则输出空行。
示例输入：
3
ab cd
示例输出：
 cd
*/
#include <stdio.h>
#include <string.h>

static void strmcpy(const char *source, size_t m, char *target) {
    size_t len = strlen(source);
    // 题目位置从 1 开始。越界时从结束符开始复制。
    size_t start = m <= len ? m - 1 : len;
    size_t i = 0;
    while (source[start + i] != '\0') {
        target[i] = source[start + i];
        i++;
    }
    target[i] = '\0';
}

int main(void) {
    int m, ch;
    char source[1000], target[1000];
    if (scanf("%d", &m) != 1 || m <= 0) return 0;
    while ((ch = getchar()) != '\n' && ch != EOF) {}
    if (!fgets(source, sizeof source, stdin)) return 0;
    source[strcspn(source, "\n")] = '\0';
    strmcpy(source, (size_t)m, target);
    puts(target);
    return 0;
}
