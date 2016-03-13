/**
* 	冒泡排序实现
*
*	直接遍历序列，依次比较相邻元素，调整顺序，直至遍历完成。
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
		for (int j = 1; j < length - i; j++)
		{
			if (data[j-1] > data[j])
			{
				swap(data[j-1], data[j]);
			}
		}
	}
}