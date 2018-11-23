#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int makeArray(int *intArray, int inputSize); // �迭�� 0~999���� ������ ���� �����ϴ� �Լ� ����
void swap(int *x, int *y); // �ڸ����� �ٲپ��ִ� �Լ� ����
void sortArray(int *intArray, int inputSize); // ���� �迭�� ���������ϴ� �Լ� ���� 

int makeArray(int *intArray, int inputSize) { // �迭�� 0~999���� ������ ���� ����

	int i;

	srand((unsigned int)time((time_t*)NULL)); // ���� �߻�

	printf("�迭�� ������ �����մϴ�. \n");

	for (i = 0; i < inputSize; i++) {
		intArray[i] = rand() % 1000; // 0~999���� ���� ����
	}

	return 0;
}

void swap(int *x, int *y) { // �ڸ����� �ٲپ��ִ� �Լ� 

	int temp = *x;  // temp ��� ���ǰ��� �����Ͽ� x,y�� ��ġ�� ��ȭ
	*x = *y;
	*y = temp;

	return ;
}


void sortArray(int *intArray, int inputSize) {
	int i, j;
	int *min; // �迭�� ����� �������� ���� ���� ������ �ּҰ�
	for (i = 0; i < inputSize; i++)
	{
		min = intArray + i; 
		for (j = i; j < inputSize; j++)
			if (*min > *(intArray + j)) // ���� ���� ������ �� ��
				min = intArray + j; 
				swap(min, intArray + i); // ���� ���� ������ ���� ���� i��° �迭���� �ٲ۴�.
	}
	printf("������������ �����մϴ�.\n");
	return;
}



int main() {

	int intArray[20];
	int input = 0;
	printf("���° ������ �������? : ");  // �迭�� ���� ����
	scanf("%d", &input); 

	makeArray(intArray, input); // �迭�� ���� �� ����

	for (int i = 0; i < input; i++) {
		printf("%d  ", intArray[i]);  // �迭 ���
	}

	printf("\n");



	sortArray(intArray, input);  // �迭 ���� ���� ����

	for (int i = 0; i < input; i++) { // ���� ������ �� �迭 ���
		printf("%d  ", intArray[i]);
	}

	printf("\n");
	return 0;
}