#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student { // Student ����ü 
	int id; // �й� ����
	char name[20]; // �̸� ���� char�� �迭 ����
	int kor; // �������� ����
	int eng; // �������� ����
	int math; // �������� ����
	int sum; // ���� ����
	double avg; // ��� ����
	char grade; // ���� ����
}Student;

void input_data(Student *pary, int inputSize); // �л� ������ �Է¹޴� �Լ�
void calc_data(Student *pary, int inputSize); // �л��� ����, ���, ���� ����ϴ� �Լ�
void sort_data(Student *pary, int inputSize); // �л��� ������ ���� �Լ�
void print_data(Student *pary, int inputSize); // �л� ������ ��� �Լ�

int main(void) {
	
	int inputSize = 0; // �л��� ���� ����
	Student std[100]; // Student�� �迭 ����
	printf("> �л� �� �Է� : "); 
	scanf("%d", &inputSize);  // �л��� �Է�
	input_data(std, inputSize); // ���� �Է�
	calc_data(std, inputSize);  // ����, ���, ���� ���
	printf("======== ���� �� ������ ======== \n");
	print_data(std, inputSize); //������ ���
	sort_data(std, inputSize); //������ ����
	printf("\n");
	printf("======== ���� �� ������ ======== \n");
	print_data(std, inputSize);//������ ���

	return 0;
}

void input_data(Student * pary, int inputSize) { // �л� ������ �Է¹޴� �Լ�
	int i = 0; 
	for (i = 0; i < inputSize; i++) { //�ݺ����� ���� �л� ���� �Է�
		printf("> �й� : "); 
		scanf("%d", &pary[i].id); 
		printf("> �̸� : "); 
		scanf("%s", &pary[i].name); 
		printf("> ����, ����, ���� ���� : "); 
		scanf("%d %d %d", &pary[i].kor, &pary[i].eng, &pary[i].math); 
	}
}

void calc_data(Student * pary, int inputSize) { // �л��� ����, ���, ���� ����ϴ� �Լ�
	int i = 0; 
	for (i = 0; i < inputSize; i++) { // �ݺ����� ���� ����, ���, ���� ��� �� ����
		pary[i].sum = pary[i].kor + pary[i].eng + pary[i].math; // ���� ��� �� ����
		pary[i].avg = (double)(pary[i].sum) / 3; // ��� ��� �� ����
		if (pary[i].avg >= 90)  // ��տ� ���� ���� ���
			pary[i].grade = 'A'; 
		else if (pary[i].avg >= 80) 
			pary[i].grade = 'B'; 
		else if (pary[i].avg >= 70) 
			pary[i].grade = 'C'; 
		else 
			pary[i].grade = 'F'; 
	}
}

void sort_data(Student * pary, int inputSize) { // �л��� ������ ���� �Լ�
	Student temp; 
	int i = 0, j = 0; 
	for (i = 0; i < inputSize - 1; i++) { // �ݺ����� ���� �������� ����
		for (j = i + 1; j < inputSize; j++) { 
			if (pary[i].sum < pary[j].sum) {  
				temp = pary[i]; 
				pary[i] = pary[j];
				pary[j] = temp;
			}
		}
	}
}

void print_data(Student * pary, int inputSize) { // �л� ������ ��� �Լ�
	int i = 0; 
	for (i = 0; i < inputSize; i++) { // �ݺ����� ���� �л��� ������ ���
		printf("%d %s %d %d %d %d %.1lf %c\n", pary[i].id, pary[i].name, pary[i].kor, pary[i].eng, pary[i].math, pary[i].sum, pary[i].avg, pary[i].grade); 
	}
}
