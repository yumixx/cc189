# 题目：Build Order

# 思路：
问题：topological sort
1. 贪心法。每次去找入度为0的点，移除这个点和它对应的边，同时对应连接的顶点的入度减1。重复这个过程，不断将每次移除的点加入容器中，直至整个图所有点都访问完。得到的vector即为对应的order。
2. 改良dfs。从任意点开始，访问其邻接点，若邻接点还未被访问，就递归此过程；直到其所有邻接点都访问完，将点压入栈。最后将栈中元素pop出，即为order。注意虽从任意点开始，但整个过程要进行至图中所有点都被访问过才结束。
注意：这里没有考虑环的情况。有环时，是不可能有可行的order的。

二者的时间复杂度均为O(P+D), P是projects的个数，D是dependencies的pair个数。

TODO:加入对环的考虑。如用dfs，这里对状态的标记除了VISITED,UNVISITED还要再增加一个。