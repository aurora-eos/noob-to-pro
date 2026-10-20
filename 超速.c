/*
功能：读入车速和限速，判断超速情况并输出处罚结果：超速比例不低于50%吊销驾照，不低于10%罚款200，否则输出OK。
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
