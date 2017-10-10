#include<stdio.h>

void swap(int *a, int *b){//此处*a可以看做*（&a1）即  a1（地址相同）// 
	printf("a: %d, b: %d\n", *a, *b);
	printf("%d\n", a);
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("a: %d, b: %d\n", *a, *b);
}

void swap2(int &a, int &b){//&a将a1的值和地址直接赋给a // 
	int temp = a;
	a = b;
	b = temp;
}
int main(){
	int a1 = 1;
	int b1 = 2;
	swap2(a1, b1);
	printf("a1:%d\n", &a1);
	printf("a1: %d, b1: %d\n", a1, b1);
}
