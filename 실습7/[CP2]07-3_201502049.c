#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int makeArray(int *intArray, int inputSize); // 배열에 0~999까지 랜덤한 값을 삽입하는 함수 선언
void swap(int *x, int *y); // 자리수를 바꾸어주는 함수 선언
void sortArray(int *intArray, int inputSize); // 받은 배열을 선택정렬하는 함수 선언 

int makeArray(int *intArray, int inputSize) { // 배열에 0~999까지 랜덤한 값을 삽입

	int i;

	srand((unsigned int)time((time_t*)NULL)); // 난수 발생

	printf("배열에 정수값 삽입합니다. \n");

	for (i = 0; i < inputSize; i++) {
		intArray[i] = rand() % 1000; // 0~999까지 난수 삽입
	}

	return 0;
}

void swap(int *x, int *y) { // 자리수를 바꾸어주는 함수 

	int temp = *x;  // temp 라는 임의값을 선언하여 x,y의 위치를 변화
	*x = *y;
	*y = temp;

	return ;
}


void sortArray(int *intArray, int inputSize) {
	int i, j;
	int *min; // 배열에 저장된 난수값이 가장 작은 원소의 주소값
	for (i = 0; i < inputSize; i++)
	{
		min = intArray + i; 
		for (j = i; j < inputSize; j++)
			if (*min > *(intArray + j)) // 가장 작은 원소의 값 비교
				min = intArray + j; 
				swap(min, intArray + i); // 가장 작은 원소의 값과 현재 i번째 배열값을 바꾼다.
	}
	printf("오름차순으로 정렬합니다.\n");
	return;
}



int main() {

	int intArray[20];
	int input = 0;
	printf("몇번째 값까지 넣을까요? : ");  // 배열의 길이 설정
	scanf("%d", &input); 

	makeArray(intArray, input); // 배열에 난수 값 삽입

	for (int i = 0; i < input; i++) {
		printf("%d  ", intArray[i]);  // 배열 출력
	}

	printf("\n");



	sortArray(intArray, input);  // 배열 선택 정렬 실행

	for (int i = 0; i < input; i++) { // 선택 정렬을 한 배열 출력
		printf("%d  ", intArray[i]);
	}

	printf("\n");
	return 0;
}