#include <iostream.h>

void fun(char* s1, char* s2);

void main()
{
	 char s1[1024];
	 char s2[256];
     cout<<"give me a string: ";
     cin.getline(s1, 1024);
	 cout<<"give me another string: ";
	 cin.getline(s2, 256);
	 fun(s1, s2);
}

void fun(char* s1, char* s2)
{
	// 计算两字符串的长度
	//int n1, n2;
	//for(n1 = 0; s1[n1] != '\0'; n1++);    // 0 与'\0' 的效果相同。
	//for(n2 = 0; s2[n2] != '\0'; n2++);
	//cout<<"n1="<<n1<<" "<<"n2="<<n2<<endl;
    
  
  此种方法变复杂。
	int n1 = 0, n2 = 0;
	for (int i = 0; s1[i] != 0; i++)
	{
		n1++;
	}
	for (i = 0; s2[i] != 0; i++)
	{
		n2++;
	}
	cout<<"n1="<<n1<<" "<<"n2="<<n2<<endl;
}
