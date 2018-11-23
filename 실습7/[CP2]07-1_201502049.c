#include <stdio.h>

void inputScore(int *scoreArray, int inputIndex); // �����Է� �Լ� ����
void printScore(int *scoreArray, int index, int inputIndex); // �Է��� ������ ����ϴ� �Լ� ����
void printSum(int *scoreArray, int inputIndex); // �Է��� �� ������ ������ ���ϰ� ����ϴ� �Լ� ����
void printAvg(int *scoreArray, int inputIndex); // �Է��� �� ������ ����� ���ϰ� ����ϴ� �Լ� ����

void inputScore(int *scoreArray, int inputIndex) { // �����Է� �Լ�
	printf("���� ���� �Է� : ");
	scanf_s("%d", &scoreArray[0]);
	printf("���� ���� �Է� : ");
	scanf_s("%d", &scoreArray[1]);
	printf("���� ���� �Է� : ");
	scanf_s("%d", &scoreArray[2]);
}

void printScore(int *scoreArray, int index, int inputIndex) { // �Է��� ������ ����ϴ� �Լ�
	printf("[%d] %d,%d,%d\n", index, scoreArray[0], scoreArray[1], scoreArray[2]);
}

void printSum(int *scoreArray, int inputIndex) { // �Է��� �� ������ ������ ���ϰ� ����ϴ� �Լ�
	int sum = 0;
	sum = scoreArray[0] + scoreArray[1] + scoreArray[2];
	printf("������ %d �Դϴ�.\n", sum);
}

void printAvg(int *scoreArray, int inputIndex) { // �Է��� �� ������ ����� ���ϰ� ����ϴ� �Լ�
	int sum = 0;
	int avg = 0;
	sum = scoreArray[0] + scoreArray[1] + scoreArray[2];
	avg = sum / 3;
	printf("����� %d �Դϴ�.\n", avg);
}


int main() {

	int scoreArray[20][3]; // �迭 ����
	int inputStudentSize; // �Է¹��� �л��� ��
	int studentIndex; // �� �л��� ��ȣ(�� ���� ��ȣ)

	printf("�Է� ���� �л����� �Է��ϼ��� : ");
	scanf_s("%d", &inputStudentSize);

	for (studentIndex = 0; studentIndex < inputStudentSize; studentIndex++) // �� �м��� ���� �Է�
		inputScore((int*)&(scoreArray[studentIndex]), inputStudentSize);

	for (studentIndex = 0; studentIndex < inputStudentSize; studentIndex++) // �� �л��� ���� ���
		printScore((int*)&(scoreArray[studentIndex]), studentIndex, inputStudentSize);

	for (studentIndex = 0; studentIndex < inputStudentSize; studentIndex++) // �� �л��� ���� ���� ���
		printSum((int*)&(scoreArray[studentIndex]), inputStudentSize);

	for (studentIndex = 0; studentIndex < inputStudentSize; studentIndex++) // �� �л��� ���� ��� ���
		printAvg((int*)&(scoreArray[studentIndex]), inputStudentSize);

	return 0;
}