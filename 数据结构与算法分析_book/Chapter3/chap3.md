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

下面的例程工作于vector和list，并且按线性时间运行。（是编写类型无关的泛型代码的一个极好的例子）

```c++
template <typename Container, typename Object>
void change(Container & c, const Object & newValue)
{
	typename Container::iterator itr=c.begin();
	while(itr != c.end())
		*itr++ = newValue;
}
```

(本小结并不是太懂)

## 3.4 向量的实现

本节给出一个可用的vector类模板的实现

C++基本数组的一些重要特性

- 数据就是指向一块内存的指针变量；实际的数组的大小必须由程序员单独确定
- 内存块可以通过new[]来分配，但是相应必须用delete[]来释放
- 内存块的大小不能改变（但是可以定义一个新的具有更大内存块的数组，并且用原来的数组来将其初始化，然后原来的内存块就可以释放了）

我们的类模板命名为Vector，其主要的细节为：

- Vecotr将仍然是基本数组（通过一个指针变量来指向分配的内存块），数组的容量和当前的数组项数目存储在Vector中
- Vector将通过实现“三大函数”，为复制构造函数和operator=提供深复制，同时也提供析构函数来回收基本数组
- Vector将提供resize例程来改变Vector的大小；提供reserve例程来改变Vector的容量。容量的改变是通过为基本数组分配一个新的内存块，然后复制旧内存块的内容到新块中，再释放旧块的内存来实现的
- Vector将提供operator[]的实现（典型实现由访问函数和修改函数两个版本）
- Vector将提供基本的例程，例如size、empty、clear、back、pop_back和push_back
- Vector将支持嵌套的iterator和const_iterator类型，并且提供关联的begin和end方法

```c++
template <typename Object>
class Vector
{
	public:
		explicit Vector(int initSize=0)
			: theSize(initSize), theCapacity(initSize+SPARE_CAPACITY)
			{objects=new Object[theCapacity];}
		Vector(const Vector & rhs): objects(NULL)
			{ operator=(rhs):}
		~Vector()
			{ delete [ ] objects;}
		
		const Vector & operator= (const Vector & rhs)
		{
			if(this != &rhs)
			{
				delete [ ] objects;
				theSize = rhs.size();
				theCapacity = rhs.theCapacity;
				
				objects = new Object[capacity()];
				for(int k=0;k<size();k++)
					objects[k] = rhs.objects[k];
			}
			return *this;
		}
		
		void resize(int newSize)
		{
			if(newSize>theCapacity)
				reserve(newSize*2+1);
			theSize = newSize;
		}
		
		void reserve(int newCapacity)
		{
			if(newCapacity<theSize)
				return;
			
			Object *oldArray = objects;
			
			objects = new Object[newCapacity];
			for(int k=0;k<theSize;k++)
				objects[k] = oldArray[k];
			
			theCapacity = newCapacity;
			
			delete [] oldArray;
		}
		Object & operator[](int index)
			{ return objects[index];}
		const Object & operator[] (int index) const
			{ return objects[index];}
			
		bool empty() const
			{ return size()==0;}
		int size() const
			{ return theSize;}
		int capacity() const
			{ return theCapacity;}
			
		void push_back( const Object & x)
		{
			if(theSize==theCapacity)
				reserve(2*theCapacity+1);
			objects[theSize++]=x;
		}
		
		void pop_back()
			{ theSize--;}
		
		const Object & back() const
			{ return objects[theSize-1];}
		
		typedef Object * iterator;
		typedef const Object * const_iterator;
		
		iterator begin()
			{ return &objects[0];}
		const_iterator begin() const
			{ return &objects[0];}
		iterator end()
			{ return &objects[size()];}
		const_interator end() const
			{ return &objects[size()];}
		
		enum { SPARE_CAPACITY=16;}
		
	praivate:
		int theSize;
		int theCapacity;
		Object * objects;
}；
```

- 第90-92行：Vector将其作为数据成员来存储大小、容量和基本数组
- 第5-7行：构造函数允许使用者自己定义初始大小（默认值为0），然后初始化数据成员，并令容量比大小稍大一点（这样就可以在不改变容量的前提下执行push_back）
- 第8-9行：复制构造函数调用operator=对已有的Vector进行复制
- 第10-11行：析构函数回收基本数组的内存空间
- 第13-26行：operator=.第15行混淆检验，第17行释放旧数组，第21行生成与所复制的Vector同样容量的新数组
- 第28-33行：resize例程。在对容量进行扩展后，代码简单地设定数据成员theSize
- 第35-49行：容量的扩展通过reserve例程来实现，该例程具有与operator[]大部分相同的逻辑。第42行分配一个新数组，第43和44行复制旧数组的内容，第48行回收旧数组
- 第50-53行：两个版本的operator[]，通过确定index是否在0至size()-1的范围内（包括size()-1)，错误检测功能可以很容易地实现，如果没有在这个范围内就抛出一个异常
- 第55-73行：许多小例程的实现，包括：empty、size、capacity、push_back、pop_back和back
- 第75-85行：内置类型的iterator和const_iterator的声明以及两个begin方法和两个end方法的声明。第75-76行，声明的typedef语句是指针变量的别名，并且begin和end需要简单地分别返回代表第一个数组位置的内存地址和第一个无效的数组位置

## 3.5 表的实现

本节提供了一个可用的list类模板的实现

List类将要作为双向链表来实现，并且需要修改指向表两端的指针

需要提供4个类：

- List类本身，包含连接到表两端的链接、表的大小以及一系列的方法
- Node类，一个结点包含数据和用来指向其前和其后的结点的指针，以及适当的构造函数
- const_iterator类，抽象了位置的概念，是一个公有的嵌套类，存储指向当前结点的指针，并且提供基本迭代器操作的实现，以及所有的重载操作符
- iterator类，抽象了位置的概念，是一个公有的嵌套类。除了operator*操作返回所指向项的引用，而不是该项的常量引用的功能外，iterator具有与const_iterator相同的功能。iterator可以用于任何需要使用const_iterator的例程里，反之不然。换句话说，iterator就是const_iterator

迭代器类存储指向“当前结点”的指针，并且尾部标志是一个有效的位置，使得在表的末尾添加一个额外的结点来作为尾部标志成为可能。也可以在表的前端生成一个额外的结点，从而逻辑上作为开始标志。这些额外的结点是**哨兵结点**，在头部的结点是**表头结点**，在末端的结点是**尾结点**

## 3.6 栈ADT

## 3.7 队列ADT

## 小结

## 练习