# 控制流

## 条件语句
在需要对一些情况进行判断时，就需要用到条件语句
### 表达式的真值
C语言把任何非零和非空的值假定为true，把零或null假定为false。
```
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
### if-else
```
int a = 10;
if (a < 20)
{
    /* 如果条件为真，则输出下面的语句 */
       printf("a 小于 20\n" );
}
else
{
	/* 如果条件为假，则输出下面的语句 */
	printf("a 不小于 20\n");
}
printf("a 的值是 %d\n", a);
```
一个 if 语句后可跟一个可选的 else if...else 语句，这可用于测试多种条件。但需要注意的是：

- 一个 if 后可跟零个或一个 else，else 必须在所有 else if 之后。
+ 一个 if 后可跟零个或多个 else if，else if 必须在 else 之前。
* 一旦某个 else if 匹配成功，其他的 else if 或 else 将不会被测试。
```
int a = 100;
/* 检查布尔条件 */
if (a == 10)
{
   /* 如果 if 条件为真，则输出下面的语句 */
   printf("a 的值是 10\n" );
}
else if (a == 20)
{
   /* 如果 else if 条件为真，则输出下面的语句 */
   printf("a 的值是 20\n" );
}
else if (a == 100)
{
   /* 如果 else if 条件为真，则输出下面的语句 */
   printf("a 的值是 100\n" );
}
else
{
   /* 如果上面条件都不为真，则输出下面的语句 */
   printf("没有匹配的值\n" );
}
```
####嵌套if语句
在C语言中，嵌套if-else语句是合法的，这意味着可以在一个if或else if 语句内使用另一个if或else if语句。
```
int a = 100;
int b = 200;
/* 检查布尔条件 */
if (a == 100)
{
   /* 如果条件为真，则检查下面的条件 */
   if (b == 200)
   {
      /* 如果条件为真，则输出下面的语句 */
      printf("a 的值是 100，且 b 的值是 200\n" );
   }
}
```

易错：if-else是一个整体，**不要在if或者else后面打分号**，这意味着一条语句的结束。

### switch
一个 switch 语句允许测试一个变量或者表达式等于多个值时的情况。每个值称为一个 case，且被测试的变量会对**每个** switch case 进行检查
```
switch(expression)
{
    case constant-expression:
       statement(s);
       break; /* 可选的 */
    case constant-expression  :
       statement(s);
       break; /* 可选的 */
    /* 可以有任意数量的 case 语句 */
    default: /* 可选的 */
       statement(s);
}
```
- switch 语句中的 expression 是一个常量表达式，必须是一个整型或枚举类型。
- 在一个 switch 中可以有任意数量的 case 语句。每个 case 后跟一个要比较的值和一个冒号。
- case 的 constant-expression 必须与 switch中的变量具有相同的数据类型，且必须是一个常量或字面量。
- 当被测试的变量等于 case 中的常量时，case 后跟的语句将被执行，直到遇到 break 语句为止。
- 当遇到 break 语句时，switch 终止，控制流将跳转到 switch 语句后的下一行。
- 不是每一个 case 都需要包含 break。如果 case 语句不包含 break，控制流将会 继续 后续的 case，直到遇到 break 为止。
- 一个 switch 语句可以有一个可选的 default case，出现在 switch 的结尾。default case 可用于在上面所有 case 都不为真时执行一个任务。default case 中的 break 语句不是必需的。
```
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
当然，switch语句也是可以嵌套的，大家可以自行尝试

## 循环语句
有的时候，我们可能需要多次执行同一块代码，这时我们就需要用到循环语句。
### for 
```
for ( init; condition; increment )
{
   /*需要被执行的代码*/
}
```
- init 会首先被执行，且只会执行一次。这一步允许声明并初始化任何循环控制变量。你也可以不在这里写任何语句，只要有一个分号出现即可。
- 接下来，会判断 condition。如果为真，则执行循环主体。如果为假，则不执行循环主体，且控制流会跳转到紧接着 for 循环的下一条语句。
- 在执行完 for 循环主体后，控制流会跳回上面的 increment 语句。该语句允许你更新循环控制变量。该语句可以留空，只要在条件后有一个分号出现即可。
- 条件再次被判断。如果为真，则执行循环，这个过程会不断重复（循环主体，然后增加步值，再然后重新判断条件）。在条件变为假时，for 循环终止。

```
int a;
for (a = 1; a <= 10; ++a)
{
	printf("a的值此时为：%d\n", a);
}
```

### while
```
while (condition)
{
    /*需要被执行的代码*/
}
```
while会先进行条件的判断，条件为真时会执行while语句内的代码，执行完之后会再次判断条件，当条件为假时结束循环，否则继续执行while语句内的代码。
```
int a = 10;
while (a < 20)
{
	printf("a的值是 %d\n", a);
	a = a + 1; 
} 
```
### do-while
```
do
{
    /*需要被执行的代码*/
} while (condition);
```
条件表达式出现在循环的尾部，所以循环中的代码会在条件被测试之前至少执行一次。
如果条件为真，控制流会跳转回上面的 do，然后重新执行循环中的 代码。这个过程会不断重复，直到给定条件变为假为止。
```
int a = 10;
do {
	a = a + 1;
	printf("a的值是 %d\n", a);
} while (a < 15);
```
通常do-while循环用的比较少，比较常用的是for和while循环。

### 循环控制语句

#### break
C语言中break语句有以下两种用法：

- 当 break 语句出现在一个循环内时，循环会立即终止，且程序流将继续执行紧接着循环的下一条语句。
- 它可用于终止switch 语句中的一个 case。

```
int a = 10;
/* while 循环执行 */
while (a < 20)
{
    printf("a 的值： %d\n", a);
    a = a + 1;
    if (a > 15)
    {
        /*使用 break 语句终止循环*/
        break;
    }
}
```
#### continue
- C语言中的continue语句有点像break语句。但它不是强制终止，continue 会跳过当前循环中的代码，强迫开始下一次循环。

- 对于 for 循环，continue 语句执行后自增语句仍然会执行。对于 while 和 do...while 循环，continue 语句重新执行条件判断语句。
```
int i = 1;
for ( ; i <= 5; i++)
{
	if (i == 3) continue;
	printf("i的值是%d \n", i);
}
```
