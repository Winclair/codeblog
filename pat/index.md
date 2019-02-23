## 题目分类与索引


+ ##### 排序、查找
    + [1062 (Talent and Virtue)](1062.cpp) 
    + [1025(PAT Ranking)](1025.md)
    + [1083(PAT Ranking)](1083.cpp)：在序列中找某个范围内的元素（**正向查找，反向查找。迭代器的应用与转换**）
    + [1080(Graduate Admission)](1080.cpp)：大学录取方法（**记得传引用给函数！**）
    + [1028(List Sorting)](1028.cpp)：数字，字符串排序（**strcmp()函数比string直接比较快！**）
    + 


+ ##### STL（标准模板库）的使用
    * [1039(Course List for Student)](1039.cpp)        **：map<string, int> 比map<int, int>在操作上要慢，可考虑哈希映射** 
    * [1054(The Dominant Color)](1054.cpp) ：在集合中查找数目最多的元素。（**用map比用set更快**）            
    * [1063(Set Similarity)](1063.cpp): 计算集合、并集的元素数目。（**copy集合会超时！**）
    * [1084(Broken Keyboard)](1084.cpp): 计算两集合(如字符串)的差集，并且按顺序输出。（**可以使其中一个为顺序序列， 一个为set**）
    



+ ##### 字符串处理
    * [1071(Speech Patterns)](1071.cpp)、 [1092(To Buy or Not to Buy)](1092.cpp)：统计文本单词、字符数目（map应用）
    * [1077(Kuchiguse)](1077.cpp): 所有子串共同后缀
    
    

+ ##### 数字处理
    * [1100(Mars Numbers)](1100.cpp)：进制转换（13——10)
    * [1048(Find Coins)](1048.cpp)：在所给序列中求两个数，其和为给定值。(**map**)
    * [1007(Maximum Subsequence Sum)](1007.cpp)：求最大子序列和。（**经典**）
    * [1046(Shortest Distance)](1046.cpp)：求序列中任何一个区间的和。（**递推算法**）
    * [1081(Rational Sum)](1081.cpp): 有理数(分数)运算 （**最大公约数**)
    * [1104(Sum of Number Segments)](1104.cpp): 所有连续子序列之和 （**排列组合、int*double*int!!!**)
    * [1152(Google Recruitment)](1152.cpp): 第一个为素数的子序列 （**素数判断**)
    * [1024(Palindromic Number)](1024.cpp): 形成回文数 （**大数相加， 回文判断**)
    * [1065 (A+B and C (64bit))](1065.cpp): 大整数溢出处理

+ ##### 整数运算
    * [(1059 Prime Factors)](1059.cpp): 质因子分解
    
    
    
    
+ ##### 空间vs时间
    * [1032 (Sharing)](1032.cpp)：求两个链表的首个共同结点的地址（**重点在地址的处理，以空间换时间**）
    * 
    
+ ##### 程序结构
    * [1116(Come on! Let's C)](1116.cpp)：诸多条件选择（**if结构**）
    * 

+ ##### 贪心算法
    * [1070(Mooncake)](1070.cpp)：分数背包问题（**先排序后贪心**） 
    * [1038(Recover the Smallest Number)](1038.cpp)：组成最小的数（**同上题**）
    * [1037 (Magic Coupon)](1037.cpp):两个序列元素积的最大和（**multiset**）
    
    
+ ##### 经典问题
    * [1040(Longest Symmetric String)](1040.cpp):求最大对称子串长度（**Manacher算法[参考链接](https://github.com/julycoding/The-Art-Of-Programming-By-July/blob/master/ebook/zh/01.05.md)**）

+ ##### 树（非链式存储：child数组或parent数组）
    * [1020 （Tree Traversals）](1020.cpp): 后序中序转平序（**递归，，以下同**）
    * [1119 (Pre- and Post-order Traversals)](1119.cpp): 后序前序转中序
    * [1086 (Tree Traversals Again)](1086.cpp): 栈转前序中序再转后序
    * [1138 Postorder Traversal](1138.cpp): 前序中序求后序第一结点（**用下标（迭代器）代替数组拷贝**）
    * [1094 (The Largest Generation)](1094.cpp): 求层节点数目（**层次遍历，以下同**）
    * [1090 (Highest Price in Supply Chain)](1090.cpp): 层数及最底层数目
    * [1106 (Lowest Price in Supply Chain)](1106.cpp): 层数及最近叶子层数目
    * [1079 (Total Sales of Supply Chain)](1079.cpp): 同上
    * [1004 (Counting Leaves)](1004.cpp): 每层的叶子数
    * [1053 (Path of Equal Weight)](1053.cpp): 求满足条件的路径（**parent数组向上遍历**）
    * [1102 (Invert a Binary Tree)](1102.cpp): 二叉树的遍历（**child数组**）
    * [1064 (Complete Binary Search Tree)](1064.cpp): 完全二叉搜索树的构建及平序（**确定root结点**）
    * [1110 (Complete Binary Tree)](1110.cpp): 判断完全树（**递归求最大的下标值**）
    
    
+ ##### 图
    * [1013 (Battle Over Cities)](1013.cpp) : 强连通分量的个数: dfs（**c格式输入输出更快**）
    * [1034 Head of a Gang](1034.cpp) : 强连通分量的个数: dfs（**hash：string--int**）
    * [1076 Forwards on Weibo](1076.cpp) : 层结点数目: bfs（**采用dfs时注意情况：1->2->4后1->4->5，当然，这个会超时**）
+ ##### 图算法
    * [1103 (Integer Factorization)](1103.cpp) : 整数因子分解（**dfs**）


+ ##### 其他
    * [1042(Shuffling Machine)](1042.cpp): 根据顺序洗牌（**map**）
    * [1069(The Black Hole of Numbers)](1069.cpp): 展示数字黑洞
    
    
+ ##### 有意思的算法
    * [1093 (Count PAT's)](1093.cpp): 字符串的pat个数。
    
