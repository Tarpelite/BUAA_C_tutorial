#ifndef classnum
#define classnum

#include<algorithm>
#include<iostream>
#include<cstdio>

namespace linear_algebra
{
	using std::abs;
	int gcd(int fi,int se)
	{
		while(se)
		{
			fi^=se^=fi^=se;
			se=se%fi;
		}
		return fi;
	}
	int lct(int fi,int se)
	{
		return fi*se/gcd(fi,se);
	}
	class num
	{
		private:
			int numerator,denominator;	//numerator:分子 denominator:分母
			void reduce()
			{
				if(denominator==0)
				{
					std::cerr<<this<<"error : The Denominator can't be 0"<<std::endl;
				}
				if(numerator)
				{
					int g=gcd(abs(numerator),abs(denominator));
					numerator/=g;
					denominator/=g;
				}
				else
				{
					denominator=1;
				}
				return;
			}
			void standardize()
			{
				if(!((numerator<=0)^(denominator<=0)))
				{
					numerator=abs(numerator);
					denominator=abs(denominator);
				}
				else
				{
					numerator=-abs(numerator);
					denominator=abs(denominator);
				}
				return;
			}
		public:
			int get_numerator() const
			{
				return numerator;
			}
			int get_denominator() const
			{
				return denominator;
			}
			double get_value() const
			{
				return (double)numerator/(double)denominator;
			}
			num(){numerator=denominator=1;}
			num(int a):numerator(a),denominator(1){standardize();}
			num(int a,int b):numerator(a),denominator(b){standardize();reduce();}
			void print(int length)
			{
				char s[100];
				length--;
				if(denominator==1)
				{
					sprintf(s,"%%%dd",(length>>1)+1);
					printf(s,get_numerator());
					for(int i=1;i<=length-(length>>1);i++)
					{
						putchar(' ');
					}
				}
				else
				{
					sprintf(s,"%%%dd/%%-%dd",length>>1,length-(length>>1));
					printf(s,get_numerator(),get_denominator());
				}
				return;
			}
	};
	num operator * (const num& fi,const num& se)
	{
		return num(fi.get_numerator()*se.get_numerator(),fi.get_denominator()*se.get_denominator());
	}
	num operator / (const num& fi,const num& se)
	{
		return num(fi.get_numerator()*se.get_denominator(),fi.get_denominator()*se.get_numerator());
	}
	num operator + (const num& fi,const num&se)
	{
		if(fi.get_denominator()==se.get_denominator())
		{
			return num(fi.get_numerator()+se.get_numerator(),fi.get_denominator());
		}
		/*
		int the_gcd=gcd(fi.get_denominator(),se.get_denominator());
		return num(fi.get_numerator()*(se.get_denominator()/the_gcd)+se.get_numerator()*(fi.get_denominator()/the_gcd),fi.get_denominator()/the_gcd*se.get_denominator());
		*/
		return num(fi.get_numerator()*se.get_denominator()+se.get_numerator()*fi.get_denominator(),fi.get_denominator()*se.get_denominator());
	}
	num operator - (const num& fi)
	{
		return num(-fi.get_numerator(),fi.get_denominator());
	}
	num operator - (const num& fi,const num& se)
	{
		/*
		if(fi.get_denominator()==se.get_denominator())
		{
			return num(fi.get_numerator()-se.get_numerator(),fi.get_denominator());
		}
		int the_gcd=gcd(fi.get_denominator(),se.get_denominator());
		return num(fi.get_numerator()*(se.get_denominator()/the_gcd)-se.get_numerator()*(fi.get_denominator()/the_gcd),fi.get_denominator()/the_gcd*se.get_denominator());
		*/
		return fi+(-se);
	}
	std::ostream& operator << (std::ostream& out,const num& fi)
	{
		if(fi.get_denominator()==1)
		{
			out<<fi.get_numerator();
		}
		else
		{
			out<<fi.get_numerator()<<'/'<<fi.get_denominator();
		}
		return out;
	}
	/*
	   istream& operator >> (istream& in,num& fi)
	   {
	   string read;
	   in>>read;
	   cerr<<"Sorry,I have not written it as a result of I'm too cai."<<endl;
	   fi=num();
	   return in;
	   }
	   */
	bool operator < (const num &fi,const num &se)
	{
		return fi.get_numerator()*se.get_denominator()<se.get_numerator()*fi.get_denominator();
	}
	bool operator == (const num &fi,const num &se)
	{
		return fi.get_numerator()*se.get_denominator()==se.get_numerator()*fi.get_denominator();
	}
	bool operator > (const num &fi,const num &se)
	{
		return fi.get_numerator()*se.get_denominator()>se.get_numerator()*fi.get_denominator();
	}
	bool operator != (const num &fi,const num &se)
	{
		return fi.get_numerator()*se.get_denominator()!=se.get_numerator()*fi.get_denominator();
	}
}

#endif
