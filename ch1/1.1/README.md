## 题目：Is Unique

## 思路：
首先确定string是ASCII还是Unicode。
假如是ASCII，是标准的128个还是256个（extended）？
思路类似构建hash table，用一个bool数组表示各个char是否已出现（遍历string），index即为char的ASCII码。
以这种方式，时间复杂度为O(n)，n为string的长度，空间复杂度为O(1)。

若不用其他数据结构，则双层遍历，时间复杂度为O(n²)，空间复杂度O(1)。

如果可以修改string，可先sort - O(nlogn)，再线性检查相邻元素是否相同。但由于sort可能需要额外的空间。