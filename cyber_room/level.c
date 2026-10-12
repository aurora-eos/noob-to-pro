#include "level.h"
#include "util.h"

#include <stdio.h>
#include <string.h>

/* 地图里只允许出现这 7 种字符 */
static int is_valid_map_char(char ch)
{
    return ch == '#' || ch == '.' || ch == '@' || ch == 'C'
        || ch == 'K' || ch == 'D' || ch == 'E';
}

int level_load(const char *path, Level *lv)
{
    FILE *fp;
    char line[256];
    int r, c;
    /* 统计 @ C K D E 各出现了几次 */
    int n_at = 0, n_c = 0, n_k = 0, n_d = 0, n_e = 0;

    fp = fopen(path, "r");
    if (fp == NULL) {
        fprintf(stderr, "错误：打不开关卡文件 %s\n", path);
        return 0;
    }

    /* ---------- 第 1 行：SIZE 行数 列数 ---------- */
    if (!util_read_line(fp, line, sizeof(line))) {
        fprintf(stderr, "错误：关卡文件是空的，缺少 SIZE 行\n");
        fclose(fp);
        return 0;
    }
    if (sscanf(line, "SIZE %d %d", &lv->rows, &lv->cols) != 2) {
        fprintf(stderr, "错误：SIZE 行格式不对，应该写成 SIZE 行数 列数\n");
        fclose(fp);
        return 0;
    }
    if (lv->rows < 3 || lv->rows > MAX_ROWS) {
        fprintf(stderr, "错误：行数必须在 3 ~ %d 之间，实际是 %d\n", MAX_ROWS, lv->rows);
        fclose(fp);
        return 0;
    }
    if (lv->cols < 3 || lv->cols > MAX_COLS) {
        fprintf(stderr, "错误：列数必须在 3 ~ %d 之间，实际是 %d\n", MAX_COLS, lv->cols);
        fclose(fp);
        return 0;
    }

    /* ---------- 第 2 行：TURNS 最大行动次数 ---------- */
    if (!util_read_line(fp, line, sizeof(line)) ||
        sscanf(line, "TURNS %d", &lv->turns) != 1) {
        fprintf(stderr, "错误：TURNS 行格式不对，应该写成 TURNS 最大行动次数\n");
        fclose(fp);
        return 0;
    }
    if (lv->turns < 1 || lv->turns > 100) {
        fprintf(stderr, "错误：TURNS 必须在 1 ~ 100 之间，实际是 %d\n", lv->turns);
        fclose(fp);
        return 0;
    }

    /* ---------- 第 3 行：MAP ---------- */
    if (!util_read_line(fp, line, sizeof(line)) || strcmp(line, "MAP") != 0) {
        fprintf(stderr, "错误：缺少 MAP 这一行\n");
        fclose(fp);
        return 0;
    }

    /* ---------- 接下来 rows 行是地图 ---------- */
    for (r = 0; r < lv->rows; r++) {
        if (!util_read_line(fp, line, sizeof(line))) {
            fprintf(stderr, "错误：地图只有 %d 行，比 SIZE 里写的 %d 行少\n", r, lv->rows);
            fclose(fp);
            return 0;
        }
        if ((int)strlen(line) != lv->cols) {
            fprintf(stderr, "错误：地图第 %d 行有 %d 个字符，应该是 %d 个\n",
                    r + 1, (int)strlen(line), lv->cols);
            fclose(fp);
            return 0;
        }
        for (c = 0; c < lv->cols; c++) {
            char ch = line[c];

            if (!is_valid_map_char(ch)) {
                fprintf(stderr, "错误：地图第 %d 行第 %d 列出现非法字符 '%c'\n",
                        r + 1, c + 1, ch);
                fclose(fp);
                return 0;
            }

            lv->map[r][c] = ch;

            /* 顺便统计五个特殊格子各出现了几次，
               并把游戏逻辑要用到的 @ 和 D 的坐标记下来 */
            if (ch == '@')      { n_at++; lv->start_r = r; lv->start_c = c; }
            else if (ch == 'C') { n_c++; }
            else if (ch == 'K') { n_k++; }
            else if (ch == 'D') { n_d++; lv->door_r = r; lv->door_c = c; }
            else if (ch == 'E') { n_e++; }
        }
        lv->map[r][lv->cols] = '\0';   /* 加上字符串结束符 */
    }

    /* ---------- ENDMAP ---------- */
    if (!util_read_line(fp, line, sizeof(line)) || strcmp(line, "ENDMAP") != 0) {
        fprintf(stderr, "错误：地图后面缺少 ENDMAP 这一行\n");
        fclose(fp);
        return 0;
    }

    fclose(fp);

    /* ---------- 检查 @ C K D E 是否各恰好出现一次 ---------- */
    if (n_at != 1 || n_c != 1 || n_k != 1 || n_d != 1 || n_e != 1) {
        fprintf(stderr,
                "错误：@ C K D E 必须各恰好出现一次（当前 @=%d C=%d K=%d D=%d E=%d）\n",
                n_at, n_c, n_k, n_d, n_e);
        return 0;
    }

    return 1;
}
