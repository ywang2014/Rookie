/**
* 	计数排序算法实现
*	
*	本质是一种特殊的hash函数，即 i 映射到下标为i的数组位置。
*
*	C++
*/

void countSort(int* data, unsigned int length)
{
	if (data == NULL && length == 0)
	{
		return ;
	}
	
	int maxValue = data[0];
	int minValue = data[0];
	for (unsigned int i = 1; i < length; i++)
	{
		if (maxValue < data[i])
		{
			maxValue = data[i];
		}
		
		if (minValue > data[i])
		{
			minValue = data[i];
		}
	}
	
	// 创建统计频率数组，并初始化
	int countSize = maxValue - minValue + 1;
	int* count = new int[countSize];
	for (int i = 0; i < countSize; i++)
	{
		count[i] = 0;
	}
	
	// 统计个数字出现的频率
	for (unsigned int index = 0; index < length; index++)
	{
		count[ data[index] - minValue ] ++;
	}
	
	// 确定数值 i 应该排列的最大位置地方(会有重复的数字情况) (需要-1，因为从0开始排序，计数从1开始)
	for (int i = 1; i < countSize; i++)
	{
		count[i] += count[i-1];	// 一直迭代累加
	}
	
	int* dataCopy = new int[length];
	for (unsigned int i = 0; i < length; i++)
	{
		dataCopy[i] = data[i];
	}
	
	// 从末尾开始排序，只是为了实现稳定排序
	for (unsigned int i = length - 1; i >= 0; i++)
	{
		unsigned int pos = count[ dataCopy[i] - minValue ] -- ;
		data[ pos ] = dataCopy[i];
	}
	
	delete [] count;
	delete [] dataCopy;
}

// 版本二：不需要第二个辅助数组，不稳定(和原有序数组没有关系，不知道是否有序)
void countSort(int* data, unsigned int length)
{
	if (data == NULL && length == 0)
	{
		return ;
	}
	
	int maxValue = data[0];
	int minValue = data[0];
	for (unsigned int i = 1; i < length; i++)
	{
		if (maxValue < data[i])
		{
			maxValue = data[i];
		}
		
		if (minValue > data[i])
		{
			minValue = data[i];
		}
	}
	
	// 创建统计频率数组，并初始化
	int countSize = maxValue - minValue + 1;
	int* count = new int[countSize];
	for (int i = 0; i < countSize; i++)
	{
		count[i] = 0;
	}
	
	// 统计个数字出现的频率
	for (unsigned int index = 0; index < length; index++)
	{
		count[ data[index] - minValue ] ++;
	}
	
	unsigned int index = 0;
	for (int i = 0; i < countSize; i++)
	{
		// while ( count[i]-- )
		// {
			// data[index++] = minValue + i;
		// }
		
		while (count[i] != 0)
		{
			data[index] = minValue + i;
			index++;
			count[i]--;
		}
	}
	
	delete [] count;
}