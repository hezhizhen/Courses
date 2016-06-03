# Markov chains - an example

1. the Markov property
2. time homogeneity
3. transition matrix
4. transition graph

##### Definition 2.1 Markov chains

Let $P$ be a $k\times k$-matrix with elements {$P_{i,j}: i,j=1,\dots,k$}. A random process $(X_0, X_1,\dots)$ with finite state space S={$s_1,s_2,\cdots,s_k$} is said to be a (homogenous) Markov chain with transition matrix $P$ if for all n $n$, all $i,j\in \{1,\dots,k\}$ and all $i_0,\dots,i_{n-1}\in \{1,\dots,k\}$ we have $P(X_{n+1}=s_j|X_0=i_0,X_1=i_1,\dots,X_{n-1}=i_{n-1},X_n=i)=P(X_{n+1}=s_j|X_n=i)=P_{i,j}$

##### Theorem 2.1

For a Markov chain $(X_0,X_1,\dots)$ with state space S={$s_1,s_2,\dots,s_k$}, initial distribution $\mu^{(0)}$ and transition matrix $P$, we have for any $n$ that the distribution $\mu^{(n)}$ at any time $n$ satisfies $\mu^{(n)}=\mu^{(0)}P^n$
