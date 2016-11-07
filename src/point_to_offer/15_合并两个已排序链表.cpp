/*两个指针分别指向两个链表的头结点，然后比较两个指针的值，小的就加入到新的链表中，然后向后移动一步当前指针，然后继续循环比较*/
ListNodeNode* UniteList(ListNodeNode* pList1, ListNodeNode* pList2)
{
	if (pList1 == NULL)
	{
		return pList2;
	}
	else if (pList2 == NULL)
	{
		return pList1;
	}

	ListNodeNode* pTemp1 = pList1;
	ListNodeNode* pTemp2 = pList2;
	ListNodeNode* pNewList = NULL;
	ListNodeNode* pNewListHead = NULL;

	while (pTemp1 != NULL && pTemp2 != NULL)
	{
		ListNodeNode* ptemp = NULL;
		if (pTemp1->m_nValue < pTemp2->m_nValue)
		{
			ptemp = pTemp1;
			pTemp1 = pTemp1->m_pNext;
		}
		else
		{
			ptemp = pTemp2;
			pTemp2 = pTemp2->m_pNext;
		}

		if(pNewList == NULL)
		{
			pNewList = ptemp;
			pNewListHead = pNewList;
		}
		else
		{
			pNewListHead->m_pNext = ptemp;
			pNewListHead = pNewListHead->m_pNext;
		}
	}

	if(pTemp1 != NULL)
	{
		pNewListHead->m_pNext = pTemp1;
	}

	if (pTemp2 != NULL)
	{
		pNewListHead->m_pNext = pTemp2;
	}

	return pNewList;
}

void main()
{
	ListNodeNode* pHead = NULL;
	ListNodeNode* p4 = new ListNodeNode;
	p4->m_nValue = 8;
	p4->m_pNext = NULL;
	ListNodeNode* p3 = new ListNodeNode;
	p3->m_nValue = 6;
	p3->m_pNext = p4;
	ListNodeNode* p2 = new ListNodeNode;
	p2->m_nValue = 4;
	p2->m_pNext = p3;
	ListNodeNode* p1 = new ListNodeNode;
	p1->m_nValue = 2;
	p1->m_pNext = p2;
	pHead = p1;

	ListNodeNode* pHead1 = NULL;
	ListNodeNode* p41 = new ListNodeNode;
	p41->m_nValue = 7;
	p41->m_pNext = NULL;
	ListNodeNode* p31 = new ListNodeNode;
	p31->m_nValue = 5;
	p31->m_pNext = p41;
	ListNodeNode* p21 = new ListNodeNode;
	p21->m_nValue = 3;
	p21->m_pNext = NULL;
	ListNodeNode* p11 = new ListNodeNode;
	p11->m_nValue = 1;
	p11->m_pNext = p21;


	pHead1 = p11;

	ListNodeNode* newList = UniteList(pHead, pHead1);

	while (newList != NULL)
	{
		cout << newList->m_nValue << endl;
		newList = newList->m_pNext;
	}

}
