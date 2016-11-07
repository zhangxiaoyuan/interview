
/*
2种解法:1.使用stack反转；2.通过三个指针进行反转*/
ListNodeNode* ReverseList(ListNodeNode* pHead)
{
	ListNodeNode* preNode = NULL;
	ListNodeNode* node = pHead;
	ListNodeNode* reverseNode = NULL;
	while (node != NULL)
	{
		ListNodeNode* nextNode = node->m_pNext;
		if(nextNode == NULL)
		{
			reverseNode = node;
		}
		node->m_pNext = preNode;
		preNode = node;
		node = nextNode;
	}

	return reverseNode;
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

	ListNodeNode* ptem = ReverseList(pHead);

	cout << ptem->m_nValue << endl;

}
