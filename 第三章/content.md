# 捕虫(debug)是个技术活

## 怎么Debug

+ C语言的脸熟赛上线了。这天，酋长呆在家里无所事事，于是登陆OJ，很快的刷完的所有的题，下线开始摸鱼。 

### 晚上  

+ （QQ消息）**皮皮**：酋长你在吗，有学妹说她代码怎么都运行不对，把代码截图问我，我看不出来问题嘤嘤嘤。
+ **酋长**：行吧，你把代码给我看看
+ **皮皮**：（图片）
+ **酋长**：这么长！这代码太长我光看图片看不出来啊，我还是得有一份源代码来**调试**才行。
+ **皮皮**：那我让学妹直接找你。
+ ………………
+ **学妹**：学长，我这代码交上去总是反馈给我WA（注：结果错误），我看代码也看不出问题啊，为什么啊？
+ **酋长**：这代码稍微有一点多了，直接看的话的确不好看出来Bug在哪里，你得输入一些数据来进行**调试**。
+ **学妹**：学长该怎么调试呢。
+ **酋长**：调试一般都是自己**造一些数据**，**输入**进自己的程序，然后根据**运行结果**，**查看中间变量**，等等，来**修正程序的错误**（比如**逻辑错误**和**语法错误**）。
+ **酋长**：一般来说，Debug时，会使用特别的工具软件，可以让程序在特定地方停下来，然后可以查看程序中某个变量，可以单步运行……
+ **学妹**：emmmmm，那具体该怎么办呢，你教教我嘛
+ **酋长**：吼！

## 详解codeblocks和DevC++ debug  

最原始的调试，是在**编译**时加上特定的指令（如gcc是加上-g），使用特定的Debug软件（如gdb），来实现的。
但是这一般是命令行界面，因此不是很直观（如下图)。

![GDB使用示意图](./gdb黑框.png)

我们使用的大部分IDE都集成了Debug软件，让我们可以更直观的使用“调试”功能来Debug。

![Dev-c——GDB使用示意图](./Dev-cDebug界面.png)

***接下来以Dev-c为主要软件讲解调试***
我们以一下程序为实例： 

```c
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
```  

首先我们随便想几组数据，输入测试，当我们输入````4 5```` 这组数据时，发现没有运行结果，报错，因此我们需要调试。

首先在Dev-c中在 ***工具/编译选项*** 中将以下选项打开
![打开Debug](./打开Debug.png)

然后是设置断点，断点即为程序中断的地方，在在调试时，程序将会在运行到这一行时暂停。
一般在认为会出bug的地方前设置
点击行号以设置断点
![设置断点](./设置断点.png)

然后点击调试。
![调试按钮1](调试按钮1.png)
![调试按钮1](调试按钮2.png)
(两个均可)

然后程序将会在断点出停下
(注意，如果程序在断点前出现了输入，依然需要在命令行窗口中输入后继续运行)

这里我们输入数据为

	4 5

如果你也跟着一起运行了，你会发现这时候出现了错误窗口，
![segmentfault](segmentfault.png)
意味着出现了错误，我们需要先改正。由于是在断点所在行或之前行出现得问题，我们可以缩小搜索范围。眼尖得同学肯定已经看见了，scanf没写&符号，我们先停止调试，把它加上。

![更改1](更改1.png)


重新运行程序，输入````4 5````，发现运行结果有问题。

继续以13行为断点，重新调试。(注意，如果程序在断点前出现了输入，依然需要在命令行窗口中输入后继续运行)
现在这里蓝色的那一行，就表示当前暂停得那一行，同时该行还没运行。
![断点停止](断点停止.png)
然后我们点击**添加查看**，查看变量，这里要查看a，b，c，d，e五个变量。
![添加查看1](添加查看1.png)
添加完后看左边
![添加查看2](添加查看2.png)
可以看到当前各个变量的值。


然后，我们点击“下一步”按键，一行一行运行程序，同时观察左侧的值是否符合预期。
![监视结果](监视结果.png)

我们可以发现，c、e的值不正确，c应该为````4*5=20````,而这里是16，而e也因此不正确。仔细观察程序，追踪c的值的来源，可以发现是13行这一步的赋值得到的c的值，而阅读程序，可以发现赋值式子写错，应该为```` c=a*b;````于是在此，我们将其改正。
![更改2](更改2.png)

重新运行程序，输入````4 5````，发现输出结果有问题。
结合之前的调试情况，我们知道e的计算没有问题了，同时e储存的也是正确结果。这说明我们输出写错了。查看第16行，我们发现，我们输出了变量e。因此更改。
![更改3](更改3.png)

重新运行程序，输入````4 5````，运行结果正确，则说明我们的程序在````4 5````这组输入下没有问题了。

最终Debug成果：
![最终](最终.png)

注意，某一组测试数据通过了，不意味着你的代码是逻辑正确的了。比如如果这里输入的是```2 2```，是调试不出```a*a```这个错误的

关于code::blocks软件中的的调试功能的使用，与Dev-c大同小异。较为明显的区别是设置断点的方式，相信你可以通过寻找菜单的方式解决。 

以上只是基本的Debug方法，调试功能中，还有其他的功能可以方便你的Debug，未来你可以去尝试。
同时，Debug时还会遇到更为复杂的情况，这时候你的经验就时很重要的东西了。但是，如果遇到不知道为什么的情况该怎么办呢，这时候，就需要——上网查了。

## 使用stack Overflow 和 CSDN 查找问题

连续多日，酋长被问问题，然而由于他并不是经常在线，没法及时回答，于是，他建议问他问题的同学先自行上网查询。

+ **学妹**：其实我也尝试上网查过，但是我不知道该怎么搜
+ **酋长**：给你推荐两个网站：[Stack Overflow](https://stackoverflow.com/) 和 [CSDN](https://www.csdn.net/)，大多数问题都可以在这网站上查到。比如说编译错误的问题，你看不出来的话，就可以把编译的报错信息复制到这些网站的搜索界面去搜索。当然，也不局限于此，你也可以直接谷歌，去找问题啦。
+ **酋长**：比如说吧，你还记得上次我给你演示调试的时候的代码的那个运行时的错误吗。
+ **学妹**：这个吗？
![segmentfault](segmentfault.png)
+ **酋长**：对，如果你是第一次遇到的话，很可能不知道是为什么错吧。
+ **学妹**：是啊，根本看不出来是scanf写错了。
+ **酋长**：那么，这种时候，就可以搜索这个内容了。简单的，你可以直接百度/必应/谷歌这段话的关键词，当然也可以在那两个网站的搜索框里直接搜啦。比如搜索“Segmentation fault”。我相信，[搜出来的内容里](https://so.csdn.net/so/search/s.do?q=Segmentation%20fault&t=%20&u=)，肯定会有相关的描述的。

## 使用github管理代码

当代码量不断提升，代码复杂程度升高，可能经常一次写不完程序，而且在调试时，不得不面临改错了的情况，此时，如果有一个可以回退代码的东西该多好啊！

+ **皮皮**：酋长，我大作业现在想加新功能，但是我怕加错，想要复制一个中间版本作为备份，但是复制太多又太麻烦。有没有什么工具可以自动帮我干这个呢。
+ **酋长**：这种东西，当然有啦：
```
git,是一个分散式版本控制软件，最初由林纳斯·托瓦兹创作，于2005年以GPL释出。

——wikipedia
```
+ **皮皮**：好好，你别发wiki了，直接教我吧。
+ **酋长**：git是常用工具了，你可以在网上找到大把的教程。
+ **酋长**：当然，你为了方便，直接使用[图形化的git](https://cn.bing.com/search?q=%E5%9B%BE%E5%BD%A2+git)吧。然后上传[github](https://github.com)，这个东西，可以把你本机版本控制得到得仓库，在远程“备份”一个一样的。
+ **皮皮**：好，我去学学。

## 调试代码的一些小tips

1. 先找一组会出错的数据，这个数据可以是自己造的，可以是样例。
2. 调过一组数据不代表代码正确，有可能还有其他错，多试试几组数据，试试大一点的数据，试试极端一点的数据（比如0），说不定可以有新的问题被发现。
3. 在某一步发现错误，可能是好几行之前的代码，甚至很前面的位置的代码的问题，记得“追踪”自己的错误来源。
4. 一部分一部分的分块调试，确保一部分正确后才方便调试与之相关的其他部分。
5. ……
