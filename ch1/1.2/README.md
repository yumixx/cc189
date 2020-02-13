## 题目： Check Permutation

## 思路：
方法1：统计每个string中各个字母出现的次数。反正就最多256类字母。O(n)

方法2：sort string,然后比较是否相等。O(nlogn)的时间去排序，O(n)的时间去比较相等。

不需要对两个string各自统计次数后再比较，可以在check第二个string时即进行比较，因为如果要是permutation，两个string的长度肯定相等，那么统计后Letter出现次数的总和应该相同，在遍历第二个string时，去减次数，如果两个string不是Permutation，则一定会出现负的情况。

