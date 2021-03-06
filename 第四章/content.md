# 数据类型

## 变量

每个变量都有**特定的类型**，不同大小的杯子装水有多少之分，不同类型的变量装数据也有自己的容量之分。

### 变量定义 

当我们想要喝水时，会拿起自己的杯子，如果杯子都长得一样，一般会给它贴个标签。贴在杯子上的标签就是标识符。贴标签这个过程就是定义了一个变量。
为了区分，在一张桌子上不能使用同一个标签，即在一个作用域内你不能定义两个名字一样的变量。 

```c
int a;          //定义了一个整型a
double b, c, d; //定义了三个浮点数b, c, d
int e = 2333;   //定义了一个整型e, 并赋初值为2333
```  

一些错误的定义方式：  

```c
int a;      //正确，定义了一个整型a
double a;   //错误，a的类型不可更改
int a;      //错误，在这个作用域内a已经被定义过
```  

注：作用域后面章节会讲。 

### 变量名称  

变量的名称可以由字母、数字和下划线字符组成。它必须以字母或下划线开头。大写字母和小写字母是不同的，因为C语言是**大小写敏感**的。
例如：  

```c
int Var, var;   //正确，是两个不同的变量
int a2;         //正确
int 2a;         //错误，是非法的变量定义
```  

C语言中还有一些关键字，他们具有特殊的含义，最简单的例子就是变量的类型int, char等，他们不能作为变量名。因为编译器并不能弄清楚你的int到底是想作为杯子的类型还是杯子的名字。  

### 变量初始化  

在函数外的变量为全局变量，它们有特定的初始值，比如int类型的初始值为0。
在函数内的变量为局部变量，它们只能在这个函数内使用，初始值最好由自己赋值。

### 整数类型

#### char  

8位整数类型，通常和字符对应，他们之间的对应关系可以参考**ASCII码表**。  
char类型数据本质上是一个整数，可以结合下面程序理解。  

```c
char a = 'a';
printf("%c %d\n", a, a);
char b = 97;
printf("%c %d\n", b, b);
```  

#### int  

32位整数类型。 
存储的整数范围是$-2^{31}\sim 2^{31}-1$。（-2的31次方~2的31次方-1）
这是**最常用**的一种变量类型，平时做题要注意考虑变量**是否溢出**，即计算过程中的值超出范围。 

```c
int a = 2147483647;     //未溢出
int b = 2147483648;     //溢出
int c = -b;             //未溢出
int d = c - 1;          //溢出
printf("%d %d %d %d\n", a, b, c, d);
```  

#### long long  

64位的整数类型。  
存储范围是$-2^{63}\sim2^{63}-1$。（（-2的63次方~2的63次方-1）
通常在int型范围不够时使用(当你装不下这么多水时，你可以换一个更大的杯子)。

### 浮点类型  

浮点数有**float**和**double**两种类型。
其中**double**的精度更高，即存储更准确，通常情况下使用**double**类型即可。
浮点数的运算难免会有误差产生，这是它的存储机制所决定的，在这里给出一个简单例子。
[Max.D的Hint](https://buaacoding.cn/problem/1539/index)  

```c
printf("%e\n", 0.1 + 0.1 + 0.1 - 0.3);
```

### 类型转换  

在C语言中，一条赋值语句的执行是先把赋值号右边的值算出来，然后赋值给左边的变量。即我们先把要装的水量算好以后一次装进去。我们来看下面一个例子。 

```c
int a = 1000000000;
int b = 1000000000;
long long c, d, e, f;
c = a * b;
d = (long long) a * (long long) b;
e = 1ll * a * b;
f = 1 * a * b;
printf("%d %d\n", a, b);
printf("%lld %lld %lld %lld\n", c, d, e, f);
```  

1是字面值，默认为int类型，1ll是long long类型的字面值，是一个常数。

1. 这段代码中，计算c和计算f的方式本质是一样的，赋值号右边的表达式里的变量全是int类型，所以最终计算出来的结果是int类型，这就导致了溢出。
1. 计算d的方式是类型的强制转换，在计算的时候把a和b转换成了long long类型参与计算，所以右边的计算结果是long long类型，是正确的。
1. 计算e的方式是在运算中加入了一个long long类型的1，这是C语言[隐式类型转换](https://blog.csdn.net/hanchaoman/article/details/7827031)。

最后再给出一个浮点型的例子，请大家和上面的例子结合起来自行理解。  

```c
int a = 3;
int b = 2;
printf("%lf\n", (double) a / (double) b);   //转成double以后再算a/b
printf("%lf\n", (double) (a / b));          //算出a/b后再转double
printf("%lf\n", 1.0 * a / b);               //原理同上例的e的计算,1.0是double类型的字面值
printf("%lf\n", a / b);                     //输出方式错误
```

### Tips:

1.很容易犯的错误就是计算过程中的溢出，int的最大值约为20亿，即$2*10^{9}$,做题时应先大致计算一下中途运算可能会出现的最大值，如果超过了int的范围需要考虑long long类型。

2.类型转换问题，最容易错的是浮点数除法部分，没有把握的话可以全部转换为double类型计算。
