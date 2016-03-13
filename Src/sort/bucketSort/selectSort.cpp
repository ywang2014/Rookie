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

void selectSort(int* data, unsigned int length)
{
	if (data == NULL && length == 0)
	{
		return ;
	}
	
	for (unsigned int i = 0; i < length; i++)
	{
		unsigned int minIndex = i;
		for (unsigned int j = i + 1; j < length; j++)	// i替换为minIndex更好
		{
			if (data[j] < data[minIndex])
			{
				minIndex = j;
			}
		}
		
		swap(data[i], data[minIndex]);
	}
}