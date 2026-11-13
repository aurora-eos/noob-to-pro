/*
功能：找出第一个所在行最大、所在列最小的元素（下标从 0 开始），没有则输出 NO。矩阵阶数为 1 到 6。
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
            int flag = 1;
            for (int k = 0; k < n; k++) {
                if (a[i][k] > a[i][j]) {
                    flag = 0;
                    break;
                }
            }
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
