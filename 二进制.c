// 这是原始阶段， 我的第一想法；


#include <iostream.h>
#include <fstream.h>
#include <cmath>

void writefile(char* str)
{
	ofstream out1;
	out1.open("modi2.txt", ios::binary|ios::app);
	for (int i = 0; str[i] != 0; i++)
	{
		out1.put(str[i]);
	}
	out1.close();
}

void fun(int x)
{
	cout<<"请输入一个整数：";
	cin>>x;
	int a[1024];
	int i = 0;
	while (x > 0)
	{
		a[i++] = x % 2;
		x = x / 2;
	}
	
	int len = i;

	char b[1024];
	for (int j = 0; j < len; j++, i--)
	{
		b[j] = a[i-1] + '0';
		cout<<b[j];
	}
	b[j] = 0;
	writefile(b);
}


void clearfile()
{
	ofstream out1;
	out1.open("modi2.txt");
	out1.close();
}

int main()
{
	clearfile();
	fun(13);
	return 0;
}


// 下面程序显示了指针的妙用。


char str[32];
int i;
for (i = 30; i >= 0; i--)
{
    if (x % 2)
        str[i] = '1';       // str[i] = (x%2) + '0';
    else
        str[i] = '0';
    x = x / 2;
    
    if (!x)
        break;
}

str[31] = '\0';
cout<<&str[i]<<endl;
writefile(&str[i]);
