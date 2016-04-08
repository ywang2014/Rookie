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

// 链表有头结点
void bucketSort(int* data, unsigned int length)
{
	if (data == NULL && length == 0)
	{
		return ;
	}
	
	BucketNode *bucketTable[bucketSize];
	memset(bucketTable, 0, sizeof(bucketTable));
	
	// 建立链表头结点，key保存桶中数据量，实际完全不需要这么处理
	for (int i = 0; i < bucketSize; i++)
	{
		bucketTable[i] = new BucketNode();
	}
	
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
		int index = (data[i] * bucketSize) / (maxValue + 1);
		BucketNode *head = bucketTable[index];
		
		// if (head->key == 0)
		// {
			// head->next = ptr;
			// head->key++;
		// }
		// else
		// {
			// ptr->next = head->next;
			// head->next = ptr;
			// head->key++;	// 此处错误
		// }
		while (head->next != NULL && head->key < ptr->key)	// 插入排序
		{
			head = head->next;
		}
		ptr->next = head->next;
		head->next = ptr;
		bucketTable[index]->key++;	// 头结点计数
		
		//delete ptr;
	} // for 遍历完一次，即完成了排序
	
	// 拷贝数据回原数组
	int index = 0;
	BucketNode *node = NULL;
	for (int i = 0; i < bucketSize; i++)
	{
		for (node = bucketTable[i]->next; node; node = node->next)
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