#include <stdio.h>
#include <string.h>

int dup_check(char **sp, char *temp, int cnt); // 문자열 중복검사 함수

int main(void) {
	char temp[50]; // 배열 생성
	char *res[100]; // 포인터 배열 생성

	int size = 0, i = 0; // 변수 선언 및 초기화

	while (1) {
		printf("> 단어 입력 : ");
		fgets(temp, sizeof(temp), stdin); // temp에 문자열 저장
		temp[strlen(temp) - 1] = '\0'; // temp 문자열 끝에 NULL 문자 저장
		if (strcmp(temp, "end") == 0)
			break; // 종료조건
		else if (dup_check(res, temp, size) == 1) { // 중복 단어 판별
			printf("> 이미 존재하는 단어 입니다. \n");
		}
		else if (size > 0 && res[size - 1][strlen(res[size - 1]) - 1] != temp[0]) { // 단어 비교 후 끝말잇기가 안되는 경우 판별
			printf("> 단어 잇기가 불가능합니다.  \n");
		}
		else
		{
			res[size] = (char*)calloc(strlen(temp) + 1, sizeof(char)); // res[size] 동적할당 실행
			if (res[size] == NULL) { // 할당오류 예외처리
				printf("메모리 부족 \n");
				break;
			}
			strcpy(res[size++], temp); // res[size]에 temp 문자열 복사 
		}
	}

	for (i = 0; i < size; i++) {
		printf("%s ", res[i]); // 출력
	}

	for (i = 0; i < size; i++) {
		free(res[i]); // 동적 할당 해제
	}

	printf("\n");

	return 0;
}

int dup_check(char **sp, char *temp, int cnt) {
	int i;
	for (i = 0; i < cnt; i++) {
		if (strcmp(sp[i], temp) == 0) // temp와 sp[i] 비교 후 같으면 1 값 반환
			return 1;
	}
	return 0;
}