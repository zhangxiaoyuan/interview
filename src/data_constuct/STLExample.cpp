
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned char BYTE;
typedef unsigned int  WORD;
typedef unsigned long DWORD;

#define FALSE 0
#define TRUE 1

enum STUDY_E
{
	YUWEN = 0,
	SHUXUE,
	YINGYU,
	STUDY_NULL
};

struct PERSON_NODE
{
	BYTE bName[10];
	WORD wWeight;
	DWORD dHeight;
	STUDY_E eStudy;
	
	PERSON_NODE()
	{
		memset(bName, 0, 10);
		wWeight = 60;
		dHeight = 180;
		eStudy = STUDY_NULL;
	}
};

void printEnd(string strPrint)
{
	cout << "*********************" << strPrint.c_str() << " end******************"<< endl;
}


/*vector是连续存储的元素，底层实现是数组，在尾部插入和随机元素访问时时间复杂度是常量级，但插入和删除随机元素就非常耗时*/
typedef vector<PERSON_NODE> VECTORNODE;
typedef vector<PERSON_NODE>::iterator VECTORITE;
bool vectorSortCmp(const PERSON_NODE& node1, const PERSON_NODE& node2)
{
	return node1.wWeight < node2.wWeight;
}
void vectorTest()
{
	VECTORNODE personVec1;
	VECTORNODE personVec2;

	//psuh_back在尾部插入元素
	PERSON_NODE per1;
	memcpy(per1.bName, "1111", 5);
	personVec1.push_back(per1);

	PERSON_NODE per2;
	memcpy(per2.bName, "2222", 5);
	personVec1.push_back(per2);

	PERSON_NODE per3;
	memcpy(per3.bName, "3333", 5);
	personVec1.push_back(per3);

	PERSON_NODE per4;
	memcpy(per4.bName, "2222", 5);
	personVec1.push_back(per4);

	PERSON_NODE per5;
	memcpy(per5.bName, "5555", 5);
	personVec2.push_back(per5);

	//begin()和end()返回第一个元素和指向最后一个元素的下一个
	VECTORITE ite = personVec1.begin();
	while(ite != personVec1.end())
	{
		PERSON_NODE per = *ite;
		cout << "name : " << per.bName << endl;
		cout << "weight : " << per.wWeight << endl;
		++ite;
	}

	//at()根据位置获取元素，和下标操作符[]功能相同，不过at更安全不会越界
	PERSON_NODE per =  personVec1.at(2);
	cout << "name : " << per.bName << endl;
	cout << "weight : " << per.wWeight << endl;

	//[]下标操作符
	PERSON_NODE per11 =  personVec1[3];
	cout << "name : " << per11.bName << endl;
	cout << "weight : " << per11.wWeight << endl;

	//back()返回最后一个元素
	PERSON_NODE per12 =  personVec1.back();
	cout << "name : " << per12.bName << endl;
	cout << "weight : " << per12.wWeight << endl;

	//front()返回第一个元素
	PERSON_NODE per13 =  personVec1.front();
	cout << "name : " << per13.bName << endl;
	cout << "weight : " << per13.wWeight << endl;

	//size()获取大小
	cout << "listCoutn : " << personVec1.size() << endl;
	VECTORITE ite2 = personVec2.begin();
	while(ite2 != personVec2.end())
	{
		PERSON_NODE per = *ite2;
		cout << "name : " << per.bName << endl;
		cout << "weight : " << per.wWeight << endl;
		++ite2;
	}

	sort(personVec1.begin(), personVec1.end(), vectorSortCmp);

	//insert()，在指定位置插入元素
	PERSON_NODE per7;
	memcpy(per7.bName, "7777", 5);
	personVec2.insert(personVec2.end(), per7);

	VECTORITE ite3 = personVec2.begin();
	while(ite3 != personVec2.end())
	{
		PERSON_NODE per = *ite3;
		cout << "name : " << per.bName << endl;
		cout << "weight : " << per.wWeight << endl;
		++ite3;
	}

	printEnd("vector");
}



/*list底层是链表实现，将元素按顺序存储在链表中，支持任意位置的快速插入和删除，支持顺序查找,随机查找比较慢*/
typedef list<PERSON_NODE> LISTNODE;
typedef list<PERSON_NODE>::iterator LISTITE;
bool listSortCmp(const PERSON_NODE& node1, const PERSON_NODE& node2)
{
	return node1.wWeight < node2.wWeight;
}
void listTest()
{
	LISTNODE personList;

	PERSON_NODE person1;
	memcpy(person1.bName, "1111", 5);
	person1.bName[4];
	person1.dHeight = 181;
	person1.wWeight = 81;
	person1.eStudy = YUWEN;
	/* list尾部添加元素 */
	personList.push_back(person1);

	PERSON_NODE person2;
	memcpy(person2.bName, "222222222", 9);
	person2.bName[9];
	person2.dHeight = 222;
	person2.wWeight = 222;
	person2.eStudy = SHUXUE;
	/*在list头部添加元素*/
	personList.push_front(person2);
	
	PERSON_NODE person3;
	memcpy(person3.bName, "33333", 10);
	person3.dHeight = 333;
	person3.wWeight = 333;
	/*在list中某个位置插入元素*/
	personList.insert(personList.begin(), person3);

	PERSON_NODE person4;
	personList.insert(personList.end(), person4);

	PERSON_NODE& person5 = personList.back();
	PERSON_NODE& person6 = personList.front();

	/*对list中的元素进行排序，按照自定义的顺序函数*/
	personList.sort(listSortCmp);


	/*获取list中元素总个数*/
	WORD listCoutn = personList.size();
	cout << "listCoutn : " << listCoutn << endl;

	/*对list中的元素遍历*/
	if (!personList.empty())
	{
		LISTITE ite = personList.begin();
		while(ite != personList.end())
		{
			PERSON_NODE per = *ite;
			cout << "name : " << per.bName << endl;
			cout << "weight : " << per.wWeight << endl;
			++ite;
		}
	}

	personList.clear();
	
	printEnd("list");
}

/*从小到大排序*/
struct nodeLess
{
	bool operator()(const PERSON_NODE& per1, const PERSON_NODE& per2)const
	{
		return per1.dHeight < per2.dHeight;
	}
};
/*set是一种包含已排序对象的关联容器,set元素为自定义的结构时，必须要传入比较函数, 基本数据类型可以自行判断大小，因此不用比较函数*/
typedef set<PERSON_NODE, nodeLess> SETNODE;
typedef set<PERSON_NODE, nodeLess>::iterator SETITE;
void setTest()
{
	SETNODE personSet;

	PERSON_NODE per1;
	memcpy(per1.bName, "1111", 5);
	per1.dHeight = 111;

	PERSON_NODE per2;
	memcpy(per2.bName, "2222", 5);
	per2.dHeight = 222;

	PERSON_NODE per3;
	memcpy(per3.bName, "3333", 5);
	per3.dHeight = 333;

	PERSON_NODE per4;
	memcpy(per4.bName, "4444", 5);
	per4.dHeight = 444;

	PERSON_NODE per5;
	memcpy(per5.bName, "4444", 5);
	per5.dHeight = 444;

	//insert() 插入元素,插入相同元素会直接校验不插入
	personSet.insert(per1);
	personSet.insert(per2);
	personSet.insert(per3);
	personSet.insert(per4);
	personSet.insert(per5);

	//count() 返回key在set中的个数
	cout << "per2 :" << personSet.count(per2) << endl;

	//empty()，begin(),end()
	if (! personSet.empty())
	{
		SETITE ite = personSet.begin();
		while(ite != personSet.end())
		{
			PERSON_NODE per = *ite;
			cout << "name : " << per.bName << endl;
			cout << "height : " << per.dHeight << endl;
			++ite;
		}
	}

	//lower_bound 指向大于或者等于key值的第一个元素的迭代器
	SETITE ite111 = (personSet.lower_bound(per2));
	PERSON_NODE per111  = *ite111;
	cout<< "name  " << per111.bName<< endl;
	
	//upper_bound 指向大于key的第一个元素的
	SETITE ite222 = (personSet.upper_bound(per3));
	PERSON_NODE per222  = *ite222;
	cout<< "name  " << per222.bName<< endl;

	//erase()删除元素
	personSet.erase(per2);

	//size()获取set中元素个数
	cout << "per2size():" << personSet.size()<< endl;

	printEnd("set");
}


/*根据key从大到小排序*/
struct nodeMore
{
	bool operator()(const WORD& key1, const WORD& key2) const
	{
		return key1 > key2;
	}
};
/*map是键值关联容器，在内存中是红黑数实现*/
typedef map<WORD, PERSON_NODE> MAPNODE;
typedef map<WORD, PERSON_NODE>::iterator MAPITE;
void mapTest()
{
	MAPNODE personMap;

	PERSON_NODE per1;
	memcpy(per1.bName, "1111", 5);
	per1.dHeight = 111;

	PERSON_NODE per2;
	memcpy(per2.bName, "2222", 5);
	per2.dHeight = 222;

	PERSON_NODE per3;
	memcpy(per3.bName, "3333", 5);
	per3.dHeight = 333;

	PERSON_NODE per4;
	memcpy(per4.bName, "4444", 5);
	per4.dHeight = 444;

	PERSON_NODE per5;
	memcpy(per5.bName, "4444", 5);
	per5.dHeight = 444;

	//几种插入方式
	personMap[1] = per1;
	personMap.insert(MAPNODE::value_type(2, per2));
	personMap.insert(pair<WORD, PERSON_NODE>(3, per3));
	personMap.insert(make_pair<WORD, PERSON_NODE>(4, per4));
	personMap[5] = per5;

	//empty(),begin(),end()
	if (! personMap.empty())
	{
		MAPITE ite = personMap.begin();
		while(ite != personMap.end())
		{
			WORD idIdx = (*ite).first;
			PERSON_NODE per = (*ite).second;

			cout << "id : " << idIdx << endl;
			cout << "name : " << per.bName << endl;
			cout << "height : " << per.dHeight << endl;
			++ite;
		}
	}

	/*size()获取大小*/
	cout << "size " << personMap.size() << endl;
	printEnd("map");
}


int _tmain(int argc, _TCHAR* argv[])
{
vectorTest();

listTest();

setTest();

mapTest();

printEnd("main");
return 0;
}
