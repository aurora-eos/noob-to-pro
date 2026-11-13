/*
功能：读入 5 个不含空白的字符串（各最多 79 字节），用冒泡排序按字典序输出。
*/
#include <stdio.h>
#include <string.h>

int main(void) {
    char words[5][80];

    for (int i = 0; i < 5; i++) {
        if (scanf("%79s", words[i]) != 1) return 0;
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4 - i; j++) {
            if (strcmp(words[j], words[j + 1]) > 0) {
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
