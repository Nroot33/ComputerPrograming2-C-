#include <stdio.h>
#include <string.h>

void invertedOutput(char str[]); // ���ڿ��� �Ųٷ� ����ϴ� �Լ� ����

void invertedOutput(char str[]) {  // ���ڿ��� �Ųٷ� ����ϴ� �Լ� 
	int i, length;
	char temp;

	length = strlen(str); // ���ڿ��� ���̸� length ������ ����

	for (i = 0; i < length / 2; i++) { // �ݺ����� ���� ���ڿ��� ���ڵ��� ��ġ�� ��ȭ ��Ŵ
		temp = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = temp;

	}
	printf("������ �Է��� ���ڿ��� �Ųٷ� ����մϴ�. \n");
	printf("%s\n", str);
}


int main() {

	char str[100] = { 0 }; // ó�� ���ڿ� ���� �� �ʱ�ȭ

	printf("�� ���� �Է��ϼ���. >>\n");
	gets(str);  // ���ڿ� �� �� �Է� �޴� get ���
	invertedOutput(str);

	return 0;
}