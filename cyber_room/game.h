#ifndef GAME_H
#define GAME_H

#include "level.h"

/* 一局游戏的全部状态 */
typedef struct {
    const Level *lv;   /* 指向关卡数据，游戏过程中只读 */

    int pr, pc;        /* 玩家当前所在的行、列 */
    int actions;       /* 已经消耗的行动次数 ACTIONS */

    int clue_found;    /* CLUE_FOUND：是否通过 inspect 取得了开门密码 */
    int key_taken;     /* KEY_TAKEN：是否通过 take 取得了钥匙 */
    int door_opened;   /* DOOR_OPENED：门是否已经打开 */

    int escaped;       /* 是否已经逃脱成功 */
    int finished;      /* 是否已经得到最终结果（逃脱或失败），是的话后面命令都不用执行了 */
} Game;

/* 游戏开始：玩家站在 @，行动数为 0，什么都没有取得 */
void game_init(Game *g, const Level *lv);

/* 执行脚本里的一行命令。line_no 只是用来打印提示的。 */
void game_run_command(Game *g, const char *line, int line_no);

/* 返回最终结果字符串："ESCAPED" 或 "FAILED" */
const char *game_result(const Game *g);

#endif
