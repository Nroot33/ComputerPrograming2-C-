#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int makeArray(int *intArray, int inputSize);
int calSum(int *intArray, int arraySize);
int calAvg(int *intArray, int arraySize);
int findMin(int *intArray, int arraySize);
int findMax(int *intArray, int arraySize);

int makeArray(int *intArray, int inputSize) { //배열에 0~1000까지 랜덤한 값을 삽입

	int i;

	srand((unsigned int)time((time_t*)NULL));

	printf("배열에 정수값 삽입합니다. \n");

	for (i = 0; i < inputSize; i++) {
		intArray[i] =  rand()%1000;
	}

	return 0;
}

int calSum(int *intArray, int arraySize) { // 삽입된 랜덤값들의 합을 구함

	int i;
	int calsum = 0;

	for (i = 0; i < arraySize; i++) { // 각 배열의 값을 모두 더함
		calsum += intArray[i];
	}

	return calsum; // 배열의 합값 반환
}

int calAvg(int *intArray, int arraySize) { // 삽입된 랜덤값들의 평균을 구함

	int i;
	int calsum = 0;
	int calavg = 0;

	for (i = 0; i < arraySize; i++) { //각 배열의 값을 모두 더함
		calsum += intArray[i];
	}

	calavg = calsum / arraySize; // 이후 배열의 size만큼 나누어 평균을 구함

	return calavg; //배열의 평균값 반환

}

int findMin(int *intArray, int arraySize) { // 삽입된 랜덤값들 중 최솟값을 구함

	int findmin;
	int i;

	printf("배열의 최솟값을 구합니다.\n");

	findmin = intArray[0]; // 배열 첫 값을 최솟값으로 초기화
	for (i = 1; i < arraySize; i++) {  
		if (intArray[i] < findmin) findmin = intArray[i]; // 전체배열의 값을 비교해가며 최솟값을 찾는다.
	}

	return findmin;
}

int findMax(int *intArray, int arraySize) { // 삽입된 랜덤값들 중 최댓값을 구함


	int findmax;
	int i;

	printf("배열의 최댓값을 구합니다.\n");
	 
	findmax = intArray[0]; // 배열 첫 값을 최댓값으로 초기화
	for (i = 1; i < arraySize; i++) {
		if (intArray[i] > findmax) findmax = intArray[i]; // 전체배열의 값을 비교해가며 최댓값을 찾는다.
	}

	return findmax;

}

void main(){
	
	
	int intArray[20];
	int input = 0;

	printf("몇번째 값까지 넣을까요? : ");
	scanf("%d",&input);

	makeArray(intArray,input);
	
	for (int i = 0; i < input; i++) {
		printf("%d  ", intArray[i]);
	}
	
	printf("\n");

	int sum = calSum(intArray, input);
	printf("배열의 합 : %d \n",sum);

	int avg = calAvg(intArray, input);
	printf("배열의 평균 : %d \n", avg);

	int max = findMax(intArray, input);
	printf("배열의 최댓값 : %d \n", max);

	int min = findMin(intArray, input);
	printf("배열의 최솟값 : %d \n", min);
	
	return 0;
}
