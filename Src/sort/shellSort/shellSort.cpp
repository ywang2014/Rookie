/**
* 	希尔排序算法实现
*	
*	非稳定算法
*
*	最普通的增量序列，n/2, n/4, ... 1
*
*	C++
*/
inline void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

// 
/*
void shellSort(int* data, unsigned int length)
{
	if (data == NULL && length == 0)
	{
		return ;
	}
	
	for (unsigned int increment = (length >> 1); increment > 0; increment >>= 1)
	{
		// for (unsigned int i = 0; i < length - inrement; i++)
		// {
			// if (data[i] > data[i + increment])
			// {
				// swap(data[i], data[i + increment]);
			// }
		// }
		// 这样向后，只是交换一次，肯定不行，只能保证最大值在最后，不能保证全体有序
		
		// 希尔排序内部，其实就是一个插入排序
		for (unsigned int i = increment; i < length; i++)
		{
			for (unsigned int j = i; j >= increment; j -= increment)
			{
				if (data[j] < data[j - increment])
				{
					swap(data[j], data[j -increment]);
				}
				else
				{
					break;
				}
			}
		}
	}
}
*/

// 最直接的插入排序算法
void shellSort(int* data, unsigned int length)
{
	if (data == NULL || length == 0)
	{
		return ;
	}
	
	for (unsigned int increment = length >> 1; 
		increment > 0;
		increment >>= 1) 
	{
		for (unsigned int iteratorCount = 0; iteratorCount < increment; iteratorCount++)
		{
			for (unsigned int index = iteratorCount + increment;
				index < length;
				index = index + increment)
			{
				int indexInsert = index;
				while (indexInsert >= increment && data[indexInsert] < data[indexInsert-increment])
				{
					swap( data[indexInsert], data[indexInsert-increment] );
					
					indexInsert -= increment;
				}
			}
		}
	}
}

// 改进版插入排序
void  shellSort(int* data, unsigned int length)
{
	// 省略错误处理
	
	for (unsigned int increment = length >> 1; increment > 0; increment >>= 1)
	{
		for (unsigned int index = increment; index < length; index++)
		{
			if ( data[index] < data[index - increment] )
			{
				unsigned int indexInsert = index;
				while (increment <= indexInsert && 
					data[indexInsert] < data[indexInsert - increment] )
				{
					swap( data[indexInsert], data[indexInsert - increment] );
					
					indexInsert -= increment;
				}
			}
		}
	}
}

// 最精简的插入排序实现版本
void shellSort(int* data, unsigned int length)
{
	for (unsigned int increment = length >> 1; increment > 0; increment >>= 1)
	{
		for (unsigned int index = increment; index < length; index++)
		{
			fot (unsigned int indexInser = index; 
				increment <= indexInser &&
				data[indexInsert] < data[indexInser - increment];
				indexInsert -= increment;
				)
			{
				swap( data[indexInser], data[indexInsert - increment] );
			}
		}
	}
}

