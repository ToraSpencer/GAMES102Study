## 0. 简介

这里是 GAMES 102 的课程作业网站。

- 课程主页：[GAMES 102](http://staff.ustc.edu.cn/~lgliu/Courses/GAMES102_2020/default.html) 
- 授课老师：[刘利刚](http://staff.ustc.edu.cn/~lgliu) 
- 助教
  - 庄涛 ([ustczt@mail.ustc.edu.cn](mailto:ustczt@mail.ustc.edu.cn))
  - 刘中远 ([zyliu28@mail.ustc.edu.cn](mailto:zyliu28@mail.ustc.edu.cn))
  - 史雨宸 ([syc0412@mail.ustc.edu.cn](mailto:syc0412@mail.ustc.edu.cn))



## 1. 作业标题

1. 函数拟合
2. 神经网络曲线拟合
3. 参数曲线拟合
4. 三次样条函数
5. 曲线细分
6. 极小曲面局部方法
7. 极小曲面全局方法、曲面参数化
8. 实现平面点集 CVT 的 Lloyd 算法
9. 网格简化的 QEM 方法
10. 曲面重建



## 2. 课程资源

### 相关软件 

- Git：[官网](https://git-scm.com/)，[下载链接](https://git-scm.com/download/win) 
- GitHub Desktop：[官网](https://desktop.github.com/)，[下载链接](https://central.github.com/deployments/desktop/desktop/latest/win32)，[官方文档](https://help.github.com/en/desktop) 
- Vistual Studio Community 2019: [官网](https://visualstudio.microsoft.com/zh-hans/vs/) 
- CMake 3.18.2：[官网](https://cmake.org/)，[下载链接](https://github.com/Kitware/CMake/releases/download/v3.16.3/cmake-3.16.3-win64-x64.msi)，[视频教程](https://www.bilibili.com/video/av85644125/)，[官方教程](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)，[官方文档](https://cmake.org/documentation/)，[简易使用教程](softwares/CMake.md) 
- Typora：[官网](https://www.typora.io/)，[下载链接](https://www.typora.io/windows/typora-setup-x64.exe?)，[官方文档](http://support.typora.io/) 

### 辅助资料

- [[菜鸟教程] C 语言教程](https://www.runoob.com/cprogramming/c-tutorial.html) 

- [[菜鸟教程] C++ 教程](https://www.runoob.com/cplusplus/cpp-tutorial.html) 

- [廖雪峰 Git 教程](https://www.liaoxuefeng.com/wiki/896043488029600) 

- [Git 教程 | 菜鸟教程](https://www.runoob.com/git/git-tutorial.html) 

- [中文技术文档的写作规范](https://github.com/ruanyf/document-style-guide) 

  

## 框架说明

我们提供了 Windows 10 下的 C++ 框架（[project](project)），内含各项作业的子项目，同学可以直接使用其完成作业。

同学们亦可根据自己的喜好，用其他语言（如 matlab）完成作业。



## 作业文档

> 文档中可能包含一些数学公式，GitHub 不支持直接显示数学公式，需要额外设置才能正常显示。
>
> 方法如下：
>
> - 网页端查看：Google Chrome 浏览器插件 [MathJax](https://chrome.google.com/webstore/detail/mathjax-plugin-for-github/ioemnmodlmafdkllaclgeombjnmnbima)（需要科学上网 fq），没法科学上网的同学参考 [Crx4Chrome | MathJax](https://www.crx4chrome.com/crx/72309/) 以及 [Chrome 插件离线安装方法](https://chromecj.com/utilities/2015-04/423.html) 
> - 本地查看：使用 Markdown 编辑器 Typora（[下载链接](https://www.typora.io/windows/typora-setup-x64.exe?)），需要手动打开“**内联公式**”功能（Typora 菜单 -> 偏好设置 -> Markdown -> Markdown 扩展语法 -> 勾选“内联公式”）



## 环境要求

- Windows 10

- DirectX 12

- VS 2019 16.7.5+（[下载链接](https://visualstudio.microsoft.com/zh-hans/vs/)）

  > 注意版本，有测试过 16.4.5 版本就不行

- Git（[下载链接](http://www.baidu.com/link?url=w93HUZZENOzPu-A7xAN5UzU0Rnd4gDpZDm5W6hhImQVTIgn9Zfzd33QN4vAt-sWj)）

  > 在 CMake 的过程中需要调用 Git，注意把 git 目录下的文件夹 bin 路径添加到系统环境变量 Path 中，参考[教程](https://www.cnblogs.com/-mrl/p/11246666.html) 

- Github Desktop（[下载链接](https://desktop.github.com/)）

  > 希望同学尽量用 GitHub desktop 来克隆库，由于项目代码经常更新，用 GitHub desktop 方便拉取更新。更新可能导致冲突问题，详细解决方法请自行查询相关资料。

- CMake 3.18.4+（[下载链接](https://cmake.org/download/)，[简单使用方法的视频教程](https://www.bilibili.com/video/BV1Z7411z78n)，[更详细的使用教程](../../softwares/CMake.md)）

- 可选：assimp（[源码链接](https://github.com/assimp/assimp)）



## 常见问题

- 编译时缺失 `atl*` 的话，可以在 vs2019 里选 工具->获取工具和功能->单个组件->搜索 "x64 14.27" 选生成工具，再搜 "atl"，选最下边的“适用于最新 v142 生成工具的 C++ ATL(x86和x64)"
- 如果启动后，弹出窗口过段时间后程序出错，可尝试（依显卡性能而定）
  - 将独显设为默认显卡
  - 把 [Irradiance.hlsl](assets/shaders/Irradiance.hlsl) 第 99 行的 `1024u` 改小试试，如 `256u`，甚至 `1u`，`0u`
  - 把 [PreFilter.hlsl](assets/shaders/PreFilter.hlsl) 第 108 行的 `256u` 改小试试，如 `64u`，甚至 `1u`，`0u` 
- 框架还处于快速开发中，鲁棒性有限，不良操作可能直接导致程序崩溃，有疑惑可联系助教



## 构建方法

### 方法一

此方法完全从源码构建，如果不行请看[方法二](#方法二) 

- 使用 Github Desktop 克隆此库 [GAMES 102](https://github.com/Ubpa/GAMES102)，注意路径应放到**较浅**的位置，如盘符根目录

- 使用 CMake-Gui 构建 vs 2019 项目

  - 注意 where is the source code 是<project 路径>，下边的路径是 <project 路径>/build
  - 首次点击 configure 默认就是 vs2019 和 x64，这两者都是必要的

  > configure 过程中会下载许多依赖库，耗时可能较久，由 git clone 速度而定。另外我们会提供编译好的依赖包（即方法二），免去下载/编译的过程，但这样无法查阅源码。
  >
  
- 打开项目，在解决方案资源栏里找到 GAMES102_HW_hw1，右键菜单中选“设为启动项目”，然后右键菜单中选“生成”。在等待较长时间的编译完成后，即可在菜单栏中点击“本地 Windows调试器”运行 hw1 空项目。你会看到一个引擎编辑器界面，在 Game 窗口中有 canvas，这将是作业1的所需完成部分。

### 方法 2

此方法使用方便，缺点是不含源码

> 所需下载的资源在课程群文件内的“框架依赖资源”里可以找到

- 使用 Github Desktop 克隆此库 [GAMES 102](https://github.com/Ubpa/GAMES102)，注意路径应放到**较浅**的位置，如盘符根目录
- 下载编译好的依赖库 [Ubpa_v2.zip](https://pan.baidu.com/s/1byH_y3rXcrrs-H7UN9mueA)（百度网盘提取码：qmp4）放到合适的位置，然后将其内的文件夹 bin 的路径加到环境变量 Path 中（参考[教程](https://www.cnblogs.com/-mrl/p/11246666.html)）
- 使用 CMake-Gui 构建 vs 2019 项目（此时会非常顺利，最终构建的项目内**仅含作业项目**，日后有需要在进行源码构建）
  - 注意 where is the source code 是<project 路径>，下边的路径是 <project 路径>/build
  - 首次点击 configure 默认就是 vs2019 和 x64，这两者都是必要的



## 作业 1

根据作业要求，通过修改 [CanvasSystem.cpp](src/hw1/Systems/CanvasSystem.cpp) 完成作业

> 所需数据存放在 [CanvasData.h](src/hw1/Components/CanvasData.h) 中，你可以调整它
>
> > 我们使用了 [USRefl](https://github.com/Ubpa/USRefl) 来实现静态反射功能，提供了一个自动生成描述文件 [CanvasData_AutoRefl.inl](src/hw1/Components/details/CanvasData_AutoRefl.inl) 的工具。
> >
> > 当你修改 CanvasData.h 后，你需要将 CanvasData_AutoRefl.inl 删除，以便使 CMake 自动生成新的描述文件。
> >
> > 该工具存在一定的问题，如
> >
> > - 不支持部分 C++17 语法
> > - 不支持模板的连续 `>>` 符号，如 `std::vector<std::vector<int>>`，可改为 `std::vector<std::vector<int>> >` 
> >
> > 你可以通过手写描述的方式避免这些问题。
>
> 如果你需要添加文件，你可以在 src 的合理位置放置代码文件，然后重新在 CMake-GUI 里 configure + generate，vs2019 会刷新项目从而包含新文件

目前该系统中有画线段功能（在canvas左键拖拽即可），你需要修改这部分逻辑，如通过鼠标点击获取点集，计算相应的曲线，对曲线采样并利用 `ImDrawList::AddLine` 来绘制 polyline（更多的绘制方法看 `ImDrawList` 定义）。

作业题涉及多种曲线生成方法，因此你还应该用 `ImGui::RadioButton` 或者其他交互方式修改曲线类型。

你可能需要用到矩阵计算，推荐使用纯头文件的 Eigen 库（[官网](http://eigen.tuxfamily.org/index.php?title=Main_Page)），添加进项目里的方式有两个

- 简单：将其源码（Eigen 文件夹）放到 `src/hw1`，接着删掉其中的 `CMakeLists.txt`，接着 cmake configure + generate 后即可将库添加到项目中，后续用 `#include "<relative-path>/Eigen/<component>"` 来包含库。
- :star:科学：将源码（Eigen 文件夹）放到文件夹 `include/_deps/` 内（自行创建），接着在 [src/hw1/CMakeLists.txt](src/hw1/CMakeLists.txt) 的 Add_Target 内添加一行 `INC "${PROJECT_SOURCE_DIR}/include/_deps"`，后续用 `#include <Eigen/<component>>"` 来包含库。

对于不想使用鼠标交互方式作为输入的同学，我们将提供 **plot** 方式的 UI 减轻大家的负担（TODO）

你需要了解

- Utopia：引擎框架。参考资料：[Utopia](https://github.com/Ubpa/Utopia)（内含文档，但并不丰富）
- ECS：以便理解框架的逻辑执行方式，以及代码编写方式。参考资料：[UECS 文档](https://github.com/Ubpa/UECS)，[Unity ECS 文档](https://docs.unity3d.com/Packages/com.unity.entities@0.14/index.html) 
- ImGui：简单易用的 UI 库。参考资料：[imgui](https://github.com/ocornut/imgui)。（一般直接从官方提供的 [example](https://github.com/ocornut/imgui#demo) 和 [demo](https://github.com/ocornut/imgui/blob/master/imgui_demo.cpp) 源码中学习使用方式）

## 作业 3

根据作业要求，通过修改 [CanvasSystem.cpp](src/hw3/Systems/CanvasSystem.cpp) 完成作业

> 所需数据存放在 [CanvasData.h](src/hw3/Components/CanvasData.h) 中，你可以调整它

作业 3 和作业 1 是类似的

## 作业 4

根据作业要求，通过修改 [CanvasSystem.cpp](src/hw4/Systems/CanvasSystem.cpp) 完成作业

> 所需数据存放在 [CanvasData.h](src/hw4/Components/CanvasData.h) 中，你可以调整它

## 作业 5

根据作业要求，通过修改 [CanvasSystem.cpp](src/hw5/Systems/CanvasSystem.cpp) 完成作业

> 所需数据存放在 [CanvasData.h](src/hw5/Components/CanvasData.h) 中，你可以调整它

## 作业 6

根据作业要求，通过修改 [DenoiseSystem.cpp](src/hw6/Systems/DenoiseSystem.cpp) 完成作业

> 所需数据存放在 [DenoiseData.h](src/hw6/Components/DenoiseData.h) 中，你可以调整它

本次主要用到了 [UHEMesh 库](https://github.com/Ubpa/UHEMesh)，课程视频中有其简单介绍，详细请查看源码中各类型（TVertex, TEdge, TPolygon, THalfEdge, HEMesh）接口

### 网格

点击下边的下载链接，把它们放到 [assets/models/](assets/models/) 下，重启框架即可找到新的 obj 

- [Balls.obj](https://cdn.jsdelivr.net/gh/Ubpa/USTC_CG_Data@master/Homeworks/04_MinSurfMeshPara/mesh/Balls.obj) 
- [Bunny_head.obj](https://cdn.jsdelivr.net/gh/Ubpa/USTC_CG_Data@master/Homeworks/04_MinSurfMeshPara/mesh/Bunny_head.obj) 
- [Cat_head.obj](https://cdn.jsdelivr.net/gh/Ubpa/USTC_CG_Data@master/Homeworks/04_MinSurfMeshPara/mesh/Cat_head.obj) 
- [David328.obj](https://cdn.jsdelivr.net/gh/Ubpa/USTC_CG_Data@master/Homeworks/04_MinSurfMeshPara/mesh/David328.obj) 
- [Nefertiti_face.obj](https://cdn.jsdelivr.net/gh/Ubpa/USTC_CG_Data@master/Homeworks/04_MinSurfMeshPara/mesh/Nefertiti_face.obj) 

## 作业 7

根据作业要求，通过修改 [DenoiseSystem.cpp](src/hw6/Systems/DenoiseSystem.cpp) 完成作业

> 所需数据存放在 [DenoiseData.h](src/hw6/Components/DenoiseData.h) 中，你可以调整它

框架涉及内容同于[作业 6](#作业 6)



# GAMES102 学习材料 (1)

> 作者：史雨宸 ([syc0412@mail.ustc.edu.cn](mailto:syc0412@mail.ustc.edu.cn))

[TOC]

## 1. 函数插值

在许多实际问题中，某个函数 $f(x)$ 往往很复杂、没有解析表达或者未知。我们往往只能通过某些手段观测到反映该函数的一些采样数据。我们希望通过这些观测的采样数据来估计该函数的信息，并预测函数在其他观测点的值。这时，我们从观测数据来求得一个函数 $\phi(x)$ 来近似 $f(x)$ 。

**定义**： $f(x)$ 为定义在区间 $[a,b]$ 上的函数， $x_0,x_1,\cdots,x_n$ 为区间上 $n+1$ 个互不相同的点， $\Phi$ 为给定的某一函数类。求 $\Phi$ 上的函数 $\phi(x)$ ，满足：
$$
\phi(x_i)=f(x_i), \ \ i=0,1,\cdots,n
$$
则称 $\phi(x)$ 为 $f(x)$ 关于节点 $x_0,x_1,\cdots,x_n$ 在 $\Phi$ 上的插值函数。称 $x_0,x_1,\cdots,x_n$ 为插值节点，称 $(x_i,f(x_i))$ 为插值点。

### 1.1 多项式插值定理

**定理**：若 $x_i$ 两两不同，则对任意给定的 $y_i$ ，存在唯一的次数至多是 $n$ 次的多项式 $p_n$ ，使得 $p_n(x_i)=y_i，i=0,\cdots,n$ 。

证明：在幂基 $\lbrace 1,x,\cdots,x^n \rbrace $ 下待定多项式 $p$ 的形式为：

$$
p(x)=a_0+a_1x+a_2 x^2+\cdots+a_n x^n
$$

由插值条件 $p(x_i)=y_i,i=0,\cdots,n$ ，得到如下方程组：

$$
\left( \begin{array} {c} 1 &x _ 0 &x _ 0^2 &\dots &x _ o^n \newline 1 &x _ 1 &x _ 1^2 &\dots &x _ 1^n \newline 1 &x _ 2 &x _ 2^2 &\dots &x _ 2^n \newline \vdots &\vdots &\vdots &\ddots &\vdots\newline 1 &x _ n &x _ n^2 &\dots &x _ n^n \newline \end{array} \right) \left( \begin{array} {c} a _ 0 \newline a _ 1 \newline a _ 2 \newline \vdots \newline a _ n \end{array} \right) = \left( \begin{array} {c} y _ 0 \newline y _ 1 \newline y _ 2 \newline \vdots \newline y _ n \end{array} \right)
$$

系数矩阵为 **Vandermonde** 矩阵，其行列式非零，因此方程组有唯一解。

### 1.2 不同形式的插值多项式

对于给定问题，插值多项式存在唯一。但是可以用不同的方法给出插值多项式的不同表示形式。

#### 1.2.1 Lagrange插值

**Lagrange基函数**：由多项式插值定理存在函数 $l_i(x)$ 满足 $l_i(x_j)=\sigma_{ij}$ ：

$$
l_i(x)=\prod_{j=0,j\neq i}\frac{x-x_j}{x_i-x_j}
$$

Lagrange插值多项式：

$$
L_n(x)=\sum_{k=0}^n y_k l_k(x)
$$

#### 1.2.2 Newton插值

**定义**：

一阶差商：

$$
f[x_0,x_1]=\frac{f(x_1)-f(x_0)}{x_1-x_0}
$$

$k $阶差商：

设$ \lbrace x_0,x_1,\cdots,x_k \rbrace  $互不相同，$ f(x) $关于$ \lbrace x_0,x_1,\cdots,x_k \rbrace  $的$ k $阶差商为：

$$
f[x_0,x_1,\cdots,x_k]=\frac{f[x_1,\cdots,x_k]-f[x_0,x_1,\cdots,x_{k-1}]}{x_k-x_0}
$$

所以**Newton插值多项式**表示为：

$$
N _ n(x)=f(x _ 0)+f[x _ 0,x _ 1](x-x _ 0)+\cdots+f[x _ 0,x _ 1,\cdots,x _ n](x-x _ 0)\cdots(x-x _ {n-1})
$$

## 2. 函数拟合

函数拟合是指：给出一组离散的点，需要确定一个函数来逼近原函数。由于离散数据通常是由观察或测试得到的，所以不可避免的会有误差。我们需要的逼近原函数的手段要满足如下两个条件：

- 不要求过所有的点（可以消除误差影响）
- 尽可能表现数据的趋势，靠近这些点

用数学的语言来说即是，需要在给定的函数空间 $\Phi$ 上找到函数 $\phi$ ，使得 $\phi$ 到原函数 $f$ 的距离最小。这里的距离指的是某种度量，不同的度量对应着不同的拟合方法。则函数 $\phi(x)$ 称为 $f(x)$ 在空间 $\Phi$ 上的拟合曲线。

### 2.1 函数拟合的最小二乘法问题

**定义**： $f(x)$ 为定义在去区间 $[a,b]$ 上的函数， $\lbrace x _ i \rbrace  _ {i=0}^m$ 为区间上 $m+1$ 个互不相同的点， $\Phi$ 为给定的某一函数类。求 $\Phi$ 上的函数 $\phi(x)$ 满足 $f(x)$ 和 $\phi(x)$ 在给定的 $m+1$ 个点上的距离最小，如果这种距离取为2-范数的话，则称为最小二乘问题。即：求 $\phi(x) \in \Phi$ ，使得：

$$
R_2=\sqrt{\sum_{i=0}^m (\phi(x_i)-f(x_i))^2}
$$

最小。

#### 2.1.1 最小二乘问题的求解

首先给出如下离散内积与离散范数的定义：

**定义**：函数 $f,g$ 的关于离散点列 $\lbrace x _ i \rbrace  _ {i=0}^m$ 的离散内积为：
$$
(f,g) _ h=\sum _ {i=0}^n f(x _ i)g(x _ i)
$$

**定义**：函数 $f$ 的离散范数为：
$$
||f||_h=\sqrt{(f,f)_h}
$$

该种内积下，范数的定义与向量的2范数一致。

> 上述定义中的下标 $h$ 表示对离散内积与离散范数的指代，类似1-范数的定义 $||x|| _ 1=\sum _ {i=1}^n |x _ i|$ ，无其他特殊含义。

设 $\Phi=span\lbrace \phi_0,\phi_1,\cdots,\phi_n \rbrace $

$$
\phi(x)=a_0\phi_0(x)+a_1\phi_1(x)+\cdots+a_n\phi_n(x)
$$

则最小二乘问题为：

$$
||f(x)-(a_0\phi_0(x)+a_1\phi_1(x)+\cdots+a_n\phi_n(x))||_h
$$

关于系数 $\lbrace a_0,a_1,\cdots,a_n \rbrace $ 最小

$$
\begin{aligned}
&||f(x)-(a _ 0\phi _ 0(x)+a _ 1\phi _ 1(x)+\cdots+a _ n\phi _ n(x))|| _ h^2 \newline
=& ||f|| _ h^2-2(f,a _ 0\phi _ 0(x)+a _ 1\phi _ 1(x)+\cdots+a _ n\phi _ n(x)) _ h+||a _ 0\phi _ 0(x)+a _ 1\phi _ 1(x)+\cdots+a _ n\phi _ n(x)|| _ h^2 \newline
=&||f|| _ h^2-2\sum _ {k=0}^n a _ k(f,\phi _ k) _ h+\sum _ {i,k=0}^n a _ i a _ k(\phi _ i,\phi _ k) _ h \newline
=&Q(a _ 0,a _ 1,\cdots,a _ n)
\end{aligned}
$$

由于它关于系数 ${a_0,a_1,\cdots,a_n}$ 最小，因此有

$$
\begin{align*}
&\frac{\partial Q}{\partial a_i}=0 ,\ \ \ i=0,1,\cdots,n \newline
i.e. \ \ &\sum_{k=0}^n a_k(\phi_i,\phi_k)_h=(f,\phi_i)_h,\ \ \ i=0,1,\cdots,n 
\end{align*}
$$

写成矩阵形式有：

$$
\left( \begin{array} {c} (\phi _ 0,\phi _ 0) _ h & \dots & (\phi _ 0,\phi _ n) _ h \newline \vdots & \ddots & \vdots \newline (\phi _ n,\phi _ 0) _ h & \dots &(\phi _ n,\phi _ n) _ h \end{array} \right) \left( \begin{array} {c} a _ 0 \newline \vdots \newline a _ n \end{array} \right) = \left( \begin{array} {c} (f,\phi _ 0) _ h\newline \vdots \newline (f,\phi _ n) _ h \end{array} \right)
$$

#### 2.1.2 线性拟合

**例1**：取 $\Phi$ 为线性多项式空间，函数空间的基为 $\lbrace 1,x \rbrace $ ,拟合曲线为 $y=a+bx$ ，则法方程为：

$$
\left( \begin{array} {c} (1,1) _ h  & (1，x) _ h \newline (x,1) _ h  &(x,x) _ h \end{array} \right) \left( \begin{array} {c} a \newline b \end{array} \right) = \left( \begin{array} {c} (f,1) _ h\newline (f,x) _ h \end{array} \right)
$$

#### 2.1.3 二次拟合

**例2**：取 $\Phi$ 为线性多项式空间，函数空间的基为 $\lbrace 1,x,x^2 \rbrace $ ,拟合曲线为 $y=a_0+a_1 x+a_2 x^2$ ，则法方程为：

$$
\left( \begin{array} {c} (1,1) _ h  & (1，x) _ h & (1,x^2) _ h\newline (x,1) _ h  &(x,x) _ h &(x,x^2) _ h\newline (x^2,1) _ h  &(x^2,x) _ h &(x^2,x^2) _ h\newline \end{array} \right) \left( \begin{array} {c} a _ 0 \newline a _ 1 \newline a _ 2 \end{array} \right) = \left( \begin{array} {c} (f,1) _ h\newline (f,x) _ h \newline (f,x^2) _ h \end{array} \right)
$$

## 3. Weierstrass 第一逼近定理

**定理**：设 $f(x)$ 是闭区间 $[a,b]$ 上的连续函数，则存在多项式序列 ${P_n(x)}$ 在 $[a,b]$ 上一致收敛于 $f(x)$ 。也就是对任意给定的 $\epsilon > 0 $ ，存在多项式$P(x) $ ，使得：

$$
|P(x)-f(x)| < \epsilon
$$

对一切 $x\in[a,b] $ 成立。

证：不失一般性，设$[a,b] $ 为$[0,1] $，使用构造性的证明。

设$ X $是$ [0,1] $上连续函数$ f(t) $的全体构成的集合，$ Y $是多项式全体构成的集合，定义映射：

$$
\begin{align*}
B_n: &\ \ X \ \rightarrow \ \ Y \newline
 & f(t) \mapsto B_n(f,x)=\sum_{k=0}^n f(\frac{k}{n})C_n^k x^k (1-x)^{n-k}
\end{align*}
$$

得到 ${B_n(f,x)}$ ， $B_n(f,x)$ 表示 $f\in X$ 在映射 $B_n$ 作用下的像，它是以 $x$ 为变量的 $n$ 次多项式，称为 $f$ 的 $n$ 此 $\textbf{Bernstein}$ 多项式。

关于映射 $B_n$ ,有下述基本性质与基本关系式：

1. 线性性: 对于任意 $f,g\in X$ 及 $\alpha,\beta \in R$ ，成立
   $$
   B_n(\alpha f+\beta g,x)=\alpha B_n(f,x)+\beta B_n(g,x)
   $$

2. 单调性: 若 $f(t)\geq g(t) (t\in[a,b])$ ,则
   $$
   B_n(f,x) \geq B_n(g,x) \ \ \ x\in [a,b]
   $$

3. $$
   \begin{align*}
     &B_n(1,x)=\sum_{k=0}^n C_n^k x^k (1-x)^{n-k}=1 \newline
     &B_n(t,x)=\sum_{k=0}^n \frac{k}{n} C_n^k x^k (1-x)^{n-k}=x \newline
     &B_n(t^2,x)=\sum_{k=0}^n \frac{k^2}{n^2} C_n^k x^k (1-x)^{n-k}=x^2+\frac{x-x^2}{n}
   \end{align*}
   $$

函数 $(t-s)^2 $ 在 $ B_n $ 映射下的像(视 $ s $ 为常数)：

$$
\begin{align*}
    B_n((t-s)^2,x)&= B_n(t^2,x)-2sB_n(t,x)+s^2B_n(1,x) \newline
    &=x^2+\frac{x-x^2}{n}-2sx+s^2=(x-s)^2+\frac{x-x^2}{n}
    \end{align*}
$$

根据 $\textbf{Cantor}$ 定理， $f$ 在 $[0,1]$ 上一致连续，于是对于任意给定的 $\epsilon > 0$ ，存在 $\delta > 0$ ，对一切 $t,s\in[0,1]$ :

当 $|t-s| < \delta$ 时，成立：

$$
|f(t)-f(s)| < \frac{\epsilon}{2}
$$

当 $|t-s| \geq \delta$ 时，成立：

$$
|f(t)-f(s)| \leq 2M \leq \frac{2M}{\delta^2}(t-s)^2
$$

于是对一切 $t,s\in[0,1]$ ,成立：

$$
|f(t)-f(s)| \leq \frac{\epsilon}{2}+\frac{2M}{\delta^2}(t-s)^2
$$

即：

$$
-\frac{\epsilon}{2}-\frac{2M}{\delta^2}(t-s)^2 \leq f(t)-f(s) \leq \frac{\epsilon}{2}+\frac{2M}{\delta^2}(t-s)^2
$$

对上式左端，中间，右端三式（视 $t$ 为变量， $s$ 为常数）考虑在映射 $B_n$ 作用下的像，得到对一切 $x,s\in[0,1]$ ，成立：

$$
-\frac{\epsilon}{2}-\frac{2M}{\delta^2}[(x-s)^2+\frac{x-x^2}{n}] \leq B_n(f,x)-f(s) \leq \frac{\epsilon}{2}+\frac{2M}{\delta^2}[(x-s)^2+\frac{x-x^2}{n}]
$$

令 $s=x$ ，注意到 $x(1-x) \leq \frac{1}{4}$ ，即得到对一切 $x\in[0,1]$ ，成立：

$$
|\sum_{k=0}^n f(\frac{k}{n})C_n^k x^k (1-x)^{n-k}-f(x)| \leq \frac{\epsilon}{2}+\frac{M}{2n\delta^2}
$$

取 $N=\lceil \frac{M}{\delta^2 \epsilon} \rceil$ ，当 $n>N$ 时：

$$
|\sum_{k=0}^n f(\frac{k}{n})C_n^k x^k (1-x)^{n-k}-f(x)| < \epsilon
$$

对一切 $x\in[0,1]$ 成立。

## 4. Weierstrass 第二逼近定理

**定理**：设 $f(x)$ 是以 $2\pi$ 为周期的连续函数，则存在三角多项式序列一致收敛于 $f(x)$ 。也就是对于任意给定的 $\epsilon > 0$ ，存在三角多项式 $T(x)$ ，使得:
$$
|T(x)-f(x)| < \epsilon
$$

对一切 $x\in(-\infty,+\infty)$ 成立。

先证明一个引理：

**引理**：设 $g(x)$ 在 $[0,\pi]$ 上连续，则对于任意 $ \epsilon > 0$ ，存在余弦三角多项式 $T(x)$ ，使得：

$$
|T(x)-g(x)| < \epsilon
$$

对一切 $x\in[0,\pi]$ 成立。

证：由 $g(\arccos y)$ 在 $[-1,1]$ 上连续，由 $\textbf{Weierstrass}$ 第一逼近定理，对任意 $\epsilon > 0$ ，存在多项式 $P(y)$ ，使得：

$$
|P(y)-g(\arccos y)| < \epsilon
$$

对一切 $y\in[-1,1]$ 成立，即：

$$
|P(\cos x)-g(x)|< \epsilon
$$

对一切 $x\in [0,\pi]$ 成立。由三角恒等式

$$
\begin{align*}
   &\cos^2x =\frac{1}{2}(1+\cos {2x}), \newline
   &\cos^3x =\frac{1}{4}(3\cos x+\cos{3x}),\newline
   &\cdots,\newline
   &\cos^{2n}x=\frac{1}{2^{2n-1}}(\sum_{k=1}^{n-1} C_{2n}^k \cos{2(n-k)x}+\frac{1}{2}C_{2n}^n),\newline
   &\cos^{2n+1}x=\frac{1}{2^{2n}}\sum_{k=0}^n C_{2n+1}^k \cos{(2n-2k+1)x}\newline
\end{align*}
$$

可知 $P(\cos x)=T(x)$ 是余弦三角多项式。

**推论**：设 $g(x)$ 是以 $2\pi$ 为周期的连续偶函数，则 $\textbf{Weierstrass}$ 第二逼近定理成立，且三角多项式是余弦三角多项式。

$\textbf{Weierstrass}$ 第二逼近定理的证明：

设$ f(x) $是以$ 2\pi $为周期的连续函数，令：

$$
\phi(x)=f(x)+f(-x),\ \psi(x)=[f(x)-f(-x)]\sin x
$$

则 $\phi(x)$ 和 $\psi(x)$ 都是以 $2\pi$ 为周期的连续偶函数，由上面推论，可知对任意给定的 $\epsilon > 0$ ，存在余弦三角多项式 $T_1(x)$ 与 $T_2(x)$ ，使得：

$$
|\phi(x)-T_1(x)| < \frac{\epsilon}{2},\ |\psi(x)-T_2(x)| < \frac{\epsilon}{2}
$$

对一切 $x\in(-\infty,+\infty)$ 成立。

记 $T_3(x)=T_1(x)\sin^2x+T_2(x)\sin x$ ，于是由：

$$
|\phi(x)\sin^2x-T_1(x)\sin^2x|< \frac{\epsilon}{2},|\psi(x)\sin x-T_2(x)\sin x|< \frac{\epsilon}{2}
$$

得到：

$$
\begin{equation}
|2f(x)\sin^2x-T_3(x)| < \epsilon \tag{1} 
\end{equation}
$$

对一切 $x\in(-\infty,+\infty)$ 成立。由于上式对 $f(t-\frac{\pi}{2})$ 也成立，于是也有：

$$
|2f(t-\frac{\pi}{2})\sin^2t-T_4(t)| < \epsilon
$$

令 $x=t-\frac{\pi}{2}$ ，得到：

$$
\begin{equation}
|2f(x)\cos^2x-T_4(x+\frac{\pi}{2})| < \epsilon  \tag{2} 
\end{equation}
$$

对一切 $x\in(-\infty,+\infty)$ 成立。

记 $T_5(x)=\frac{1}{2}[T_3(x)+T_4(x+\frac{\pi}{2})]$ ，结合 (1) 和 (2)，得到：

$$
|f(x)-T_5(x)| < \epsilon
$$

对一切 $x\in(-\infty,+\infty)$ 成立。

## 5. 距离空间的完备性

**定义**：设 $X$ 是距离空间， $\lbrace x_n \rbrace \subset X$ 。 $\lbrace x_n \rbrace $ 是 $X$ 中的基本列，是指对任意 $\epsilon > 0$ ，存在 $N=N(\epsilon)$ ，当 $m,n> N$ 时，有 $\rho(x_m,x_n) < \epsilon$ 。

**定义**：称 $X$ 是完备距离空间，是指 $X$ 中的任何基本列都收敛于 $X$ 中的点。

**例**： $C[a,b]$ 按距离 $\rho(x,y)=\max |x(t)-y(t)|$ 是完备距离空间。

## 6. Fourier级数

首先，周期函数是客观世界中周期运动的数学表述，如物体挂在弹簧上作简谐振动、单摆振动、无线电电子振荡器的电子振荡等，大多可以表述为：

$$
f(t)=A\sin(\omega t +\psi)
$$

这里 $t$ 表示时间， $A$ 表示振幅， $\omega$ 为角频率， $\psi$ 为初相（与考察时设置原点位置有关，可以理解为一个常量）。

然而，世界上许多周期信号并非正弦函数那么简单，如方波、三角波等。于是傅里叶在其著作《热的解析理论》中，推导出用一系列的三角函数 $ A_n\sin(n\omega t+\psi_n)$之和来表示那个较复杂的周期函数 $ f(x)$，即：

$$
\begin{equation}
f(t)=A_0+\sum_{n=1}^{\infty}A_n \sin(n \omega t+\psi_n) \tag{3}
\end{equation}
$$

由 $\psi_n$ 为常数， $A_n$ 也是常数，则对上式进行变形：

$$
A_n \sin(n \omega t+\psi_n)=A_n \sin{\psi_n}\cos(n\omega t)+A_n \cos{\psi_n}\sin(n\omega t)
$$

记 $a_n=A_n\cdot \sin{\psi_n}$ ,\ $b_n=A_n \cos{\psi_n} $ ，则可写 (3) 为如下形式：

$$
\begin{equation}
f(t)=A_0+\sum_{n=1}^{\infty}[a_n\cos(n\omega t)+b_n\sin(n\omega t)]
\end{equation} \tag{4}
$$

即是常见的 **Fourier** 级数形式。

### 6.1 系数求解

对 (4) 式从 $[-\pi,\pi]$ 积分，得：

$$
\begin{align*}
\int_{-\pi}^{\pi} f(t) dt &=\int_{-\pi}^{\pi} A_0dt +\int_{-\pi}^{\pi} \sum_{n=1}^{\infty}[a_n\cos(n\omega t)+b_n\sin(n\omega t)] dt \newline
&=\int_{-\pi}^{\pi} A_0 dt+0\newline
&=2\pi A_0
\end{align*}
$$

解得： $A_0=\frac{1}{2\pi}\int_{-\pi}^{\pi} f(t)$ 。

这样就求得了第一个系数 $A_0$ 的表达式，接下来求 $a_n$ 和 $b_n$ 的表达式。用 $\cos(k\omega t)$ 乘 (4) 式两边得：

$$
f(t)\cdot \cos(k\omega t)=A_0 \cos(k\omega t)+\sum_{n=1}^{\infty}[a_n\cos(n\omega t)\cos(k\omega t)+b_n\sin(n\omega t)\cos(k\omega t)]
$$

对上式从 $[-\pi,\pi]$ 积分，得：

$$
\int_{-\pi}^{\pi}f(t)\cdot \cos(k\omega t) dt=A_0 \int_{-\pi}^{\pi}\cos(k\omega t) dt+\sum_{n=1}^{\infty}[a_n\int_{-\pi}^{\pi}\cos(n\omega t)\cos(k\omega t) dt+b_n\int_{-\pi}^{\pi}\sin(n\omega t)\cos(k\omega t) dt]
$$

由三角函数系的正交性， $A_0$ 和 $b_n$ 后积分均为0， $a_n$ 后积分当且仅当 $k=n$ 时不为0，所以：

$$
\begin{align*}
\int_{-\pi}^{\pi}f(t)\cdot \cos(n\omega t) dt&=a_n\ int_{-\pi}^{\pi} \cos^2(n\omega t) dt \newline
&=\frac{a_n}{2}\int_{-\pi}^{\pi}(1+\cos{2n\omega t}) dt \newline
&=\frac{a_n}{2}(\int_{-\pi}^{\pi} 1 dt+\int_{-\pi}^{\pi} \cos{2n\omega t} dt)\newline
&=\frac{a_n}{2} \dot 2\pi =a_n\pi
\end{align*}
$$

解得：

$$
a_n=\frac{1}{\pi}\int_{-\pi}^{\pi}f(t)\cdot \cos(n\omega t) dt
$$

同理用 $\sin(k\omega t) $ 乘 (4) 式两边得：

$$
b_n=\frac{1}{\pi}\int_{-\pi}^{\pi}f(t)\cdot \sin(n\omega t) dt
$$

令 $a_0=2A_0$ 则有：

$$
f(t)=\frac{a_0}{2}+\sum_{n=1}^{\infty}[a_n\cos(n\omega t)+b_n\sin(n\omega t)]
$$
