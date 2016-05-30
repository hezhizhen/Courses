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

这两个private例程分别返回指向树中包含最小元和最大元的结点的指针。

- 执行findMin，从根开始并且只要有左儿子就向左进行，终止点就是最小的元素
- findMax例程除分支朝向右儿子外其余过程相同

```c++
// Internal method to find the smallest item in a subtree t
// Return node containing the smallest item
BinaryNode * findMin(BinaryNode *t) const
{
	if(t==NULL)
		return NULL;
	if(t->left==NULL)
		return t;
	return findMin(t->left);
}
```

```c++
// Internal method to find the largest item in a subtree t
// Return node containing the largest item
BinaryNode * findMax( BinaryNode *t) const
{
	if(t!=NULL)
		while(t->right!=NULL)
			t=t->right;
	return t;
}
```

findMin用递归编写，而findMax用非递归编写

处理空树的退化情况

### 4.3.3 insert

为了将X插入到树T中，可以像使用contains那样沿着树查找。如果找到X，则什么也不做；否则，将X插入到遍历的路径上的最后一点上

重复元的插入可以通过在结点记录一个附加字段以指示此数据元出现的频率来处理，这使整个树增加了某些附加空间，但是，却比将重复信息放到树中要好（将使树的深度变得很大）

可以把具有相同键的所有结构保留在一个辅助数据结构中，如表或是另一棵查找树

```c++
// Internal method to insert into a subtree
// x is the item to insert
// t is the node that roots the subtree
// Set the new root of the subtree
void insert( const Comparable & x, BinaryNode *& t)
{
	if (t==NULL)
		t=new BinaryNode(x,NULL,NULL);
	else if(x<t->element)
		insert(x,t->left);
	else if( t->element < x)
		insert (x, t->right);
	else
		; //Duplicate; do nothing
}
```

上述为插入例程，递归地将x插入到适当的子树中。只有当一个新树叶生成的时候，t才改变

### 4.3.4 remove

删除的几种情况：

- 结点是树叶：可以立即删除
- 结点有一个儿子：该结点在其父结点调整它的链以绕过该结点后被删除（将该结点的父结点指向它的链改成指向它的儿子的链）
- 结点具有两个儿子：用其右子树的最小的数据代替该结点的数据，并递归地删除那个结点

```c++
// Internal method to remove from a subtree
// x is the item to remove
// t is the node that roots the subtree
// Set the new root of the subtree
void remove( const Comparable & x, BinaryNode * & t)
{
	if(t==NULL)
		return;// Item not found; do nothing
	if(x<t->element)
		remove(x,t->left);
	else if (t->element<x)
		remove(x,t->right);
	else if(t->left!=NULL && t->right!=NULL)// two children
	{
		t->element = findMin(t->right)->element;
		remove(t->element, t->right);
	}
	else
	{
		BinaryNode * oldNode = t;
		t=(t->left!=NULL)?t->left:t->right;
		delete oldNode;
	}
}
```

如果删除的次数不多，则策略为**懒惰删除**

懒惰删除：当一个元素要被删除时，它仍留在树种，而只是做了个被删除的记号（这种做法在有重复项时很常见）

### 4.3.5 析构函数和复制赋值操作符

析构函数调用makeEmpty

共有的makeEmpty则简单调用私有的递归版本的makeEmpty

```c++
// Destructor for the tree
~BinarySearchTree()
{
	makeEmpty();
}
// Internal method to make subtree empty.
void makeEmpty( BinaryNode * & t)
{
	if(t != NULL)
	{
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}
	t->NULL;
}
```

在递归地处理t的子树之后，对t调用delete，使所有结点都递归回收。最后t改为指向NULL

复制赋值运算符首先调用makeEmpty来回收内存，然后进行rhs的复制

```c++
// Deep copy
const BinarySearchTree & operator=(const BinarySearchTree & rhs)
{
	if(this != &rhs)
	{
		makeEmpty();
		root=clone(rhs.root);
	}
	return *this;
}
// Internal method to clone subtree
BinaryNode * clone (BinaryNode *t) const
{
	if(t==NULL)
		return NULL;
	return new BinaryNode(t->element, clone(t->left), clone(t->right));
}
```

### 4.3.6 平均情况分析

所有操作（除了makeEmpty和operator=）的运行时间都是$O(d)$，其中d是包含所访问项的结点的深度

to prove: 如果所有的插入序列都是等可能的，那么，树的所有结点的平均深度为$O(logN)$

**内部路径长**：一棵树的所有结点的深度和

令D(N)是具有N个结点的某棵树T的内部路径长，D(1)=0。一棵N结点树是由一棵i结点左子树和一棵(N-i-1)结点右子树以及深度为0的一个根节点组成，其中$0\leq i<N$,D(i)为根的左子树的内部路径长。但是在原树中，所有这些结点都要加深一层。同样的结论对右子树也成立。由此得到递推关系：$$D(N)=D(i)+D(N-i-1)+N-1$$

如果所有子树的大小都是等可能出现，这对于**二叉查找树**是成立的（因为子树的大小只依赖于第一个插入到树中的元素的相对的秩），但对二叉树不成立。那么D(i)和D(N-i-1)的平均值都是$(1/N)\sum\limits_{j=0}^{N-1}D(j)$。于是$$D(N)=\frac{2}{N}[\sum\limits_{j=0}^{N-1}D(j)]+N-1$$

最终得到的平均值为$D(N)=O(NlogN)$，因此任意结点预期的深度为$O(logN)$

上面描述的删除算法会使得左子树比右子树深度深，因为总是用右子树的一个结点来代替删除的结点。已经证明，如果交替插入和删除$\Theta(N^2)$次，那么树的期望深度将是$\Theta(\sqrt{N})$。在删除操作中，可以通过随机选取右子树的最小元素或左子树的最大元素来代替被删除的元素以消除这种不平衡问题

**平衡**条件：任何结点的深度不得过深

**自调整**类结构

在二叉查找树的情况下，对于任意单个运算我们不再保证$O(logN)$的时间界，但是可以证明任意连续M次操作在最坏的情形下花费时间$O(M logN)$

## 4.4 AVL树

AVL树是带有**平衡条件**的二叉查找树

必须保证树的深度是$O(logN)$，最简单的想法是要求左右子树具有相同的高度

另一个平衡条件是要求每个结点都必须有相同高度的左子树和右子树，则只有具有$2^k-1$个结点的理想平衡树才能满足这条件

空子树的高度定义为-1

AVL树：每个结点的左子树和右子树的高度最多差1的二叉查找树

在高度为h的AVL树中，最少结点数S(h)=S(h-1)+S(h-2)+1给出。对于h=0，S(h)=1; h=1, S(h)=2。函数S(h)与斐波那契数密切相关。

除去可能的插入外，所有的树操作都可以以时间$O(logN)$执行。当进行插入时，需要更新通向根结点路径上那些结点的所有平衡信息，而插入操作隐含着困难的原因在于，插入一个结点可能破坏AVL树的特性，需要恢复平衡的性质之后才能认为插入完成。修正的操作叫做**旋转**

只有那些从插入点到根结点的路径上的结点的平衡可能被改变，因为只有这些结点的子树可能发生变化

把必须重新平衡的结点叫做$\alpha$。由于任意结点最多有两个儿子，因此高度不平衡时，$\alpha$点的两棵子树的高度差2.这种不平衡可能出现在下面4种情况中：

- 对$\alpha$的左儿子的左子树进行一次插入
- 对$\alpha$的左儿子的右子树进行一次插入
- 对$\alpha$的右儿子的左子树进行一次插入
- 对$\alpha$的右儿子的右子树进行一次插入

第一种和最后一种情况是关于$\alpha$点的镜像对称，而中间两种情况也是关于$\alpha$点的镜像对称，因此只需要考虑两种情况即可

第一种情况是插入发生在“外边”的情形，通过对树的一次**单旋转**可完成调整；第二种情况是插入发生在“内部”的情形，通过稍复杂的**双旋转**来处理

### 4.4.1 单旋转

抽象的形容就是：把树形象地看成是柔软灵活的，抓住子结点$k_1$，使劲摇动它，在重力作用下，$k_1$就变成了新的根。

### 4.4.2 双旋转

要将项为X的一个新结点插入到一棵AVL树T中去，我们递归地将X插入到T的相应的子树$T_{LR}$中。如果$T_{LR}$的高度不变，那么插入完成；否则，如果在T中出现高度不平衡，那么根据X以及T和$T_{LR}$中的项做适当的单旋转或双旋转，更新这些高度并解决好与树的其余部分的链接，从而完成插入。

```c++
struct AvlNode
{
	Comparable element;
	AvlNode *left;
	AvlNode *right;
	int height;
	AvlNode( const Comparable & theElement, AvlNode *lt, AvlNode *rt, int h=0)
		: element(theElement), left(lt), right(rt), height(h)
};

// Return the height of node t or -1 if NULL
int height(AvlNode *t) const{
	return t==NULL ? -1:t->height;
}

// Internal method to insert into a subtree
// x is the item to insert
// t is the node that roots the subtree
// Set the new root of the subtree
void insert( const Comparable & x, AvlNode * & t)
{
	if(t==NULL)
	{
		t=new AvlNode(x, NULL, NULL);
	}
	else if(x<t->element)
	{
		insert(x,t->left);
		if(height(t->left)-height(t->right)==2)
			if(x<t->left->element)
				rotateWithLeftChild(t);
			else
				doubleWithLeftChild(t);
	}
	else if(t->element<x)
	{
		insert(x,t->right);
		if(height(t->right)-height(t->left)==2)
			if(t->right->element<x)
				rotateWithLeftChild(t);
			else
				doubleWithLeftChild(t);
	}
	else
		;//Duplicate; do nothing
	t->height=max(height(t->left),height(t->right))+1;
}

// Rotate binary tree node with left child
// For AVL trees, this is a single rotation for case 1
// Update heights, then set new root
void rotateWithLeftChild(AvlNode * & k2)
{
	AvlNode *k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;
	k2->height = max(height(k2->left), height(k2->right))+1;
	k1->height = max(height(k1->left), k2->height)+1;
	k2 = k1;
}

// Double rotate binary tree node: first left child
// with its right child; then node k3 with new left child
// For AVL trees, this is a double rotation for case 2
// Update heights, then set new root
void doubleWithLeftChild(AvlNode * & k3)
{
	rotateWithLeftChild(k3->left);
	rotateWithLeftChild(k3);
}
```

函数rotateWithLeftChild把左边的树变成右边的树，并返回指向新根的指针。该函数是对称的

## 4.5 伸展树

伸展树保证从空树开始任意连续M次对树的操作最多花费$O(MlogN)$时间。不存在不好的输入序列

当M次操作的序列总的最坏情形运行时间为$O(Mf(N))$时，我们就说它的**摊还**运行时间为$O(f(N))$

一棵伸展树每次操作的摊还代价是$O(logN)$

伸展树基于如下事实：对于二叉查找树而言，每次操作最坏情形时间$O(N)$并非不好，只要它相对不常发生就行。任何一次访问，即使发生$O(N)$，仍然可能非常快。累积的运行时间很重要

只要有一个结点被访问，它就必须被移动；否则，一旦我们发现一个深层的结点，就有可能不断地对它进行访问

基本想法：当一个结点被访问后，，它就要经过一系列AVL树的旋转被推到根上。

### 4.5.1 一个简单的想法（不能直接使用）

实施上面描述的重新构造的一种方法是执行单旋转，自底向上进行。这意味着将对访问路径上的每一个结点和它们的父结点实施旋转。

使用这种策略将会存在一系列M个操作共需要$\Omega{M\cdot N}$的时间

### 4.5.2 伸展



## 4.6 树的遍历

## 4.7 B树

## 4.8 标准库中的set和map
