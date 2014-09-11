#include <iostream.h>
#include <math.h>

#define MAXSIZE 100

class factor{
	int n;
	int factors[MAXSIZE], exps[MAXSIZE];
	int count;
public:

  //构造函数
	factor(int x)
	{
		n = x;
		count = 0;
	}
  
  
	void save_factor(int fact, int exp)
	{   
		factors[count] = fact;
		exps[count] = exp;
		count++;
	}

  //寻找n的质因子及出现的次数
	void process()
	{
		int f = 0, e = 0;

		for (int i = 1; i <= n; i++)
		{
			for (int j = 2; j < i; j++)
			{
				if (i % j == 0)
					break;
			}
			
			// 在这里stuck
		  if (i == j)
			{
				if (n % i == 0)
				{
                    f = i;
					e = 1;
					int num = i*i;
					while (n % num == 0)
					{
						e += 1;
						num = num * i;
					}
					save_factor(f, e);
				}
			}
			
		}

	}

	void print()
	{
		cout<<n<<" = ";
		for (int i = 0; i < count; i++)
		{   
			if (i == 0)
			    cout<<factors[i]<<"^"<<exps[i];
			else
			    cout<<"*"<<factors[i]<<"^"<<exps[i];
		}
	}

};


void main()
{
	int x;
	//int count = 0;
	cout<<"输入一个正整数：";
	cin>>x;
	factor p(x);
	p.process();
	p.print();
	cout<<endl;
}
