# 函数

简单理解，函数就是把它把一堆代码放到了一起，这些代码一起实现特定的功能。有些函数有返回值，有些函数需要你传入一些数据。

c语言自带了很多函数，比如用来连接两个字符串的`strcat()`,用来比较两个字符串的`strcmp()`(需要#include<string.h>)。
## 基本语法
```c
return_type function_name(parameter list)
{
   body of the function
}
```
函数只能返回一个值，return_type由返回的值的类型确定，但如果我不想返回值呢？这个时候就需要关键字**void**。

function_name的命名是可以随便取的，比如`zyynb`，只要符合命名规范就行。
参数列表可以传入很多参数，~~只要开心就好~~，也可以不传入参数。

### 实例
```c
#include<stdio.h>
int max(int a, int b)
{
    return a > b ? a : b;
}

void min(int a, int b)
{
    printf("%d\n", a < b ? a : b);
}

int main()
{
    int c = 10, d = 1;
    printf("%d\n", max(c, d));
    min(c, d);
}
```
需要返回的值由关键字return返回，return会直接退出这个函数。

调用函数时，程序会进入函数执行里面的代码，执行完成后开始执行调用函数的位置的后一条语句。

### 函数参数
有两种方式，一种是传入变量的值，在函数内修改不会影响到外面的变量，就相当于在函数内部定义了新的变量，值和传入的值一样。

一种是传入参数的地址，通过指针传递，在函数里面的操作会影响到函数外面的变量，相当于我们在函数内换个名字调用了外面的变量。

指针相关的知识会在第十章讲到，这里只举个例子。
```c
#include<stdio.h>
void swap(int a, int b)     //传入变量的值
{
	int t = a;
	a = b; b = t;
	printf("%d %d\n", a, b);
}

void swap2(int *a, int *b)  //传入变量的地址
{
	int t = *a;
	*a = *b; *b = t;
	printf("%d %d\n", *a, *b);
}

int main()
{
	int a = 10, b = 20;
	printf("sawp1:\n");
	swap(a, b);
	printf("%d %d\n", a, b); 
	printf("swap2:\n");
	swap2(&a, &b);
	printf("%d %d\n", a, b);
}
```
其中仅有swap2能对外面的a和b进行交换。

## 作用域
作用域就是一个变量所存在的区域，C语言有三个地方可以定义变量。

一是所有函数外部的全局变量，整个程序中都只能有它一个，是独一无二的~~尊贵~~变量。

二是某个函数或者某个代码块(如循环中的代码块)中定义的变量，当这部分的代码结束以后这个变量就没了，可以在其他地方继续定义。

三是函数的参数定义中，它只在这个函数里面有效。
