/*
题目：输入 5 个以空白分隔的字符串，每个最多 79 字节。
输出：按 strcmp 的字典序从小到大输出，每行一个，重复项照常输出。
*/
#include <stdio.h>
#include <string.h>

int main(void) {
    char words[5][80];

    for (int i = 0; i < 5; i++) {
        if (scanf("%79s", words[i]) != 1) return 0;
    }

    for (int i = 0; i < 4; i++) {
        // 每轮把当前最大项移到尾部，下一轮少比较一次。
        for (int j = 0; j < 4 - i; j++) {
            if (strcmp(words[j], words[j + 1]) > 0) {
                // 字符数组需要复制内容，先备份再交换。
                char temp[80];
                strcpy(temp, words[j]);
                strcpy(words[j], words[j + 1]);
                strcpy(words[j + 1], temp);
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        puts(words[i]);
    }
    return 0;
}

/*
示例输入：
pear apple apricot app apple
示例输出：
app
apple
apple
apricot
pear
*/
