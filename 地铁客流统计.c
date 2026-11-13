/*
题目：对程序内给定的五分钟客流量，输出总和、首次峰值所在分钟和人数，再按降序输出客流量。
示例输入：
（无）
示例输出：
总客流量：65
客流最高峰在第 4 分钟（20 人）
客流从高到低排序：20 15 12 10 8
*/
#include <stdio.h>
#define MINUTES 5

int total_passengers(const int data[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += data[i];
    return sum;
}

int find_peak(const int data[], int size) {
    int max = data[0], idx = 0;
    for (int i = 1; i < size; i++) {
        if (data[i] > max) {
            max = data[i];
            idx = i;
        }
    }
    return idx;
}

void sort_desc(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] > arr[max_idx])
                max_idx = j;
        }
        if (max_idx != i) {
            int temp = arr[i];
            arr[i] = arr[max_idx];
            arr[max_idx] = temp;
        }
    }
}

int main(void) {
    int passengers[MINUTES] = {12, 8, 15, 20, 10};
    int total = total_passengers(passengers, MINUTES);
    int peak = find_peak(passengers, MINUTES);
    printf("总客流量：%d\n", total);
    printf("客流最高峰在第 %d 分钟（%d 人）\n",
           peak + 1, passengers[peak]);

    // 排序会改变下标，须先从原数组取得峰值分钟。
    sort_desc(passengers, MINUTES);
    printf("客流从高到低排序：");
    for (int i = 0; i < MINUTES; i++)
        printf("%s%d", i == 0 ? "" : " ", passengers[i]);
    printf("\n");
    return 0;
}
