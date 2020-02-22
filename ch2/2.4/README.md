# 题目：Partition

# 思路：
1. 分别构造两个linked list，一个存储比x小的node,一个存储比x大的node。最后将两个list连起来。这种方式得到的最后的list是stable的。
2. 可以直接构造两个node，一个为head,一个为tail，当当前node比head小，则加到head前，反之加到tail后。这样得到的list不是stable的。
