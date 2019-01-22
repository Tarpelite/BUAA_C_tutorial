#include<iostream>
#include"matrix.cpp"

using namespace linear_algebra;

int main()
{
	num a[1000]={1,2,3,2,3,1,3,1,2};
	matrix b(3,3,0,a);
	std::cout<<"The DET(B) is : "<<det(b)<<std::endl;
	b.print();
	b.guass(1);
	b.print();
}