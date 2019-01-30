/*
 * Debug示例程序 
 * 程序目的是读入两个数A B 输出A*B-(A+B)的值
 * 
 */

#include <stdio.h>

int main()
{
	int a,b,c,d,e;
	scanf("%d%d",&a,&b);
	c=a*b;
	d=a+b;
	e=c-d;
	printf("%d",e);
	return 0;
}
