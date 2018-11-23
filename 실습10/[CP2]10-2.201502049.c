#include <stdio.h>

void exchange(double*, double*);
void func(void(*fp)(double*, double*), double, double);

int main(void) {
	double a = 10, b = 20;
	func(exchange, a, b); // func �Լ� ����
	return 0;

}

void exchange(double *a, double *b) { // �ּҸ� �μ��� �޾� ����Ű�� �� ���� �ٲٴ� �Լ�

	double temp; // double�� ���� temp ����
	temp = *a; 
	*a = *b;
	*b = temp; // �ּҰ� ����

}

void func(void(*fp)(double*a, double*b), double a, double b) { // �� ��� �� exchange �Լ� ��� �� �ٽ� ����ϴ� �Լ�

	printf("a : %.1lf , b : %.1lf \n", a, b); // ���
	exchange(&a, &b); // exchange �Լ� ����
	printf("a : %.1lf , b : %.1lf \n", a, b); // �� ���� �� ���


}
