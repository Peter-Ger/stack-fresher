//组栈示例:实现一个char类型数据栈

//用宏参数定义一个是否用stl::stack的开关：定义宏，用自定义的stack；注销宏定义，便是用stl::stack
#define  NOUSE_STL


#include <iostream>

#ifdef NOUSE_STL
#include <cassert>

class stack
{
	int m_size;		//栈空间大小
	int m_top;		//栈顶下标
	char* m_p;		//栈空间，动态分配
public:
	stack()
		:m_size(16), m_top(0), m_p(0)
	{
		m_p = new char[m_size];
	}

	stack(int size)	//参数为定制栈空间大小
		: m_size(size), m_top(0), m_p(0)
	{
		assert(m_size > 0);
		m_p = new char[m_size];
	}

	~stack()
	{
		delete[] m_p;
	}

	bool empty()	//栈空返回true
	{
		if (!m_top)
			return true;
		return false;
	}

	char top()	//返回栈顶数据
	{
		assert(!empty());
		return m_p[m_top - 1];
	}

	void push(char data)	//压栈
	{
		if (m_top == m_size)//栈满
		{
			char* p = new char[m_size + 16];
			memcpy(p, m_p, sizeof(char) * m_top);
			delete[] m_p;
			m_p = p;
		}
		m_p[m_top++] = data;
	}

	void pop()		//出栈
	{
		assert(m_top > 0);
		m_top--;
	}
};

#else
#include <stack>
#endif

//主程序测试代码：读入一串字符串，将其反序输出
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


