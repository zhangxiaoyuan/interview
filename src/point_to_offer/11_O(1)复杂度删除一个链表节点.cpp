/*
给定一个链表的头指针和一个节点的指针，定义一个函数在O(1)时间内删除此节点
思路：将待删除节点的下一个节点覆盖到此节点，然后将待删除节点的下一个节点删除即可
*/

struct ListNodeNode
{
	int m_nValue;
	ListNodeNode* m_pNext;
};
void deleteNode(ListNodeNode** pListHead, ListNodeNode* pToBeDeleted)
{
	if ((*pListHead == NULL) || (pListHead == NULL) || (pToBeDeleted == NULL))
	{
		return;
	}

	ListNodeNode* pTemp = *pListHead;

	/*如果链表只有一个节点*/
	if (pTemp->m_pNext == NULL)
	{
		delete pTemp;
		pTemp = NULL;
		return;
	}
	
	/*如果删的节点是尾节点，则必须要找到前节点*/
	if (pToBeDeleted->m_pNext == NULL)
	{
		while(pTemp->m_pNext != pToBeDeleted)
		{
			pTemp = pTemp->m_pNext;
		}
		delete pToBeDeleted;
		pToBeDeleted = NULL;
		pTemp->m_pNext = NULL;
		return;
	}

	/*正常的删除节点，将待删除节点的后一个节点赋值给待删除节点即可*/
	ListNodeNode* pNext = pToBeDeleted->m_pNext;
	pToBeDeleted->m_nValue = pNext->m_nValue;
	pToBeDeleted->m_pNext = pNext->m_pNext;
	delete pNext;
	pNext = NULL;

	return;
}

void main()
{
	//Get1ToMax(1);
	//Print1ToMaxAnother(2);

	ListNodeNode* pHead = NULL;
	ListNodeNode* p4 = new ListNodeNode;
	p4->m_nValue = 4;
	p4->m_pNext = NULL;
	ListNodeNode* p3 = new ListNodeNode;
	p3->m_nValue = 3;
	p3->m_pNext = p4;
	ListNodeNode* p2 = new ListNodeNode;
	p2->m_nValue = 2;
	p2->m_pNext = p3;
	ListNodeNode* p1 = new ListNodeNode;
	p1->m_nValue = 1;
	p1->m_pNext = p2;

	pHead = p1;

	deleteNode(&pHead, p4);
}
