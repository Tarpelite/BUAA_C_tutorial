# 数组 


## 声明数组

在C中声明一个数组的方式十分简单，即`type arrayName [ arraySize ]`，其中`type`是任意C中可以定义的类型，`arraySize`必须是**整数常量**，我们看几个实例。

定义一个描述商品价格的数组，`double goods[1000]`，是有效的定义。

定义一个描述学生成绩的数组，`int std_score[2019]`，是有效的定义。

定义一个存储$$0! \sim 19!$$的数组，`int fact[20]`，是有效的定义，但是这是不合理的定义，注意到$$2^{31} -1 < 19!$$，所以应该定义为`long long fact[20]`，其包含`fact[0],fact[1],fact[2],...,fact[19]`共20个long long变量。

定义一个描述太阳光中各种波长是否出现的数组，`int light[700.12]`是无效的定义，数组大小不能实数。

定义一个描述$n$个人身高的数组，`int height[n]`，是不合理的定义，应该定义为$n$可能的最大值。

特别的，储存一个完整的英文单词可以定义为一个字符数组`char word[20]`，有时我们把字符数组中存储内容特殊的一种，定义为字符串，字符串拥有大量特殊的相关函数。

##数组的初始化

**仅在数组的声明时**，可以使用初始化语句。

如下所示

```c
double goods[5]={1.0,2.0,3.0,4.5,1.1};
int std_score[]={59,60,99,100,98,89};
int height[10]={0};
```

第一行相当于对，goods[0],goods[1],goods[2],goods[3],goods[4],5个变量一词赋值。

第二行忽略了定义数组大小，此时的数组大小初始化时元素的个数，即等同于`int std_score[6]={59,60,99,100,98,89}`。

其中第三行是，常用的定义一个初始值全为零的数组。

## 传递数组给函数

形式参数是一个未定义大小的数组，实际参数是数组的名字。

```c
void myFunc(int param[]);
```

## 小应用  

输入$n$个整数，输出他们的和。

```c
#include <stdio.h>

int getsum(int num[],int size){
	int i,ret=0;
	for (i=1;i<=size;i++) ret+=num[i];
	return ret;
}

int main(){
	int n,i;
	int a[100]={0};

	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%d",&a[i]);

	printf("%d\n",getsum(a,n));

	return 0;
}
```

## 多维数组

多维数组的声明和数组类似

`type name[size1][size2]...[sizeN]`声明了一个$$N$$维数组。

## 数组的应用

### 标号数组

### 标记数组

### 计数数组
