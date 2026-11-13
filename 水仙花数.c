/*
题目：输入位数 N（1 到 9），找出各位数字的 N 次幂之和等于自身的 N 位正整数。
输出：按升序逐行输出符合条件的数。
示例输入：
3
示例输出：
153
370
371
407
*/
#include <stdio.h>

int main(void) {
    int digits;
    if (scanf("%d", &digits) != 1 || digits < 1 || digits > 9) return 0;

    // 每种数字的 N 次幂只算一次，枚举时直接查表。
    long long powers[10];
    for (int digit = 0; digit < 10; digit++) {
        powers[digit] = 1;
        for (int i = 0; i < digits; i++) powers[digit] *= digit;
    }

    int start = 1;
    for (int i = 1; i < digits; i++) start *= 10;
    // 10^N 已经多出一位，使用开区间上界。
    for (int number = start; number < start * 10; number++) {
        long long sum = 0;
        for (int rest = number; rest > 0; rest /= 10) {
            sum += powers[rest % 10];
        }
        if (sum == number) printf("%d\n", number);
    }
    return 0;
}
