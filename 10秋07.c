#include <iostream.h>
#include <string.h>

class id{
	char s[19], x[12];
	int w[17];
public:
	id(char* str)
	{
		strcpy(s, str);
		
		//注意赋值的方法
		char x1[] = "10X98765432";
		int w1[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};

		strcpy(x, x1);

		for (int i = 0; i < 17; i++)
		{
			w[i] = w1[i];
		}
	}

	void fun()
	{
	  
	  // 巧妙
		char t[20];
		strcpy(t, s+6);
		strcpy(s+8, t);
		
		s[6] = '1';
		s[7] = '9';

		int sum = 0;
		for (int i = 0; i < 17; i++)
			sum += (s[i] - '0')*w[i];
		sum %= 11;
		s[17] = x[sum];
		// 注意这里
		s[18] = '\0';
	}

	void print()
	{
		cout<<s<<endl;
	}
};

void main()
{
	char st[] = "340524800101001";
	id test(st);
	cout<<"原身份证号：";
	test.print();
	test.fun();
	cout<<"处理后的身份证号: ";
	test.print();
}
