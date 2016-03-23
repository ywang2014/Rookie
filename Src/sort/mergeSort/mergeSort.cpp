/**
* 	归并排序算法实现
*	
*	C++
*/

inline void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void mergeSort(int* data, unsigned int length)
{
	if (data == NULL && length == 0)
	{
		return ;
	}
	
	mSort(data, 0, length);
}

// [lo, hi) 开区间
void merge(int* data, unsigned int lo, unsigned int mid, unsigned hi)
{
	int l_len = mid - lo;
	int r_len = hi - mid;
	
	int* l_data = new int[l_len];
	for (unsigned int i = lo; i < mid; i++)
	{
		l_data[i - lo] = data[i];
	}
	
	int* r_data = new int[r_len];
	for (unsigned int j = mid; j < hi; j++)
	{
		r_data[j - mid] = data[j];
	}
	
	int l_index = 0;
	int r_index = 0;
	while (lo < hi)
	{
		while (l_index < l_len && (r_index >= r_len || l_data[l_index] <= r_data[r_index]))
		{
			data[lo++] = l_data[l_index++];
		}
		
		while (r_index < r_len && (l_index >= l_len || r_data[r_index] < l_data[l_index]))
		{
			data[lo++] = r_data[r_index++];
		}
	}
	
	delete [] l_data;
	delete [] r_data;
}

// [lo, hi)
void mSort(int* data, unsigned int lo, unsigned int hi)
{
	if (lo < hi)
	{
		unsigned int mid = (lo + hi) >> 1;
		
		// 一分为二
		mSort(data, lo, mid);
		mSort(data, mid, hi);
		
		// 合二为一
		merge(data, lo, mid, hi);
	}
}