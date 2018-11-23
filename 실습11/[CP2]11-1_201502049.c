#include <stdio.h>
#include <string.h>

int dup_check(char **sp, char *temp, int cnt); // ���ڿ� �ߺ��˻� �Լ�

int main(void) {
	char temp[50]; // �迭 ����
	char *res[100]; // ������ �迭 ����

	int size = 0, i = 0; // ���� ���� �� �ʱ�ȭ

	while (1) {
		printf("> �ܾ� �Է� : ");
		fgets(temp, sizeof(temp), stdin); // temp�� ���ڿ� ����
		temp[strlen(temp) - 1] = '\0'; // temp ���ڿ� ���� NULL ���� ����
		if (strcmp(temp, "end") == 0)
			break; // ��������
		else if (dup_check(res, temp, size) == 1) { // �ߺ� �ܾ� �Ǻ�
			printf("> �̹� �����ϴ� �ܾ� �Դϴ�. \n");
		}
		else if (size > 0 && res[size - 1][strlen(res[size - 1]) - 1] != temp[0]) { // �ܾ� �� �� �����ձⰡ �ȵǴ� ��� �Ǻ�
			printf("> �ܾ� �ձⰡ �Ұ����մϴ�.  \n");
		}
		else
		{
			res[size] = (char*)calloc(strlen(temp) + 1, sizeof(char)); // res[size] �����Ҵ� ����
			if (res[size] == NULL) { // �Ҵ���� ����ó��
				printf("�޸� ���� \n");
				break;
			}
			strcpy(res[size++], temp); // res[size]�� temp ���ڿ� ���� 
		}
	}

	for (i = 0; i < size; i++) {
		printf("%s ", res[i]); // ���
	}

	for (i = 0; i < size; i++) {
		free(res[i]); // ���� �Ҵ� ����
	}

	printf("\n");

	return 0;
}

int dup_check(char **sp, char *temp, int cnt) {
	int i;
	for (i = 0; i < cnt; i++) {
		if (strcmp(sp[i], temp) == 0) // temp�� sp[i] �� �� ������ 1 �� ��ȯ
			return 1;
	}
	return 0;
}