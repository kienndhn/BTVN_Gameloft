#include<stdio.h>
#include <stdlib.h>

//ham tinh giai thua
unsigned long long factorial(int i) {
	if (i < 2) return 1;
	else return i*factorial(i - 1);
}

int main() {
	int n = 0;
	//nhap vao so nguyen khong am
	do {
		printf("nhap n khong am: ");
		scanf_s("%d", &n);
	} while (n < 0);
	
	
	printf("n! = %llu\n", factorial(n));

	system("pause");
	return 0;
}