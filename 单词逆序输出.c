/*
功能：读取以空白分隔的单词，按相反顺序输出。
*/
#include <stdio.h>

int main(void) {
    char a[100][100];
    int i = 0;

    while (i < 100 && scanf("%99s", a[i]) == 1) {
        i++;
    }

    for (int j = i - 1; j >= 0; j--) {
        printf("%s", a[j]);
        if (j != 0) {
            printf(" ");
        }
    }

    return 0;
}

/*
示例输入：
one   two three
示例输出：
three two one
*/
