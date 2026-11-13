/*
题目：输入两个各最多 19 字节的单词，输出拼接结果。
示例输入：
hello world
示例输出：
helloworld
*/
#include <stdio.h>

char *my_strcat(char *str1, char *str2) {
    char *start = str1;

    while (*str1 != '\0') {
        str1++;
    }

    while (*str2 != '\0') {
        *str1 = *str2;
        str1++;
        str2++;
    }

    *str1 = '\0';
    return start;
}

int main(void) {
    // 目标需容纳两个单词和一个结束符。
    char str1[39];
    char str2[20];

    if (scanf("%19s %19s", str1, str2) != 2) return 0;
    printf("%s\n", my_strcat(str1, str2));

    return 0;
}
