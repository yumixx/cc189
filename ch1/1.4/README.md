# 题目： Palindrome Permutation
# 思路：
题目要确定的是这个字符串是不是一个palindrome的permutation,我们不必把这个字符串的所有permutation列出来，太费时而且没有必要，应该去考虑palindrome permutation有什么内在的特性。
如果一个字符串是palindrome permutation，考虑其中各个字符出现的次数，奇数个次数的字符一定最多只能有一个。
由于作为输入的字符串是不论大小写的，要注意一下。

因为一定会遍历string，所以是O(n)复杂度，n为string的长度。

**TODO**: Bit Vector