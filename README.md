# 数据结构 ( Data Structure )

## 链表 ( node )

常见的链表的定义分为两部分, 数据域和指针域: 数据域中存储数据, 指针域用于存储下一个链表的位置. 对链表的结构体定义如下:

``` c
typedef struct node_t
{
    elemType data;	  //数据域
    node_t *next;	//指针域
} node_t;
```

## 栈 ( stack )

栈中的数据遵循后进先出的原则( LIFO )

## 队列 ( queue )

队列中的数据遵循先进先出的原则( LILO )

## 树 ( tree )

相互连接的节点的有限集合. 
