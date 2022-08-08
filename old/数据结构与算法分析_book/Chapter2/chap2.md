# 第2章 算法分析

算法是为求解一个问题需要遵循的、被清楚地指定的简单指令的集合

- 如何估计一个程序所需要的时间
- 如何将一个程序的运行时间从天或年降低到不足一秒
- 粗心地使用递归的后果
- 用于将一个数自乘得到其幂以及计算两个数的最大公因数的非常有效的算法

## 2.1 算法基础

4个定义

1. 如果存在正常数$c$和$n_0$ s.t. 当$N\ge n_0$时$T(N)\le cf(N)$，则记为$T(N)=O(f(N))$
2. 如果存在正常数$c$和$n_0$ s.t. 当$N\ge n_0$时$T(N)\ge cg(N)$，则记为$T(N)=\Omega(g(N))$
3. $T(N)=\Theta(h(N))$ iff $T(N)=O(h(N))$和$T(N)=\Omega(h(N))$
4. 如果对所有的常数$c$存在$n_0$ s.t. 当$N>n_0$时$T(N)<cp(N)$，则记为$T(N)=o(p(N))$ (如果$T(N)=O(p(N))$且$T(N)\neq\Theta(p(N))$，则$T(N)=o(p(N))$ )

相对增长率

1. T(N)的增长率小于等于f(N)的增长率 （上界）
2. T(N)的增长率大于等于g(N)的增长率 （下界）
3. T(N)的增长率等于h(N)的增长率
4. T(N)的增长率小于p(N)的增长率

大O记法

重要结论

1. 如果$T_1(N)=O(f(N))$且$T_2(N)=O(g(N))$，则：
	1. $T_1(N)+T_2(N)=O(f(N)+g(N))$ ( $max(O(f(N)), O(g(N)) )$ )
	2. $T_1(N)T_2(N)=O(f(N)g(N))$
2. 如果$T(N)$是一个k次多项式，则$T(N)=\Theta(N^k)$
3. 对任意常数k，$log^kN=O(N)$ (对数增长得非常缓慢)

线性函数

## 2.2 模型

为了在形式的框架中分析算法，我们需要一个计算模型

- 一台标准的计算机，在机器中指令被顺序地执行
- 有一个标准的简单指令系统，如加法、乘法、比较和赋值等
- 做任意一件简单的工作都恰好花费一个时间单位
- 有定长的整数并且不存在诸如矩阵求逆或排序运算
- 有无限的内存

## 2.3 要分析的问题

1. 运行时间
	1. 影响程序运行时间的因素：编译器和计算机，所使用的算法，对该算法的输入
	2. 典型情形：输入的大小是主要的考虑方面。我们定义两个函数$T_{avg}(N)和T_{worst}(N)$，分别为算法对于输入N所花费的平均情形的和最坏情形的运行时间
2. 一个算法最好情形的性能
	1. 平均情形性能常常反映典型的结果
	2. 最坏情形的性能则代表对任何可能的输入在性能上的一种保证

**最大的子序列和问题**：给定整数$A_1,A_2,\cdots,A_N$（可能有负数），求$\sum\limits_{k=i}^{j} A_k$的最大值（若所有整数均为负数，则最大子序列和为0）

- 如果只是小量输入的情形，那么花费大量的努力去设计聪明的算法就不太值得了
- 给出的时间不包括读入数据所需要的时间，而仅仅从磁盘读入数据所用的时间可能在数量级上比求解问题所需要的时间还要大 （这是很多高效算法的典型特点）。数据的读入一般是瓶颈

## 2.4 运行时间计算

要确定哪个程序更快的最好方法可能就是把它们编码并运行

### 2.4.1 一个简单的例子

计算$\sum\limits_{i=1}^{N}i^3$的总量是6N+4个时间单位，所以该方法是$O(N)$

### 2.4.2 一般法则

1. for循环：一个for循环的运行时间至多是该for循环内语句（包括测试）的运行时间乘以迭代的次数
2. 嵌套循环：从里向外分析这些循环。在一组嵌套循环内部的一条语句总的运行时间为该语句的运行时间乘以该组所有循环的大小的乘积
3. 顺序语句：将各语句的运行时间求和即可
4. if/else语句：一个if/else语句的运行时间从不超过判断再加上各自执行语句中运行时间较长者的总的运行时间

### 2.4.3 最大子序列和问题的解

##### 第一个算法

```c++
// Cubic maximum contiguous subsequence sum algorithm
int maxSubSum1(const vector<int> & a)
{
	int maxSum = 0;
	for(int i=0;i<a.size();i++)
		for(int j=i;j<a.size();j++)
		{
			int thisSum=0;
			for(int k=i;k<=j;k++)
				thisSum += a[k];
			if(thisSum>maxSum)
				maxSum = thisSum;
		}
	return maxSum;
}
```

精确的分析由和$\sum\limits_{i=0}^{N-1}\sum\limits_{j=i}^{N-1}\sum\limits_{k=i}^{j}1=\frac{N^3+3N^2+2N}{6}$得到

##### 第二个算法

```c++
// Quadratic maximum contiguous subsequence sum algorithm
int maxSubSum2(const vector<int> & a)
{
	int maxSum = 0;
	for(int i=0;i<a.size();i++)
	{
		int thisSum = 0;
		for(int j=i;j<a.size();j++)
		{
			thisSum += a[j];
			if(thisSum>maxSum)
				maxSum = thisSum;
		}
	}
	return maxSum;
}
```

##### 第三个算法

分治策略：把问题分成两个大致相等的子问题，然后递归地对它们求解；将两个子问题的解合并到一起并可能再做少量的附加工作，最后得到整个问题的解

这个问题中，最大子序列和可能出现在三处地方：或者整个出现在输入数据的左半部，或者整个出现在右半部，或者跨越输入数据的中部从而占据左右两半部分。前两种情况可以递归求解；第三种情况的最大和可以通过求出前半部分的最大和（包含前半部分最后一个元素）以及后半部分的最大和（包含后半部分的第一个元素），然后加在一起。

```c++
// Recursive maximum contiguous subsequence sum algorithm
// Finds maximum sum in subarray spanning a[left..right]
// Does not attempt to maintain actual best sequence
int maxSumRec(const vector<int> & a, int left, int right)
{
	if(left == right)//Base case: 只有一个元素
		if(a[left]>0)
			return a[left];
		else
			return 0;
	int center=(left+right)/2;
	int maxLeftSum=maxSumRec(a,left,center);
	int maxRightSum=maxSumRec(a,center+1,right);
	
	int maxLeftBorderSum=0, leftBorderSum=0;
	for(int i=center;i>=left;i--)
	{
		leftBorderSum += a[i];
		if(leftBorderSum>maxLeftBorderSum)
			maxLeftBorderSum=leftBorderSum;
	}
	int maxRightBorderSum=0, rightBorderSum=0;
	for(int i=center+1;i<=right;i++)
	{
		rightBorderSum += a[i];
		if(rightBorderSum>maxRightBorderSum)
			maxRightBorderSum=rightBorderSum;
	}

	return max3(maxLeftSum, maxRightSum, maxLeftBorderSum+maxRightBorderSum);
}

// Driver for divide-and-conquer maximum contiguous subsequence sum algorithm
int maxSubSum3(const vector<int> & a)
{
	return maxSumRec(a,0,a.size()-1);
}
```

对运行时间的分析：

令$T(N)$是求解大小为N的最大子序列和问题所花费的时间。有方程组$T(1)=1;T(N)=2T(N/2)+O(N)$ (计算时可以用N代替O(N))。通过对前面若干次的计算，从形式中得到，若$N=2^k$，则$T(N)=N\times(k+1)=N(logN+1)=O(NlogN)$ (当N不是2的幂时，分析会复杂一些，但是结果不变)

##### 第四种算法

```c++
// Linear-time maximum contiguous subsequence sum algorithm
int maxSubSum4( const vector<int> & a)
{
	int maxSum = 0, thisSum = 0;
	for(int j=0;j<a.size();j++)
	{
		thisSum += a[j];
		if(thisSum>maxSum)
			maxSum = thisSum;
		else if(thisSum<0)
			thisSum = 0;
	}
	return maxSum;
}
```

改进：

- i代表当前序列的起点，而我们不需要知道最佳的子序列在哪里，所以i可以优化掉
- 如果a[i]是负的，那么它不可能代表最优序列的起点
- 任何负的子序列不可能是最优子序列的前缀。如果在内循环中检测到从a[i]到a[j]的子序列是负的，则我们可以推进到j+1

联机算法：在任意时刻，算法都能对它已经读入的数据给出子序列问题的正确答案。具有这种特性的算法是联机算法

仅需要常量空间并以线性时间运行的联机算法几乎是完美的算法

### 2.4.4 运行时间中的对数

某些分治算法将以$O(NlogN)$时间运行

对数最常出现的规律：如果一个算法用常数时间$O(1)$将问题的大小削减为其一部分(通常是1/2)，那么该算法就是$O(logN)$的；如果使用常数时间只是把问题减少一个常数的数量（比如减少1），那么这种算法是$O(N)$的

**二分搜索**：给定一个整数$X$和整数$A_0,A_1,\cdots,A_{N-1}$，后者已经预先排序并在内存中，求下标$i$使得$A_i=X$，如果$X$不在数据中，则返回$i=-1$

```c++
// Perform the standard binary search using two comparisons per level
// Return index where item is found or -1 if not found
template <typename Comparable>
int binarySearch(const vector<Comparable> & a, const Comparable & x)
{
	int low=0, high=a.size()-1;
	while(low<=high)
	{
		int mid=(low+high)/2;
		if(a[mid]<x)
			low=mid+1;
		else if(a[mid]>x)
			high=mid-1;
		else
			return mid;//Found
	}
	return NOT_FOUND;// defined as -1
}
```

二分索索提供了在$O(logN)$时间内的contains操作，但是所有其他操作（特别是insert操作）均需要$O(N)$时间。在数据是稳定（即不允许插入操作和删除操作）的应用中非常有用

**欧几里得算法**

```c++
long gcd(long m, long n)
{
	while(n!=0)
	{
		long rem=m % n;
		m=n;
		n=rem;
	}
	return m;
}
```

通过连续计算余数直到余数是0为止，最后的非零余数就是最大公因数

定理2.1：如果$M>N$，则$M mod N<M/2$ (证明分N<=M/2和N>M/2两种情况)

**幂运算**

- 如果N是偶数：$X^N=X^{N/2}\cdot X^{N/2}$
- 如果N是奇数：$X^N=X^{(N-1)/2}\cdot X^{(N-1)/2}\cdot X$

```c++
long pow(long x, int n)
{
	if(n==0)
		return 1;
	if(n==1)
		return x;
	if(isEven(n))
		return pow(x*x,n/2);
	else
		return pow(x*x,n/2)*x;
}
```

### 2.4.5 检验你的分析

分析进行之后，要看答案是否正确，是否尽可能地好

一种方法是编程并比较实际观察到的运行时间是否与通过分析所描述的运行时间所匹配

- 线性程序：N扩大一倍，运行时间乘以2
- 二次程序：N扩大一倍，运行时间乘以4
- 三次程序：N扩大一倍：运行时间乘以8
- 对数程序：N扩大一倍，运行时间只是多加一个常数
- $O(NlogN)$程序：N扩大一倍，运行时间为两倍多一些的时间

验证已给程序是否是O(f(N))的另一个常用技巧是对N的某个范围计算比值T(N)/f(N)（通常用2的倍数隔开），其中T(N)是凭经验观察到的运行时间。

- 如果f(N)是运行时间的理想近似，则所算出的值收敛于一个正常数
- 如果f(N)估计过大，则算出的值收敛于0
- 如果f(N)估计过低，则算出的值发散

```c++
double probRelPrime(int n)
{
	int rel=0, tot=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			tot++;
			if(gcd(i,j)==1)
				rel++;
		}
	return (double)rel/tot;
}
```

### 2.4.6 分析结果的准确性

经验指出，有时分析会估计过大

对于许多复杂的算法，最坏的界通过某个不良输入是可以达到的，但在实践中它通常是估计过大的

## 小结

下界的证明一般是最难的，因为它们不只适用求解某个问题的一个算法，而是适用求解该问题的一类算法

## 练习

## 参考文献