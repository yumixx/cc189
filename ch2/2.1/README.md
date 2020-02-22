# 题目：Remove Dups

# 思路：
两种方法。
1. 说到duplicates，那么很容易想到hash table。
2. 用两个指针，做双重循环。即，对每一个Node，将其与其后所有的Node进行比较，移除掉重复项。
以上两种方法都需要保存一个previous node，同时注意在remove duplicates时要把不再使用的指针delete掉。
