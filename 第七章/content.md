# 字符串

## 介绍
在上一章中我们特意提及了字符数组中特定的一类：字符串，它是指使用null字符(ASCII码 0)终止的一维数组。
下面的声明和初始化，创建了字符串一个包含`Hello`的字符串。

```
char str[6]={'H','e','l','l','o'};
```

## 字符串常量
字符串常量用一对双引号及其内的字符表示。
据此**初始化**语句可以写成以下形式

```
char str[]="Hello";
```

和上一句是等价的，注意到字符串实际上有一个null字符，故该字符数组的大小为6。

##输入和输出字符串
输入和输出字符串可以用转义字符`%s`
如下

```
#include <stdio.h>
int main(){
	char str[10];
	scanf("input: %s\n",str);
	printf("echo: %s\n",str);
	return 0;
}
```

##字符串函数

在头文件`string.h`中，有大量的字符串函数。

`strlen(s1)`，得到`s1`字符串的长度。
`strcmp(s1,s2)`，比较`s1`和`s2`两个字符串的大小，相等则返回零，`s1<s2`则返回值小于零，`s1>s2`则返回值大于零。比较方式为字典序。
`strcat(s1,s2)`，将`s2`字符串拼接到`s1`的末尾。
`strcpy(s1,s2)`，将`s2`复制到`s1`，包括其null字符。

**注意**在初始化语句之外，将常量赋值给字符串变量，不能使用初始化的方式，可以使用`strcpy`函数。

##例子

```
#include <stdio.h>
#include <string.h>
int main(){
	char str1[]="Hello";
	char str2[40];
	char str3[40];

	printf("%d\n",strlen(str1));

	strcpy(str2,"World");

	if (strcmp(str1,str2)==0) printf("the same string!\n"); 
	else printf("something different!\n");

	strcpy(str3,str1);
	strcat(str3," ");
	strcat(str3,str2);

	printf("%s\n",str3);
	return 0;
}
```

输出结果为
```
5
something different!
Hello World
```
