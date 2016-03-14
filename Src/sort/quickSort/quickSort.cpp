/**
* 	选择排序算法实现
*	
*	C++
*/
inline void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void quickSort(int* data, unsigned int length)
{
	if (data == NULL && length == 0)
	{
		return ;
	}
	
	partion(data, 0, length - 1);
}

// 递归处理 [lo, hi]闭区间
void partion(int* data, unsigned int lo, unsigned int hi)
{
	unsigned int index = divide(data, lo, hi);
	
	partion(data, lo, index - 1);
	partion(data, index + 1, hi);
}

// 分而治之
// 最简单的实现方法，直接取右端点值，作为轴点
unsigned int divide(int* data, unsigned int lo, unsigned int hi)
{
	int pivot = data[hi];
	while (lo < hi)
	{
		while (lo < hi && data[lo] < pivot)
		{
			lo++;
		}
		
		if (lo < hi)
		{
			data[hi--] = data[lo];
		}
		
		while (lo < hi && povit < data[hi])
		{
			hi--;
		}
		
		if (lo < hi)
		{
			data[lo++] = data[hi];
		}
	}
	
	data[lo] = povit;
	
	return lo;
}