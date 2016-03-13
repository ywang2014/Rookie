/**
* 	交换函数的实现

*	方法一：使用指针

*	C语言方式
*/

void swap(int* first, int* second)
{
	int temp = *first;
	*first = *second;	// 必须使用值交换，不能交换指针，否则无效！
	*second = temp;
}

// 模板方式
template<typename T>
void swap(T* first, T* second)
{
	if (first == NULL || second == NULL)
	{
		return ;
	}
	
	T temp = *first;
	*first = *second;
	*second = temp;
	
}