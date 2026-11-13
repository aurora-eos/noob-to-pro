/*
题目：输入整数 n（1 到 6），再输入 n 行、每行 n 个整数。鞍点同时是所在行的最大值和所在列的最小值。
输出：按从上到下、从左到右的顺序输出第一个鞍点的行号和列号（从 0 开始），两者以空格分隔。没有鞍点输出 NO。
*/
#include <stdio.h>
int main(void) {
    int n, a[6][6], found = 0;
    if (scanf("%d", &n) != 1 || n < 1 || n > 6) return 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (scanf("%d", &a[i][j]) != 1) return 0;

    for (int i = 0; i < n && !found; i++) {
        for (int j = 0; j < n && !found; j++) {
            // 先假设当前候选合格。同行更大或同列更小才是反例。
            int flag = 1;
            for (int k = 0; k < n; k++) {
                if (a[i][k] > a[i][j]) {
                    flag = 0;
                    break;
                }
            }
            // 行条件失败即可跳过；通过后固定列下标检查整列。
            if (!flag) continue;
            for (int k = 0; k < n; k++) {
                if (a[k][j] < a[i][j]) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                printf("%d %d\n", i, j);
                found = 1;
            }
        }
    }
    if (!found) printf("NO\n");
    return 0;
}

/*
示例输入：
3
1 2 3
4 5 6
7 8 9
示例输出：
0 2
*/
