/*
 * 赛博密室·零点逃脱
 *
 * 用法：
 *   ./cyber_room --level level.txt --script script.txt --output result.txt
 *
 * 程序流程：
 *   1. 解析命令行参数，取得三个文件名（文件名不写死在代码里）；
 *   2. 读取并检查关卡文件；
 *   3. 打开脚本文件；
 *   4. 按文件顺序一条一条执行命令，直到逃脱、失败或者脚本读完；
 *   5. 把结果按固定格式写进输出文件。
 */

#include <stdio.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>   /* 只为了用 SetConsoleOutputCP 设置控制台编码 */
#endif

#include "level.h"
#include "game.h"
#include "util.h"

/* 把最终结果写进输出文件（会覆盖原来的内容） */
static int write_result(const char *path, const char *result,
                        int actions, int clue, int key, int door)
{
    FILE *fp = fopen(path, "w");

    if (fp == NULL) {
        fprintf(stderr, "错误：无法创建输出文件 %s\n", path);
        return 0;
    }

    fprintf(fp, "RESULT %s\n", result);
    fprintf(fp, "ACTIONS %d\n", actions);
    fprintf(fp, "CLUE_FOUND %d\n", clue);
    fprintf(fp, "KEY_TAKEN %d\n", key);
    fprintf(fp, "DOOR_OPENED %d\n", door);

    fclose(fp);
    return 1;
}

/* 在终端打印一下地图，只是给人看的，不影响结果文件 */
static void print_map(const Level *lv)
{
    int r;

    printf("地图（%d 行 %d 列，最多 %d 次行动）：\n", lv->rows, lv->cols, lv->turns);
    for (r = 0; r < lv->rows; r++) {
        printf("  %s\n", lv->map[r]);
    }
    printf("\n");
}

static void print_usage(const char *prog)
{
    printf("用法: %s --level 关卡文件 --script 脚本文件 --output 结果文件\n", prog);
}

int main(int argc, char *argv[])
{
    const char *level_path = NULL;
    const char *script_path = NULL;
    const char *output_path = NULL;

    Level lv;
    Game game;
    FILE *sf;
    char line[256];
    int line_no = 0;
    int i;

    /* ---------- 0. 让 Windows 控制台能正确显示中文 ----------
       本文件的源码是 UTF-8 编码，printf 出去的也是 UTF-8 字节。
       但 Windows 控制台默认按 GBK 解释这些字节，中文就变成了乱码。
       把控制台的输出编码改成 UTF-8（65001）之后，中文就能正常显示了。 */
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    /* ---------- 1. 解析命令行参数 ---------- */
    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--level") == 0 && i + 1 < argc) {
            level_path = argv[++i];
        } else if (strcmp(argv[i], "--script") == 0 && i + 1 < argc) {
            script_path = argv[++i];
        } else if (strcmp(argv[i], "--output") == 0 && i + 1 < argc) {
            output_path = argv[++i];
        } else {
            fprintf(stderr, "错误：无法识别的参数 %s\n", argv[i]);
            print_usage(argv[0]);
            return 1;
        }
    }

    if (level_path == NULL || script_path == NULL || output_path == NULL) {
        fprintf(stderr, "错误：--level、--script、--output 三个参数都必须给出。\n");
        print_usage(argv[0]);
        return 1;
    }

    /* ---------- 2. 读取并检查关卡 ---------- */
    if (!level_load(level_path, &lv)) {
        fprintf(stderr, "关卡文件不合法，游戏直接判定为失败。\n");
        /* 就算关卡有问题，也写出一份格式正确的失败结果 */
        write_result(output_path, "FAILED", 0, 0, 0, 0);
        return 1;
    }

    /* ---------- 3. 打开脚本文件 ---------- */
    sf = fopen(script_path, "r");
    if (sf == NULL) {
        fprintf(stderr, "错误：打不开脚本文件 %s\n", script_path);
        write_result(output_path, "FAILED", 0, 0, 0, 0);
        return 1;
    }

    /* ---------- 4. 按顺序执行脚本中的命令 ---------- */
    game_init(&game, &lv);
    print_map(&lv);
    printf("玩家从 (%d, %d) 出发。\n\n", game.pr, game.pc);

    while (!game.finished && util_read_line(sf, line, sizeof(line))) {
        line_no++;
        game_run_command(&game, line, line_no);
    }
    fclose(sf);

    if (!game.escaped) {
        game.finished = 1;
    }

    /* ---------- 5. 输出结果 ---------- */
    printf("\n===== 游戏结束 =====\n");
    printf("RESULT %s\n", game_result(&game));
    printf("ACTIONS %d\n", game.actions);
    printf("CLUE_FOUND %d\n", game.clue_found);
    printf("KEY_TAKEN %d\n", game.key_taken);
    printf("DOOR_OPENED %d\n", game.door_opened);

    write_result(output_path, game_result(&game), game.actions,
                 game.clue_found, game.key_taken, game.door_opened);
    printf("结果已经写入 %s\n", output_path);

    return 0;
}
