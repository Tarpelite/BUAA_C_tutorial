#ifndef classmatrix
#define classmatrix

#include<algorithm>
#include<iostream>
#include<cstdio>
#include"num.cpp"

namespace linear_algebra
{
	using std::abs;
	using std::swap;
	const int MAXN=10;
	class matrix
	{
		private:
			num a[MAXN][MAXN];
			int m,n;
			bool b;
		public:
			matrix(){}
			matrix(int mm,int nn,bool bb,num *aa):m(mm),n(nn),b(bb)
			{
				int cur=0;
				for(int i=1;i<=m;i++)
				{
					for(int j=1;j<=n+b;j++)
					{
						a[i][j]=aa[cur];
						cur++;
					}
				}
			}
			void print()
			{
				for(int j=1;j<=m;j++)
				{
					for(int k=1;k<=n+b;k++)
					{
						//printf("%8.4f",a[j][k]);
						a[j][k].print(9);
					}
					putchar(10);
				}
			}
			void guass(int need_print=0)	//need_print=0:不输出 1:输出操作 2:每次输出矩阵
			{
				int cur=0;
				for(int i=1;i<=m;i++)
				{
					if(need_print)
					{
						printf("line %d:\n",i);
					}
					cur++;
					while(cur<=n)
					{
						int j=i;
						while(j<=m&&a[j][cur]==num(0))
						{
							j++;
						}
						if(j<=m)
						{
							if(i!=j)
							{
								for(int k=cur;k<=n+b;k++)
								{
									swap(a[i][k],a[j][k]);
								}
								if(need_print)
								{
									printf("(%d,%d), ",i,j);
								}
							}
							break;
						}
						else
						{
							cur++;
						}
					}
					if(cur>n)
					{
						break;
					}
					num lam{0};
					for(int j=1;j<=m;j++)
					{
						if(i^j)
						{
							if(a[j][cur]!=0)
							{
								lam=-a[j][cur]/a[i][cur];
								for(int k=cur;k<=n+b;k++)
								{
									a[j][k]=a[j][k]+(a[i][k]*lam);
								}
								if(need_print)
								{
									//printf("%.4lf(%d)+(%d), ",lam,i,j);
									std::cout<<lam;
									printf("(%d)+(%d), ",i,j);
								}
							}
						}
					}
					if(need_print)
					{
						putchar(10);
					}
					if(need_print>=2)
					{
						print();
					}
				}
				if(need_print)
				{
					std::cout<<"final:\n";
				}
				for(int i=1;i<=m;i++)
				{
					int be=0;
					for(int j=1;j<=n;j++)
					{
						if(a[i][j]!=num(0))
						{
							be=j;
							break;
						}
					}
					if(be)
					{
						num lam=num(1)/a[i][be];
						for(int j=be;j<=n+b;j++)
						{
							a[i][j]=a[i][j]*lam;
						}
						if(need_print)
						{
							//printf("%.4lf(%d), ",lam,i);
							std::cout<<lam;
							printf("(%d), ",i);
						}
					}
				}
				if(need_print)
					putchar(10);
				if(need_print>=2)
				{
					print();
				}
				return;
			}
			bool is_square()
			{
				return n==m;
			}
			int get_row()
			{
				return m;
			}
			int get_col()
			{
				return n;
			}
			num get_element(int i,int j)
			{
				return a[i][j];
			}
	};
	num det(matrix ma)//因为要高斯，所以不传引用参。
	{
		if(!ma.is_square())
		{
			std::cerr<<"If you want to get det,the matrix should be a square matrix!";
			return 0;
		}
		ma.guass();
		num re=1;
		for(int i=1;i<=ma.get_row();i++)
		{
			re=re*ma.get_element(i,i);
		}
		return re;
	}
}
#endif
