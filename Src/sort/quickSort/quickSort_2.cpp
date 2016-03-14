/**
* 	选择排序算法实现
*
*	优化算法，选择轴点做优化
*	
*	C++
*/

// 专门用于随机数
#include <stdlib.h>
#include <time.h>

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
	if (lo < hi)
	{
		unsigned int index = divide(data, lo, hi);
	
		partion(data, lo, index - 1);
		partion(data, index + 1, hi);
	}
}

// 分而治之
// 优化方法选择轴点
unsigned int divide(int* data, unsigned int lo, unsigned int hi)
{
	int pivot = choosePivot(data, lo, hi, 0);	// 0普通方法, 1三点取中方法, 2随机数方法
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

// 三点取中的方法
void middlePivot(int* data, unsigned int lo, unsigned int hi)
{
	if (data == NULL || hi <= lo)
	{
		return ;
	}
	
	unsigned int mid = (lo + hi) >> 1;
	
	if (data[lo] < data[mid])
	{
		if (data[mid] < data[hi])
		{
			// 中间值 mid
			swap(data[mid], data[hi]);
		}
		else
		{
			if (data[lo] < data[hi])
			{
				// 不需要交换，data[hi]就是轴点
			}
			else
			{
				// 中间值 lo
				swap(data[lo], data[hi]);
			}
		}
	}
	else	// mid < lo
	{
		if (data[lo] < data[hi])
		{
			// 中间值 lo
			swap(data[lo], data[hi]);
		}
		else	// hi < lo
		{
			if (data[mid] < data[hi])
			{
				// 不需要交换，data[hi]就是轴点
			}
			else
			{
				// 中间值 mid
				swap(data[mid], data[hi]);
			}
		}
	}
}

// 三点取中的方法，优化代码
void middlePivot(int* data, unsigned int lo, unsigned int hi)
{
	if (data == NULL || hi <= lo)
	{
		return ;
	}
	
	unsigned int mid = (lo + hi) >> 1;
	
	if (data[mid] < data[lo])
	{
		swap(data[lo], data[mid]);
	}
	
	if (data[mid] < data[hi])	// hi最大
	{
		swap(data[mid], data[hi]);
	}
	else if (data[hi] < data[lo])	// hi最小
	{
		swap(data[lo], data[hi]);
	}
}

// 随机数选择轴点方法
void randomPivot(int* data, unsigned int lo, unsigned int hi)
{
	srand((unsigned int)time(NULL));	// 以时间作为作为随机数种子
	unsigned int index = rand() % (hi - lo) + lo;	//  rand()不需要参数，返回一个从0到最大随机数的任意整数
	swap(data[index], data[hi]);
}

// 选择轴点方法
int choosePivot(int* data, unsigned int lo, unsigned int hi, int choice)
{
	switch (choice)
	{
		case 1:	// 三点取中
			middlePivot(data, lo, hi);
			break;
			
		case 2:	// 随机数
			randomPivot(data, lo, hi);
			break;
			
		default :
			break;
	}
	
	return data[hi];
}