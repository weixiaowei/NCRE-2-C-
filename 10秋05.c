#include <iostream.h>

class array{
	int *a, size_a;
	int *b, size_b;
	int top;
public:
	array(int *h, int n)
	{   
		// 在这里程序崩溃，因为重复定义， int *a, int *b
		a = new int[n];
		b = new int[n];
		for (int i = 0; i < n; i++)
		{
			a[i] = h[i];
		}
	    size_a = n;
	    size_b = 0;
    	top = 0;
	}

	~array()
	{
		delete [] a;
		delete [] b;
	}

	void set_top(int t)
	{
		top = t;
	}

	int cal(int *a, int n)
	{
		int min = a[0];
		int max = a[0];
		for (int i = 1; i < n; i++)
		{
			if (a[i] <= min)
				min = a[i];
			if (a[i] > max)
				max = a[i];
		}
		return (max - min);
	}

	void resolve()
	{
        int *temp = new int[size_a];
		int temp_size = 0;


		temp[0] = a[0];
		temp_size = 1;

		b[0] = a[0];
		size_b = 1;

		for (int i = 1, j = 1; i < size_a; i++, j++)
		{
			temp[j] = a[i];
			temp_size += 1;

			if (cal(temp, temp_size) <= top)
			{	
				if (temp_size > size_b)
				{
					for (int j = 0; j < temp_size; j++)
					{
						b[j] = temp[j];
					}
					size_b = temp_size;
				}
			}
			else
			{	
				temp[0] = a[i];
				temp_size = 1;
				j = 0;           //  若j = 1，进入下次循环j=2,漏掉了temp[1]
				
			}
		}
	}


	void print()
	{
		cout<<"原数组："<<endl;
		for (int i = 0; i < size_a; i++)
		{
			cout<<a[i]<<" ";
		}

		cout<<'\n';

		cout<<"处理后的数组："<<endl;
		for (i = 0; i < size_b; i++)
		{
			cout<<b[i]<<" ";
		}
		cout<<'\n';
	}
};


void main()
{   int h[] = {4,3,2,2,4,7,6,8,6,7,7};
    int n = 11;
	array ar(h, n);
	ar.set_top(2);
	ar.resolve();
	ar.print();
}

