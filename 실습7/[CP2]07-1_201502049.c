#include <stdio.h>

void inputScore(int *scoreArray, int inputIndex); // 성적입력 함수 선언
void printScore(int *scoreArray, int index, int inputIndex); // 입력한 성적을 출력하는 함수 선언
void printSum(int *scoreArray, int inputIndex); // 입력한 각 성적의 총합을 구하고 출력하는 함수 선언
void printAvg(int *scoreArray, int inputIndex); // 입력한 각 성적의 평균을 구하고 출력하는 함수 선언

void inputScore(int *scoreArray, int inputIndex) { // 성적입력 함수
	printf("국어 성적 입력 : ");
	scanf_s("%d", &scoreArray[0]);
	printf("영어 성적 입력 : ");
	scanf_s("%d", &scoreArray[1]);
	printf("수학 성적 입력 : ");
	scanf_s("%d", &scoreArray[2]);
}

void printScore(int *scoreArray, int index, int inputIndex) { // 입력한 성적을 출력하는 함수
	printf("[%d] %d,%d,%d\n", index, scoreArray[0], scoreArray[1], scoreArray[2]);
}

void printSum(int *scoreArray, int inputIndex) { // 입력한 각 성적의 총합을 구하고 출력하는 함수
	int sum = 0;
	sum = scoreArray[0] + scoreArray[1] + scoreArray[2];
	printf("총점은 %d 입니다.\n", sum);
}

void printAvg(int *scoreArray, int inputIndex) { // 입력한 각 성적의 평균을 구하고 출력하는 함수
	int sum = 0;
	int avg = 0;
	sum = scoreArray[0] + scoreArray[1] + scoreArray[2];
	avg = sum / 3;
	printf("평균은 %d 입니다.\n", avg);
}


int main() {

	int scoreArray[20][3]; // 배열 선언
	int inputStudentSize; // 입력받을 학생의 수
	int studentIndex; // 각 학생의 번호(각 행의 번호)

	printf("입력 받을 학생수를 입력하세요 : ");
	scanf_s("%d", &inputStudentSize);

	for (studentIndex = 0; studentIndex < inputStudentSize; studentIndex++) // 각 학샹의 성적 입력
		inputScore((int*)&(scoreArray[studentIndex]), inputStudentSize);

	for (studentIndex = 0; studentIndex < inputStudentSize; studentIndex++) // 각 학생의 성적 출력
		printScore((int*)&(scoreArray[studentIndex]), studentIndex, inputStudentSize);

	for (studentIndex = 0; studentIndex < inputStudentSize; studentIndex++) // 각 학생의 성적 총합 출력
		printSum((int*)&(scoreArray[studentIndex]), inputStudentSize);

	for (studentIndex = 0; studentIndex < inputStudentSize; studentIndex++) // 각 학생의 성적 평균 출력
		printAvg((int*)&(scoreArray[studentIndex]), inputStudentSize);

	return 0;
}