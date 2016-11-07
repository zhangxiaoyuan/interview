/*实现单例模式，使用与多线程操作*/

class SingleTonClass
{
public:
	static SingleTonClass& getInstance()
	{
		if (NULL == m_single)
		{
			Lock();
			if (NULL == m_single)
			{
				m_single = new SingleTonClass();
			}
			Unlock();
		}

		return *m_single;
	}

	static SingleTonClass* getInstancePtr()
	{
		if (NULL == m_single)
		{
			Lock();
			if (NULL == m_single)
			{
				m_single = new SingleTonClass();
			}
			Unlock();
		}

		return m_single;
	}

private:
	SingleTonClass(){};
	static SingleTonClass* m_single;
};
