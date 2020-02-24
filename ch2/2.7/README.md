# 题目：Intersection

# 思路：
1. 如果只是要确认是否有Intersection，那么至少两个linkedlist的tail是相同的，那么只用分别遍历两个链表然后比较tail就好。
2. 如果需要找到Intersection的node，那么也是直接遍历比较，但要注意长度的差别。较长的链表在较短的链表的长度之前的Node都可以跳过不考虑。由于同时返回intersection的node和是否intersect的值，这里将intersection以二重指针的形式传入。

PS: 好像之前一直对指针作为函数参数传递有点搞错了。。