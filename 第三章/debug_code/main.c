/*
 * Debug示例程序 
 * 程序目的是读入两个数A B 输出A*B-(A+B)的值
 * 该程序有大量错误
 */

#include <stdio.h>

int main()
{
	int a,b,c,d,e;
	scanf("%d%d",&a,b);
	c=a*a;
	d=a+b;
	e=c-d;
	printf("%d",d);
	return 0;
}
