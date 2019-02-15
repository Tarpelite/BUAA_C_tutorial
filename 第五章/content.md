# 控制流

## 条件语句  

用于执行判断和跳转，比如**if**。  
  

### 表达式的真值  

C语言把任何非零和非空的值假定为true，把零或null假定为false。  

```c
if (1)
	printf("1 is true\n");
else
	printf("1 is flase\n");
if (0)
	printf("0 is true\n");
else
	printf("0 is flase\n");
if (-1)
	printf("-1 is true\n");
```  

如果是一个表达式，当表达式成立时为true，不成立时为false

### 逻辑运算符  

1. 表示判断的相等，用的是 **==两个等号** ,一个等号是赋值号!
每年都会有初学者在这个地方WA的不知所措，大家一定要注意。
2. `&&` 表示 与
例子：大于3的奇数 `((n % 2 == 1) && (n > 3) )`
3. `||` 表示 或 
例子：是偶数或者大于100的数 `((n % 2 == 0)||（n > 100))`
4. `!` 表示 非 
例子：不是偶数的数 `!(n % 2 == 0)`
聪明的你一定发现了，也可以可以写成`(n % 2 == 1)`
另一个写法是`(n % 2 != 0)` 其中`!=`表示不等于

**在不熟练优先级的时候，勤加括号！！！加括号总能对的！！！**

### if  

if的语法十分简单，这里不赘述。我们主要举几个例子。

如果n大于0，输出QiuZhangKeYanKeTian。无论什么情况下都输出QiuZhangRenJianRenAi  

```c
if (n > 0)
    printf("Tarpe is easy-going\n");
printf("Tarpe is a strict TA\n");
```  

那如果写成这样呢？  

```c
if (n > 0)
    printf("Tarpe is easy-going\n");
    printf("Tarpe is a strict TA\n");
```  

这两份代码效果其实是一样的，区别在于缩进，建议大家写成第一种形式，相对逻辑关系更清晰。[C语言代码规范](http://c.biancheng.net/view/158.html)
那写成这样呢？  

```c
if (n > 0)
{
    printf("Tarpe is easy-going\n");
    printf("Tarpe is a strict TA\n");
}
```  

这份代码中两条输出语句被复合到了一起，是一条复合语句，当n > 0时才会被执行。  

### if-else  

为了表示如果 ... 否则 ... 这样的含义，我们引进了if-else语句。

[闰年判断](https://buaacoding.cn/problem/1548/index)：  

```c
if ( (year % 400 == 0）|| ((year % 4 == 0) && (year % 100 != 0)）)
    printf("Yes\n");
else
    printf("No\n");
```  

### if-else嵌套  

问题的判断可能不止一个条件，需要多个分支:
如果 A 那么 AA
否则 如果 B 那么 BB
否则 如果 C 那么 CC
否则 DD

讲一个~~编造的~~故事：某学妹拜托Tarpe酋长去买水果。学妹说：“学长帮我去买两个西瓜，如果看见了苹果，买一个”，最后Tarpe酋长买了一个西瓜回来。学妹很疑惑，这一个西瓜是怎么买出来的？Tarpe酋长：“因为我在回来的路上看见了苹果”。

学妹的思路：  

```c
//为1表示看见了西瓜或苹果，为0表示没看见
if (watermelon == 1 && apple == 1)
    printf("Tarpe酋长买回来两个瓜和一个苹果");
else if (watermelon == 1)
    printf("Tarpe酋长买回来两个瓜");
else if (apple == 1)
    printf("Tarpe酋长买回来一个苹果");
else
    printf("Tarpe酋长什么都没有买");
```  

Tarpe酋长的思路：  

```c
if (watermelon == 0)
    printf("Tarpe酋长什么都没有买");
else if (apple == 1)
    printf("Tarpe酋长买了一个西瓜");
else
    printf("Tarpe酋长执行原计划，买了两个西瓜");
```


### switch

switch语句的语法见下面例子，它会对**每个**case进行检查直到被break掉。  

```c
char c = 'B';
printf("first example:\n");
switch (c) {	
	case 'A':
		printf("A\n");
	case 'B':
		printf("B\n");
	default :
		printf("C\n");
}
printf("second example:\n");
switch (c) {	
	case 'A':
		printf("A\n");
		break;
	case 'B':
		printf("B\n");
		break;
	default :
		printf("C\n");
		break;
}
```

## 循环语句  

有的时候，我们可能需要多次执行同一块代码，这时我们就需要用到循环语句。  

### for  

```c
for ( init; condition; increment)
{
   /*code*/
}
```  

掌握for循环最关键的便是理解它的执行顺序：  

1. 执行init。
2. 判断condition, 如果为假结束循环。
3. 执行code。
4. 执行increment。
5. 回到第2步。

```c
int a;
for (a = 1; a <= 5; ++a)
{
	printf("%d ", a);
}
printf("%d\n", a);
//输出为1 2 3 4 5 6
```

### while  

```c
while (condition)
{
    /*code*/
}
```  

while可以看作没有init和increment的for循环。
当condition为真时会一直执行code部分。  

```c
int a = 10;
while (a < 15)
{
	printf("%d ", a);
	a = a + 1; 
}
//输出为10 11 12 13 14  
```  

### do-while  

```c
do
{
    /*code*/
} while (condition);
```  

它会先执行code部分再判断condition，当condition为假时结束循环。

```c
int a = 10;
do {
	a = a + 1;
	printf("%d ", a);
} while (a < 15);
//输出为11 12 13 14 15  

```  

通常do-while循环用的比较少，比较常用的是for和while循环。

### 循环控制语句

#### break  

当break语句出现在一个循环内时，循环会立即终止。

```c
int a = 10;
while (a < 20)
{
    printf("%d ", a);
    a = a + 1;
    if (a > 15)
        break;
}
//输出为10 11 12 13 14 15
```  

#### continue  

C语言中的continue语句有点像break语句。但它不是强制终止，continue 会跳过当前循环中的代码，强迫开始下一次循环。可以理解为直接跳到到code块的末尾。  

```c
int i = 1;
for ( ; i <= 5; i++)
{
	if (i == 3) continue;
	printf("%d ", i);
}
//输出为1 2 4 5
```

### Tips  

1. `if (n == 1);`语法正确，是一条完整的if语句，但当n为1时什么都不会发生。（分号结尾没有执行语句）
2. 在if-else结构中else会去找离它最近的一个if, 如果没有把握可以多加大括号。
3. switch语句会执行所有的case，初学者建议都加上break，当然更建议使用if语句。
4. if，for这些后面有多条语句需要执行时一定要记住加上大括号。
5. ~~Tarpe酋长可甜可盐，人见人爱，还会买水果，学妹考虑一下？~~
