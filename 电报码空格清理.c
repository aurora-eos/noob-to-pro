/*
题目：输入一行最多 500 字节的文本。去掉首尾普通空格，把词间连续的普通空格压缩为一个。
输出：输出处理后的文本并追加一个英文句号。空行或全空格行输出一个句号。
*/
#include <stdio.h>
int main(void) {
    char a[502];
    if (fgets(a, sizeof(a), stdin) == NULL) return 0;
    int i = 0;
    while (a[i] != '\0') i++;

    int t = 0;
    while (a[t] == ' ') t++;

    // i 是有效区间的右端（不包含），顺带去掉 fgets 读入的换行。
    while (i > t && (a[i-1] == ' ' || a[i-1] == '\n'))
        i--;

    for (int j = t; j < i; j++) {
        // 区间内的空格只输出一串连续空格中的第一个。
        if (j > t && a[j] == ' ' && a[j-1] == ' ')
            continue;
        putchar(a[j]);
    }
    putchar('.');
    return 0;
}

/*
示例输入：
  HELLO   WORLD  
示例输出：
HELLO WORLD.
*/
