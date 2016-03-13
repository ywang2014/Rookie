/**
* 	交换函数的实现

*	方法三：高级版本，使用异或方式交换值，不使用临时变量

*	C++方式
*/

void swap(int& first, int& second)
{
	if (&first == &second)
	{
		return ;
	}
	
	// 0 ^ 1 = 1;
	// 1 ^ 0 = 1;
	// 1 ^ 1 = 0;
	// 0 ^ 0 = 0;
	first ^= second;
	second ^= first;
	first ^= second;
}

// 模板方式
template<typename T>
bool swap(T& first, T& second)
{
	if (&first == NULL || &second == NULL || &first == &second)
	{
		return false;
	}
	
	first ^= second;
	second ^= first;
	first ^= second;
	
	return true;
}