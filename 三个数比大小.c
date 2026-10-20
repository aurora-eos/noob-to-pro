/*
题目要求：输入三个整数，从小到大排序后输出，数字之间用"->"连接。
*/
#include <stdio.h>

int main() {
    int a, b, c;

    int temp;
    scanf("%d%d%d", &a, &b, &c);

    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }

    if (a > c) {
        temp = a;
        a = c;
        c = temp;
    }

    if (b > c) {
        temp = b;
        b = c;
        c = temp;
    }

    printf("%d->%d->%d", a, b, c);

    return 0;
}
/*
运行结果（输入：5 2 8）
2->5->8
*/
