#ifndef LEVEL_H
#define LEVEL_H

/* 题目规定的范围：行数 3~20，列数 3~40 */
#define MAX_ROWS 20
#define MAX_COLS 40

/* 关卡数据 */
typedef struct {
    int rows;                        /* 地图行数 */
    int cols;                        /* 地图列数 */
    int turns;                       /* 最大行动次数 TURNS */
    char map[MAX_ROWS][MAX_COLS + 1];/* 地图，每个字符串以 '\0' 结尾，方便直接打印 */

    /*
     * 只有下面这两个坐标是游戏逻辑一定要用到的，读关卡时顺便记下来：
     *   @ 是玩家的出发位置；
     *   D 的位置用来算"有没有站在门的上下左右相邻格"。
     * 其余特殊格（C、K、E）判断时直接看玩家脚下那一格的字符就行，
     * 不需要单独记坐标，所以这里就不存了。
     */
    int start_r, start_c;            /* @ 玩家起点 */
    int door_r,  door_c;             /* D 密码门 */
} Level;

/*
 * 读取并检查关卡文件。
 * 成功返回 1，失败返回 0（同时把出错原因用中文打印到终端）。
 */
int level_load(const char *path, Level *lv);

#endif
