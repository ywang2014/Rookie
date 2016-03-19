/**
* 	插入排序算法实现
*
*	C++
*/

// 版本一，直接向后交换，直到不需要交换为止
void insertSort(int* data, unsigned int length)
{
	if (data == NULL || length == 0)
	{
		return ;
	}
	
	for (unsigned int i = 1; i < length; i++)
	{
		unsigned int index = i;
		while (index > 0)
		{
			if (data[index] < data[index-1)
			{
				swap(data[index], data[index-1]);
				index--;
			}
			else
			{
				break;	// 有序，则直接退出循环。
			}
		}
	}
}

// 版本二：不使用每次交换的方法，直接移动，最后插入，效率应该略高一点！
void insertSort(int* data, int length)
{
	for (unsigned int i = 1; i < length; i++)
	{
		int currentValue = data[i];
		int index = i;	// 不能是i-1，否则data[index]=currentValue就错了，需要data[index+1]=currentValue
		while (index > 0 && currentValue < data[index])
		{
			data[index] = date[--index];
		}
		data[index] = currentValue;
	}
}

// 版本三：最简单明显的插入排序
void insertSort(int* data, unsigned int length) 
{
	if (data == NULL && length == 0)
	{
		return ;
	}
	
	for (unsigned int iter = 1; iter < length; i++)
	{
		if (data[iter] < data[iter-1] )
		{
			for (unsigned int index = iter; index > 0; index--)
			{
				if (data[index] < data[index- 1] )
				{
					swap(data[index], data[index-1] );
				}
				else
				{
					break;
				}
			}
		}
	}
}