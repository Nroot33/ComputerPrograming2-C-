#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cracker { // craker ����ü ����
	int price; // ����ü ��� ����
	int calories; 
};

int main(void) {

	//�ǽ�1
	char temp[32]; // �迭 ����
	char *ps, *pt; // ������ ����
	int len = 1; 
	ps = (char*)calloc(1, 1); // calloc�� ���� ũ�� 1, ���� 1�� �����Ҵ� ���� ������ ps �����Ϳ� ����
	while (1) {
		printf("�޸��Է� : ");
		fgets(temp, sizeof(temp), stdin); // temp�� ���ڿ� ����
		temp[strlen(temp) - 1] = '\0'; // temp ���ڿ� ���� NULL ���� ����
		if (strcmp(temp, "end") == 0) break; // ��������
		len += strlen(temp) + 1; // temp�� ����+1 ��ŭ len ���� 
		pt = (char*)realloc(ps, len); // relloc�� ���� ps�� len ��ŭ�� �ӱ��̷� ���Ҵ��� pt �����Ϳ� ����
		if (pt == NULL) { // �޸� �Ҵ� ���� ó�� 
			printf("�޸� ����....\n");
			break;
		}
		ps = pt; // pt�� ps�� ����
		strcat(ps, temp); // ps ���ڿ��� temp�� ����
		strcat(ps, " "); // ps ���ڿ��� ������ ����
	}
	printf("%s\n", ps); // ���
	free(ps); // �Ҵ� ����

	//�ǽ�2
	struct cracker basasak; // craker �� ����ü basasak ����
	printf("�ٻ�� ���ݰ� ���� �Է� : "); 
	scanf("%d %d", &basasak.price, &basasak.calories); // �Է� ���� ���� basasak ����ü ����� ����
	printf("price : %dwon\n", basasak.price); // basasak�� price ���
	printf("calories : %dkcal\n", basasak.calories); //basasak�� calories ���

	return 0;
}