
void PreWide(BTreeNode* ptree)
{
	if (ptree != NULL)
	{
		cout << ptree->m_value << endl;
		PreWide(ptree->pLeft);
		PreWide(ptree->pRight);
	}
}

void MidWide(BTreeNode* pTree)
{
	if (pTree != NULL)
	{
		MidWide(pTree->pLeft);
		cout << pTree->m_value << endl;
		MidWide(pTree->pRight);
	}
}

void PostWide(BTreeNode* pTree)
{
	if (pTree != NULL)
	{
		PostWide(pTree->pLeft);
		PostWide(pTree->pRight);
		cout << pTree->m_value << endl;
	}
}


void main()
{

	BTreeNode p4;
	p4.m_value = 5;
	p4.pLeft = NULL;
	p4.pRight = NULL;
	BTreeNode p5;
	p5.m_value = 6;
	p5.pLeft = NULL;
	p5.pRight = NULL;
	BTreeNode p6;
	p6.m_value = 7;
	p6.pLeft = NULL;
	p6.pRight = NULL;
	BTreeNode p3;
	p3.m_value = 4;
	p3.pLeft = &p6;
	p3.pRight = NULL;
	BTreeNode p1;
	p1.m_value = 2;
	p1.pLeft = &p3;
	p1.pRight = &p4;
	BTreeNode p2;
	p2.m_value = 3;
	p2.pLeft = &p5;
	p2.pRight = NULL;
	BTreeNode proot;
	proot.m_value = 1;
	proot.pLeft = &p1;
	proot.pRight = &p2;
	
		cout << "pre" << endl;
	PreWide(&proot);
	cout << "mid" << endl;
	MidWide(&proot);
	cout << "Post" << endl;
	PostWide(&proot);
	}
