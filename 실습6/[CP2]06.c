#include <stdio.h>


void main() {

	//�ǽ�1
	int arr1[4];
	printf("���� ������ �Է��ϼ��� : ");
	scanf("%d", &arr1[0]);
	printf("���� ������ �Է��ϼ��� : ");
	scanf("%d", &arr1[1]);
	printf("���� ������ �Է��ϼ��� : ");
	scanf("%d", &arr1[2]);

	arr1[3] = arr1[0] + arr1[1] + arr1[2];
	printf("\n");
	printf("���� : %d\n",arr1[0]);
	printf("���� : %d\n", arr1[1]);
	printf("���� : %d\n", arr1[2]);
	printf("�հ� : %d\n", arr1[3]);
	printf("��� : %2.f\n", arr1[3]/3.0);

	printf("\n");
	// �ǽ�2 
	int arr2[5];
	int i, sum = 0;

	for (i = 1; i <= 5; i++) {
		printf("%d  ��° �л����� ���� : ", i);
		scanf("%d", &arr2[i - 1]);
	}

	printf("<< �Է��� �л����� ���� >>\n");
	for (i = 0; i < 5; i++) {
		printf("%d ", arr2[i]);
	}

	printf("\n");
	for (i = 0; i<5; i++) {
		sum += arr2[i];
	}

	printf("�л����� �� �հ� : %d\n", sum);
	printf("�л����� ��� ���� : %2.f\n", sum / 5.0);

	return 0;
}