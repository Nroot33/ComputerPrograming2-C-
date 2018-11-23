#include <stdio.h>

void exchange(double*, double*);
void func(void(*fp)(double*, double*), double, double);

int main(void) {
	double a = 10, b = 20;
	func(exchange, a, b); // func 함수 실행
	return 0;

}

void exchange(double *a, double *b) { // 주소를 인수로 받아 가리키는 두 값을 바꾸는 함수

	double temp; // double형 변수 temp 생성
	temp = *a; 
	*a = *b;
	*b = temp; // 주소값 변경

}

void func(void(*fp)(double*a, double*b), double a, double b) { // 값 출력 및 exchange 함수 사용 후 다시 출력하는 함수

	printf("a : %.1lf , b : %.1lf \n", a, b); // 출력
	exchange(&a, &b); // exchange 함수 실행
	printf("a : %.1lf , b : %.1lf \n", a, b); // 값 변경 후 출력


}
