/*
题目：输入一个最多 499 字节的单词。输出英文字母 a、e、i、o、u 的出现总次数，忽略大小写。
示例输入：
OpenAI
示例输出：
4
*/
#include <stdio.h>
int main(void) {
    char a[500];
    if (scanf("%499s", a) != 1) return 1;
    int i = 0;
    while (a[i] != '\0') i++;
    int b = 0;
    // 只访问有效字符，字符串结束符不计入。
    for (int j = 0; j < i; j++) {
        if (a[j]=='a'||a[j]=='e'||a[j]=='i'||a[j]=='o'||a[j]=='u'||
            a[j]=='A'||a[j]=='E'||a[j]=='I'||a[j]=='O'||a[j]=='U') b++;
    }
    printf("%d\n", b);
    return 0;
}
