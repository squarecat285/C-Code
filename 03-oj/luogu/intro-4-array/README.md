# 【入门4】数组（training/103）

题单地址：https://www.luogu.com.cn/training/103

20 题。主线是一维数组、二维数组、计数/标记数组和二维模拟，正好接上教材第六章。

## 进度

| 题目 | 文件 |
|---|---|
| [P1428 小鱼比可爱](https://www.luogu.com.cn/problem/P1428) | [`P1428_cute_compare.c`](P1428_cute_compare.c) |
| [P1427 小鱼的数字游戏](https://www.luogu.com.cn/problem/P1427) | [`P1427_number_reverse.c`](P1427_number_reverse.c) |
| [P5727 【深基5.例3】冰雹猜想](https://www.luogu.com.cn/problem/P5727) | [`P5727_hailstone.c`](P5727_hailstone.c) |
| [P1047 [NOIP 2005 普及组] 校门外的树](https://www.luogu.com.cn/problem/P1047) | — |
| [P5728 【深基5.例5】旗鼓相当的对手](https://www.luogu.com.cn/problem/P5728) | — |
| [P5729 【深基5.例7】工艺品制作](https://www.luogu.com.cn/problem/P5729) | — |
| [P2550 [AHOI2001] 彩票摇奖](https://www.luogu.com.cn/problem/P2550) | — |
| [P2615 [NOIP 2015 提高组] 神奇的幻方](https://www.luogu.com.cn/problem/P2615) | — |
| [P5730 【深基5.例10】显示屏](https://www.luogu.com.cn/problem/P5730) | — |
| [P1554 [USACO06DEC] 梦中的统计 Dream Counting B](https://www.luogu.com.cn/problem/P1554) | — |
| [P2141 [NOIP 2014 普及组] 珠心算测验](https://www.luogu.com.cn/problem/P2141) | — |
| [P1614 爱与愁的心痛](https://www.luogu.com.cn/problem/P1614) | — |
| [P2911 [USACO08OCT] Bovine Bones G](https://www.luogu.com.cn/problem/P2911) | — |
| [P1161 开灯](https://www.luogu.com.cn/problem/P1161) | — |
| [P5731 【深基5.习6】蛇形方阵](https://www.luogu.com.cn/problem/P5731) | — |
| [P5732 【深基5.习7】杨辉三角](https://www.luogu.com.cn/problem/P5732) | — |
| [P1789 【Mc生存】插火把](https://www.luogu.com.cn/problem/P1789) | — |
| [P1319 压缩技术](https://www.luogu.com.cn/problem/P1319) | — |
| [P1320 压缩技术（续集版）](https://www.luogu.com.cn/problem/P1320) | — |
| [P1205 [USACO1.2] Transformations](https://www.luogu.com.cn/problem/P1205) | — |

> 这张表按题单顺序列全 20 题，当清单用。写好文件就把 `—` 换成文件名。
> 交没交、过没过在洛谷上看，这里不记。

### 这几题各自栽在哪

| 题 | 坑 |
|---|---|
| P1428 | 没有错，而且躲过了最容易踩的那个点：题目特意说「可爱程度**可能一样**」，所以「不如自己可爱」必须是严格小于，判断要写 `>` 而不是 `>=`，你写对了。两个可改的地方：①`int s[n]` 是变长数组（C99），gcc 能过但栈上按 n 分配，n 一大就崩，竞赛里开固定 `int s[105]` 更稳；②`printf("%d ")` 行末多一个空格，洛谷不介意但严格比对的题会介意。**更优解**：`a_i ≤ 10` 是题目给的最大提示，开 `int cnt[11]` 计数数组，答案 = `cnt[0] + … + cnt[a-1]`，再 `cnt[a]++`，O(n²) 直接降到 O(11n) —— 这就是「用值域换时间」 |
| P1427 | 没有错。`for (;;)` + `break` 是「不知道有几个数」的标准写法，`count` 只在非 0 时自增，所以倒着打时 0 自动被排除，不用再判一次。唯一隐患是没检查 `scanf` 返回值：万一数据提前结束（EOF），`s[i]` 保持旧值，`s[i] == 0` 可能永远不成立 → 死循环并越界写栈，这题全靠「保证末尾有一个 0」才没事。更稳的写法：`while (scanf("%d", &x) == 1 && x != 0) s[count++] = x;` |
| P5727 | 没有错。这题数组是绕不过去的（必须倒序输出），你的写法就是标准解。最容易漏的一步是「变成 1 那一步也要存进数组」，漏了就会从 2 开始打、少一个数 —— 你没错。`n ≤ 100` 时最长的链是 `n = 97`（118 步），`s[1000]` 绰绰有余 |

## 这一组要注意的

- **下标从 0 开始，最后一个合法下标是 `n - 1`。** 循环一律写 `i < n`，写成 `i <= n` 就正好越界一格。
- **数组开多大由数据范围决定，不由「感觉够不够」决定。** 开之前先去题面末尾看约束：`L ≤ 10000` 就开 `10005`，100 × 100 的网格就开 `105 × 105`（二维的每一维都留点余量）。
- **越界不报错，这是数组最坑的地方。** 写到栈外面可能当场崩，也可能「看着还是对的」，交到洛谷上就变成莫名其妙的 WA 或 RE —— 而且换台机器结果可能又不一样。看到「本地对、提交错」，先数一遍下标。
- **`a[i][j]` 和 `a[i, j]` 不是一回事。** 后者里的逗号是 C 的逗号运算符，`a[i, j]` 实际等于 `a[j]`，编译器一句话都不会说。
- **`int a[100] = {0};` 是「后面全清零」，函数里的 `int a[100];` 全是栈上垃圾。** 需要整块清零也可以用 `memset(a, 0, sizeof(a))`（要 `<string.h>`）。
- **数组作函数参数会退化成指针**，函数里的 `sizeof(a)` 拿到的是指针大小，不是数组长度 —— 长度必须单独传一个参数。这条在 P1009 的高精度里已经用过了。
- **这一组会反复出现的四个套路**：计数数组（`cnt[x]++`）、标记数组（`vis[x] = 1`）、前缀和（`sum[i] = sum[i-1] + a[i]`）、二维模拟填表（蛇形方阵、杨辉三角、棋盘染色）。
- **数组你不是第一次见。** P1055 按下标取 ISBN 的各位数字、P4414 的排序网络 + `s[i] - 'A'` 查表、P1720 的 `long long s[48]`、P1009 一格一位的高精度、P1980 的 `% 10` 拆位 —— 这些都是数组思想，只是这一组开始把它当成主角。
