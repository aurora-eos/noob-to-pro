/*
题目：输入由整数和 +、-、*、/ 组成的表达式，以 = 结束。运算符和整数之间可以有空白。
输出：严格从左到右计算，输出两位小数。除数为 0 时输出 ERROR。
*/
#include <stdio.h>

int main(void) {
    int num;
    char op = 0;
    double result;

    if (scanf("%d", &num) != 1) return 0;
    result = num;

    // %c 前的空格会跳过输入里的空白；遇到等号时无需再读整数。
    while (scanf(" %c", &op) == 1 && op != '=') {
        scanf("%d", &num);

        if (op == '+') {
            result += num;
        } else if (op == '-') {
            result -= num;
        } else if (op == '*') {
            result *= num;
        } else if (op == '/') {
            if (num == 0) {
                printf("ERROR");
                return 0;
            }
            // result 是 double，因此这里保留小数部分。
            result /= num;
        } else {
            printf("ERROR");
            return 0;
        }
    }

    if (op != '=') return 0;
    printf("%.2f", result);
    return 0;
}

/*
示例输入：
2 + 3 * 4 =
示例输出：
20.00
*/
