/*
功能：去掉首尾空格，将词间连续空格压缩成一个，并在末尾输出句号。
*/
#include <stdio.h>
int main(void) {
    char a[502];
    if (fgets(a, sizeof(a), stdin) == NULL) return 0;
    int i = 0;
    while (a[i] != '\0') i++;

    int t = 0;
    while (a[t] == ' ') t++;

    while (i > t && (a[i-1] == ' ' || a[i-1] == '\n'))
        i--;

    for (int j = t; j < i; j++) {
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
