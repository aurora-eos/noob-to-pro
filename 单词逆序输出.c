/*
题目：输入由空白分隔的单词，最多 100 个，每个最多 99 字节。
输出：按逆序输出所有单词，词间一个空格，末尾无空格。
*/
#include <stdio.h>

int main(void) {
    char a[100][100];
    int i = 0;

    // 先检查行数上限；%99s 为字符串结尾的空字符留出一位。
    while (i < 100 && scanf("%99s", a[i]) == 1) {
        i++;
    }

    // i 是已读单词数，最后一个有效下标是 i - 1。
    for (int j = i - 1; j >= 0; j--) {
        printf("%s", a[j]);
        if (j != 0) {
            printf(" ");
        }
    }

    return 0;
}

/*
示例输入：
one   two three
示例输出：
three two one
*/
