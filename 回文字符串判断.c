/*
题目：输入一行最多 98 字节的字符串，保留空格并区分大小写。输出 Yes 或 No。
示例输入：
abba
示例输出：
Yes
*/
#include <stdio.h>
#include <string.h>

int palindrome(char *s);

int main(void) {
    char s[100];
    if (fgets(s, sizeof s, stdin) == NULL) return 0;
    s[strcspn(s, "\n")] = '\0';

    if (palindrome(s) == 1) {
        printf("Yes");
    } else {
        printf("No");
    }

    return 0;
}

int palindrome(char *s) {
    int len = 0;

    while (s[len] != '\0') {
        len++;
    }

    // 每对字符只比较一次，双端下标相遇后结束。
    for (int i = 0; i < len - 1 - i; i++) {
        if (s[i] != s[len - 1 - i]) {
            return 0;
        }
    }

    return 1;
}
