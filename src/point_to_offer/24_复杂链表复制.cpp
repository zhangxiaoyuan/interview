
/*
给点一个复杂链表，实现复杂链表的复制并返回
1.先复制每一个节点并有m_pNext连接成一般的链表，然后通过查找每一个节点的另一个m_pSibling指针位置，然后去赋值，但是这样查找就会非常耗时，O(n平方)时间；
2.先复制每一个节点并有m_pNext连接成一般的链表,然后再复制时用一个哈希表将节点和m_pSibling保存起来，这样查找m_pSibling指针就没那么耗时，O(1)时间，不过是采用空间换时间
*/
#include <map>
struct ComplexListNode
{
	int m_value;
	ComplexListNode* m_pNext;
	ComplexListNode* m_pSibling;
};

ComplexListNode* CloneList(ComplexListNode* pHead)
{
	if (pHead == NULL)
	{
		return NULL;
	}

	ComplexListNode* pNew = NULL;
	ComplexListNode* pNewTemp = NULL;
	ComplexListNode* pTemp = pHead;
	map<ComplexListNode*, ComplexListNode*> NodeMap;

	while(pTemp != NULL)
	{
		ComplexListNode* node = new ComplexListNode();
		node->m_value = pTemp->m_value;
		node->m_pNext = NULL;
		node->m_pSibling = NULL;
		if (pTemp->m_pSibling != NULL)
		{
			NodeMap[node] = pTemp->m_pSibling;
		}
		
		if (pNew == NULL)
		{
			pNew = node;
			pNewTemp = pNew;
		}
		pNewTemp->m_pNext = node;

		pNewTemp = pNewTemp->m_pNext;
		pTemp = pTemp->m_pNext;
	}

	ComplexListNode* pNewTemp2 = pNew;
	while(pNewTemp2 != NULL)
	{
		map<ComplexListNode*, ComplexListNode*>::iterator ite = NodeMap.find(pNewTemp2);
		if (ite != NodeMap.end())
		{
			pNewTemp2->m_pSibling = (ite)->second;
		}

		pNewTemp2 = pNewTemp2->m_pNext;
	}
	
	return pNew;
}

/*复制一个节点并连接到当前节点的后面*/
void CloneNode(ComplexListNode* pHead)
{
	ComplexListNode* ptemp = pHead;
	while(ptemp != NULL)
	{
		ComplexListNode* pClone = new ComplexListNode();
		pClone->m_value = ptemp->m_value;
		pClone->m_pNext = ptemp->m_pNext;
		pClone->m_pSibling = NULL;

		ptemp->m_pNext = pClone;
		ptemp = pClone->m_pNext;
	}
}

void ConnectSiblingNodes(ComplexListNode* pHead)
{
	ComplexListNode* pTemp = pHead;
	while(pTemp != NULL)
	{
		ComplexListNode* pNode = pTemp->m_pNext;
		if (pTemp->m_pSibling != NULL)
		{
			//因为新添加的节点在旧节点的下一个，所以这里要取next
			pNode->m_pSibling = pTemp->m_pSibling->m_pNext;
		}
		pTemp = pNode->m_pNext;
	}
}

/*将前两步连接的好的链表拆分，奇数为原来的链表，偶数为新增的链表*/
ComplexListNode* ReconnectNode(ComplexListNode* pHead)
{
	ComplexListNode* pTemp = pHead;
	ComplexListNode* pClonedHead = NULL;
	ComplexListNode* pClonedNode = NULL;

	if (pTemp != NULL)	
	{
		pClonedHead = pClonedNode = pTemp->m_pNext;
		pTemp->m_pNext = pClonedNode->m_pNext;
		pTemp = pTemp->m_pNext;
	}
	
	while(pTemp != NULL)
	{
		pClonedNode->m_pNext = pTemp->m_pNext;
		pClonedNode = pClonedNode->m_pNext;
		pTemp->m_pNext = pClonedNode->m_pNext;
		pTemp = pTemp->m_pNext;
	}

	return pClonedHead;
}

ComplexListNode* CloneList1(ComplexListNode* pHead)
{
	CloneNode(pHead);
	ConnectSiblingNodes(pHead);
	return ReconnectNode(pHead);
}


void main()
{
	ComplexListNode node2;
	ComplexListNode node5;
	node5.m_value = 5;
	node5.m_pNext = NULL;
	node5.m_pSibling = NULL;
	ComplexListNode node4;
	node4.m_value = 4;
	node4.m_pNext = &node5;
	node4.m_pSibling = &node2;
	ComplexListNode node3;
	node3.m_value = 3;
	node3.m_pNext = &node4;
	node3.m_pSibling = NULL;
	node2.m_value = 2;
	node2.m_pNext = &node3;
	node2.m_pSibling =&node5;
	ComplexListNode node1;
	node1.m_value = 1;
	node1.m_pNext = &node2;
	node1.m_pSibling = &node3;

	//ComplexListNode* newList = CloneList(&node1);
	ComplexListNode* newList = CloneList1(&node1);

}
