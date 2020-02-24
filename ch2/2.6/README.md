# 题目：Palindrome

# 思路：
1. reverse LinkedList,然后比较。注意reverse的话要重新构造一个新的list。O(n)的时间与空间。
2. 用stack，其实是类似reverse的思路。或者采用runner technique，先确定到中间元素位置，然后比较。
3. 用recursion，每次返回后是上一个node，那么需要返回往后的next node，同时需要返回一个bool量表明元素比较的情况，是否相等。这里构造了一个新的struct来存储next node和bool flag。
