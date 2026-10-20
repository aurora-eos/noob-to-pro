/*
题目要求：输入车速和限速。若超速比例不低于50%，输出"Exceed X%. License Revoked"；若不低于10%，输出"Exceed X%. Ticket 200"；否则输出"OK"（X为超速百分比取整）。
*/
#include <stdio.h>

int main() {
    double speed, limit;

    scanf("%lf%lf", &speed, &limit);

    if (speed >= 15 * limit / 10) {
        printf("Exceed %.0lf%%. License Revoked", (speed / limit - 1) * 100);
    } else if (speed >= 11 * limit / 10) {
        printf("Exceed %.0lf%%. Ticket 200", (speed / limit - 1) * 100);
    } else
        printf("OK");

    return 0;
}
/*
运行结果（输入：120 100）
Exceed 20%. Ticket 200
*/
