//��ջʾ��:ʵ��һ��char��������ջ

//�ú��������һ���Ƿ���stl::stack�Ŀ��أ�����꣬���Զ����stack��ע���궨�壬������stl::stack
#define  NOUSE_STL


#include <iostream>

#ifdef NOUSE_STL
#include <cassert>

class stack
{
	int m_size;		//ջ�ռ��С
	int m_top;		//ջ���±�
	char* m_p;		//ջ�ռ䣬��̬����
public:
	stack()
		:m_size(16), m_top(0), m_p(0)
	{
		m_p = new char[m_size];
	}

	stack(int size)	//����Ϊ����ջ�ռ��С
		: m_size(size), m_top(0), m_p(0)
	{
		assert(m_size > 0);
		m_p = new char[m_size];
	}

	~stack()
	{
		delete[] m_p;
	}

	bool empty()	//ջ�շ���true
	{
		if (!m_top)
			return true;
		return false;
	}

	char top()	//����ջ������
	{
		assert(!empty());
		return m_p[m_top - 1];
	}

	void push(char data)	//ѹջ
	{
		if (m_top == m_size)//ջ��
		{
			char* p = new char[m_size + 16];
			memcpy(p, m_p, sizeof(char) * m_top);
			delete[] m_p;
			m_p = p;
		}
		m_p[m_top++] = data;
	}

	void pop()		//��ջ
	{
		assert(m_top > 0);
		m_top--;
	}
};

#else
#include <stack>
#endif

//��������Դ��룺����һ���ַ��������䷴�����
int main()
{
#ifdef NOUSE_STL
	stack s;
#else
	std::stack<char> s;
#endif
	char c;
	while (1)
	{
		std::cin.get(c);
		if (c == '\n')
			break;
		s.push(c);
	}

	while (!s.empty())
	{
		std::cout << s.top();
		s.pop();
	}
	std::cout << '\n';
}


