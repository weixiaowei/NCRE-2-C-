#include <iostream.h>

class array{
	int a[4][5];
public:
	//构造函数
	array(int b[][5], int n)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				a[i][j] = b[i][j];
			}
		}
	}
  //前3个数拼接成一个整数，赋值给第4个数
	void val(int j)
	{
		a[3][j] = 0;
		for (int i = 0; i < 3; i++)
		{
			int k = a[i][j];
			do
			{
				a[3][j] *= 10;
				k /= 10;
			}
			while (k);
			a[3][j] += a[i][j];
		}
		
	}
  //调用函数
	void fun()
	{
		for (int j = 0; j < 5; j++)
		{
			val(j);
		}
	}
  //print 函数
	void print()
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				cout<<a[i][j]<<'\t';
			}
			cout<<'\n';
		}
	}

};


void main()
{
	int b[4][5] = {1, 2, 0, 4, 1, 16, 11, 21, 0, 2, 2, 0, 3, 1, 3, 0, 0, 0, 0, 0};
	array arr(b, 4);
	cout<<"输出示例："<<endl;
	arr.print();
	arr.fun();
	cout<<"处理后的数组："<<endl;
	arr.print();
}
