#include <stdio.h>

int main() {
	int distance, speed, hour, min; //�ð�, �ӵ�, �ð�, �� ��������
	double sec, setTime; //��, setTime ���� ����

	printf("�Ÿ��� �ӷ��� �Է��Ͻÿ� : ");
	scanf("%d %d", &distance, &speed);

	setTime = (double)distance / (double)speed; //�Ÿ��� �ӷ��� �ð��� ���� ������ ���

	hour = (int)setTime;  //���������� ��ȯ�� �ð� �κ� ȯ�� �� ���
	setTime = setTime - hour;
	setTime = setTime * 60.0;

	min = (int)setTime; //���������� ��ȯ�� �� �κ� ȯ�� �� �Ի�
	setTime = setTime - min;
	setTime = setTime * 60.0;

	sec = (double)setTime; //�Ǽ������� ��ȯ�� �� �κ� ȯ�� �� ���

	printf("�ҿ�ð��� %d�ð� %d�� %.3lf���Դϴ�. \n", hour, min, sec);

}