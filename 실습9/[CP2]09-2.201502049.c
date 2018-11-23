#include <stdio.h>

int disp_menu(void); // �޴� ��� �Լ�
void enter_park(int(*park_space)[2][5], int(*reserved)[3]); // ���� �Լ�
void exit_park(int(*park_space)[2][5]); // ���� �Լ�
void reserve_park(int(*reserved)[3]); // �������� ��� �Լ�
void print_park(int(*park_space)[2][5], int(*reserved)[3]); // ���� ��Ȳ ��� �Լ�
void print_basement(int(*park_space)[5], int floor, int(*reserved)[3]); // ���� ��Ȳ Ȯ�� ��� �Լ�
int check_reservation(int(*reserved)[3], int basement, int num);  // �������� �������� Ȯ�� �Լ�
int check_reserved_num(int(*reserved)[3], int car_num, int *floor, int *resv_num); // �������� Ȯ�� �Լ�
int find_space(int(*park_space)[5], int floor, int(*reserved)[3]); // �� ���� Ȯ�� �Լ�

int main(void) {

	disp_menu(); // �޴� ����

	return 0;
}

int disp_menu(void) { // �޴� ��� �� ��ȯ 

	int n;
	int park_space[3][2][5]; // ���� ���� int �� 3���� �迭 ���� �� �ʱ�ȭ

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 5; k++)
				park_space[i][j][k] = 0;


	int reserved[10][3]; // ���� ���� ��� int�� 3���� �迭 ���� �� �ʱ�ȭ

	for (int j = 0; j < 10; j++)
		for (int k = 0; k < 3; k++)
			reserved[j][k] = 0;

	// �޴� ���� �� if ���� ���� �޴� ����
	printf("1. ���� \n");
	printf("2. ���� \n");
	printf("3. �������� ��� \n");
	printf("4. ������Ȳ ��� \n");
	printf("0. ���� \n");
	printf("> ��ȣ ���� : ");
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
		printf("��ȿ�� �޴��� �ƴմϴ�.\n");
		disp_menu();
	}
}

void enter_park(int(*park_space)[2][5], int(*reserved)[3]) { // ���� �Լ�
	int car_num, resv_floor, resv_num;
	int floor = 0, num, floor_num = 1;


	while (1) {
		printf("> ���� �Է�(���� 4�ڸ�) : ");
		scanf("%d", &car_num);
		if (car_num > 999 && car_num < 10000)
			break;
		else {
			printf("�ùٸ��� ���� ������ȣ �Դϴ�. \n");
			continue;
		}
	}

	if (check_reserved_num(reserved, car_num, &resv_floor, &resv_num)) { // ����������ȣ Ȯ�� �� ���� 
		park_space[resv_floor][resv_num / 5][resv_num % 5] = car_num;
		printf("�������� ����");
	}

	else {
		printf("@ ���� ���� ���� : 1��[%d��] , 2��[%d��], 3��[%d��] \n", find_space(park_space, 0, reserved), find_space(park_space, 1, reserved), find_space(park_space, 2, reserved));

		print_basement(park_space, floor, reserved); // ������ 1�� ���

		while (1) {
			printf("\n> ���� ��ȣ �Է�(�ٸ��� 0, ��� -1) : ");
			scanf("%d", &num);
			if (num == -1) // ����
				disp_menu();
			else if (num == 0) { // �� �̵� 
				if (floor == 2)
					floor_num = -1;
				else if (floor == 0)
					floor_num = 1;
				print_basement(park_space, floor = floor + floor_num, reserved);
				printf("\n");
			}
			else if (num > 0 && num < 11) { // ���� 
				if (park_space[floor][(num - 1) / 5][(num - 1) % 5] != 0) // ���� ���� Ȯ��
					printf("�� ������ �ƴմϴ�.");
				else
				{
					park_space[floor][(num - 1) / 5][(num - 1) % 5] = car_num;
					printf("@ ���� �Ϸ� \n");
					disp_menu();
				}
			}
			else
				printf("�ùٸ� ��ȣ�� �ƴմϴ�."); //���� ó��
		}
	}
}

void exit_park(int(*park_space)[2][5]) { // ���� �Լ�

	int car_num;

	printf("\n> ���� �Է�(���� 4�ڸ�) : ");
	scanf("%d", &car_num);

	// �ݺ����� ���� �迭 Ž��
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 5; k++)
				if (car_num == park_space[i][j][k]) {
					park_space[i][j][k] = 0; // ���� ���� �ʱ�ȭ
					printf("@ ���� �Ϸ�\n");
					return; // �Լ� ����
				}
	printf("@ �ش� ������ �����ϴ�.\n"); // ���� ����
}
void reserve_park(int(*reserved)[3]) { // �������� ��� �޼ҵ�
	while (1) { // while�� ���ѹݺ�
		int floorNum, n, carNum; // int�� ���� floorNum, n, carNum ����

		printf("\n> ���� ��ȣ �Է�(���� 0) : "); // ���ڿ� ���
		scanf("%d", &floorNum); // �Է¹��� �������� floorNum�� ����

		if (floorNum == 0) // floorNum�� 0�� ��,
			disp_menu(); // while�� Ż��

		scanf("%d", &n); // �Է¹��� �������� n�� ����
		printf("> ������� ��ȣ �Է� : "); // ���ڿ� ���
		scanf("%d", &carNum); // �Է¹��� �������� carNum�� ����
		reserved[n - 1][floorNum - 1] = carNum; // reserved[n - 1][floorNum - 1]�� carNum ����
		printf("@ ��ϵǾ����ϴ�.\n\n"); // ���ڿ� ���
	}
}

void print_park(int(*park_space)[2][5], int(*reserved)[3]) { // ���� ��Ȳ ��� �޼ҵ�

	print_basement(park_space, 0, reserved); // 1���� ��Ȳ ���
	printf("\n");
	print_basement(park_space, 1, reserved); // 2���� ��Ȳ ���
	printf("\n");
	print_basement(park_space, 2, reserved); // 3���� ��Ȳ ���
	printf("\n");
	disp_menu();
}

void print_basement(int(*park_space)[5], int floor, int(*reserved)[3]) { // ���� ��Ȳ Ȯ�� ��� �Լ�

	printf("\n[%d��]============================\n", floor + 1); // �� ���
	for (int i = 0; i < 2; i++) { // �ݺ����� ���� ��Ȳ Ž��
		for (int j = 0; j < 5; j++) {
			if (park_space[floor * 2 + i][j] == 0) {
				if (check_reservation(reserved, floor, i * 5 + j)) // �������� ���� ���� Ȯ��
					printf("[resv]");
				else
					printf("[%3d]", i * 5 + j + 1);
			}
			else
				printf("[%4d]", park_space[floor * 2 + i][j]); // �ش� ��ġ ���� ������ȣ ���
		}
		printf("\n");
	}
}

int check_reservation(int(*reserved)[3], int basement, int num) { // �������� ���� Ȯ�� �Լ�
	return !(reserved[num][basement] == 0);
}

int check_reserved_num(int(*reserved)[3], int car_num, int *floor, int *resv_num) { // �������� Ȯ�� �Լ�
	for (int i = 0; i < 10; i++) // �ݺ����� ���� ���� ���� ��� �迭 Ž��
		for (int j = 0; j < 3; j++) {
			if (reserved[i][j] == car_num) { // ���� ���� ��ȣ Ȯ��
				*resv_num = i; // �� ����
				*floor = j;
				return 1;
			}
		}
	return 0;
}

int find_space(int(*park_space)[5], int floor, int(*reserved)[3]) { //�� ���� ���� ã�� �Լ�

	int count_floor = 0; // ���� �� ���� ���� Ȯ�� ���� ���� �� �ʱ�ȭ 

	for (int j = 0; j < 2; j++) // �ݺ����� ���� �� ���� ��� 
		for (int k = 0; k < 5; k++) {
			if ((*(park_space + floor * 2 + j))[k] == 0 && reserved[j * 5 + k][floor] == 0)
				++count_floor;
		}

	return count_floor; // ���� ��ȯ
}
