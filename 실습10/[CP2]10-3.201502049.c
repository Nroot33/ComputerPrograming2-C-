#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int input_intro(char(*intro)[80]);
void init_intro(char(*intro)[80], char **intp);
void sort_intro(char **intp, int cnt);
void print_intro(int mode, void *vp, int cnt);

int main(void) {

	char intro[10][80];
	char *intp[10];
	int cnt;

	init_intro(intro, intp);
	cnt = input_intro(intro);
	sort_intro(intp, cnt);
	print_intro(1, intp, cnt);
	print_intro(0, intro, cnt);

	return 0;
}




int input_intro(char(*intro)[80]) { // 문장을 입력받는 함수
	int index = 0;
	while (1) {
		printf("> 문장 입력 : ");
		scanf("%s", intro[index]);
		fflush(stdin);
		if (strcmp(intro[index], "end") == 0) // end가 입력되면 입력 종료
			break;
		index++;

	}
	return index - 1;
}

void init_intro(char(*intro)[80], char ** intp) { // 전달 받은 intro를 intp로 복사하는 함수
	for (int i = 0; i < 10; i++)
		intp[i] = intro[i]; // intro[i]가 저장한 주소값을 intp[i]에 저장
}

void sort_intro(char ** intp, int cnt) { // 사전순으로 정렬하는 함수

	char** temp;

	for (int i = 0; i < cnt - 1; i++)  // 반복문을 통한 탐색
		for (int j = i; j < cnt; j++) {
			if (strcmp(intp[i], intp[j]) == 1) { // intp[i]와 intp[j]가 같은 문자열일 때,
				temp = intp[i];
				intp[i] = intp[j];
				intp[j] = temp; // 사전식 정렬 실행
			}
		}
}

void print_intro(int mode, void * vp, int cnt) { // 배열을 출력하는 메소드
	if (mode == 1) { // mode가 1일 때
		char **res = (char **)vp; // vp를 char형 이중 포인터로 형변환 후 char형 이중 포인터 res저장
		printf("----사전순으로 출력----\n");
		for (int i = 0; i <= cnt; i++) // 반복문을 통한 배열 출력
			printf("%s\n",res[i]);
	}

	if (mode == 0) { // mode가 0일 때
		char(*res)[80] = (char **)vp; // vp를 char형 이중 포인터로 형변환 후 char형 포인터 배열 res에 저장
		printf("----입력순으로 출력----\n");

		for (int i = 0; i <= cnt; i++) // 반복문을 통한 배열 출력
			printf("%s\n", res[i]);
	}
}
