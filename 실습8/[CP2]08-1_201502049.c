#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int sortIndex(char *str, char *res_str); // �Է� ���� �ܾ ���� ������� �̾� ���̴� �Լ�

int main() {
	char res[200] = { 0 };  
	int size = 0; 
	// �迭 res ���� �� ������ ���� �ʱ�ȭ

	while (1) { 
		char str[16] = { 0 }; // �迭 str ���� �� �ʱ�ȭ

		printf("�ܾ� �Է� : "); 

		if (!scanf_s("%s", str, sizeof(str))) // ũ�� 15 �ʰ��� ���ڿ� ����ó�� (����)
			printf("���̰� �ʹ� ��ϴ�.\n"); 

		else { 
			if (!strcmp(str, "end")) // end �Է� �� ����
				break; 

			else {
				if (!sortIndex(str, res)) 
					break; 

				printf("������� ���ڿ� : %s\n", res); 
			}
		}

		while (getchar() != '\n'); // ���� �ʱ�ȭ
	}
}

	int sortIndex(char *str, char *res_str) { // �Է� ���� �ܾ ���� ������� �̾� ���̴� �Լ� )

		char temp_res[200] = { 0 }; // �迭 temp_str ���� �� �ʱ�ȭ

		char *temp = NULL; // ������ temp ���� �� NULL�� �ʱ�ȭ

		if (strlen(str) + strlen(res_str) > 200) { // �Է¹��� ���ڿ� ���̿� ���� ����� ���ڿ� ������ ���� 200�� ���� �� ����ó��
			printf("�� �̻� �Է¹��� �� �����ϴ�.\n"); 
			return 0; 
		}

		else { 
			temp = strtok(res_str, " "); // temp�� " "�� Ű����� res_str�� �߶� ���ڿ��� �ּҰ��� ����

			while (temp != NULL) { 
				if (strcmp(str, temp) != 1) // strcmp ���
					break; 

				strcat(temp_res, temp); //temp_res ���ڿ� �ڿ� temp �̾����
				strcat(temp_res, " ");

				temp = strtok(NULL, " "); // temp�� " "�� Ű����� �߶� �����κ��� �߶� ���ڿ��� �ּҰ��� ����
			}

			strcat(temp_res, str); // temp_res ���ڿ� �ڿ� str �̾����

			if (temp != NULL) { 
				strcat(temp_res, " "); 
				strcat(temp_res, temp); // temp_res ���ڿ� �ڿ� temp �̾����
			}

			while ((temp = strtok(NULL, " ")) != NULL) {  
				strcat(temp_res, " "); 
				strcat(temp_res, temp); // temp_str ���ڿ� �ڿ� temp �̾����
			}

			strcpy(res_str, temp_res); // res_str�� temp_str�� ����

			return 1; 
		}
	}