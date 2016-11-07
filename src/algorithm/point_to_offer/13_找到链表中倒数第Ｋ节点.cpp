

/*第一种常规解法：先遍历一遍找出链表总个数c，然后计算倒数第k个节点就是顺数第c-k+1，然后再遍历到顺数第c-k+1节点返回即可*/
ListNodeNode* FindKthToTail(ListNodeNode* pHead, unsigned int k)
{
	if (pHead == NULL || k < 1)
	{
		return NULL;
	}

	unsigned int count = 1;
	ListNodeNode* pTemp = pHead;

	while(pTemp->m_pNext != NULL)
	{
		count++;
		pTemp = pTemp->m_pNext;
	}

	if (k > count)
	{
		return NULL;
	}

	unsigned int step = count - k + 1;
	ListNodeNode* findNode = pHead;

	while(step - 1 != 0)
	{
		step--;
		findNode = findNode->m_pNext;
	}

	return findNode;
}

/*
第二种解法：用第一个指针p1从头开始遍历k-1步,然后用第二个指针指向头结点，
然后两个指针同时往后移动，当p1移动到尾节点时，P2正好就到达倒数第k个节点，因为两个指针之间始终相差k-1步
*/
ListNodeNode* findKthToTail2(ListNodeNode* pHead, unsigned int k)
{
	if (pHead == NULL || k < 1)
	{
		return NULL;
	}
	ListNodeNode* pTemp1 = pHead;
	ListNodeNode* pTemp2 = pHead;
	
	while ((k - 1> 0) && (pTemp1->m_pNext != NULL))
	{
		k--;
		pTemp1 = pTemp1->m_pNext;
	}

	if (k > 1)
	{
		return NULL;
	}

	while(pTemp1->m_pNext != NULL)
	{
		pTemp1 = pTemp1->m_pNext;
		pTemp2 = pTemp2->m_pNext;
	}

	return pTemp2;
}

void main()
{
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

	ListNodeNode* temp1 = FindKthToTail(pHead, 5);
	ListNodeNode* ptem2 = findKthToTail2(pHead, 5);

	cout << temp1->m_nValue << endl;
	cout << ptem2->m_nValue << endl;
	}
