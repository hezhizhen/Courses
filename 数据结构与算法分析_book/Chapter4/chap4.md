# 第4章 树

二叉查找树的大部分操作的运行时间平均为$O(logN)$

- 了解树是如何用于实现几个流行的操作系统中的文件系统的
- 了解树如何用来计算算术表达式的值
- 指出如何利用树支持以$O(logN)$平均时间进行的各种搜索操作，以及如何细化以得到最坏情况时间界$O(logN)$。还将讨论当数据被存放在磁盘上时如何实现这些操作
- 讨论并使用set和map类

## 4.1 预备知识

树的递归定义：一棵树是一些结点的集合。这个集合可以是空集；若不是空集，则树由**根**结点$r$以及零或多个非空的（子）树$T_1,T_2,\cdots,T_k$组成，这些子树中每一棵的根都被来自根$r$的一条有向的**边**所连接。每一棵子树的根叫做根$r$的**儿子**，而$r$是每一棵子树的根的**父亲**

一棵树是N个结点和N-1条边的结合，其中的一个结点叫做根。每条边都将某个结点连接到它的父亲；而除去根节点外，每一个结点都有一个父亲

- 叶结点：没有儿子的结点
- 兄弟结点：具有相同父亲的结点
- 祖父
- 孙子
- 路径：从结点$n_1$到$n_k$的路径为结点$n_1,n_2,\cdots,n_k$的一个序列，使得对于$1\leq i<k$，结点$n_i$是$n_{i+1}$的父亲
- 路径的长度：路径上边的条数，即k-1 （从每一个结点到它自己有一条长为0的路径，在一棵树中从根到每个结点恰好存在一条路径）
- 深度：$n-i$的深度为从根到$n_i$唯一路径的长度 （根的深度为0）
- 高度：$n_i$的高度是从$n_i$到一片树叶的最长路径的长度 （所有的树叶的高度都是0，一棵树的高度等于它的根的高)
- 祖先/后裔：如果存在从$n_1$到$n_2$的一条路径，那么$n_1$是$n_2$的一个**祖先**，而$n_2$是$n_1$的一个**后裔**
- 真祖先/真后裔：如果$n_1\neq n_2$

### 4.1.1 树的实现

实现树的一个方法：将每个结点的所有儿子都放在树结点的链表中

```c++
struct TreeNode
{
	Object element;
	TreeNode *firstChild;
	TreeNode *nextSibling;
};
```

典型的声明

### 4.1.2 树的遍历及应用

树的应用之一：用于包括UNIX和DOS在内的许多常用操作系统中的目录结构

![UNIX目录]()

全路径名

在UNIX文件系统中的目录就是含有它的所有儿子的一个文件，在不同目录下的两个文件还可以享有相同的名字

列出目录中所有文件的名字（输出格式为：深度为$d_i$的文件将被$d_i$次跳格(tab)缩进后打印其名）

```c
void FileSystem::listAll(int depth=0) const
{
	printName(depth);// Print the name of the object
	if(isDirectory())
		for each file c in this directory(for each child)
			c.listAll(depth+1);
}
```

为了显示根时不缩进，递归函数listAll需要从深度0开始，因此需要给depth提供默认值0

- **前序遍历**：对结点的处理工作是在它的诸儿子结点被处理之前进行的
- **后序遍历**：在一个结点的工作是在它的诸儿子结点被计算后进行的

想要计算被该树所有文件占用的磁盘块的总数

```c
int FileSystem::size() const
{
	int totalSize = sizeOfThisFile();
	
	if(isDirectory())
		for each file c in this directory (for each child)
			totalSize += c.size();
			
	return totalSize;
}
```

## 4.2 二叉树

二叉树：一棵每个结点都不能有多于两个儿子的树

性质：平均二叉树的深度要比结点个数N小得多，平均深度为$O(\sqrt{N})$

二叉查找树：特殊的二叉树，平均深度为$O(logN)$，最坏情况下深度可以大到$N-1$

### 4.2.1 实现

一个结点就是由element（元素）的信息加上两个到其他结点的引用（left和right）组成的结构

```c++
struct BinaryNode
{
	Object element;    // The data in the node
	BinaryNode *left;  // Left child
	BinaryNode *right; // Right child
};
```

具有N个结点的二叉树都需要N+1个NULL链

### 4.2.2 一个例子——表达式树

- 操作数：表达式树的树叶，如常数或变量名字
- 操作符：其他结点
- 一元减运算符：只有一个儿子的结点
- 中缀表达式：
- 中序遍历：（左，结点，右）
- 后续遍历：递归地打印出左子树、右子树，然后打印操作符（根结点）
- 后缀表达式
- 前序遍历：先打印出操作符，然后递归地打印出左子树和右子树
- 前缀表达式

##### 构造一棵表达式树

把后缀表达式转变为表达式树

算法描述：一次一个符号地读入表达式。如果符号是操作数，那么就建立一个单节点树并将它推入栈中；如果符号是操作符，那么就从栈中弹出两棵树，并形成一棵新的树，该树的根就是操作符。然后将指向这棵新树的指针压入栈中。

（自己画个图就清楚了）

## 4.3 查找树ADT——二叉查找树

使二叉树成为二叉查找树的性质：对于树中的每个结点X，它的左子树中所有项的值小于X中的项，而它的右子树中所有项的值大于X中的项

```c++
template <typename Comparable>
class BinarySearchTree
{
	public:
		BinarySearchTree();
		BinarySearchTree( const BinarySearchTree & rhs);
		~BinarySearchTree();
		
		const Comparable & findMin() const;
		const Comparable & findMax() const;
		bool contains( const Comparable & x) const;
		bool isEmpty() const;
		void printTree() const;
		
		void makeEmpty();
		void insert( const Comparable & x);
		void remove( const Comparable & x);
		
		const BinarySearchTree & operator=( const BinarySearchTree & rhs);
		
	private:
		struct BinaryNode
		{
			Comparable element;
			BinaryNode *left;
			BinaryNode *right;
			
			BinaryNode( const Comparable & theElement, BinaryNode *lt, BinaryNode *rt)
				: element( theElement), left(lt), right(rt){}
		};
		
		BinaryNode *root;
		
		void insert( const Comparable & x, BinaryNode * & t) const;
		void remove( const Comparable & x, BinaryNode * & t) const;
		BinaryNode * findMin( BinaryNode *t) const;
		BinaryNode * findMax( BinaryNode *t) const;
		bool contains( const Comparable & x, BinaryNode *t) const;
		void makeEmpty( BinaryNode * & t);
		void printTree( BinaryNode *t) const;
		BinaryNode * clone( BinaryNode *t) const;
};
```

BinarySearchTree类模板的接口。查找是基于“<”操作符的，而该操作符对特定的Comparable类型必须定义

- 数据成员是指向树根结点的指针，该指针对空树为NULL
- public的成员函数使用调用private递归函数的常规技术
- private成员函数使用引址调用来传递指针变量的技术，这允许public成员函数将指向树根的指针传递给private递归成员函数，然后递归函数就可以改变根的值，于是root就可以指向其他的结点

### 4.3.1 contains

如果在树T中有项为X的结点，那么contains操作就返回true，否则就返回false。

如果T为空，那么返回false；否则，如果存储在T中的项为X，就返回true。若以上两种情况都不成立，就对T的一个子树进行递归调用

```c++
// Return true if x is found in the tree
bool contains( const Comparable & x) const
{
	return contains(x, root);
}
// Insert x into the tree; duplicates are ignored
void insert( const Comparable & x)
{
	insert(x, root);
}
// Remove x from the tree. Nothing is done if x is not found
void remove( const Comparable & x)
{
	remove(x, root);
}
```

above为公有成员函数调用私有递归成员函数的示例

```c++
// Internal method to test if an item is in a subtree
// x is item to search for
// t is the node that roots the subtree
bool contains( const Comparable & x, BinaryNode *t) const
{
	if(t==NULL)
		return false;
	else if(x < t->element)
		return contains(x, t->left);
	else if(t->element < x)
		return contains(x, t->right);
	else
		return true; // Match
}
```

above为二叉查找树的contains操作

关键的问题是首先要对是否为空树进行测试

尾递归：递归调用都是在函数的末尾

```c++
template <typename Object, typename Comparator=less<Object> >
class BinarySearchTree
{
	public:
		// Same methods, with Object replacing Comparable
	private:
		BinaryNode *root;
		Comparator isLessThan;
		// Same methods, with Object replacing Comparable
		
		// Internal method to test if an item is in a tree
		// x is item to search for
		// t is the node that roots the subtree
		bool contains( const Object & x, BinaryNode *t) const
		{
			if(t==NULL)
				return false;
			else if(isLessThan(x, t->element))
				return contains(x, t->left);
			else if(isLessThan(t->element, x))
				return contains(x,t->right);
			else
				return true;//Match
		}
};
```

### 4.3.2 findMin和findMax

### 4.3.3 insert

### 4.3.4 remove

### 4.3.5 析构函数和复制赋值操作符

### 4.3.6 平均情况分析

## 4.4 AVL树

## 4.5 伸展树

## 4.6 树的遍历

## 4.7 B树

## 4.8 标准库中的set和map