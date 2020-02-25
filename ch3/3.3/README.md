# 题目：Stack of Plates

# 思路：
这里不考虑popAt可能会导致的空间浪费，即不考虑在这个中间的子栈空了后将后面的子栈前移。
用vector存储stack的指针。这样可以很好的通过index来定位各个stack。
