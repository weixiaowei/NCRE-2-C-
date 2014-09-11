#include <iostream.h>
#include <string.h>

class str{
	char* p;
public:

  // 我直接用 p = s; 出现assertion, 为什么？
	str(char* s)
	{
		p = new char[strlen(s)+1];
		strcpy(p,s);
	
	}


	void move(char &t1, char &t2)
	{
		char temp;
		temp = t1;
		t1 = t2;
		t2 = temp;
	}

	void fun()
	{
		for (int i = 0; p[i] != '\0'; i++)
		{
			if ((p[i] >= 'A' && p[i] <= 'Z') || (p[i] >= 'a' && p[i] <= 'z'))
			{
				while (((p[i-1] >= 48 && p[i-1] <= 57) || p[i-1] == 91 || p[i-1] == 93) && (i > 0))
				{
					move(p[i], p[i-1]);
					i = i - 1;
				}
			}
		}
	}


	void print()
	{
		cout<<p<<endl;
	}

	~str()
	{
		delete [] p;
	}


};


void main()
{
	char* s = "11[22A3A3b4b4ccDD]55";
	str sr(s);
	cout<<"原字符串: ";
	sr.print();
	sr.fun();
	cout<<"处理后的字符串: ";
	sr.print();
}
