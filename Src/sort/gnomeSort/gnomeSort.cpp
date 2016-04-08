/**
* 	地精排序算法实现
*	
*	号称最简单的排序算法,只有一层循环,默认情况下前进冒泡,一旦遇到冒泡的情况发生就往回冒,直到把这个数字放好为止。
*
*	C++
*/
inline void swap(int &a, int &b)
{
	int oldA = a;
	a = b;
	b = oldA;
}

void gnomeSort(int* data, unsigned int length)
{
	if (data == NULL && length == 0)
	{
		return ;
	}
	
	unsigned int index = 1;
	while (index < length)
	{
		if (index != 0 && data[index] < data[index-1])
		{
			swap(data[index], data[index - 1]);
			index--;
		}
		else
		{
			index++;
		}
	}
}