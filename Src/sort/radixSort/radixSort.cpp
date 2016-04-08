/**
* 	基数排序算法实现
*	
*	非比较型排序算法，将整数按位数切割成不同的数字，然后按位分别比较。
*	整数可以表示成字符串，即基数排序也可以用于字符串。
*
*	实现原理：将整数值视为同一长度，数位短的前面补0.然后从低位开始，依次排序
*	LSD(Least significant digital): 由键值的最右边开始
*	MSD(Most significant digital):  由键值的最左边开始
*
*	C++
*	算法实现，均为考虑大数问题，即不考虑整型溢出问题！！！
*
*/

void radixSort(int* data, unsigned int length)
{
	if (data == NULL && length == 0)
	{
		return ;
	}
	
	int maxValue = data[0];
	for (unsigned int i = 1; i < length; i++)
	{
		if (maxValue < data[i])
		{
			maxValue = data[i];
		}
	}
	//int maxBits = getBits(maxValue);
	int **radixTable = new int*[10];	// 十进制的整数，10位
	for (int i = 0; i < 10; i++)
	{
		radixTable[i] = new int[length];
	}
	
	int count[10] = { 0 };
	for (int bits = 1; bits <= maxValue; bits *= 10)
	{
		for (unsigned int i = 0; i < length; i++)
		{
			int bitNumber = (data[i] / bits) % 10; 
			radixTable[bitNumber][ count[bitNumber] ] = data[i];
			count[bitNumber]++;
		}
		
		int index = 0;
		for (int i = 0; i < 10; i++)
		{
			// int offset = count[i];
			// while (count[i] != 0)
			// {
				// data[index + count[i] - 1] = radixTable[i][count[i]-1];
				// count[i]--;
			// }
			// index += offset;
			if (count[i] != 0)
			{
				for (int j = 0; j < count[i]; j++)
				{
					data[index++] = radix[i][j];
				}
			}
			count[i] = 0;
		}
	}
	
	
	for (int i = 0; i < 10; i++)
	{
		delete [] radixTable[i];
	}
	delete [] radixTable;
}

int getBits(unsigned int number)
{
	if (number == 0)
	{
		return 1;
	}
	
	int count = 0;
	while (number)
	{
		count++;
		number /= 10;
	}
	
	return count;
}

// 获得某位数字
int getBitDigit(const unsigned int number, const unsigned int bits)
{
	int divisor = (int)pow(10, bits - 1);
	
	return (number / divisor) % 10;
}