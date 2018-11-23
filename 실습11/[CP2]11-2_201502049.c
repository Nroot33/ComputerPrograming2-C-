#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student { // Student 구조체 
	int id; // 학번 선언
	char name[20]; // 이름 저장 char형 배열 선언
	int kor; // 국어점수 선언
	int eng; // 영어점수 선언
	int math; // 수학점수 선언
	int sum; // 총점 선언
	double avg; // 평균 선언
	char grade; // 학점 선언
}Student;

void input_data(Student *pary, int inputSize); // 학생 정보를 입력받는 함수
void calc_data(Student *pary, int inputSize); // 학생의 총점, 평균, 학점 계산하는 함수
void sort_data(Student *pary, int inputSize); // 학생의 데이터 정렬 함수
void print_data(Student *pary, int inputSize); // 학생 데이터 출력 함수

int main(void) {
	
	int inputSize = 0; // 학생수 변수 선언
	Student std[100]; // Student형 배열 선언
	printf("> 학생 수 입력 : "); 
	scanf("%d", &inputSize);  // 학생수 입력
	input_data(std, inputSize); // 정보 입력
	calc_data(std, inputSize);  // 총점, 평균, 학점 계산
	printf("======== 정렬 전 데이터 ======== \n");
	print_data(std, inputSize); //데이터 출력
	sort_data(std, inputSize); //데이터 정렬
	printf("\n");
	printf("======== 정렬 후 데이터 ======== \n");
	print_data(std, inputSize);//데이터 출력

	return 0;
}

void input_data(Student * pary, int inputSize) { // 학생 정보를 입력받는 함수
	int i = 0; 
	for (i = 0; i < inputSize; i++) { //반복문을 통한 학생 정보 입력
		printf("> 학번 : "); 
		scanf("%d", &pary[i].id); 
		printf("> 이름 : "); 
		scanf("%s", &pary[i].name); 
		printf("> 국어, 영어, 수학 점수 : "); 
		scanf("%d %d %d", &pary[i].kor, &pary[i].eng, &pary[i].math); 
	}
}

void calc_data(Student * pary, int inputSize) { // 학생의 총점, 평균, 학점 계산하는 함수
	int i = 0; 
	for (i = 0; i < inputSize; i++) { // 반복문을 통한 총점, 평균, 학점 계산 후 저장
		pary[i].sum = pary[i].kor + pary[i].eng + pary[i].math; // 총점 계산 후 저장
		pary[i].avg = (double)(pary[i].sum) / 3; // 평균 계산 후 저장
		if (pary[i].avg >= 90)  // 평균에 따른 학점 계산
			pary[i].grade = 'A'; 
		else if (pary[i].avg >= 80) 
			pary[i].grade = 'B'; 
		else if (pary[i].avg >= 70) 
			pary[i].grade = 'C'; 
		else 
			pary[i].grade = 'F'; 
	}
}

void sort_data(Student * pary, int inputSize) { // 학생의 데이터 정렬 함수
	Student temp; 
	int i = 0, j = 0; 
	for (i = 0; i < inputSize - 1; i++) { // 반복문을 통한 오름차순 정렬
		for (j = i + 1; j < inputSize; j++) { 
			if (pary[i].sum < pary[j].sum) {  
				temp = pary[i]; 
				pary[i] = pary[j];
				pary[j] = temp;
			}
		}
	}
}

void print_data(Student * pary, int inputSize) { // 학생 데이터 출력 함수
	int i = 0; 
	for (i = 0; i < inputSize; i++) { // 반복문을 통한 학생의 데이터 출력
		printf("%d %s %d %d %d %d %.1lf %c\n", pary[i].id, pary[i].name, pary[i].kor, pary[i].eng, pary[i].math, pary[i].sum, pary[i].avg, pary[i].grade); 
	}
}
