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




int input_intro(char(*intro)[80]) { // ������ �Է¹޴� �Լ�
	int index = 0;
	while (1) {
		printf("> ���� �Է� : ");
		scanf("%s", intro[index]);
		fflush(stdin);
		if (strcmp(intro[index], "end") == 0) // end�� �ԷµǸ� �Է� ����
			break;
		index++;

	}
	return index - 1;
}

void init_intro(char(*intro)[80], char ** intp) { // ���� ���� intro�� intp�� �����ϴ� �Լ�
	for (int i = 0; i < 10; i++)
		intp[i] = intro[i]; // intro[i]�� ������ �ּҰ��� intp[i]�� ����
}

void sort_intro(char ** intp, int cnt) { // ���������� �����ϴ� �Լ�

	char** temp;

	for (int i = 0; i < cnt - 1; i++)  // �ݺ����� ���� Ž��
		for (int j = i; j < cnt; j++) {
			if (strcmp(intp[i], intp[j]) == 1) { // intp[i]�� intp[j]�� ���� ���ڿ��� ��,
				temp = intp[i];
				intp[i] = intp[j];
				intp[j] = temp; // ������ ���� ����
			}
		}
}

void print_intro(int mode, void * vp, int cnt) { // �迭�� ����ϴ� �޼ҵ�
	if (mode == 1) { // mode�� 1�� ��
		char **res = (char **)vp; // vp�� char�� ���� �����ͷ� ����ȯ �� char�� ���� ������ res����
		printf("----���������� ���----\n");
		for (int i = 0; i <= cnt; i++) // �ݺ����� ���� �迭 ���
			printf("%s\n",res[i]);
	}

	if (mode == 0) { // mode�� 0�� ��
		char(*res)[80] = (char **)vp; // vp�� char�� ���� �����ͷ� ����ȯ �� char�� ������ �迭 res�� ����
		printf("----�Է¼����� ���----\n");

		for (int i = 0; i <= cnt; i++) // �ݺ����� ���� �迭 ���
			printf("%s\n", res[i]);
	}
}
