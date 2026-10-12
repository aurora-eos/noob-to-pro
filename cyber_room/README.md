# 赛博密室·零点逃脱

用 C 语言实现的密室小游戏：程序从文件读入关卡和操作脚本，逐条执行命令，
最后把结果写到指定的输出文件里。

## 一、编译与运行

在项目根目录（也就是有 `main.c` 和 `Makefile` 的那一层）执行：

```
make clean
make
./cyber_room --level level.txt --script script.txt --output result.txt
```

`make` 会自动编译根目录下所有 `.c` 文件，生成可执行文件 `cyber_room`。
前两行是编译命令，第三行才是运行命令。

三个文件路径由命令行参数给出，程序里没有写死，可以换成别的路径。

### 中文显示

源码是 UTF-8 编码，而中文 Windows 的控制台默认按 GBK 解释输出的字节，所以中文提示会变成
`鍦板浘锛?` 这样的乱码。为此 `main.c` 在 `main` 函数开头加了一句：

```c
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);   /* 把控制台输出编码改成 UTF-8 */
#endif
```

这一句只改控制台怎么解释输出的字节，不影响程序逻辑，也不影响结果文件——结果文件里只有大写英文和数字。
换到 Linux/macOS 编译时 `#ifdef _WIN32` 会让这一句自动失效，不用担心移植问题。

### 编译器

`Makefile` 按题目给的模板**原样使用 gcc**，一行都没改：

```
CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -pedantic -O2
```

源码本身与编译器无关，同一份代码在 clang 下也做过完整验证（见下面「用 clang 做的检查」）。
想用 clang 编译，在命令行覆盖即可，不用动文件：

```
make CC=clang
```

不用 make 的话就是一条命令：

```
clang -std=c11 -Wall -Wextra -pedantic -O2 -o cyber_room main.c level.c game.c util.c
```

## 二、文件与模块分工

| 文件 | 负责什么 |
| --- | --- |
| `main.c` | 程序入口。解析 `--level` / `--script` / `--output` 三个参数；把关卡、脚本、游戏、输出串起来；最后按固定格式写出结果文件 |
| `level.h` / `level.c` | 关卡模块。读取并检查关卡文件：行数列数范围、TURNS 范围、地图每行的长度、非法字符、`@ C K D E` 是否各出现一次。检查通过后把关卡存进 `Level` 结构体 |
| `game.h` / `game.c` | 游戏模块。保存一局游戏的状态（玩家位置、已用行动数、密码/钥匙/门的三个标志），实现 `move` / `inspect` / `take` / `open` 四个动作的规则，以及每一步之后的结束条件判断 |
| `util.h` / `util.c` | 小工具。`util_read_line` 负责从文件读一行并去掉行尾换行符、首尾空格，还会去掉文件开头的 UTF-8 BOM |
| `Makefile` | 编译脚本，按题目模板用 gcc 编译根目录下所有 `.c` 文件 |
| `level.txt` / `script.txt` | 题目给出的示例关卡和示例脚本，供测试用 |

## 三、程序流程

```
解析命令行参数
      |
      v
level_load() 读取并检查关卡 ---失败---> 打印错误，写出 FAILED 结果，退出
      |
      v
打开脚本文件 ---失败---> 打印错误，写出 FAILED 结果，退出
      |
      v
game_init() 初始化：玩家站在 @，行动数 0，三个标志都是 0
      |
      v
循环：读一行脚本 -> game_run_command() 执行
      每消耗一次行动就检查：刚进出口则 ESCAPED；否则行动数用满则 FAILED
      已经得到最终结果就立刻停止，后面的命令不再执行
      |
      v
脚本读完还没逃脱 -> FAILED
      |
      v
按固定格式写出结果文件
```

## 四、规则实现要点

* **行动次数只在"成功行动"时才 +1**。移动撞墙、移动到地图外、门没打开就想进门、
  在非 `C` 格调查、重复调查、在非 `K` 格拾取、重复拾取、密码或钥匙没拿全就开门、
  站得不够近就开门、重复开门，全都只是打印一条提示，不改变任何状态。
* **密码只是一个状态**。只有在 `C` 格执行成功的 `inspect` 才会把 `CLUE_FOUND` 置 1，
  仅仅是路过 `C` 格不算。
* **门没打开时 `D` 和 `E` 都不能进入**。门打开以后才能走进 `D`，走进 `E` 就立刻判定逃脱。
* **结束条件有优先级**：某一步刚好走进出口时，即使这一步正好用满了行动次数，也算
  `ESCAPED`；其余情况行动次数达到 `TURNS` 就判 `FAILED`。
* **空行和不认识的命令**只会在终端打印提示，不改变状态、不消耗次数，程序继续读下一行。
  命令大小写严格匹配，例如 `Move right` 会被当作无效命令。
* **结果文件只包含规定的五行**，全是大写英文和数字，不写地图、日志或中文说明。
  过程提示只输出到终端。

## 五、已经测试过的情况

| 测试 | 期望 | 实测 |
| --- | --- | --- |
| 题目示例，`TURNS 20` | `ESCAPED`，`ACTIONS 11`，三个标志都是 1 | 一致 |
| 题目示例改成 `TURNS 8` | `FAILED`，`ACTIONS 8`，`CLUE_FOUND 1`，`KEY_TAKEN 1`，`DOOR_OPENED 1` | 一致 |
| 脚本提前用完（一直撞墙） | `FAILED`，`ACTIONS 0`，标志全 0 | 一致 |
| 没调查线索就去开门 | 开门失败，不消耗次数；后来补齐后再开才成功 | 一致 |
| 重复 `inspect` / 重复 `take` / 重复 `open` | 全部失败，不消耗次数 | 一致 |
| 空行、`fly up`、`Move right` 等无效命令 | 忽略并提示，不消耗次数 | 一致 |
| 门还没打开就想走进去 | 移动失败，不消耗次数 | 一致 |
| 关卡文件带 UTF-8 BOM | 能正常读取 | 一致 |
| 行数超范围 / 每行长度不对 / 出现非法字符 / 缺 `E` / `TURNS` 为 0 / 缺 `ENDMAP` | 打印出具体原因，退出码 1 | 一致 |

**关于非法关卡**：题目规定 `RESULT` 只能是 `ESCAPED` 或 `FAILED`。所以如果关卡文件本身
不合法，程序会在终端打印出具体是哪一行不合法，同时仍然写出一份格式正确的
`FAILED`（行动次数和三个标志都是 0）的结果文件，并返回退出码 1。

### 用 clang 做的检查

`Makefile` 按题目模板用 gcc，但源码也专门在 clang 下验证过一遍，确保两个编译器都干净：

| 检查 | 结果 |
| --- | --- |
| `clang -std=c11 -Wall -Wextra -pedantic -O2` | 零警告、零错误 |
| 再加上 `-Wshadow -Wstrict-prototypes -Wmissing-prototypes -Wconversion -Wsign-conversion -Wcast-qual -Wwrite-strings -Wundef` | 同样零警告 |
| `clang --analyze`（clang 自带的静态分析器） | 没有发现可疑问题 |
| 上面所有测试用例分别用 gcc 和 clang 编译后再跑一遍 | 两种编译器的结果逐字节一致 |

代码风格上也适配了 clang 的严格检查：

* 每个非 `static` 函数都在对应的头文件里有原型声明，`clang -Wmissing-prototypes`
  和 `-Wstrict-prototypes` 不会报警；
* 只在本文件内部使用的函数一律加 `static`；
* 变量都在函数开头声明并用 `int r, c;` 这种写法，不使用 C99 的
  `for (int i = ...)`；
* 没有隐式类型转换、变量遮蔽（`-Wshadow`）、`char` 与 `int` 比较这类问题，
  所以 `-Wconversion` 和 `-Wsign-conversion` 也是干净的。
