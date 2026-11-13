/*
题目：输入 0 到 255 的整数。第一行输出固定 8 位二进制，第二行输出大写十六进制。
示例输入：
13
示例输出：
00001101
D
*/
#include <stdio.h>

int main(void)
{
    unsigned int n;
    if (scanf("%u", &n) != 1 || n > 255) return 0;

    // 从最高位权开始打印，前导零也会输出。
    for (int k = 128; k >= 1; k /= 2) {
        printf("%u", (n / k) % 2);
    }

    printf("\n");
    printf("%X\n", n);

    return 0;
}
