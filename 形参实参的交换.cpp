#include<stdio.h>

void swap(int *a, int *b){//�˴�*a���Կ���*��&a1����  a1����ַ��ͬ��// 
	printf("a: %d, b: %d\n", *a, *b);
	printf("%d\n", a);
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("a: %d, b: %d\n", *a, *b);
}

void swap2(int &a, int &b){//&a��a1��ֵ�͵�ֱַ�Ӹ���a // 
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
