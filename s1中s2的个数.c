#include <iostream.h>

int fun(char* s1, char* s2);

void main()
{
	 char s1[1024];
	 char s2[256];
	 int count;
     cout<<"give me a string: ";
     cin.getline(s1, 1024);
	 cout<<"give me another string: ";
	 cin.getline(s2, 256);
	 count = fun(s1, s2);
	 cout<<"count="<<count<<endl;
}

int fun(char* s1, char* s2)
{
	// 计算两字符串的长度
	int n1, n2;
	for(n1 = 0; s1[n1] != '\0'; n1++);
	for(n2 = 0; s2[n2] != '\0'; n2++);
	
	// 计算s1中出现的s2个数
	int count = 0;
	for (int i = 0; i < n1; i++)
	{
		int j;
		for (j = 0; j < n2; j++)        // 这里我想的是定义一个临时数组，将s1中 n2长度 赋给临时数组，再用临时数组来比较，
		                                //将问题变复杂。
		{
			if (s1[i+j] != s2[j])
				break;
		}

		if (j == n2)
		{
			count += 1;
			i = i + j - 1;   // 进入下次循环后，i++, 这里先减去1.
		}
	}
	return count;
}
