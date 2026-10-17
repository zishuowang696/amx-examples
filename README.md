# amx-examples

> **Ambiorix (AMX) / libamxc 的可运行示例。** 对应博客系列《AMX 原理》。
> 所有示例都**实际编译并运行过**。

## 这是什么
[Ambiorix](https://gitlab.com/prpl-foundation/components/ambiorix/ambiorix)（AMX）是 prplOS 的核心框架。
它的基础库 `libamxc` 提供 C 的通用容器：链表、哈希、动态字符串、Variant、数组、集合。

这个仓库把"怎么用"做成**能跑的最小例子**——因为官方文档偏 API 参考，缺"上手"。

## 快速开始
```bash
./build.sh
```

它会：
1. 克隆并编译 `libamxc`（到 `_libamxc/`）；
2. 编译 `libamxc/examples.c`；
3. 运行。

也可以复用已有源码：
```bash
AMXC_DIR=/path/to/libamxc ./build.sh
```

## 示例（`libamxc/examples.c`）
1. `llist` 双向链表
2. `htable` 哈希表
3. `string` 动态字符串
4. `variant` 通用类型
5. `array` 动态数组
6. `set` 字符串集合

## 依赖
- Linux（x86_64/arm64）、`gcc`/`clang`、`make`、`git`
- `libamxc` 本身是纯 C，**不需要 C++ 运行库**（只依赖 libc）

## 相关文章
- 系列总纲：[AMX 原理（1）](https://embedai.com.cn/posts/amx-principles-1-container-bus-datamodel)
- 数据模型：[AMX 原理（2）](https://embedai.com.cn/posts/amx-principles-2-datamodel)
- **本文示例讲解**：[AMX 原理（3）libamxc 实战](https://embedai.com.cn/posts/amx-libamxc-examples)
- 心路：[我找了 C 的容器很多年](https://embedai.com.cn/posts/why-i-searched-for-a-c-container)

## 许可
MIT（示例代码）。
`libamxc` 本身是 **BSD-2-Clause-Patent**（见其仓库）。
