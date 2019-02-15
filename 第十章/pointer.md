# 指针
## 地址
在写程序时，我们访问变量(值)的方法是使用变量名，那么，指针给我们另一种访问一个变量(值)的方法。接下来的部分都在介绍，什么是这种不一般的访问方法。

## 指针的算术运算

指针的自增和自减运算并非是增加1和减少1，而是增加指针类型所代表的字节数，这样做的目的和效果可以看如下程序

```c
#include <stdio.h>

int a[10]={10,20};

int main(){
	int *p=a;
	printf("add=%p val=%d\n",p,*p);
	p++;
	printf("add=%p val=%d\n",p,*p);
	return 0;
}
```

注意到，我们可以认为数组名其实是一个不可改变的地址，不妨试试如下的几种输入方式。

```c
#include <stdio.h>

int a[10];

int main(){
	int *p=a;
	int i;
	
	for (i=1;i<10;i++) scanf("%d",a[i]);
	printf("case 1:"); for (i=1;i<10;i++) printf("%d ",a[i]); printf("\n");

	for (i=1;i<10;i++) scanf("%d",a+i);
	printf("case 2:"); for (i=1;i<10;i++) printf("%d ",a[i]); printf("\n");

	for (i=1;i<10;i++) scanf("%d",p+i);
	printf("case 3:"); for (i=1;i<10;i++) printf("%d ",a[i]); printf("\n");

	return 0;
}
```

## 将指针传入函数

利用指针和函数，可以写一些常常使用的函数。

### 交换函数

利用函数`swap`交换两个变量的值

```c
#include <stdio.h>

void swap(int *xx,int *yy){
	int t;
	t = *xx;
	*xx = *yy;
	*yy = t;
	return 0;
}

int main(){
	int a=10,b=5;
	printf("%d %d\n",a,b);
	swap(a,b);
	printf("%d %d\n",a,b);
	return 0;
}
```
