# `switch` 的 `case` 不建作用域，同名变量会撞车

- **日期**：2026-10-19
- **出处**：`03-oj/luogu/intro-2-branch/P2433_elementary_math.c`（一道题里塞了 14 个 `case`）
- **关键词**：switch、case、作用域、重定义、conflicting types、大括号、redefinition

## 现象

一个 `switch` 里，两个 `case` 各自声明了一个叫 `a` 的变量，类型不同：

```c
switch (t)
{
case 1:
    int a = 10;
    printf("%d\n", a);
    break;
case 2:
    double a = 2.5;
    printf("%f\n", a);
    break;
}
```

`gcc -Wall -Wextra` 直接不给过：

```text
case_scope_demo.c: In function 'main':
case_scope_demo.c:14:16: error: conflicting types for 'a'; have 'double'
   14 |         double a = 2.5;
      |                ^
case_scope_demo.c:10:13: note: previous definition of 'a' with type 'int'
   10 |         int a = 10;
      |             ^
case_scope_demo.c:14:16: warning: unused variable 'a' [-Wunused-variable]
[exit code: 1]
```

在 P2433 里一次性撞了四个：`a`、`b`、`r`、`pi`。其中 `pi` 在两边都是 `double`，报的不是 `conflicting types` 而是 `redefinition of 'pi'`——**同名同类型也不行**。

## 原因

`case 1:` 只是一个**标签**（跟 `goto` 的标号是同一类东西），**不是代码块**。

整个 `switch (t) { ... }` 的大括号才是作用域。所有 `case` 的代码全都平铺在这**同一个**作用域里，所以：

```c
case 1: int a = 10;    // 在这个作用域里定义 a
case 2: double a;      // 还是同一个作用域，a 已经存在了 → 冲突
```

**推论**：给每个 `case` 自己加一对 `{ }`，它就变成独立作用域，变量互不相干。

但反过来也有代价——加了括号之后，这个变量就**只活在那一个 `case` 里**了。P2433 里第 13 小题原本图省事，用了第 5 小题声明的 `int v`，加括号之后编译器立刻报 `'v' undeclared`。这其实是好事：它暴露了「跨分支借变量」这种脆弱的写法。

## 教训

**每个 `case` 都加 `{ }`**，养成习惯。

> `case` 是标签不是块，要用变量就自己加花括号。

```c
switch (t)
{
case 1:
{
    int a = 10;
    printf("%d\n", a);
    break;
}
case 2:
{
    double a = 2.5;
    printf("%f\n", a);
    break;
}
}
```

顺带一条：`switch` 只适合「一个变量等于某几个值」的场合。分支一多、或者每个分支里都要算半天，`if / else if` 反而更好读。
