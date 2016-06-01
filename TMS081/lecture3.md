# Repetition

definition fix three things

- a sequence of random variables (the chain)
- a state space (in which the random variables take values)
- the rule for transition (the transition matrix)

##### definition 2.1 Markov chain

see it in Lecture 2

##### The Markov property

> The future depends on the past through the present

- transition matrix: a matrix containing the transition probabilities
- transition graph: a positive transition probability is represented by an arrow
- time homogeneity: the property that the transition probabilities doesn't change over time

##### simulation of Markov chains

simulating a Markov chain is about simulating the sequence of variables $X_0,X_1,X_2,\dots$

- the distribution for $X_0$ is often stated explicitly
- the distribution for $X_n$ is given by the rows of the transition matrix, that is $P(X_n=j|X_{n-1}=i)=P_{i,j}$

when writing simulation programs this is about using $U[0,1]$ random numbers to get the correct distribution in every step

### important properties

- irreducibility
- aperiodicity

final goal: the property of having stationary distributions

- theoretical property: existence of the stationary distribution
- practical utility: the distribution of $X_n$ approaches the stationary distribution as $n$ grows larger

**irreducibility** and **aperiodicity** guarantee the existence of stationary distribution

##### Irreducible Markov chains

Irreducibility is the property that regardless the present state we can reach any other state in finite time. Mathematically, $\forall i,j\in S,\exists m<\infty:P(X_{n+m}=j|X_n=i)>0$.

##### Aperiodic Markov chains

- If a state $s_i$ have period 2 is the chain can be in $s_i$  every second time, that is on even or odd times depending on where we start, but not both
- if a state has period 1, we say that it is aperiodic

when considering periodicity we always look at the set of possible times we can be in a certain state

##### Theorem 4.1

suppose we have an aperiodic Markov chain $(X_0,X_1,\dots)$ with state space $S=\{s_1,\dots,s_k\}$ and transition matrix $P$. Then there exists an $N<\infty$ such that $(P^n)_{i,i}>0$ for all $i\in \{1,\dots,k\}$ and all $n\geq N$

##### Corollary 4.1

Let $(X_0,X_1,\dots)$ be an irreducible and aperiodic Markov chain with state space $S=\{s_1,\dots,s_k\}$ and transition matrix $P$. Then there exists an $M<\infty$ such that $(P^n)_{i,j}>0$ for all $i,j\in\{1,\dots,k\}$ and all $n\geq N$
