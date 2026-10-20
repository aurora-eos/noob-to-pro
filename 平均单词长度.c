/*
题目要求：输入一行英文文本，统计字母总数和单词数，输出平均单词长度（保留2位小数；若没有单词则输出0.00）。
*/
#include <stdio.h>

int main(void) {
    int ch;
    int total_letters = 0;
    int word_count = 0;
    int in_word = 0; // 0表示在空格中，1表示在单词中

    // 读取一行，直到遇到换行符或文件结束
    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (ch != ' ') {
            // 如果不是空格，说明是字母
            total_letters++;
            
            // 如果之前状态是“不在单词中”，说明这是新单词的开始
            if (in_word == 0) {
                word_count++;
                in_word = 1; // 标记现在进入了单词
            }
        } else {
            // 如果是空格，标记现在不在单词中
            in_word = 0;
        }
    }

    // 防止除以0（如果没有单词的情况）
    if (word_count > 0) {
        double average = (double)total_letters / word_count;
        printf("%.2f\n", average);
    } else {
        printf("0.00\n");
    }

    return 0;
}
/*
运行结果（输入：How are you）
3.00
*/
