# 数据结构基础
### 数组
##### 定义

        n(n > 0, int) 个相同数据元素占用物理上连续的内存空间的有限序列，一种数据结构类型。
        
        index： 0， 1，2，...
        
        可以寻址访问，O(1)时间查找
        
        数组是最古老，最常用的数据结构：简单易用，效率不高
        
        一维数组 array[N]   二维数组 array[M][N]    多维数组 array[N1]...[Nn]
        
        动态数组： malloc()分配空间，free()释放空间
        
        封装之后，变成了 vector

##### 知识要点
        
        Advantage:
        
          find(index)
        
          modify(index)
          
          直接寻址：O(1)！
        
        Disadvantage:
        
          insert(index, elem)
          
          delete(elem)
        
          移动开销太大

##### 时间复杂度

        查找：
        
              基于索引查找 O(1)
              
              基于元素查找：二分查找(有序) O(log(N))    普通查找 O(N)
              
        插入、删除 O(N)

### 链表
##### 定义

        元素离散的存储在计算机上，通过指针链接在一起：头结点、前区节点、后继节点
        
        struct ListNode
        {
            elem data; 
            struct ListNode* next;
        };
        
        单向链表、单向循环链表、双向链表、双向循环链表

##### 知识要点

        Advantage:
        
          insert(node, elem)
          
          delete(node)
          
          仅仅需要修改指针即可，无移动开销：O(1)！
        
        Disadvantage:
        
          find(elem)  不能寻址访问
  
        链表多用于操作系统设计中，栈的实现、缓冲区的实现等

##### 时间复杂度

        查找：O(n) 只能是遍历搜索查找
        
        插入、删除：O(1)

#### 堆栈是“后进先出”（LIFO）的数据结构
#### 队列是“先进先出”（FIFO）的数据结构

### 散列表(哈希表)
##### 定义

        将关键字映射表中的特定位置，建立关键字和存储地址之间联系
        
        hash function   mod %
        
        通过散列函数建立的表，属于散列表，集合数据结构的一种

##### 要点

        Advantage:
        
          find(elem)
        
          insert(elem)
          
          delete(elem)
          
          直接映射：O(1)！
        
        Disadvantage:
        
          space
          
              装填因子、lazy_delete
          
          collision (无法避免: bloom filter)
          
              链接法
          
              开放地址：一次聚集、二次聚集
              
              二次散列
          
        哈希表对于关联数组和数据库检索十分重要

##### 时间复杂度

        查找、插入、删除：O(1)

### 二叉树
##### 定义

        树形结构：根节点、叶子节点、左孩子、右孩子
        
        struct TreeNode
        {
            elem data;
            struct TreeNode* lchild;
            struct TreeNode* rchild;
        };

##### 知识要点

        Advantage：
        
          search(elem)
          
          insert(elem)
          
          delete(elem)
          
          集中了数组(二分查找)和链表(直接插入和删除)的优点
          
        Disadvantage:
        
          退化：严重影响效率
          
##### 时间复杂度

        二叉查找树：查找、插入、删除：O(log n)
        
### 优先队列
##### 定义
        
        堆 
        
        堆排序

##### 知识要点

        Advantage：
          
          deleteMin()
    
        
