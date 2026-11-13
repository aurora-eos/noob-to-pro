/*
题目：首行给出待删除字符，次行输入最多 998 字节的文本。输出删除该字符所有出现位置后的文本。
示例输入：
a
happy new year
示例输出：
hppy new yer
*/
#include <stdio.h>
#include <string.h>

void delchar(char *str, char c) {
    for (int i = 0; str[i] != '\0'; i++) {
        // 跳过命中字符，其余字符按原顺序输出。
        if (str[i] == c) {
            continue;
        }
        printf("%c", str[i]);
    }
}

int main(void) {
    char line[1000];
    int target = getchar();
    if (target == EOF || target == '\n') return 0;
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {}
    if (!fgets(line, sizeof line, stdin)) return 0;
    line[strcspn(line, "\n")] = '\0';
    delchar(line, (char)target);
    return 0;
}
