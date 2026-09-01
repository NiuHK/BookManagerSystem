# BookManagerSystem

一个使用 C++ 编写的图书管理系统，源于学校创新实践周项目。

仓库保留了两套独立实现，分别放在两个分支中：

| 分支 | 实现方式 | 说明 |
| --- | --- | --- |
| [`main`](https://github.com/NiuHK/BookManagerSystem/tree/main) | 类 / 面向对象 | 使用 `LibrarySystem`、`Reader` 等类组织图书与读者功能 |
| [`NoClass`](https://github.com/NiuHK/BookManagerSystem/tree/NoClass) | 结构体 / 非类 | 使用结构体和多文件模块组织功能，并通过文本文件保存数据 |

## 切换分支

```bash
# 类实现
git switch main

# 非类实现
git switch NoClass
```

两个分支保留各自原有的提交历史，可根据需要分别查看和使用。
