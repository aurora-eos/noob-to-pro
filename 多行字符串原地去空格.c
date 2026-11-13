/*
题目：逐行读取最多 998 字节的文本。遇空行结束，删除每行普通空格，输出行之间用换行分隔。
示例输入：
a b
 c  d 

ignored
示例输出：
ab
cd
*/
#include <stdio.h>

char *delete_space(char *str) {
    char *p = str;  // 读指针
    char *q = str;  // 写指针

    while (*p != '\0' && *p != '\n') {
        if (*p != ' ') {
            // 写指针停在新字符串末尾，必须补结束符。
    *q = *p;
            q++;
        }
        p++;
    }

    *q = '\0';
    return str;
}

int main(void) {
    char line[1000];
    int first = 1;

    // 每次处理一行，复用同一个缓冲区。
    while (fgets(line, sizeof line, stdin) && line[0] != '\n') {
        if (!first) putchar('\n');
        fputs(delete_space(line), stdout);
        first = 0;
    }
    return 0;
}
