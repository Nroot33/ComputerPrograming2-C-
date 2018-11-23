#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Rand �Լ� �������
#include <windows.h> // Clear ��� �������
#include <time.h> // Srand �������
#include <conio.h> // getch �������

// *************************** �÷� ����ϱ� Define �� *************************** //

#define colorHandle GetStdHandle(STD_OUTPUT_HANDLE) // �ܼ�â�� �ڵ����� �ޱ�
#define BLACK SetConsoleTextAttribute(colorHandle,0x0000); // ������
#define GRAY SetConsoleTextAttribute(colorHandle,0x0007); // ���� ȸ��
#define RED SetConsoleTextAttribute(colorHandle,0x000c); // ������
#define BLUE SetConsoleTextAttribute(colorHandle,0x0001 | 0x0008); // �Ķ���
#define WHITE SetConsoleTextAttribute(colorHandle,0x000f); // �Ͼ��
#define YEL SetConsoleTextAttribute(colorHandle,0x000e); // �����
#define GREEN SetConsoleTextAttribute(colorHandle,0x0002); // ���
#define VIO SetConsoleTextAttribute(colorHandle,0x0001 | 0x0008 |0x000c); // �����

// *************************** Ŀ�� ����� ��ũ�� *************************** //
enum { HIDDEN, SHOW };

// *************************** �̷��Լ� ����Ű �ƽ�Ű�ڵ尪 *************************** //
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define Enter 13 
#define ESC 27

// *************************** System �Լ� *************************** //
void gotoxy(int, int); // �̵��Լ�
void delay(clock_t wait); // �Լ��ð� ��� �Լ�
void color(unsigned short color);// ���� �÷� ���� �Լ�
void viewCursor(char show); // Ŀ�� ����� �Լ�

							// *************************** �̷�Ż����� �Լ� *************************** //
void miro(); // �̷ΰ��� �����Լ�
int miroGame();

int main() {
	miro();
	return 0;
}

void miro() {
	int n;
	n = miroGame();
}

void gotoxy(int x, int y) { // �̵��Լ�
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void color(unsigned short color) {// ���� �÷� ���� �Լ�
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, color);
}

void viewCursor(char show) { // Ŀ�� ����� �Լ�
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}



void delay(clock_t wait) { // ��� �Լ�
	clock_t goal;
	goal = wait + clock();
	while (goal>clock());
}



int miroGame() {
	struct MIRO { // ����ü MIRO ����
		int x, y; // int�� ��� x, y ��ǥ 
		int PlayN; 
	};
	struct MIRO Me, Mon[20], Pre[10]; // MIRO ����ü Me, Mon[20], Pre[10] ����
	static int Stage = 1, PreNum; // stage : ��������, PreNum ����
	static int i, j, k = 0, T = 0, b, c[20][2] = { 0 }, d[30] = { 0 }; // i, j, k = 0, T = 0, b, c[20][2], d[30] ����
	static int Screen[18][28] = { 0 }; // 18 * 28 ũ���� int�� ������ �迭 Screen ����
	int randNum[2] = { 0 }; // int�� �迭 ranNum[2] ���� �� �ʱ�ȭ
	char ch; // char�� ���� ����
	int Life = 3, LifeN, GameOver = 0; // Life : ����, LifeN, GameOver ����

	srand(time(NULL)); // �ð����� ������ ����

	system("mode con lines=20 cols=58"); // â ũ�� ���
	system("cls"); // ȭ�� �ʱ�ȭ
	viewCursor(HIDDEN); // Ŀ�� �����
	system("cls"); // ȭ�� �ʱ�ȭ

	while (1) { // ���� �ʱ�ȭ
		randNum[0] = 0; 
		randNum[1] = 0; 

		gotoxy(22, 9); // Ŀ���� ȭ�� �߾� �̵�
		printf("S t a g e %d", Stage); // Stage ���
		Sleep(3000); 
		system("cls"); // ȭ�� �ʱ�ȭ

		b = rand() % 14 + 2; // b�� 2 ~ 15 ���� ���� �� ����

		for (i = 0; i < Stage * 2; i++) {
			c[i][0] = rand() % 14 + 2; // c[i][0]�� 2 ~ 15 ������ ���� �� ����
			c[i][1] = rand() % 22 + 3; // c[i][1]�� 3 ~ 24 ������ ���� �� ����

		}
		for (i = 0; i < 35; i++) {
			d[i] = rand() % 26 + 1; // d[i]�� 1 ~ 26 ������ ������ �� ����
		}

		Me.x = 7; // �÷��̾� x�� ������ 7 ����
		Me.y = 1; // �÷��̾� y�� ������ 1 ����
		Me.PlayN = 1; // �÷��̾� PlayN�� 1 ����

		for (i = 0; i < Stage * 2; i++) { // ���� stage * 2 ��ŭ ����
			Mon[i].x = c[i][0];
			Mon[i].y = c[i][1];
			Mon[i].PlayN = 10;
		}

		for (i = 0; i < Stage; i++) { // ������ stage ��ŭ ����
			Pre[i].x = c[i][0];
			Pre[i].y = c[i][1] + 1;
			Pre[i].PlayN = 7;
		}

		for (i = 0; i < 18; i++) { // Screen �迭�� 0���� �ʱ�ȭ ��
			for (j = 0; j < 28; j++) {
				Screen[i][j] = 0;
			}
		}

		k = 0; 

		for (i = 0; i < 18; i++) { // �� ����
			for (j = 0; j < 28; j++) {
				if (i == 0 || i == 17)
					Screen[i][j] = 9;
				else if (j == 0 || j == 27)
					Screen[i][j] = 9;
			}
		}
		for (i = 1; i < 18; i++) { //  �����ϰ� ���� �� ����
			for (j = 0; j < 28; j++) {
				if (d[k] == j) {
					Screen[i][j] = 9;
					k++;
				}
			}
		}
		Screen[b][26] = 0; // b�� �̿��� �����ϰ� ������ Ż�� ��� �� ��
		Screen[b][27] = 0; // b�� �̿��� �����ϰ� ������ Ż�� ���
		Screen[7][1] = 1; // �ʱ�ȭ, �÷��̾� ���� ��ġ
		Screen[6][1] = 0; // �÷��̾� ���� ��ġ ����

		for (i = 0; i < Stage * 2; i++) { // ���� ��ġ
			Screen[Mon[i].x][Mon[i].y] = Mon[0].PlayN;
		}
		for (i = 0; i < Stage; i++) { // ������ ��ġ
			Screen[Pre[i].x][Pre[i].y] = Pre[0].PlayN;
		}

		while (1) { // ���� ����
			PreNum = 0; // PreNum 0���� �ʱ�ȭ

			for (i = 0; i < Stage * 2; i++) { // ���� �̵�
				randNum[0] = rand() % 15; // 0 ~ 14 ������ ������ ����
				if (randNum[0] == 0) { // randNum�� 0�� �� ���� �̵�
					randNum[1] = rand() % 4; // 0 ~ 3 ������ ������ ����
					switch (randNum[1]) { // randNum[1] ���� ���� �̵�
					case 0: // ����
						if (Screen[Mon[i].x][Mon[i].y - 1] != 9 && Screen[Mon[i].x][Mon[i].y - 1] != Mon[i].PlayN && Screen[Mon[i].x][Mon[i].y - 1] != Pre[0].PlayN) { 
							Screen[Mon[i].x][Mon[i].y] = 0; 
							Mon[i].y -= 1; // ���� �̵�
							if (Screen[Mon[i].x][Mon[i].y] == Me.PlayN) 
								Me.PlayN = 99; // 99 ����
						}
						Screen[Mon[i].x][Mon[i].y] = Mon[0].PlayN; // ���� ��ġ�� ���� ��ġ
						break; 
					case 1: // ������
						if (Screen[Mon[i].x][Mon[i].y + 1] != 9 && Screen[Mon[i].x][Mon[i].y + 1] != Mon[i].PlayN && Screen[Mon[i].x][Mon[i].y + 1] != Pre[0].PlayN) { 
							Screen[Mon[i].x][Mon[i].y] = 0; 
							Mon[i].y += 1; // ������ �̵�
							if (Screen[Mon[i].x][Mon[i].y] == Me.PlayN) 
								Me.PlayN = 99; //  99 ����
						}
						Screen[Mon[i].x][Mon[i].y] = Mon[0].PlayN; // ���� ��ġ�� ���� ��ġ
						break; 

					case 2: // ����
						if (Screen[Mon[i].x - 1][Mon[i].y] != 9 && Screen[Mon[i].x - 1][Mon[i].y] != Mon[i].PlayN && Screen[Mon[i].x - 1][Mon[i].y] != Pre[0].PlayN) { 
							Screen[Mon[i].x][Mon[i].y] = 0; 
							Mon[i].x -= 1; // ���� �̵�
							if (Screen[Mon[i].x][Mon[i].y] == Me.PlayN) 
								Me.PlayN = 99; //  99 ����
						}
						Screen[Mon[i].x][Mon[i].y] = Mon[0].PlayN; // ���� ��ġ�� ���� ��ġ
						break; 
					case 3: // �Ʒ���
						if (Screen[Mon[i].x + 1][Mon[i].y] != 9 && Screen[Mon[i].x + 1][Mon[i].y] != Mon[i].PlayN && Screen[Mon[i].x + 1][Mon[i].y] != Pre[0].PlayN) { 
							Screen[Mon[i].x][Mon[i].y] = 0; 
							Mon[i].x += 1; // �Ʒ��� �̵�
							if (Screen[Mon[i].x][Mon[i].y] == Me.PlayN) 
								Me.PlayN = 99; // 99 ����
						}
						Screen[Mon[i].x][Mon[i].y] = Mon[0].PlayN; // ���� ��ġ�� ���� ��ġ
						break; 
					}
				}
			}

			for (i = 0; i < 18; i++) { // ���
				gotoxy(1, i + 1); // Ŀ���� (1, i + 1)�� �̵�
				for (j = 0; j < 28; j++) {
					if (Screen[i][j] == 0) { // �� ���� 
						BLACK; // ����
						printf("��"); // ��
					}
					else if (Screen[i][j] == Me.PlayN) { // �÷��̾� 
						RED; // ����
						printf("��"); // �� ��
					}
					else if (Screen[i][j] == 9) { // �� ���
						WHITE; // �Ͼ�
						printf("��"); // �׸�
					}
					else if (Screen[i][j] == Mon[0].PlayN) { // ���� 
						VIO; // ����
						printf("��"); // ������
					}
					else if (Screen[i][j] == Pre[0].PlayN) { // ��Ʈ
						YEL; // ���
						printf("��"); // �� ��Ʈ
					}
				}
				printf("\n"); /
			}

			if (kbhit()) { 
				ch = getch(); //  �Է¹��� ���� ch�� ����
				switch (ch) { // �Է¹��� ���� ���� �̵�
				case 75: // ����
						
					if (Screen[Me.x][Me.y - 1] != 9) { // ���ʿ� ���� ���� ���,
						Screen[Me.x][Me.y] = 0; 
						Me.y -= 1; // �������� �̵�
					}
					if (Screen[Me.x][Me.y] == Mon->PlayN) { // ���͸� ������ �� ����
						Me.PlayN = 99; 
					}
					Screen[Me.x][Me.y] = Me.PlayN; // ���� ��ġ�� �÷��̾� ��ġ
					break;
				case 77: // ������
						 
					if (Screen[Me.x][Me.y + 1] != 9) { // �����ʿ� ���� ���� ���,
						Screen[Me.x][Me.y] = 0; 
						Me.y += 1; // ���������� �̵�
					}
					if (Screen[Me.x][Me.y] == Mon->PlayN) { // ���͸� ������ �� ����
						Me.PlayN = 99; 
					}
					Screen[Me.x][Me.y] = Me.PlayN; // ���� ��ġ�� �÷��̾� ��ġ
					break;
				case 72: // ����
						 
					if (Screen[Me.x - 1][Me.y] != 9) { // ���ʿ� ���� ���� ���,
						Screen[Me.x][Me.y] = 0; 
						Me.x -= 1; // �������� �̵�
					}
					if (Screen[Me.x][Me.y] == Mon->PlayN) { // ���͸� ������ �� ����
						Me.PlayN = 99; 
					}
					Screen[Me.x][Me.y] = Me.PlayN; //  ���� ��ġ�� �÷��̾� ��ġ
					break;
				case 80: // �Ʒ���
						
					if (Screen[Me.x + 1][Me.y] != 9) { // �Ʒ��ʿ� ���� ���� ���,
						Screen[Me.x][Me.y] = 0; 
						Me.x += 1; // �Ʒ������� �̵�
					}
					if (Screen[Me.x][Me.y] == Mon[0].PlayN) { // ���͸� ������ �� ����
						Me.PlayN = 99; 
					}
					Screen[Me.x][Me.y] = Me.PlayN; // ���� ��ġ�� �÷��̾� ��ġ
					break;
				case ESC: break; // ESC �Է½� ����
				}
			}

			if (ch == ESC) break; // �Է� �޾Ҵ� ch�� ESC�� ��,  ����

			LifeN = Life; 
			if (Me.PlayN == 99) { // �÷��̾�� ���Ͱ� ���� ����
				Life -= 1; // Life  ����
				break; 
			}
			for (i = 0; i < 18; i++) { // ��Ʈ Ȯ��
				for (j = 0; j < 28; j++) {
					if (Screen[i][j] == Pre[0].PlayN) {
						PreNum++;
					}
				}
			}
			if (PreNum == 0) { // ��Ʈ�� ���� ȹ�� �� Ż��� ���� ����
				if (Me.y == 27)break; 
			}
		}
	}
}
