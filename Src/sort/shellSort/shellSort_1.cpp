/**
* 	希尔排序算法优化
*	
*	改变其增量序列，那个显著改变效率
*	比如：2^k-1 增量序列
*
*	C++
*/
inline void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

// 优化增量序列: 1, 3, 7, ... 2^k-1
void shellSort(int* data, unsigned int length)
{
	if (data == NULL && length == 0)
	{
		return ;
	}
	
	// 第一步，构造增量序列的指数值
	std::vector<int> increment;		// 假定序列长度不超过int最大值
	
	// while ( (pow(2, k) - ) < (length / 2) )	// 效率太低 
	
	int maxIncrement = length >> 1;
	for (int k = 1; ; k++)
	{
		int value = pow(2, k) - 1;	// 存储低效率运算，仅计算一次
		if (value < maxIncrement)
		{
			increment.push_back(value);
		}
		else
		{
			break;
		}
	}
	
	for (std::vector<int>::iterator it =  increment.rbegin(); it != increment.rend(); it++)
	{
		int stepValue = *it;	// 减少容器的访问次数
		for (int index = stepValue; index < length; index++)
		{
			for (int indexInsert = index; 
				indexInsert >= stepValue && data[indexInsert] < data[indexInsert-stepValue];
				indexInsert -= stepValue )
			{
				swap( data[indexInsert], data[indexInsert-stepValue] );
			}
		}
	}
}