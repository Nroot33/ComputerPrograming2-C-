#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Rand 함수 헤더파일
#include <windows.h> // Clear 사용 헤더파일
#include <time.h> // Srand 헤더파일
#include <conio.h> // getch 헤더파일

// *************************** 컬러 사용하기 Define 값 *************************** //

#define colorHandle GetStdHandle(STD_OUTPUT_HANDLE) // 콘솔창의 핸들정보 받기
#define BLACK SetConsoleTextAttribute(colorHandle,0x0000); // 검정색
#define GRAY SetConsoleTextAttribute(colorHandle,0x0007); // 밝은 회색
#define RED SetConsoleTextAttribute(colorHandle,0x000c); // 빨간색
#define BLUE SetConsoleTextAttribute(colorHandle,0x0001 | 0x0008); // 파란색
#define WHITE SetConsoleTextAttribute(colorHandle,0x000f); // 하얀색
#define YEL SetConsoleTextAttribute(colorHandle,0x000e); // 노란색
#define GREEN SetConsoleTextAttribute(colorHandle,0x0002); // 녹색
#define VIO SetConsoleTextAttribute(colorHandle,0x0001 | 0x0008 |0x000c); // 보라색

// *************************** 커서 숨기기 매크로 *************************** //
enum { HIDDEN, SHOW };

// *************************** 미로함수 방향키 아스키코드값 *************************** //
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define Enter 13 
#define ESC 27

// *************************** System 함수 *************************** //
void gotoxy(int, int); // 이동함수
void delay(clock_t wait); // 함수시간 대기 함수
void color(unsigned short color);// 랜덤 컬러 지정 함수
void viewCursor(char show); // 커서 숨기기 함수

							// *************************** 미로탈출게임 함수 *************************** //
void miro(); // 미로게임 메인함수
int miroGame();

int main() {
	miro();
	return 0;
}

void miro() {
	int n;
	n = miroGame();
}

void gotoxy(int x, int y) { // 이동함수
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void color(unsigned short color) {// 랜덤 컬러 지정 함수
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, color);
}

void viewCursor(char show) { // 커서 숨기기 함수
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}



void delay(clock_t wait) { // 대기 함수
	clock_t goal;
	goal = wait + clock();
	while (goal>clock());
}



int miroGame() {
	struct MIRO { // 구조체 MIRO 선언
		int x, y; // int형 멤버 x, y 좌표 
		int PlayN; 
	};
	struct MIRO Me, Mon[20], Pre[10]; // MIRO 구조체 Me, Mon[20], Pre[10] 생성
	static int Stage = 1, PreNum; // stage : 스테이지, PreNum 생성
	static int i, j, k = 0, T = 0, b, c[20][2] = { 0 }, d[30] = { 0 }; // i, j, k = 0, T = 0, b, c[20][2], d[30] 생성
	static int Screen[18][28] = { 0 }; // 18 * 28 크기의 int형 이차원 배열 Screen 생성
	int randNum[2] = { 0 }; // int형 배열 ranNum[2] 생성 후 초기화
	char ch; // char형 변수 생성
	int Life = 3, LifeN, GameOver = 0; // Life : 생명, LifeN, GameOver 생성

	srand(time(NULL)); // 시간으로 랜덤값 설정

	system("mode con lines=20 cols=58"); // 창 크기 출력
	system("cls"); // 화면 초기화
	viewCursor(HIDDEN); // 커서 숨기기
	system("cls"); // 화면 초기화

	while (1) { // 게임 초기화
		randNum[0] = 0; 
		randNum[1] = 0; 

		gotoxy(22, 9); // 커서를 화면 중앙 이동
		printf("S t a g e %d", Stage); // Stage 출력
		Sleep(3000); 
		system("cls"); // 화면 초기화

		b = rand() % 14 + 2; // b는 2 ~ 15 사이 랜덤 수 저장

		for (i = 0; i < Stage * 2; i++) {
			c[i][0] = rand() % 14 + 2; // c[i][0]에 2 ~ 15 사이의 랜덤 수 저장
			c[i][1] = rand() % 22 + 3; // c[i][1]에 3 ~ 24 사이의 랜덤 수 저장

		}
		for (i = 0; i < 35; i++) {
			d[i] = rand() % 26 + 1; // d[i]에 1 ~ 26 사이의 랜덤한 수 저장
		}

		Me.x = 7; // 플레이어 x축 변수에 7 저장
		Me.y = 1; // 플레이어 y축 변수에 1 저장
		Me.PlayN = 1; // 플레이어 PlayN에 1 저장

		for (i = 0; i < Stage * 2; i++) { // 몬스터 stage * 2 만큼 생성
			Mon[i].x = c[i][0];
			Mon[i].y = c[i][1];
			Mon[i].PlayN = 10;
		}

		for (i = 0; i < Stage; i++) { // 아이템 stage 만큼 생성
			Pre[i].x = c[i][0];
			Pre[i].y = c[i][1] + 1;
			Pre[i].PlayN = 7;
		}

		for (i = 0; i < 18; i++) { // Screen 배열을 0으로 초기화 함
			for (j = 0; j < 28; j++) {
				Screen[i][j] = 0;
			}
		}

		k = 0; 

		for (i = 0; i < 18; i++) { // 벽 생성
			for (j = 0; j < 28; j++) {
				if (i == 0 || i == 17)
					Screen[i][j] = 9;
				else if (j == 0 || j == 27)
					Screen[i][j] = 9;
			}
		}
		for (i = 1; i < 18; i++) { //  랜덤하게 안쪽 벽 생성
			for (j = 0; j < 28; j++) {
				if (d[k] == j) {
					Screen[i][j] = 9;
					k++;
				}
			}
		}
		Screen[b][26] = 0; // b를 이용해 랜덤하게 생성된 탈출 장소 앞 길
		Screen[b][27] = 0; // b를 이용해 랜덤하게 생성된 탈출 장소
		Screen[7][1] = 1; // 초기화, 플레이어 시작 위치
		Screen[6][1] = 0; // 플레이어 시작 위치 위쪽

		for (i = 0; i < Stage * 2; i++) { // 몬스터 배치
			Screen[Mon[i].x][Mon[i].y] = Mon[0].PlayN;
		}
		for (i = 0; i < Stage; i++) { // 아이템 배치
			Screen[Pre[i].x][Pre[i].y] = Pre[0].PlayN;
		}

		while (1) { // 게임 실행
			PreNum = 0; // PreNum 0으로 초기화

			for (i = 0; i < Stage * 2; i++) { // 몬스터 이동
				randNum[0] = rand() % 15; // 0 ~ 14 사이의 랜덤값 저장
				if (randNum[0] == 0) { // randNum이 0일 때 몬스터 이동
					randNum[1] = rand() % 4; // 0 ~ 3 사이의 랜덤값 저장
					switch (randNum[1]) { // randNum[1] 값에 따라 이동
					case 0: // 왼쪽
						if (Screen[Mon[i].x][Mon[i].y - 1] != 9 && Screen[Mon[i].x][Mon[i].y - 1] != Mon[i].PlayN && Screen[Mon[i].x][Mon[i].y - 1] != Pre[0].PlayN) { 
							Screen[Mon[i].x][Mon[i].y] = 0; 
							Mon[i].y -= 1; // 왼쪽 이동
							if (Screen[Mon[i].x][Mon[i].y] == Me.PlayN) 
								Me.PlayN = 99; // 99 저장
						}
						Screen[Mon[i].x][Mon[i].y] = Mon[0].PlayN; // 현재 위치에 몬스터 위치
						break; 
					case 1: // 오른쪽
						if (Screen[Mon[i].x][Mon[i].y + 1] != 9 && Screen[Mon[i].x][Mon[i].y + 1] != Mon[i].PlayN && Screen[Mon[i].x][Mon[i].y + 1] != Pre[0].PlayN) { 
							Screen[Mon[i].x][Mon[i].y] = 0; 
							Mon[i].y += 1; // 오른쪽 이동
							if (Screen[Mon[i].x][Mon[i].y] == Me.PlayN) 
								Me.PlayN = 99; //  99 저장
						}
						Screen[Mon[i].x][Mon[i].y] = Mon[0].PlayN; // 현재 위치에 몬스터 위치
						break; 

					case 2: // 위쪽
						if (Screen[Mon[i].x - 1][Mon[i].y] != 9 && Screen[Mon[i].x - 1][Mon[i].y] != Mon[i].PlayN && Screen[Mon[i].x - 1][Mon[i].y] != Pre[0].PlayN) { 
							Screen[Mon[i].x][Mon[i].y] = 0; 
							Mon[i].x -= 1; // 위쪽 이동
							if (Screen[Mon[i].x][Mon[i].y] == Me.PlayN) 
								Me.PlayN = 99; //  99 저장
						}
						Screen[Mon[i].x][Mon[i].y] = Mon[0].PlayN; // 현재 위치에 몬스터 배치
						break; 
					case 3: // 아래쪽
						if (Screen[Mon[i].x + 1][Mon[i].y] != 9 && Screen[Mon[i].x + 1][Mon[i].y] != Mon[i].PlayN && Screen[Mon[i].x + 1][Mon[i].y] != Pre[0].PlayN) { 
							Screen[Mon[i].x][Mon[i].y] = 0; 
							Mon[i].x += 1; // 아래쪽 이동
							if (Screen[Mon[i].x][Mon[i].y] == Me.PlayN) 
								Me.PlayN = 99; // 99 저장
						}
						Screen[Mon[i].x][Mon[i].y] = Mon[0].PlayN; // 현재 위치에 몬스터 배치
						break; 
					}
				}
			}

			for (i = 0; i < 18; i++) { // 출력
				gotoxy(1, i + 1); // 커서를 (1, i + 1)로 이동
				for (j = 0; j < 28; j++) {
					if (Screen[i][j] == 0) { // 빈 공간 
						BLACK; // 검정
						printf("★"); // 별
					}
					else if (Screen[i][j] == Me.PlayN) { // 플레이어 
						RED; // 빨강
						printf("☆"); // 빈 별
					}
					else if (Screen[i][j] == 9) { // 벽 출력
						WHITE; // 하양
						printf("■"); // 네모
					}
					else if (Screen[i][j] == Mon[0].PlayN) { // 몬스터 
						VIO; // 보라
						printf("◆"); // 마름모
					}
					else if (Screen[i][j] == Pre[0].PlayN) { // 하트
						YEL; // 노랑
						printf("♡"); // 빈 하트
					}
				}
				printf("\n"); /
			}

			if (kbhit()) { 
				ch = getch(); //  입력받은 값을 ch에 저장
				switch (ch) { // 입력받은 값에 따라 이동
				case 75: // 왼쪽
						
					if (Screen[Me.x][Me.y - 1] != 9) { // 왼쪽에 벽이 없을 경우,
						Screen[Me.x][Me.y] = 0; 
						Me.y -= 1; // 왼쪽으로 이동
					}
					if (Screen[Me.x][Me.y] == Mon->PlayN) { // 몬스터를 만났을 때 조건
						Me.PlayN = 99; 
					}
					Screen[Me.x][Me.y] = Me.PlayN; // 현재 위치에 플레이어 배치
					break;
				case 77: // 오른쪽
						 
					if (Screen[Me.x][Me.y + 1] != 9) { // 오른쪽에 벽이 없을 경우,
						Screen[Me.x][Me.y] = 0; 
						Me.y += 1; // 오른쪽으로 이동
					}
					if (Screen[Me.x][Me.y] == Mon->PlayN) { // 몬스터를 만났을 때 조건
						Me.PlayN = 99; 
					}
					Screen[Me.x][Me.y] = Me.PlayN; // 현재 위치에 플레이어 배치
					break;
				case 72: // 위쪽
						 
					if (Screen[Me.x - 1][Me.y] != 9) { // 위쪽에 벽이 없을 경우,
						Screen[Me.x][Me.y] = 0; 
						Me.x -= 1; // 위쪽으로 이동
					}
					if (Screen[Me.x][Me.y] == Mon->PlayN) { // 몬스터를 만났을 때 조건
						Me.PlayN = 99; 
					}
					Screen[Me.x][Me.y] = Me.PlayN; //  현재 위치에 플레이어 배치
					break;
				case 80: // 아래쪽
						
					if (Screen[Me.x + 1][Me.y] != 9) { // 아래쪽에 벽이 없을 경우,
						Screen[Me.x][Me.y] = 0; 
						Me.x += 1; // 아래쪽으로 이동
					}
					if (Screen[Me.x][Me.y] == Mon[0].PlayN) { // 몬스터를 만났을 때 조건
						Me.PlayN = 99; 
					}
					Screen[Me.x][Me.y] = Me.PlayN; // 현재 위치에 플레이어 배치
					break;
				case ESC: break; // ESC 입력시 종료
				}
			}

			if (ch == ESC) break; // 입력 받았던 ch가 ESC일 때,  종료

			LifeN = Life; 
			if (Me.PlayN == 99) { // 플레이어와 몬스터가 만난 조건
				Life -= 1; // Life  감소
				break; 
			}
			for (i = 0; i < 18; i++) { // 하트 확인
				for (j = 0; j < 28; j++) {
					if (Screen[i][j] == Pre[0].PlayN) {
						PreNum++;
					}
				}
			}
			if (PreNum == 0) { // 하트을 전부 획득 및 탈출시 게임 종료
				if (Me.y == 27)break; 
			}
		}
	}
}
