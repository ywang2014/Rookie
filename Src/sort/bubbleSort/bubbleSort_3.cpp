/**
* 	冒泡排序实现
*
*	优化方法二，设置前后标识位，只需要调整未排序部分。
*
*	只能设置终点，冒泡排序原理是最大值冒出来，先确定，起点处未到最后，不能确定。
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
	unsigned int index = length;
	unsigned int hi = index;
	bool unordered = true;
	
	while (unordered)
	{
		unordered = false;	// 假设已经有序
		
		hi = index;
		for (unsigned int i = lo; i < hi; i++)
		{
			if (data[i-1] > data[i])
			{
				swap(data[i-1], data[i]);
				unordered = true;	// 说明未排好序
				index = i;
			}
		}
	}
}