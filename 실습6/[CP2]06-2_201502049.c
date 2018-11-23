#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int findMin(int index, int findmin);
int findMax(int index, int findmax);
int divide(int first, int arraySize, int findmax);

int intArray[20];

int makeArray(int *intArray, int inputSize) { //�迭�� 0~1000���� ������ ���� ����

	int i;
	
	srand((unsigned int)time((time_t*)NULL));
	printf("�迭�� ������ �����մϴ�. \n");

	for (i = 0; i < inputSize; i++) {
		intArray[i] = rand() % 1000;
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

int findMin(int index, int findmin) { // ���Ե� �������� �� �ּڰ��� ����

	if (index == 0) {

		return findmin; //index�� 0�� �Ǹ� findmin�� ��ȯ
	}

	if ( intArray[index - 1] <  findmin)  //index-1�� �ڸ��� �迭���� �迭�� ���� ���Ͽ�, ���� ���� findmin�� ����
	{
		findmin = intArray[index - 1];
	}

	return findMin(index - 1, findmin); // ���� index�� ����Լ� ȣ��
}

int findMax(int index, int findmax) { // ���Ե� �������� �� �ִ��� ����
	
	if(index == 0)//index�� 0�� �Ǹ� findmax�� ��ȯ
	{
		if (intArray[index] < findmax){
			return findmax;
		}
		else{
			return intArray[index];
		}
	}

	findmax = divide(0, index, findmax); // first�� 0���� �ʱ�ȭ index�� ������ �ε��� findmax�� �ִ�.

	return findMax(index /2, findmax); // ������ ������ ����Լ� ȣ��
}

int divide(int first, int index, int findmax) { // �迭�� ������ ������ �Լ�, first : ��Ϳ� �ʿ��� �Ű������� 0���� 1�� ����

	if (index - index / 2 == first) { // ���ҵ� �迭�� first�� ���� ������ ���߰� �迭�� �ε�����  findmax�� ũ�⸦ ���� �ִ� ��ȯ

		if (intArray[index - first] > findmax) {
			return intArray[index - first];
		}
		else {
			return findmax;
		}
	}

	// findmax ���� �迭�� �ε����� ũ�⺸�� �۴ٸ� ���� �ű� �� �ֵ��� if�� �ۼ�
	if (intArray[index - first - 1] > findmax) {
		findmax = intArray[index - first - 1];
	}
	// first �� �� ���� ���� ����Լ��� ȣ�� �� ��ȯ
	return divide(first + 1, index, findmax);
}

void main() {

	int input = 0;

	printf("���° ������ �������? : ");
	scanf("%d", &input);

	makeArray(intArray, input);

	for (int i = 0; i < input; i++) {
		printf("%d  ", intArray[i]);
	}

	printf("\n");


	int sum = calSum(intArray, input);
	printf("�迭�� �� : %d \n", sum);

	int avg = calAvg(intArray, input);
	printf("�迭�� ��� : %d \n", avg);


	int min = findMin(input,1000);
	printf("�迭�� �ּڰ� : %d \n", min);


	int max = findMax(input,0);
	printf("�迭�� �ִ� : %d \n", max);


	return 0;
}
