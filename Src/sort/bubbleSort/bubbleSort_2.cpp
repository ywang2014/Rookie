/**
* 	冒泡排序实现
*
*	优化普通冒泡排序，设置标志位，已排好序，则提前结束程序。
*
*	O(n^2)
*	C++
*/

inline void swap(int& first, int& second)
{
	int temp = first;
	first = second;
	second = temp;
}

void bubbleSort(int* data, unsigned int length)
{
	for (int i = 0; i < length; ++i)
	{
		bool isOrdered = true;
		for (int j = 1; j < length - i; j++)
		{
			if (data[j-1] > data[j])
			{
				swap(data[j-1], data[j]);
				isOrdered = false;
			}
		}
		if (isOrdered)
		{
			return ;
		}
	}
}