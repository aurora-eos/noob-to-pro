/*
题目：输入非负实数 x，且 x 小于 2147483648。分别输出整数部分和小数部分，小数部分保留 6 位。
示例输入：
12.375
示例输出：
12
0.375000
*/
#include <stdio.h>

static void splitfloat(double x, int *intpart, double *fracpart) {
    // 指针参数指向调用者的变量，可以一次带回两个结果。
    *intpart = (int)x;
    *fracpart = x - *intpart;
}

int main(void) {
    double x, fraction;
    int integer;
    if (scanf("%lf", &x) != 1 || !(x >= 0 && x < 2147483648.0)) return 0;
    splitfloat(x, &integer, &fraction);
    printf("%d\n%.6f\n", integer, fraction);
    return 0;
}
