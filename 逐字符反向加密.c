/*
题目：输入一行文本。大写英文字母按 A↔Z、B↔Y 的规则替换，其余字符原样输出。
示例输入：
Hello ABC!
示例输出：
Sello ZYX!
*/
#include <stdio.h>
int main(void) {
    // 使用 int 保存 getchar 的返回值，才能识别 EOF。
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (ch >= 'A' && ch <= 'Z') {
            // 字母距 A 的偏移，就是密文距 Z 的偏移。
            ch = 'Z' - (ch - 'A');
        }
        putchar(ch);
    }
    return 0;
}
