#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int findMin(int index, int findmin);
int findMax(int index, int findmax);
int divide(int first, int arraySize, int findmax);

int intArray[20];

int makeArray(int *intArray, int inputSize) { //배열에 0~1000까지 랜덤한 값을 삽입

	int i;
	
	srand((unsigned int)time((time_t*)NULL));
	printf("배열에 정수값 삽입합니다. \n");

	for (i = 0; i < inputSize; i++) {
		intArray[i] = rand() % 1000;
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

int findMin(int index, int findmin) { // 삽입된 랜덤값들 중 최솟값을 구함

	if (index == 0) {

		return findmin; //index가 0이 되면 findmin을 반환
	}

	if ( intArray[index - 1] <  findmin)  //index-1의 자리의 배열부터 배열의 값을 비교하여, 작은 값을 findmin에 저장
	{
		findmin = intArray[index - 1];
	}

	return findMin(index - 1, findmin); // 다음 index로 재귀함수 호출
}

int findMax(int index, int findmax) { // 삽입된 랜덤값들 중 최댓값을 구함
	
	if(index == 0)//index가 0이 되면 findmax을 반환
	{
		if (intArray[index] < findmax){
			return findmax;
		}
		else{
			return intArray[index];
		}
	}

	findmax = divide(0, index, findmax); // first는 0으로 초기화 index는 현재의 인덱스 findmax는 최댓값.

	return findMax(index /2, findmax); // 반으로 나누어 재귀함수 호출
}

int divide(int first, int index, int findmax) { // 배열은 반으로 나누는 함수, first : 재귀에 필요한 매개변수로 0부터 1씩 증가

	if (index - index / 2 == first) { // 분할된 배열과 first의 값이 같으면 멈추고 배열의 인덱스와  findmax의 크기를 비교후 최댓값 반환

		if (intArray[index - first] > findmax) {
			return intArray[index - first];
		}
		else {
			return findmax;
		}
	}

	// findmax 값이 배열의 인덱스의 크기보다 작다면 값을 옮길 수 있도록 if문 작성
	if (intArray[index - first - 1] > findmax) {
		findmax = intArray[index - first - 1];
	}
	// first 값 을 증가 시켜 재귀함수를 호출 뒤 반환
	return divide(first + 1, index, findmax);
}

void main() {

	int input = 0;

	printf("몇번째 값까지 넣을까요? : ");
	scanf("%d", &input);

	makeArray(intArray, input);

	for (int i = 0; i < input; i++) {
		printf("%d  ", intArray[i]);
	}

	printf("\n");


	int sum = calSum(intArray, input);
	printf("배열의 합 : %d \n", sum);

	int avg = calAvg(intArray, input);
	printf("배열의 평균 : %d \n", avg);


	int min = findMin(input,1000);
	printf("배열의 최솟값 : %d \n", min);


	int max = findMax(input,0);
	printf("배열의 최댓값 : %d \n", max);


	return 0;
}
