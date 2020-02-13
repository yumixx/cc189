# 题目：One Away

# 思路：
一个比较直接的想法是分三种情况讨论，取决于两个字符串的长度。
再进一步，其实只有两种情况，相等与相差1的情况。
再进一步，可以把三种情况一起讨论。此时我们关注于那个长度更短的字符串。

此前还有一个想法，就是像前面几题一样，去统计两个字符串中所有字符的出现情况。但是这其实不是一个适合这道题的方式，因为在本题中，字符按照顺序匹配是很重要的，而且也没有必要全统计出来。

时间复杂度O(n)，n为较短字符串的长度。