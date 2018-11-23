#include <stdio.h>

int count_num(int (*ary1)[4], int (*ary2)[4], int (*same_num)[2]); // �Է¹��� �迭������ ��ġ�ϴ� ��ȣ Ȯ�� �Լ� ���� 

int main(int argc, const char *argv[]) {

	int ary1[3][4] = { // int�� 2���� �迭 ary1 ���� �� ����
	   {15, 3, 9, 11},
	   {23, 7, 10, 12},
	   {0, 17, 55, 35}
	};

	int ary2[3][4] = { // int�� 2���� �迭 ary2 ���� �� ����
		{13, 8, 9, 15},
		{23, 0, 10, 11},
		{29, 17, 43, 3}
	};

	int same_num[12][2]; // int�� 2���� �迭 same_num ����
	int cnt;
	cnt = count_num(ary1, ary2, same_num); // count_num �Լ� ����
	printf("��ġ�ϴ� ��ȣ�� �� : %d\n", cnt); // ��ġ�ϴ� ��ȣ�� �� ���
	printf("�迭������ ��ġ(��,��)...\n");

	for (int i = 0; i < cnt; i++) { // �迭������ ��ġ ���
		printf("(%d, %d) \n", same_num[i][0], same_num[i][1]);
	}


	return 0;
}

int count_num(int(*ary1)[4], int(*ary2)[4], int(*same_num)[2]) { // �Է¹��� �迭������ ��ġ�ϴ� ��ȣ Ȯ�� �Լ�
	int same = 0;
	for (int i = 0; i < 3; i++) // �迭 Ž��
		for (int j = 0; j < 4; j++) {
			if (ary1[i][j] == ary2[i][j]) {
				same_num[same][0] = i;
				same_num[same][1] = j;
				same++;
			}
		}
	return same; // same ��ȯ
}