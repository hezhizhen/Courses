# 第3章 表、栈和队列

- 介绍抽象数据类型（ADT）的概念
- 阐述如何对表进行高效的操作
- 介绍栈ADT及其在实现递归方面的应用
- 介绍队列ADT及其在操作系统和算法设计中的应用
- 给出了两个库类vector和list的重要子集的实现代码

## 3.1 抽象数据类型（ADT）

- **ADT**是带有一组操作的一些对象的集合
- 在ADT的定义中没有提到这组操作是如何实现的
- 诸如表、集合、图以及与它们各自的操作一起形成的这些对象都可以看做是ADT
- 集合ADT有加、删除、大小、包含等操作
- 另一种集合ADT，只有并、查找两种操作

## 3.2 表ADT

处理形如$A_0,A_2,\cdots,A_{N-1}$的一般的表，大小为N

- 空表：大小为0的表
- 后继，前驱：除空表外，$A_i$后继$A_{i-1}$，$A_{i-1}$前驱$A_i$ 
- 位置：元素$A_i$在表中的位置为$i$

我们要在表ADT上进行操作的集合

- printList
- makeEmpty
- find：返回项首次出现的位置
- insert：从表的某个位置插入一些元素
- remove：从表的某个位置删除一些元素
- findKth：返回某个位置上的元素
- next：取一个位置作为参数并返回其后继元的位置
- previous：取一个位置作为参数并返回其前驱元的位置

### 3.2.1 表的简单数组实现

对表的所有操作都可以使用**数组**来实现

数组是静态分配的，但是内部存储数组的vector类允许在需要的时候将数组的大小增加一倍

数组实现使得printList以线性时间执行，而findKth花费常数时间；插入和删除在最坏情况下为$O(N)$，平均情况下需要移动一半的元素，仍需要线性时间

### 3.2.2 简单链表

链表由一系列不必在内存中相连的结点组成，每一个结点均含有**表元素**和到包含该元素后继元的结点的**链**（next链）。最后一个单元的next链指向NULL

双向链表

## 3.3 STL中的向量和表

标准模板库STL

这些数据结构称为**集合**或**容器**

表ADT的两个实现

- vector：给出了表ADT的可增长的数组实现，优点在于在常量时间内可索引，缺点是插入或删除的代价高
- list：提供了双向链表的实现，优点是插入和删除的代价小，缺点是不容易索引

两者的公共的方法

- int size() const: 返回容器内的元素个数
- void clear(): 删除容器中所有的元素
- bool empty(): 如果容器没有元素，返回true，否则返回false

两者都支持在常量的时间内在表的末尾添加或删除项，都支持在常量的时间内访问表的前端的项

- void push_back( const Object & x): 在表的末尾添加x
- void pop_back(): 删除表的末尾的对象
- const Object & back() const: 返回表的末尾的对象（也提供返回引用的修改函数）
- const Object & front() const: 返回表的前端的对象（也提供返回引用的修改函数）

仅对list有效的方法

- void push_front( const Object & x): 在list的前端添加x
- void pop_front(): 在list的前端删除对象

仅对vector有效的方法

- Object & operator[] (int idx): 返回vector中idx索引位置的对象，不包含边界检测（也提供返回常量引用的访问函数）
- Object & at (int idx): 返回vecotr中idx索引位置的对象，包含边界检测（也提供返回常量引用的访问函数）
- int capacity() const: 返回vector的内部容量
- void reserve( int new Capacity): 设定vector的新容量。如果已有良好的估计的话，可以避免对vector进行扩展

### 3.3.1 迭代器

一些表的操作，需要位置标记。在STL中，通过内置类型iterator来给出位置

- 对list<string>，位置通过类型list<string>::iterator给出
- 对vector<int>，位置由类vector<int>::iterator给出
- 依此类推

三个问题

- 如何得到迭代器
- 迭代器可以执行什么操作
- 哪些表ADT方法需要迭代器作为形参

##### 获得迭代器

- iterator begin(): 返回指向容器的第一项的一个适当的迭代器
- iterator end(): 返回指向容器的终止标志（容器中最后一项的后面的位置）的一个适当的迭代器

##### 迭代器方法

迭代器可以使用`!=`和`==`进行比较，也有复制构造函数和operator=的定义，还有许多方法（都使用操作符重载）

迭代器常见的操作

- itr++和++itr: 推进迭代器itr至下一个位置（前缀和后缀两种形式都是允许的）
- *itr: 返回存储在迭代器itr指定位置的对象的引用
- itr1==itr2: 如果itr1和itr2都指向同一个位置就返回true，否则返回false
- itr1!=itr2: 如果itr1和itr2都指向不同位置就返回true，否则返回false

```c++
for(vector<int>::iterator itr=v.begin();itr !=v.end();++itr)
	cout << *itr << endl;
```

使用操作符重载可以允许迭代器访问当前项，然后使用`*itr++`推进到下一项

```c++
vector<int>::iterator itr=v.begin();
while(itr !=v.end())
	cout << *itr++ << endl;
```

##### 需要迭代器的容器操作

三个流行的方法，在表中的特定位置添加或删除项

- iterator insert(iterator pos, const Object & x): 添加x到表中迭代器pos所指向的位置之前的位置，返回值是一个指向插入项位置的迭代器
- iterator erase(iterator pos): 删除迭代器所给出位置的对象，返回值是调用之前pos所指向元素的下一个元素的位置
- iterator erase(iterator start, iterator end): 删除所有的从位置start开始、直到位置end（但是不包括end）的所有元素（整个表的删除可以调用c.erase(c.begin(), c.end())

### 3.3.2 示例：对表使用erase

一个例程，从表的起始项开始间隔地删除项

```c++
template <typename Container>
void removeEveryOtherItem( Container & lst)
{
	typename Container::iterator itr = lst.begin();
	while(itr != lst.end() )
	{
		itr = lst.erase(itr);
		if(itr != lst.end())
			++itr;
	}
}
```

### 3.3.3 const_iterator

*itr的结果不只是迭代器指向的项的值，也是该项本身



## 3.4 向量的实现

## 3.5 表的实现

## 3.6 栈ADT

## 3.7 队列ADT

## 小结

## 练习