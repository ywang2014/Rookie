/**
* 	交换函数的实现

*	方法二：使用引用

*	C++方式
*/

void swap(int& first, int& second)
{
	int temp = first;
	first = second;
	second = temp;
}

// 模板方式
template<typename T>
bool swap(T& first, T& second)
{
	if (&first == NULL || &second == NULL)
	{
		return false;
	}
	
	T temp = first;
	first = second;
	second = temp;
	
	return true;
}