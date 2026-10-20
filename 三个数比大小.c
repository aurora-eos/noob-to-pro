/*
功能：读入三个整数，用两两比较交换的方法从小到大排序，以「a->b->c」的形式输出。
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
