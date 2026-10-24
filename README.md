# C 语言学习记录

2026 年 9 月开始学 C 语言。这个仓库放我的练习、作业、刷题和笔记。

## 目录

| 目录 | 内容 | 状态 |
|---|---|---|
| [`01-textbook/`](01-textbook/) | 教材《C程序设计》的课后练习 | 进行中 |
| [`02-homework/`](02-homework/) | 课程作业 | 待开始 |
| [`03-oj/`](03-oj/) | 在线判题（洛谷、PTA） | 进行中 |
| [`04-projects/`](04-projects/) | 自己做的小玩意儿 | 进行中 |
| [`05-notes/`](05-notes/) | 学习笔记 | 进行中 |
| [`scratch/`](scratch/) | 随手试的零散代码 | — |
| [`templates/`](templates/) | 新建文件时套用的模板 | — |

## 命名约定

- **文件名说明「程序做什么」**，不写页码和题号
- 出处、日期、要点写在文件开头的注释里（模板见 [`templates/c-file-header.txt`](templates/c-file-header.txt)）
- 同一个程序的多个版本用 `v1_` `v2_` `v3_` 前缀
- 刷题文件用题目编号开头，如 `P1001_a_plus_b.c`

## 不提交的内容

`.gitignore` 已排除：`*.exe`、`*.o`、`*.i`、`*.s`、`.vscode/`、`tempCodeRunnerFile.*`

## 怎么编译

环境：MSYS2 UCRT64 的 gcc

```
gcc prime_check.c -Wall -Wextra -g -o prime_check.exe
```

在 VS Code 里的三个常用操作：

| 快捷键 | 作用 |
|---|---|
| `Ctrl+Alt+N` | Code Runner 直接运行当前文件 |
| `F9` → `F5` | 打断点后调试，`F10` 单步 |
| `Shift+Alt+F` | 格式化代码 |
