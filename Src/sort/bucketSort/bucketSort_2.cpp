/**
* 	桶排序算法实现
*	
*	桶排序 (Bucket sort)或所谓的箱排序，是一个排序算法，工作的原理是将阵列分到有限数量的桶子里。每个桶子再个别排序
*	(有可能再使用别的排序算法或是以递回方式继续使用桶排序进行排序)。桶排序是鸽巢排序的一种归纳结果。当要被排序的阵列
*	内的数值是均匀分配的时候，桶排序使用线性时间 Θ(n)。
*	桶排序并不是比较排序，他不受到 O(n log n) 下限的影响
*
*	C++
*/
inline void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

struct BucketNode
{
	int key;
	BucketNode *nex;
	
	BucketNode()
	{
		key = 0;
		next = NULL;
	}
	
	BucketNode(int value)
	{
		key = value;
		next = NULL;
	}
};

#define bucketSize = 10;	// 桶数目，可等于元素数目

// 无头结点的实现版本
void bucketSort(int* data, unsigned int length)
{
	if (data == NULL && length == 0)
	{
		return ;
	}
	
	BucketNode *bucketTable[bucketSize];
	memset(bucketTable, 0, sizeof(bucketTable));
	
	int maxValue = data[0];
	for (unsigned int i = 1; i < length; i++)
	{
		if (maxValue < data[i])
		{
			maxValue = data[i];
		}
	}
	
	// 入桶分类
	for (unsigned int i = 0; i < length; i++)
	{
		// key保存元素数值
		BucketNode *ptr = new BucketNode(data[i]);
		
		// 映射桶编号
		int index = (int)((data[i] * bucketSize) / (maxValue + 1));
		BucketNode *head = bucketTable[index];
		
		// 寻找合适的插入位置
		while (head != NULL && head->key < ptr->key)
		{
			head = head->next;
		}
		if (head == NULL)
		{
			head = ptr;
		}
		else
		{
			// 链表的插入工作
			ptr->next = head->next;
			head->next = ptr;
		}
	}
	
	// 拷贝数据回原数组
	int index = 0;
	BucketNode *node = NULL;
	for (int i = 0; i < bucketSize; i++)
	{
		for (node = bucketTable[i]; node; node = node->next)
		{
			data[index++] = node->key;
		}
	}
	
	// 释放节点
	for (int i = 0; i < bucketSize; i++)
	{
		node = bucketTable[i];
		BucketNode *nextNode;
		while (node)
		{
			nextNode = node->next;
			delete node;
			node = nextNode;
		}
	}
}