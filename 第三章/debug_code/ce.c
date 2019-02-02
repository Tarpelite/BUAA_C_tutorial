#include<stdio.h>

int gcd(int a,int b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b); 
}

int mian()
{
	int a,b,c;
	scanf("%d%d",&a,&b);
	c=a+b-gcd(a,b);
	printf("%d",c);	
	return 0;
}
