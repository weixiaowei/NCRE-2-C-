#include <iostream.h>

class array{
	int *p, n;
public:
	array(int* t, int m)
	{
		p = new int[m];
		for (int i = 0; i < m; i++)
		{
			p[i] = t[i];
		}
		n = m;
	}

	void fun()
	{
		int *temp = new int[n];
		int size = 0;


		temp[0] = p[0];
		size = 1;
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (p[i] == temp[j])
					break;
			}
			if (j == size)
			{
				temp[size] = p[i];
				size += 1;
			}
		}


		delete [] p;
		p = new int[size];
		n = size;

		for (i = 0; i < n; i++)
		{
			p[i] = temp[i];
		}

		delete [] temp;
	}

	~array()
	{
		delete [] p;
	}

	void print()
	{
		for (int i = 0; i < n; i++)
		{
			cout<<p[i]<<" ";
		}
		cout<<endl;
	}
};


void main()
{
	int h[] = {1,1,2,2,3,3,4,4};
	int m = 8;
	array ar(h, m);
	cout<<"原数组："<<endl;
	ar.print();
	ar.fun();
	cout<<"处理后的数组："<<endl;
	ar.print();
}
