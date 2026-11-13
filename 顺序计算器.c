/*
功能：读取以等号结束的整数表达式，从左到右运算，结果保留两位小数。除以零时输出 ERROR。
*/
#include <stdio.h>

int main(void) {
    int num;
    char op = 0;
    double result;

    if (scanf("%d", &num) != 1) return 0;
    result = num;

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
