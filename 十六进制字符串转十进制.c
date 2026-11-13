/*
题目：读取到 #，跳过无关字符，开头有效负号表示负数。保证绝对值不超过 2147483648。输出十进制整数。
示例输入：
-sasd#
示例输出：
-173
*/
#include <stdio.h>
int main(void) {
    int result = 0, sign = 1, started = 0, digit;
    int ch;
    while ((ch = getchar()) != '#' && ch != EOF) {
        if (ch >= '0' && ch <= '9') digit = ch - '0';
        else if (ch >= 'A' && ch <= 'F') digit = ch - 'A' + 10;
        else if (ch >= 'a' && ch <= 'f') digit = ch - 'a' + 10;
        else if (ch == '-' && !started) { sign = -1; started = 1; continue; }
        else continue;
        started = 1;
        result = result * 16 + digit;
    }
    printf("%d\n", sign * result);
    return 0;
}
