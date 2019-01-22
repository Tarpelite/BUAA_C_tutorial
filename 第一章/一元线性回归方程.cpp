#include<bits/stdc++.h>
using namespace std;

double sqr(double x) 
{
	return x * x;
}

int n;
double a, b, r;
double x[100], y[100];
double sumx, sumy, sumx_y, sumx_x, sumy_y;
double avgx, avgy, avgx_y, avgx_x, avgy_y;

int main()
{
	//将数据输入到同目录下的data.txt文件中 第一行一个数n表示数据行数，接下来n行每行两个数表示x和y 
	freopen("data.txt", "r", stdin);
	scanf("%d", &n); 
	for (int i = 1; i <= n; ++i)
	{
		scanf("%lf %lf", &x[i], &y[i]);
		sumx += x[i]; sumy += y[i];
		sumx_y += x[i] * y[i];
		sumx_x += sqr(x[i]);
		sumy_y += sqr(y[i]); 
	}
	avgx = sumx / n; avgy = sumy / n;
	avgx_y = sumx_y / n;
	avgx_x = sumx_x / n;
	avgy_y = sumy_y / n;
	b = (avgx * avgy - avgx_y) / (avgx * avgx - avgx_x);
	printf("b = %.10lf\n", b);
	a = avgy - b * avgx;
	printf("a = %.10lf\n", a);
	r = (avgx_y - avgx * avgy) / sqrt( (avgx_x - sqr(avgx)) * (avgy_y - sqr(avgy)) );
	printf("r = %.10lf\n", r);
	return 0;
}
