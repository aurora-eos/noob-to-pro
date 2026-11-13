/*
题目：输入一个 int 范围内的整数和一个 0 到 9 的数字。忽略符号，输出该数字出现次数。
示例输入：
-202 2
示例输出：
2
*/
#include <stdio.h>
int CountDigit(int number, int digit) {
    if (digit < 0 || digit > 9) return 0;
    // 先扩大类型再取绝对值，避免 INT_MIN 取负溢出。
    long long x = number;
    if (x < 0) x = -x;
    int count = 0;
    // 数值 0 也有一位，至少处理一次。
    do {
        if (x % 10 == digit) count++;
        x /= 10;
    } while (x != 0);
    return count;
}
int main(void) {
    int number, digit;
    if (scanf("%d %d", &number, &digit) != 2) return 0;
    printf("%d\n", CountDigit(number, digit));
    return 0;
}
