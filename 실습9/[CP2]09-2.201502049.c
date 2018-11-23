#include <stdio.h>

int disp_menu(void); // 메뉴 출력 함수
void enter_park(int(*park_space)[2][5], int(*reserved)[3]); // 주차 함수
void exit_park(int(*park_space)[2][5]); // 츨차 함수
void reserve_park(int(*reserved)[3]); // 지정차량 등록 함수
void print_park(int(*park_space)[2][5], int(*reserved)[3]); // 주차 현황 출력 함수
void print_basement(int(*park_space)[5], int floor, int(*reserved)[3]); // 주차 현황 확인 출력 함수
int check_reservation(int(*reserved)[3], int basement, int num);  // 지정차량 주차공간 확인 함수
int check_reserved_num(int(*reserved)[3], int car_num, int *floor, int *resv_num); // 지정차량 확인 함수
int find_space(int(*park_space)[5], int floor, int(*reserved)[3]); // 빈 공간 확인 함수

int main(void) {

	disp_menu(); // 메뉴 실행

	return 0;
}

int disp_menu(void) { // 메뉴 출력 및 반환 

	int n;
	int park_space[3][2][5]; // 주차 공간 int 형 3차원 배열 생성 및 초기화

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 5; k++)
				park_space[i][j][k] = 0;


	int reserved[10][3]; // 지정 차량 등록 int형 3차원 배열 생성 및 초기화

	for (int j = 0; j < 10; j++)
		for (int k = 0; k < 3; k++)
			reserved[j][k] = 0;

	// 메뉴 생성 후 if 문을 통한 메뉴 실행
	printf("1. 주차 \n");
	printf("2. 출차 \n");
	printf("3. 지정차량 등록 \n");
	printf("4. 주차현황 출력 \n");
	printf("0. 종료 \n");
	printf("> 번호 선택 : ");
	scanf("%d", &n);

	if (n == 1)
		enter_park(park_space, reserved);
	else if (n == 2)
		exit_park(park_space);
	else if (n == 3)
		reserve_park(reserved);
	else if (n == 4)
		print_park(park_space, reserved);
	else if (n == 0)
		return 1;
	else {
		printf("유효한 메뉴가 아닙니다.\n");
		disp_menu();
	}
}

void enter_park(int(*park_space)[2][5], int(*reserved)[3]) { // 주차 함수
	int car_num, resv_floor, resv_num;
	int floor = 0, num, floor_num = 1;


	while (1) {
		printf("> 차번 입력(숫자 4자리) : ");
		scanf("%d", &car_num);
		if (car_num > 999 && car_num < 10000)
			break;
		else {
			printf("올바르지 않은 차량번호 입니다. \n");
			continue;
		}
	}

	if (check_reserved_num(reserved, car_num, &resv_floor, &resv_num)) { // 지정차량번호 확인 후 주차 
		park_space[resv_floor][resv_num / 5][resv_num % 5] = car_num;
		printf("지정차량 주차");
	}

	else {
		printf("@ 주차 가능 공간 : 1층[%d대] , 2층[%d대], 3층[%d대] \n", find_space(park_space, 0, reserved), find_space(park_space, 1, reserved), find_space(park_space, 2, reserved));

		print_basement(park_space, floor, reserved); // 주차장 1층 출력

		while (1) {
			printf("\n> 주차 번호 입력(다른층 0, 취소 -1) : ");
			scanf("%d", &num);
			if (num == -1) // 종료
				disp_menu();
			else if (num == 0) { // 층 이동 
				if (floor == 2)
					floor_num = -1;
				else if (floor == 0)
					floor_num = 1;
				print_basement(park_space, floor = floor + floor_num, reserved);
				printf("\n");
			}
			else if (num > 0 && num < 11) { // 주차 
				if (park_space[floor][(num - 1) / 5][(num - 1) % 5] != 0) // 주차 공간 확인
					printf("빈 공간이 아닙니다.");
				else
				{
					park_space[floor][(num - 1) / 5][(num - 1) % 5] = car_num;
					printf("@ 주차 완료 \n");
					disp_menu();
				}
			}
			else
				printf("올바른 번호가 아닙니다."); //예외 처리
		}
	}
}

void exit_park(int(*park_space)[2][5]) { // 출차 함수

	int car_num;

	printf("\n> 차번 입력(숫자 4자리) : ");
	scanf("%d", &car_num);

	// 반복문을 통한 배열 탐색
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 5; k++)
				if (car_num == park_space[i][j][k]) {
					park_space[i][j][k] = 0; // 주차 공간 초기화
					printf("@ 출차 완료\n");
					return; // 함수 종료
				}
	printf("@ 해당 차량이 없습니다.\n"); // 예외 조건
}
void reserve_park(int(*reserved)[3]) { // 지정차량 등록 메소드
	while (1) { // while문 무한반복
		int floorNum, n, carNum; // int형 변수 floorNum, n, carNum 생성

		printf("\n> 층과 번호 입력(종료 0) : "); // 문자열 출력
		scanf("%d", &floorNum); // 입력받은 정수값을 floorNum에 저장

		if (floorNum == 0) // floorNum이 0일 때,
			disp_menu(); // while문 탈출

		scanf("%d", &n); // 입력받은 정수값을 n에 저장
		printf("> 등록차량 번호 입력 : "); // 문자열 출력
		scanf("%d", &carNum); // 입력받은 정수값을 carNum에 저장
		reserved[n - 1][floorNum - 1] = carNum; // reserved[n - 1][floorNum - 1]에 carNum 저장
		printf("@ 등록되었습니다.\n\n"); // 문자열 출력
	}
}

void print_park(int(*park_space)[2][5], int(*reserved)[3]) { // 주차 현황 출력 메소드

	print_basement(park_space, 0, reserved); // 1층의 현황 출력
	printf("\n");
	print_basement(park_space, 1, reserved); // 2층의 현황 출력
	printf("\n");
	print_basement(park_space, 2, reserved); // 3층의 현황 출력
	printf("\n");
	disp_menu();
}

void print_basement(int(*park_space)[5], int floor, int(*reserved)[3]) { // 주차 현황 확인 출력 함수

	printf("\n[%d층]============================\n", floor + 1); // 층 출력
	for (int i = 0; i < 2; i++) { // 반복문을 통한 현황 탐색
		for (int j = 0; j < 5; j++) {
			if (park_space[floor * 2 + i][j] == 0) {
				if (check_reservation(reserved, floor, i * 5 + j)) // 지정차량 주차 공간 확인
					printf("[resv]");
				else
					printf("[%3d]", i * 5 + j + 1);
			}
			else
				printf("[%4d]", park_space[floor * 2 + i][j]); // 해당 위치 주차 차량번호 출력
		}
		printf("\n");
	}
}

int check_reservation(int(*reserved)[3], int basement, int num) { // 지정차량 공간 확인 함수
	return !(reserved[num][basement] == 0);
}

int check_reserved_num(int(*reserved)[3], int car_num, int *floor, int *resv_num) { // 지정차량 확인 함수
	for (int i = 0; i < 10; i++) // 반복문을 통한 지정 차량 등록 배열 탐색
		for (int j = 0; j < 3; j++) {
			if (reserved[i][j] == car_num) { // 지정 차량 번호 확인
				*resv_num = i; // 값 저장
				*floor = j;
				return 1;
			}
		}
	return 0;
}

int find_space(int(*park_space)[5], int floor, int(*reserved)[3]) { //빈 주차 공간 찾기 함수

	int count_floor = 0; // 층별 빈 주차 공간 확인 변수 선언 및 초기화 

	for (int j = 0; j < 2; j++) // 반복문을 통한 빈 공간 계산 
		for (int k = 0; k < 5; k++) {
			if ((*(park_space + floor * 2 + j))[k] == 0 && reserved[j * 5 + k][floor] == 0)
				++count_floor;
		}

	return count_floor; // 변수 반환
}
