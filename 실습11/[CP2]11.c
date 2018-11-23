#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cracker { // craker 구조체 생성
	int price; // 구조체 멤버 선언
	int calories; 
};

int main(void) {

	//실습1
	char temp[32]; // 배열 생성
	char *ps, *pt; // 포인터 생성
	int len = 1; 
	ps = (char*)calloc(1, 1); // calloc을 통해 크기 1, 개수 1인 동적할당 영역 생성후 ps 포인터에 저장
	while (1) {
		printf("메모입력 : ");
		fgets(temp, sizeof(temp), stdin); // temp에 문자열 저장
		temp[strlen(temp) - 1] = '\0'; // temp 문자열 끝에 NULL 문자 저장
		if (strcmp(temp, "end") == 0) break; // 종료조건
		len += strlen(temp) + 1; // temp의 길이+1 만큼 len 증가 
		pt = (char*)realloc(ps, len); // relloc을 통해 ps를 len 만큼으 ㅣ길이로 재할당후 pt 포인터에 저장
		if (pt == NULL) { // 메모리 할당 오류 처리 
			printf("메모리 부족....\n");
			break;
		}
		ps = pt; // pt값 ps에 저장
		strcat(ps, temp); // ps 문자열에 temp를 붙힘
		strcat(ps, " "); // ps 문자열에 공백을 붙힘
	}
	printf("%s\n", ps); // 출력
	free(ps); // 할당 해제

	//실습2
	struct cracker basasak; // craker 형 구조체 basasak 생성
	printf("바사삭 가격과 열량 입력 : "); 
	scanf("%d %d", &basasak.price, &basasak.calories); // 입력 받은 값을 basasak 구조체 멤버에 저장
	printf("price : %dwon\n", basasak.price); // basasak의 price 출력
	printf("calories : %dkcal\n", basasak.calories); //basasak의 calories 출력

	return 0;
}