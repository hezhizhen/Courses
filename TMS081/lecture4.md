# The stationary distribution, part 1

### stationary distributions

focus on Markov chains which are both irreducible and aperiodic

stationary distributions, expressing an equlibrium state for the chain

##### hitting times for a markov chain

consider the markov chain $(X_0,X_1,\dots)$ and let $X_0=s_i$ for some fixed but arbitrary state $s_i\in S$. Let $T_{i,j}=min\{n\geq 1:X_n=s_j\}$ with $T_{i,j}=\infty$ if the chain never hits $s_j$. Let $\tau_{i,j}=E[T_{i,j}]$ be the mean hitting time. The hitting time $T_{i,j}$ is the time it takes to reach state $s_j$ when starting from $s_i$

##### lemma 5.1

for any irreducible aperiodic markov chain with state space $S=\{s_1,\dots,s_k\}$ and transition martrix $P$, we have for any two states $s_i,s_j\in S$ that if the chain starts in $s_i$ then $P(T_{i,j}<\infty)=1$. Moreover, the mean hitting time $\tau_{i,j}$ is finite, i.e. $E[T_{i,j}<\infty]=1$

### Convergence of distributions

when studying how distributions converge, we need some sort of measure of how different distributions are.

##### Definition of Total variation

if $v^{(1)}=(v_1^{(1)},\dots,v_k^{(1)})$ and $v^{(2)}=(v_1^{(2)},\dots,v_k^{(2)})$ are probability distributions on $S=\{s_1,\dots,s_k\}$, then we define the total variation distance between $v^{(1)}$ and $v^{(2)}$ as follows: $d_{TV}(v^{(1)},v^{(2)})=\frac{1}{2}\sum\limits_{l=1}^k|v_i^{(1)}-v_i^{(2)}|$.

If $v^{(1)},v^{(2)},v^{(3)},\dots$ and $v$ are probability distributions on $S$, we say that $v^{(n)}$ converges to $v$ in total variation as $n\rightarrow \infty$, writing $v^{(n)}\to v$, if $lim_{n\to\infty}d_{TV}(v^{(n)},v)=0$

Another equivalent way to define total variation is the following: $d_{TV}(v^{(1)},v^{(2)})=max_{A\subseteq S}|v^{(1)}(A)-v^{(2)}(A)|$.

considering two different distributions, total variations give us the maximum difference between the probabilities they assign to any event.

##### Theorem 5.1 Existence of a stationary distributions

for any irreducible and aperiodic Markov chain, there exists at least one stationary distribution.

##### Theorem 5.2 The Markov chain convergence Theorem

Let $(X_0,X_1,\dots)$ be an irreducible aperiodic Markov chain with state space $S=\{s_1,\dots,s_k\}$, transition matrix $P$, and arbitrary initial distribution $\mu^{(0)}$. Then, for any distribution $\pi$ which is stationary for the transition matrix $P$, we have $\mu^{(n)}\to \pi$.

##### Theorem 5.3 Uniqueness if the stationary distribution

any irreducible and aperiodic Markov chain has exactly one stationary distribution.
