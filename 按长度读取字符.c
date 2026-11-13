/*
题目：首行给出 n（0 到 100）。原样输出第二行开始的前 n 个字符，空格和换行均计入，提前到 EOF 时输出已读部分。
示例输入：
5
ab cdXYZ
示例输出：
ab cd
*/
#include <stdio.h>

void my_getchar(int n, char *arr);

int main(void) {
    int n;
    if (scanf("%d", &n) != 1 || n < 0 || n > 100) return 0;

    // 丢弃首行剩余字符，把第二行作为正文起点。
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {}

    char arr[101];  // 示例：假设 n 最大为 100
    my_getchar(n, arr);

    printf("%s", arr);
    return 0;
}

void my_getchar(int n, char *arr) {
    int ch;
    int i = 0;

    // 先判断容量，再调用 getchar；用 int 保存 EOF。
    while (i < n && (ch = getchar()) != EOF) {
        arr[i] = ch;
        i++;
    }

    arr[i] = '\0';
}
