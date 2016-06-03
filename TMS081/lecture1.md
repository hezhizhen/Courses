# Randomized Algorithms: a very short introduction

- randomized algorithms are algorithms using random bits
- a randomized algorithm sometimes tosses a coin when making a decision
- Instead of having worst cases of input, randomized algorithms will a possibility of back luck for every input
- the key to using randomized algorithms is to make this probability of a back luck sufficiently small

### classify randomized algorithms

- numerical algorithm
- monte carlo algorithm
- las vegas algorithms
- simulation algorithms

##### numerical algorithm

- calculates its answer with a certain precision and a certain probability
- the result is typically an interval of confidens
- the result resembles the result of a statistical investigation, we have a parameter of interest, a confidence interval and a level of confidence

##### monte carlo algorithm

- we will always get an answer, but not always a correct one
- if the algorithm is $p$-correct, it gives a correct answer with probability $p$
- the randomness is used to guide the algorithm to its answer in a faster way with risk of making errors and not being able to detect these errors

##### las vegas algorithms

- always give a correct answer, but the execution time is random
- is the algorithms where randomness is used to find a shorter route to a correct answer

##### simulation algorithms

- any algorithm used to simulate the behavior of some phenomenon in our world
- simulation are sometimes used as a component in the other type of algorithms mentioned above

### analysis of a randomized algorithm

- analyze running time and get an upper bound on the average running time
- analyze the required amount of data storage needed during execution
- so on

### a small example

consider a small queuing system at a gateway on the Internet

- sample space: $\Omega$, the set of all possible states of the system
- state: $X_t$ is the state of the system at time $t$. $\{X_0,X_1,\dots\}$ describes what happen with the system for all times
- update function: $f:\Omega\rightarrow\Omega$ is the update function of the system. given a state $i\in\Omega$ it tosses a coin and use probabilities $P(X_{n+1}=j|X_n=i)$ to return the next state $j\in\Omega$
- a sequence of random variables $\{X_n\}_{n=1}^{\infty}$

### a peek at Markov chains

Markov property (the memoryless property): the future depend of the past only through the present
