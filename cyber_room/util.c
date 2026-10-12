#include "util.h"

#include <string.h>

int util_read_line(FILE *fp, char *buf, int size)
{
    int len;
    int start = 0;

    /* fgets 读取失败说明已经到文件末尾或者出错，直接返回 0 */
    if (fgets(buf, size, fp) == NULL) {
        return 0;
    }

    /* 第零步：文件开头可能有 UTF-8 BOM（3 个字节 EF BB BF），
       有些编辑器保存文本时会自动加上，去掉它才不会影响后面的判断。 */
    if (strlen(buf) >= 3 &&
        (unsigned char)buf[0] == 0xEF &&
        (unsigned char)buf[1] == 0xBB &&
        (unsigned char)buf[2] == 0xBF) {
        memmove(buf, buf + 3, strlen(buf + 3) + 1);
    }

    /* 第一步：去掉行尾的 '\n' 和 '\r' */
    len = (int)strlen(buf);
    while (len > 0 && (buf[len - 1] == '\n' || buf[len - 1] == '\r')) {
        buf[len - 1] = '\0';
        len--;
    }

    /* 第二步：去掉行首的空格和制表符 */
    while (buf[start] == ' ' || buf[start] == '\t') {
        start++;
    }
    if (start > 0) {
        /* 把后面的内容整体往前挪，memmove 可以处理重叠的内存 */
        memmove(buf, buf + start, (size_t)(len - start + 1));
    }

    /* 第三步：去掉行尾的空格和制表符 */
    len = (int)strlen(buf);
    while (len > 0 && (buf[len - 1] == ' ' || buf[len - 1] == '\t')) {
        len--;
        buf[len] = '\0';
    }

    return 1;
}
