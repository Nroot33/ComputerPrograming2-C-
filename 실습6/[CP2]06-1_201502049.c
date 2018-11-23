#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int makeArray(int *intArray, int inputSize);
int calSum(int *intArray, int arraySize);
int calAvg(int *intArray, int arraySize);
int findMin(int *intArray, int arraySize);
int findMax(int *intArray, int arraySize);

int makeArray(int *intArray, int inputSize) { //�迭�� 0~1000���� ������ ���� ����

	int i;

	srand((unsigned int)time((time_t*)NULL));

	printf("�迭�� ������ �����մϴ�. \n");

	for (i = 0; i < inputSize; i++) {
		intArray[i] =  rand()%1000;
	}

	return 0;
}

int calSum(int *intArray, int arraySize) { // ���Ե� ���������� ���� ����

	int i;
	int calsum = 0;

	for (i = 0; i < arraySize; i++) { // �� �迭�� ���� ��� ����
		calsum += intArray[i];
	}

	return calsum; // �迭�� �հ� ��ȯ
}

int calAvg(int *intArray, int arraySize) { // ���Ե� ���������� ����� ����

	int i;
	int calsum = 0;
	int calavg = 0;

	for (i = 0; i < arraySize; i++) { //�� �迭�� ���� ��� ����
		calsum += intArray[i];
	}

	calavg = calsum / arraySize; // ���� �迭�� size��ŭ ������ ����� ����

	return calavg; //�迭�� ��հ� ��ȯ

}

int findMin(int *intArray, int arraySize) { // ���Ե� �������� �� �ּڰ��� ����

	int findmin;
	int i;

	printf("�迭�� �ּڰ��� ���մϴ�.\n");

	findmin = intArray[0]; // �迭 ù ���� �ּڰ����� �ʱ�ȭ
	for (i = 1; i < arraySize; i++) {  
		if (intArray[i] < findmin) findmin = intArray[i]; // ��ü�迭�� ���� ���ذ��� �ּڰ��� ã�´�.
	}

	return findmin;
}

int findMax(int *intArray, int arraySize) { // ���Ե� �������� �� �ִ��� ����


	int findmax;
	int i;

	printf("�迭�� �ִ��� ���մϴ�.\n");
	 
	findmax = intArray[0]; // �迭 ù ���� �ִ����� �ʱ�ȭ
	for (i = 1; i < arraySize; i++) {
		if (intArray[i] > findmax) findmax = intArray[i]; // ��ü�迭�� ���� ���ذ��� �ִ��� ã�´�.
	}

	return findmax;

}

void main(){
	
	
	int intArray[20];
	int input = 0;

	printf("���° ������ �������? : ");
	scanf("%d",&input);

	makeArray(intArray,input);
	
	for (int i = 0; i < input; i++) {
		printf("%d  ", intArray[i]);
	}
	
	printf("\n");

	int sum = calSum(intArray, input);
	printf("�迭�� �� : %d \n",sum);

	int avg = calAvg(intArray, input);
	printf("�迭�� ��� : %d \n", avg);

	int max = findMax(intArray, input);
	printf("�迭�� �ִ� : %d \n", max);

	int min = findMin(intArray, input);
	printf("�迭�� �ּڰ� : %d \n", min);
	
	return 0;
}
