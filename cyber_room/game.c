#include "game.h"

#include <stdio.h>
#include <stdlib.h>   /* abs */
#include <string.h>

void game_init(Game *g, const Level *lv)
{
    g->lv = lv;
    g->pr = lv->start_r;
    g->pc = lv->start_c;
    g->actions = 0;
    g->clue_found = 0;
    g->key_taken = 0;
    g->door_opened = 0;
    g->escaped = 0;
    g->finished = 0;
}

const char *game_result(const Game *g)
{
    return g->escaped ? "ESCAPED" : "FAILED";
}

/*
 * 每消耗一次行动之后都要调用这个函数检查游戏是否结束。
 * just_escaped 表示"刚刚这一步是走进出口"，这种情况优先判定逃脱成功。
 */
static void check_after_action(Game *g, int just_escaped)
{
    if (just_escaped) {
        g->escaped = 1;
        g->finished = 1;
        printf("  -> 走进出口，逃脱成功！\n");
        return;
    }
    if (g->actions >= g->lv->turns) {
        g->finished = 1;
        printf("  -> 已用行动达到上限 %d 次，逃脱失败。\n", g->lv->turns);
    }
}

/*
 * 判断 (r, c) 这一格玩家能不能走进去。
 *   越界 或 墙 '#'            -> 不能进
 *   门 'D' 还没打开           -> 不能进
 *   出口 'E' 门还没打开       -> 不能进
 */
static int can_enter(const Game *g, int r, int c)
{
    char ch;

    if (r < 0 || r >= g->lv->rows || c < 0 || c >= g->lv->cols) {
        return 0;
    }

    ch = g->lv->map[r][c];

    if (ch == '#') {
        return 0;
    }
    if (ch == 'D' && !g->door_opened) {
        return 0;
    }
    if (ch == 'E' && !g->door_opened) {
        return 0;
    }

    return 1;
}

/* ---------- move ---------- */
static void do_move(Game *g, int dr, int dc)
{
    int nr = g->pr + dr;
    int nc = g->pc + dc;

    if (!can_enter(g, nr, nc)) {
        printf("  移动失败（越界、撞墙，或者门还没打开），不消耗行动次数。\n");
        return;
    }

    g->pr = nr;
    g->pc = nc;
    g->actions++;
    printf("  移动到 (%d, %d)，已消耗行动 %d 次。\n", nr, nc, g->actions);

    /* 如果走进的是出口格，就优先判定逃脱 */
    check_after_action(g, g->lv->map[nr][nc] == 'E');
}

/* ---------- inspect ---------- */
static void do_inspect(Game *g)
{
    if (g->lv->map[g->pr][g->pc] != 'C') {
        printf("  调查失败：当前不在线索格 C 上，不消耗行动次数。\n");
        return;
    }
    if (g->clue_found) {
        printf("  调查失败：线索已经调查过了，不消耗行动次数。\n");
        return;
    }

    g->clue_found = 1;
    g->actions++;
    printf("  调查线索成功，取得开门密码！已消耗行动 %d 次。\n", g->actions);
    check_after_action(g, 0);
}

/* ---------- take ---------- */
static void do_take(Game *g)
{
    if (g->lv->map[g->pr][g->pc] != 'K') {
        printf("  拾取失败：当前不在钥匙格 K 上，不消耗行动次数。\n");
        return;
    }
    if (g->key_taken) {
        printf("  拾取失败：钥匙已经拿过了，不消耗行动次数。\n");
        return;
    }

    g->key_taken = 1;
    g->actions++;
    printf("  拾取钥匙成功！已消耗行动 %d 次。\n", g->actions);
    check_after_action(g, 0);
}

/* ---------- open ---------- */
static void do_open(Game *g)
{
    int dist;   /* 玩家到门的曼哈顿距离，等于 1 就说明站在上下左右相邻格 */

    if (g->door_opened) {
        printf("  开门失败：门已经打开了，不消耗行动次数。\n");
        return;
    }
    if (!g->clue_found) {
        printf("  开门失败：还没有取得密码（要先在 C 格执行 inspect），不消耗行动次数。\n");
        return;
    }
    if (!g->key_taken) {
        printf("  开门失败：还没有取得钥匙（要先在 K 格执行 take），不消耗行动次数。\n");
        return;
    }

    dist = abs(g->pr - g->lv->door_r) + abs(g->pc - g->lv->door_c);
    if (dist != 1) {
        printf("  开门失败：没有站在门 D 的上下左右相邻格，不消耗行动次数。\n");
        return;
    }

    g->door_opened = 1;
    g->actions++;
    printf("  用密码和钥匙打开门成功！已消耗行动 %d 次。\n", g->actions);
    check_after_action(g, 0);
}

void game_run_command(Game *g, const char *line, int line_no)
{
    /* 空行直接忽略 */
    if (line[0] == '\0') {
        return;
    }

    printf("[脚本第 %d 行] %s\n", line_no, line);

    if (strcmp(line, "move up") == 0) {
        do_move(g, -1, 0);
    } else if (strcmp(line, "move down") == 0) {
        do_move(g, 1, 0);
    } else if (strcmp(line, "move left") == 0) {
        do_move(g, 0, -1);
    } else if (strcmp(line, "move right") == 0) {
        do_move(g, 0, 1);
    } else if (strcmp(line, "inspect") == 0) {
        do_inspect(g);
    } else if (strcmp(line, "take") == 0) {
        do_take(g);
    } else if (strcmp(line, "open") == 0) {
        do_open(g);
    } else {
        printf("  无效命令，忽略（不消耗行动次数）。\n");
    }
}
