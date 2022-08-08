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

许多编程语言都使用**按值调用**来传递参数，即将实参复制给形参

C++三种传递参数的方式：

1. 按常量引用调用
2. 按值调用
3. 引址调用

参数传递机制的选用的判断：

1. 如果形参必须能够改变实参的值，那么就必须*引址调用*
2. 否则，实参的值不能被形参改变。如果参数类型是简单类型，使用*按值调用*；否则，参数类型是类类型的，一般*按常量引用调用*来传递

参数传递选项：

1. **按值调用**适用于不被函数更改的小对象
2. **按常量引用调用**适用于不被函数更改的大对象
3. **引址调用**适用于所有可以被函数更改的对象

### 1.5.3 返回值传递

对象的返回也可以是**按值返回**和**按常量引用返回**，偶尔也用到**引址返回** （多数情况下不要使用引址返回）

### 1.5.4 引用变量

**引用变量**和**常量引用变量**常用于参数传递，也可以用作局部变量或类的数据成员。在这些情况下，变量名就是它所引用的对象名的同义词。作为局部变量，它们避免了复制的成本。

```c++
const string & findMax (const vector<string> & arr)
{
	int maxIndex = 0;
	
	for(int i=1;i<arr.size();i++)
		if(arr[maxIndex]<arr[i])
			maxIndex=i;
			
	return arr[maxIndex];
}
```

`string x = findMax(a)`比`const string &x = findMax(a)`要好

引用变量可以用作类数据成员，引用必须被初始化

### 1.5.5 三大函数：析构函数、复制构造函数和operator=

三个特殊函数：析构函数、复制构造函数、operator=

1. 析构函数：当一个对象超过其作用域或执行delete时，就调用析构函数。析构函数的唯一任务就是释放使用对象时所占有的所有资源。默认操作是对每一个数据成员都使用析构函数
2. 复制构造函数：特殊的构造函数，用于构造新的对象，被初始化为相同类型对象的一个副本。默认情况下，复制构造函数通过将复制构造函数依次应用到每一个数据成员来实现。简单的数据类型进行简单赋值就行
	1. 声明的同时初始化
	2. 使用按值调用传递（而不是通过&或const &）的对象无论如何都应该尽量少用
	3. 通过值（而不是通过&或const &）返回对象
3. operator=：当=应用于两个已经构造的对象时，就调用**复制赋值运算符**operator=
4. 默认值带来的问题：主要问题出现在其数据成员是指针的类。
	1. 浅复制：不复制指针所指向的对象，而是简单地复制指针的值，这样两个类实例都指向了同一个对象
	2. 深复制：对整个对象进行克隆
5. 当默认值不可用时：最常见的情况是，数据成员是指针类型的，并且被指对象通过某些对象成员函数（例如构造函数）来分配地址

### 1.5.6 C风格的数组和字符串

数组名事实上是一个指向内存的指针，而不是基本类数组类型的。对数组使用=的结果是复制两个指针的值，而不是整个数组。

内置的C风格的字符串是当做字符数组来实现的，特殊的终止符'\0'用以标识字符串逻辑上的结束，以避免传递字符串的长度值。

- strcpy：字符串的复制
- strcmp：字符串的比较
- strlen：字符串的长度

每个字符都可以通过数组索引操作来访问

## 1.6 模板

考虑在数组中寻找最大项的问题

类型无关：这种算法的逻辑与存储在数组中的项的类型无关，相同的逻辑可以适用于整数、浮点数或者具有可比性的任何类型

类型无关的算法，也称为泛型算法

- 函数模板
- 类型模板

### 1.6.1 函数模板

函数模板不是真正的函数，而是一个用以产生函数的公式

```c++
// Return the maximum item in array a
// Assume a.size()>0
// Comparable objects must provide operator< and operator=
template <typename Comparable>
const Comparable & findMax( const vector<Comparable> & a)
{
	int maxIndex = 0;
	for(int i=1;i<a.size();i++)
		if(a[maxIndex]<a[i])
			maxIndex=i;
	return a[maxIndex];
}
```

含有template声明的行显示Comparable是模板实参，该实参可以被任何类型代替来生成函数

代码膨胀：函数模板可以应需要而自动扩展，随着每种类型的扩展，都会生成附加代码

模板的实参应该定义为非基本数据类型，这也是采用常量引用的原因

### 1.6.2 类模板

```c++
// A class for simulating a memory cell
template <typename Object>
class MemoryCell
{
	public:
		explicit MemoryCell(const Object & initialValue=Object())
			: storedValue(initialValue) { }
		const Object & read() const
			{ return storedValue;}
		void write (const Object & x)
			{ storedValue = x;}
	private:
		Object storedValue;
};
```

- MemoryCell可以用于任何类型的Object，只要Object具有一个零参数构造函数、一个复制构造函数和一个复制赋值运算符
- Object是通过常量引用来传递的
- 构造函数的默认参数不是0

### 1.6.3 Object、Comparable和例子

Object定义为含有一个零参数构造函数、一个operator=和一个复制构造函数

```c++
class Employee
{
	public:
		void setValue(const string & n, double s)
		{ name = n; salary = s;}
		const string & getName() const
		{ return name; }
		void print (ostream & out) const
		{ out << name << " (" << salary <<" )"; }
		bool operator< (const Employee & rhs) const
		{ return salary<rhs.salry; }
		//other general accessors and mutators, not shown
	private:
		string name;
		double salary;
};

//define an output operator for Employee
ostream & operator<< (ostream & out, const Employee & rhs)
{
	rhs.print(out);
	return out;
}

int main()
{
	vector<Employee> v(3);
	v[0].setValue( "George Bush", 400000.00);
	v[1].setValue( "Bill Gates", 2000000000.00);
	v[2].setValue( "Dr.Phil:, 13000000.00);
	cout << findMax(v) << endl;
	
	return 0;
```

- Comparable可以是类类型，比如Employee
- 操作符重载，允许重新定义内置操作符的含义

### 1.6.4 函数对象

对象同时包含数据和成员函数

一个如传递参数一样传递函数的巧妙的办法是：定义一个包含零个数据和一个成员函数的类，然后传递这个类的实例

函数对象

函数调用操作符

### 1.6.5 类模板的分离编译

在许多情况下，整个的类模板连同其实现都放置在一个单独的头文件中 （常见的标准库的实现在实现类模板时遵循这个原则）

## 1.7 使用矩阵

称为矩阵的二维数组

matrix类的基本思想：使用向量的向量

对matrix定义operator[]，即数组索引操作符

### 1.7.1 数据成员、构造函数和基本访问函数

矩阵通过被声明为vector<Object>的vector的array数据成员来表述

```c++
#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
using namespace std;

template <typename Object>
class matrix
{
	public:
		matrix (int rows, int cols) : array(rows)
		{
			for(int i=0;i<rows;i++)
				array[i].resize(cols);
		}
		const vector<Object> & operator[] (int row) const
		{ return array[row];}
		vector<Object> & operator[] (int row)
		{ return array[row];}
		
		int numrows() const
		{ return array.size();}
		int numcols() const
		{ return numrows() ? array[0].size():0;}
	private:
		vector< vector<Object> > array;
};
#endif
```

- 构造函数首先构造了array，通过rows来进入每个通过零参数构造函数构造的vector<Object>
- 然后进入构造函数代码体中，每一行的大小都被重新定义为cols列

### 1.7.2 operator[]

operator[]的思想：如果有一个matrix m，那么m[i]应该返回一个对应matrix m的行i的向量。因此，matrix operator[] 不是返回一个Object, 而是一个vector<Object>

我们需要两个版本的operator[]，它们的区别仅仅在于返回类型不同

### 1.7.3 析构函数、复制赋值和复制构造函数

vector处理了上述函数，所以，这些函数都是自动处理的

## 小结

1. 面临大量输入时，一个算法所需要的运行时间是判断其好坏的重要标准
2. 速度是相对的
3. 对于某个问题在某台机器上运行很快的算法，对另一个问题或在另一台机器上运行就可能很慢

## 练习

1. 编写一个程序解决选择问题。令k=N/2。画出表格显示你的程序对N取不同值时的运行时间
2. 编写一个程序求解字谜游戏问题
3. to be continued

## 参考文献

1. Discrete Mathematics with Algorithms
2. Companion for Computer Science
3. Introductory Combinatorics
4. A Discipline of Programming
5. Thinking in C++
6. Concrete Mathematics
7. The Science of Programming
8. The Elements of Programming Style
9. The Art of Computer Programming
10. C++ Primer
11. to be continued