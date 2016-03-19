/**
* 	堆排序算法实现
*	
*	C++
*/


inline void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

// 左孩子索引
inline unsigned int leftChildIndex(unsigned int index)
{
	return (2 * index + 1);
}

// 右孩子索引
inline unsigned int rightChildIndex(unsigned int index)
{
	return ((index + 1) * 2);
}

// 判断是否存在右兄弟
inline bool hasSibling(unsigned int index, unsigned int n)
{
	return (index < (n -1));
}

// 下滤算法
void filter(int *data, unsigned int i, unsigned int n)
{
	int currentNodeValue = data[i];
	unsigned int child = leftChildIndex(i);
	
	while (child < n)
	{
		if (hasSibling(child, n) && data[child + 1] < data[child])
		{
			child++;	// 取左右子节点中，更小的值
		}
		
		if (data[child] < currentNodeValue)
		{
			data[i] = data[child];
			i = child;
			child = leftChildIndex(i);
		}
		else
		{
			break;
		}
	}
	
	data[i] = currentNodeValue;
}

void heapSort(int* data, int n)
{
	for (int i = n / 2; i >= 0; i--)
	{
		filter(data, i, n);
	}
	
	for (int i = n - 1; i > 0; i--)
	{
		swap(&data[0], &data[i]);
		filter(data, 0, i);
	}
}
