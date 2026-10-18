# 教材练习

《C程序设计》的课后习题。

## 分类

| 目录 | 知识点 | 状态 |
|---|---|---|
| [`basics/`](basics/) | 顺序结构：输出、变量、数据类型、输入输出 | ✅ |
| [`control/`](control/) | 选择结构（`if`）与循环结构（`while` / `for`） | ✅ |

### 第三章课后题（都在 `basics/` 里）

| 文件 | 题目让你算什么 | 练到的 |
|---|---|---|
| [`basics/growth_rate.c`](basics/growth_rate.c) | 年增长率 7%，10 年后比现在增长百分之几 | `pow`、`%%` 打百分号 |
| [`basics/repay_loan.c`](basics/repay_loan.c) | 贷款 30 万、月还 6000、月利率 1%，几个月还清 | `log` 换底公式 |
| [`basics/char_analysis.c`](basics/char_analysis.c) | 同一个变量，`%c` 打是 `a`、`%d` 打是 `97` | `char` 就是小整数 |
| [`basics/encrypt_china.c`](basics/encrypt_china.c) | 每个字母往后挪 4 位，`China` → `Glmre` | `putchar`、字符运算 |
| [`basics/circle.c`](basics/circle.c) | 圆周长、圆面积、球面积、球体积、圆柱体积 | `scanf` 读 double、`%.2f` |

## 以后继续加

按**知识阶段**分目录，不要按书的页码分。学到哪就建哪个：

| 目录 | 对应内容 |
|---|---|
| `array/` | 数组 |
| `function/` | 函数 |
| `pointer/` | 指针 |
| `struct/` | 结构体与共用体 |
| `file/` | 文件操作 |

## 为什么文件名里不写页码

`21P_E5.c` 这种名字过一个月自己就看不懂了。**页码和题号写在每个文件开头的注释里**，文件名只说程序做什么。

对照一下：

| 旧名字 | 新名字 |
|---|---|
| `ONE/14P_6.c` | `control/max_of_three.c` |
| `TWO/19P_E3.c` | `control/leap_year.c` |
| `TWO/21P_E5.c` | `control/prime_check.c` |

信息一点没少，全在注释里：

```c
/*
 * prime_check.c —— 判断一个数是否为素数
 * 来源：《C程序设计》第 21 页 第 5 题（原 TWO/21P_E5.c）
 * 日期：2026-10-13
 * 要点：用 i*i<=n 代替 i<=n 减少循环次数；注意 n<=1 的边界（已修正）
 */
```
