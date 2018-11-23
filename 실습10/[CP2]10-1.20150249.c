#include <stdio.h>

int count_num(int (*ary1)[4], int (*ary2)[4], int (*same_num)[2]); // 입력받은 배열에서의 일치하는 번호 확인 함수 정의 

int main(int argc, const char *argv[]) {

	int ary1[3][4] = { // int형 2차원 배열 ary1 생성 및 정의
	   {15, 3, 9, 11},
	   {23, 7, 10, 12},
	   {0, 17, 55, 35}
	};

	int ary2[3][4] = { // int형 2차원 배열 ary2 생성 및 정의
		{13, 8, 9, 15},
		{23, 0, 10, 11},
		{29, 17, 43, 3}
	};

	int same_num[12][2]; // int형 2차원 배열 same_num 생성
	int cnt;
	cnt = count_num(ary1, ary2, same_num); // count_num 함수 실행
	printf("일치하는 번호의 수 : %d\n", cnt); // 일치하는 번호의 수 출력
	printf("배열에서의 위치(행,열)...\n");

	for (int i = 0; i < cnt; i++) { // 배열에서의 위치 출력
		printf("(%d, %d) \n", same_num[i][0], same_num[i][1]);
	}


	return 0;
}

int count_num(int(*ary1)[4], int(*ary2)[4], int(*same_num)[2]) { // 입력받은 배열에서의 일치하는 번호 확인 함수
	int same = 0;
	for (int i = 0; i < 3; i++) // 배열 탐색
		for (int j = 0; j < 4; j++) {
			if (ary1[i][j] == ary2[i][j]) {
				same_num[same][0] = i;
				same_num[same][1] = j;
				same++;
			}
		}
	return same; // same 반환
}