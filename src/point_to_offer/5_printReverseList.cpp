
/*
给定一个链表，输入链表头结点，从尾到头反向打印链表中的每个节点的值
1.采用std的栈存储每一个节点，然后就可以发现打印出来
2.采用一个新的链表，将链表反序
3.直接修改原来的链表，将原来的链表反序
*/
typedef struct _List_Node
{
	int data;
	listNode* pNext;
}listNode;

int printReverseList(listNode* pHead)
{
	if (NULL == pHead)
	{
		return -1;
	}

	listNode* ptem = pHead;

	stack<listNode*> nodeStack;

	while (ptem->pNext != NULL)
	{
		nodeStack.push(ptem);
		ptem++;
	}

	while (!nodeStack.empty())
	{
		listNode* node = nodeStack.top();
		cout <<" " << node->data<< endl;
		nodeStack.pop();
	}

	return 0;
}
