# 算法类型基础

#### 递归算法
定义

	在定义过程中调用其本身的算法
	递归事件：用于触发递归的条件语句
	基本事件：用于结束递归的条件语句
	
要点

	堆栈级过深和栈溢出
	如果在递归算法中见到上述两种情况中的任一个，那就糟糕了
	那就意味着因为算法错误，或者问题规模太过庞大导致问题解决前 RAM 已耗尽，从而基本事件从未被触发
	必须理解：不论基本事件是否被触发，它在递归中都不可或缺
	通常用于深度优先搜索

#### 迭代算法
定义

	一种被重复调用有限次数的算法，每次调用都是一次迭代
	通常用于数据集中递增移动

要点

	通常迭代的形式为循环、for、while和until语句
	把迭代看作是在集合中依次遍历每个元素
	通常用于数组的遍历

递归 VS. 迭代

	由于递归和迭代可以相互实现，两者之间的区别很难清晰地界定。但必须知道：
	通常递归的表意性更强，更易于实现
	迭代占用的内存更少
	(i.e. Haskell)函数式语言趋向于使用递归（如 Haskell 语言）
	命令式语言趋向于使用迭代（如 Ruby 语言）
	
遍历数组的伪代码（这就是为什么使用迭代的原因）

	Recursion| Iteration
	----------------------------------|----------------------------------
	recursive method (array, n)| iterative method (array)
	if array[n] is not nil|   
		for n from 0 to size of array
			print array[n]|print(array[n])
	recursive method(array, n+1)  |
	else |
		exit loop

#### 贪婪算法
定义

	一种算法，在执行的同时只选择满足某一条件的信息
	通常包含5个部分，摘自维基百科：
	候选集，从该集合中可得出解决方案
	选择函数，该函数选取要加入解决方案中的最优候选项
	可行性函数，该函数用于决策某一候选项是否有助于解决方案
	目标函数，该函数为解决方案或部分解赋值
	解决方案函数，该函数将指明完整的解决方案

要点

	用于找到预定问题的最优解
	通常用于只有少部分元素能满足预期结果的数据集合
	通常贪婪算法可帮助一个算法降低时间 复杂度
		
伪代码：用贪婪算法找到数组中任意两个数字间的最大差值

	greedy algorithm (array)
	var largest difference = 0
	var new difference = find next difference (array[n], array[n+1])
	largest difference = new difference 
	if new difference is > largest difference
		repeat above two steps until all differences have been found
	return
		largest difference

这一算法无需比较所有数字两两之间的差值，省略了一次完整迭代。

