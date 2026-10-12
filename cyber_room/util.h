#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>

/*
 * 通用小工具：从文件里读一行文本。
 *
 * 读成功返回 1，读到文件末尾返回 0。
 * 函数会自动：
 *   1. 去掉行尾的 '\n' 和 '\r'（这样在 Windows 和 Linux 下都能正常读）；
 *   2. 去掉行首、行尾的空格和制表符。
 * 这样调用者拿到的就是一个"干净"的字符串。
 */
int util_read_line(FILE *fp, char *buf, int size);

#endif
