# 经典排序算法

### 1.冒泡排序
	时间复杂度：O(n^2)		空间复杂度：O(1)		稳定排序
	
	基本思想：两两比较相邻记录的关键字，逆序则交换。
	
	优化：
		1.设置标记位，如果序列提前完成排序，则函数直接返回。
		2.记录本轮中未排序的终点，下次遍历直接做这中间的排序即可。
		
[源代码](https://github.com/ywang2014/Rookie/tree/master/Src/sort/bubbleSort)

### 2.插入排序
	时间复杂度：O(n^2)		空间复杂度：O(1)		稳定排序
	
	基本思想：将一个元素，插入到已排序好的列表中，得到一个新的有序表，一直插入n个元素，则完成排序。
	
[源代码](https://github.com/ywang2014/Rookie/tree/master/Src/sort/insertSort)

### 3.选择排序
	时间复杂度：O(n^2) 		空间复杂度：O(1)	不稳定排序
	
	基本思想：每次选择序列中最小的元素，添加到有序数列的末尾即可
	
[源代码](https://github.com/ywang2014/Rookie/tree/master/Src/sort/selectSort)

### 4.快速排序
	时间复杂度：平均-O(n*log(n)) 最坏-O(n^2)		空间复杂度：O(1)		不稳定排序
	
	基本思想：选择一个轴点，通过一次遍历，将数列分成两个部分，小于轴点的元素放在左边，大于轴点的数放在右边。然后
	通过递归的方法，分别处理左边和右边部分，直到分为1个元素时，即排序完成。
	
	优化：
		1.三点取中法，解决快排对于有序数列的退化情况
		2.借用随机数生成器，选择轴点，也可以处理有序数列的退化情况
		3.对于很多相等数字情况，分三部分，小于轴点，等于轴点，大于轴点
		4.元素少于10个的时候，使用插入排序，代替快速排序
	
[源代码](https://github.com/ywang2014/Rookie/tree/master/Src/sort/quickSort)

### 5.归并排序
	时间复杂度：O(n*log(n))		空间复杂度：O(n+log(n))		稳定排序
	
	基本思想：将含有n个元素的序列看做n个含有一个元素的序列，两两归并，一直递归到最后。
	
[源代码](https://github.com/ywang2014/Rookie/tree/master/Src/sort/bubbleSort)

### 6.堆排序
		时间复杂度：O(n*log(n))		空间复杂度：O(1)		不稳定排序
		
		基本思想：利用堆结构，进行排序。
		第一步，将序列构造成一个大根堆，则序列的最大值即为堆的跟节点值，将堆顶元素与最后元素交换(即删除)，构造剩下的n-1个节点的堆，
		最终剩下一个节点时，则排序完成。
		
[源代码](https://github.com/ywang2014/Rookie/tree/master/Src/sort/bubbleSort)

### 7.希尔排序
	时间复杂度：与选择步长序列有关，最优的O(n*log(n))		空间复杂度：O(1)		不稳定排序
	
	基本思想：
	
[源代码](https://github.com/ywang2014/Rookie/tree/master/Src/sort/bubbleSort)

### 8.基数排序
	时间复杂度：O(n)		空间复杂度：O(n+k)		稳定排序
	
	基本思想：
	
[源代码](https://github.com/ywang2014/Rookie/tree/master/Src/sort/bubbleSort)

### 9.计数排序
	时间复杂度：O(n+k)		空间复杂度：O(n+k)		稳定排序
	
	基本思想：
	
[源代码](https://github.com/ywang2014/Rookie/tree/master/Src/sort/bubbleSort)

### 10.桶排序
	时间复杂度：O(n)	空间复杂度：O(2n)		稳定排序
	
	基本思想：
	
[源代码](https://github.com/ywang2014/Rookie/tree/master/Src/sort/bubbleSort)

#### 相关定义
**稳定排序**

所有相等的数经过某种排序方法后，仍能保持它们在排序之前的相对次序

**非稳定排序**

所有相等的数经过某种排序方法后，不能保持它们在排序之前的相对次序

**内部排序**

如果在排序过程中，所有需要排序的数都能够放进内存中，直接在内存中调整它们的存储顺序

**外部排序**

如果在排序过程中，需要排序的数据量过于庞大，不能一次存储进内存中，只有一部分一部分数据调入内存，进行排序，并借助内存调整数在外存中的存放顺序排序

**inline**

内敛函数(在线函数)：直接展开，效率更高，但是大型程序中，多个包含头文件时，存在重复定义等问题	C语言的 宏
