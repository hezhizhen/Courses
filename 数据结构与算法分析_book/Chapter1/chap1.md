# 第1章 引论

- 阐述本书的目的和目标
- 简要复习离散数学和程序设计的一些概念
- 了解程序在合理范围内的大规模输入情况下运行性能与其在中等规模输入下的运行性能同等重要

1. 概括本书其余部分所需要的基本的数学基础
2. 简要复习一下递归
3. 概括用于本书的C++语言的一些重要特点

## 1.1 本书讨论的内容

选择问题：设有一组N个数，要确定其中第k个最大者

- solution 1: 将这N个数读入一个数组中，以递减顺序将数组排序，然后返回位置k上的元素
- solution 2: 先将前k个元素读入数组并以递减的顺序排序，然后将剩下的元素逐个读入：小于第k个元素则忽略，大于就放到数组中正确位置并挤出一个元素，最后返回第k个位置上的元素

求解一个流行的字谜游戏：输入由一个二维字母数组和一个单词表组成，目标是要找出字谜中的单词，这些单词可能是水平、垂直或沿任何对角线方向放置的

- solution 1: 对列出的每个单词，检查每一个有序三元组（行，列，方向）来看这个单词是否存在。（需要大量的嵌套）
- solution 2: 对于每一个在字谜界限以内的有序四元组（行，列，方向，字符数），检查所指的单词是否在单词表中。（如果任意单词中的最大字符数已知，就有可能节省一些时间）

## 1.2 数学知识复习

### 1.2.1 指数

- $$X^AX^B=X^{A+B}$$
- $$\frac{X^A}{X^B}=X^{A-B}$$
- $$(X^A)^B=X^{AB}$$
- $$X^N+X^N=2X^N \neq X^{2N}$$
- $$2^N+2^N=2^{N+1}$$

### 1.2.2 对数

> 在计算机科学中，所有的对数都是以**2**为底的，除非另有声明

- $X^A=B$ iff $log_XB=A$
- $log_AB=\frac{log_CB}{log_CA}$; A,B,C>0,A$\neq$1
- $logAB=logA+logB$; A,B>0
- $logA/B=logA-logB$
- $log(A^B)=BlogA$
- $logX<X$ for all X>0

### 1.2.3 级数

- $\sum\limits_{i=0}^N2^i=2^{N+1}-1$
- $\sum\limits_{i=0}^NA^i=\frac{A^{N+1}-1}{A-1}$
- if $0<A<1$, then $\sum\limits_{i=0}^NA^i\le\frac{1}{1-A}$
- 几何级数
- $\sum\limits_{i=1}^{\infty}\frac{i}{2^i}=2$
- 算术级数：$\sum\limits_{i=1}^Ni=\frac{N(N+1)}{2}\approx\frac{N^2}{2}$
- $\sum\limits_{i=1}^Ni^2=\frac{N(N+1)(2N+1)}{6}\approx\frac{N^3}{3}$
- $\sum\limits_{i=1}^Ni^k\approx\frac{N^{k+1}}{|k+1|}, k\neq-1$
- 调和数$H_N$: $H_N=\sum\limits_{i=1}^N\frac{1}{i}\approx log_eN$ (近似误差趋向于$\gamma\approx0.57721566$, 欧拉常数)
- 调和数的和为调和和
- $\sum\limits_{i=1}^Nf(N)=Nf(N)$
- $\sum\limits_{i=n_0}^Nf(i)=\sum\limits_{i=1}^Nf(i)-\sum\limits_{i=1}^{n_0-1}f(i)$

### 1.2.4 模运算

- 如果N整除A-B，则A与B模N**同余**，记为$A\equiv B$ (mod N)
- 若$A\equiv B$ (mod N), 则$A+C\equiv B+C$ (mod N), 以及$AD\equiv BD$ (mod N)

### 1.2.5 证明方法

两种常见方法：归纳法证明 & 反证法证明 (反例证明不成立)

**归纳法证明**

- 基准情形(base case): 确定定理对于某个（些）小的（通常是退化的）值的正确性
- 归纳假设(inductive hypothesis): 假设定理对直到某个有限数k的所有情况都是成立的，然后使用这个假设证明定理对下一个值（通常是k+1）也是成立的
- 结论: 定理得证（在k是有限的情形下）

**反例**

**反证法证明**

通过假设定理不成立，然后证明该假设导致某个已知的性质不成立，从而证明原假设是错误的

## 1.3 递归的简单介绍

递归：当一个函数用自身来定义时就称为是*递归*的

- 基准情况：即此时函数的值可以直接算出而不用求助递归
- 递归调用：递归调用将一直进行到基准情况出现为止

对于递归程序，不存在“特殊情形”

递归的四个基本法则：

- 基准情形：必须总有某些基准的情形，它们不用递归就能求解
- 不断推进：对于那些要被递归求解的情形，递归调用必须总能够朝着一个基准情形推进
- 设计法则：假设所有的递归调用都能运行
- 合成效益法则：在求解一个问题的同一实例时，切勿在不同的递归调用中做重复性的工作

## 1.4 C++类

### 1.4.1 基本class语法

在C++中

- 类由成员构成
- 成员：可以是数据、函数（称为成员函数）
- 类中的每一个实例都是一个对象
- 每一个对象包含类中指定的数据成员
- 成员函数作用于对象，通常被称为方法

```c++
// A class for simulating an integer memory cell

class IntCell
{
	public:
		// construct the IntCell
		// initial value is 0
		IntCell()
		{ storedValue = 0; }
		
		//construct the IntCell
		// initial value is initialValue
		IntCell(int initialValue)
		{ storedValue = initialValue; }
		
		//return the stored value
		int read()
		{ return storedValue; }
		
		//change the stored value to x
		void write(int x)
		{ storedValue = x; }
		
	private:
		int storedValue;
};
```

- 两个标号：public & private，声明类成员的可见性
- public的类成员可以被任何类中的任何方法访问
- private的类成员仅可以被它所在类的方法访问
- 数据成员声明为private，这样可以禁止对该类内部细节的访问；作为一般用途的方法则定义为public
- 上述称为**信息隐藏**
- 构造函数是描述如何构建类的实例的方法
- 如果没有显式定义的构造函数，则可以自动生成使用编程语言的默认值来初始化数据成员的构造函数

### 1.4.2 特别的构造函数语法与访问函数

改进的IntCell类

```c++
// a class for simulating an integer memory cell

class IntCell
{
	public:
		explicit IntCell (int initialValue = 0)
			: storedValue ( initialValue ) { }
		int read() const
			{ return storedValue; }
		void write (int x)
			{ storedValue = x; }
	private:
		int storedValue;
};
```

- 默认参数：定义了两个IntCell构造函数，一个接受initialValue，另一个是零参数构造函数，后者是隐含的。默认值0意味着如果没有确定的参数，则使用0
- 初始化列表：用来直接初始化数据成员 （const意味着在对象呗构造后就不能再改变）
- explicit构造函数：所有的单参数的构造函数都必须是explicit，以避免后台的类型转换 （通常单参数构造函数定义了一个隐式类型转换，该转换创建了一个临时对象，从而使赋值或函数参数变成兼容的）
- 常量成员函数：访问函数——只进行检测但不改变其对象的状态的成员函数；修改函数——改变其对象的状态的成员函数。访问函数不能用于常量对象(why?)，所有的成员函数默认都是修改函数，只有跟在参数类型列表结尾圆括号后的const才表示一个访问函数

### 1.4.3 接口与实现的分离

- 接口：列出了类及其成员（数据和函数）
- 实现：提供了函数的具体实现
- 接口与实现分离

类IntCell的接口

```c++
#ifndef IntCell_H
#define IntCell_H

class IntCell
{
	public:
		explicit IntCell (int initialValue=0);
		int read() const;
		void write (int x);
	
	private:
		int storedValue;
};

#endif
```

类IntCell的接口的实现

```c++
#include "IntCell.h"

IntCell::IntCell( int initialValue) : storedValue (initialValue)
{
}

int IntCell::read( ) const
{
	return storedValue;
}

void IntCell::write (int x)
{
	storedValue = x;
}
```

一个使用IntCell的main例程

```c++
#include <iostream>
#include "IntCell.h"
using namespace std;

int main()
{
	IntCell m;// or, IntCell m(0); but not IntCell m();
	m.write(5);
	cout << "Cell contents: " << m.read() << endl;
	
	return 0;
}
```

- 预处理命令：接口通常放在以.h结尾的文件中，需要接口信息的源代码必须#include接口文件。编译一个文件时一个接口被读两遍是非法的，所以每个头文件在读类接口时都定义一个预处理器来定义一个符号，符号通常都是文件名。接口文件第一行检测该符号是否是未定义的
- 作用域运算符：实现文件通常以.cpp、.cc或者.c结尾，其中的成员函数都必须声明为类的一部分，否则函数就会被认为是全局的。语法是ClassName::member, ::称为作用域运算符
- 签名必须精确匹配：实现的成员函数的签名必须与类接口中列出的签名精确匹配。默认参数仅在接口中被定义，在实现中则被忽略
- 如基本类型一样声明对象：使用单参数构造函数的声明必须使用圆括号来赋初始值

### 1.4.4 vector和string

两个类：vector & string

- vector：替代带来无穷麻烦的C++内置数组（其行为与基本类对象不同）
- vector有确定的大小
- string对象可以用==和<等进行比较
- vector和string都可以用=进行复制

```c++
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> squares(100);
	
	for(int i=0;i<squares.size();i++)
		squares[i]=i*i;
	
	for(int i=0;i<squares.size();i++)
		cout << i << " " << squares[i] << endl;
	
	return 0;
}
```

## 1.5 C++细节

### 1.5.1 指针

指针变量：用来存储其他对象的存储地址的变量

动态内存分配

```c++
int main()
{
	IntCell *m;
	
	m=new IntCell(0);
	m->write(5);
	cout << "Cell contents: " << m->read() << endl;
	
	delete m;
	return 0;
}
```

1. 声明：\*说明m是一个指针变量，用来指向一个IntCell对象。m的值是它所指向的对象的地址
2. 动态对象创建：new返回指向新建对象的指针，C++中有两种方式可以使用零参数构造函数来创建对象 (m=new IntCell(); 或 m=new IntCell; 推荐后者)
3. 垃圾收集及delete：C++没有垃圾收集，需要用delete操作来删除。内存泄漏（对象所占的内存不能释放）。能用自动变量的时候就不用new。
4. 指针的赋值和比较：在C++中指针变量的赋值和比较是基于指针变量的值，即它所存储的地址，地址不同则不相等
5. 通过指针访问对象的成员：通过->操作符
6. 其他指针运算：<——当A指向的对象的存储地址低于B指向对象的存储地址时，A<B就为真；&——取地址运算符，返回对象所在的内存地址

### 1.5.2 参数传递

### 1.5.3 返回值传递

### 1.5.4 引用变量

### 1.5.5 三大函数：析构函数、复制构造函数和operator=

### 1.5.6 C风格的数组和字符串

## 1.6 模板

### 1.6.1 函数模板

### 1.6.2 类模板

### 1.6.3 Object、Comparable和例子

### 1.6.4 函数对象

### 1.6.5 类模板的分离编译

## 1.7 使用矩阵

### 1.7.1 数据成员、构造函数和基本访问函数

### 1.7.2 operator[]

### 1.7.3 析构函数、复制赋值和复制构造函数

## 小结

## 练习