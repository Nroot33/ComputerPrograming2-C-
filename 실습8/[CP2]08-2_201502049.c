#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void makeLottoNumber(int *lottoNums); // �ζ� ��ȣ ���� �Լ�
void sortLottoNumber(int *lottoNums); // �ζ� ��ȣ �������� ���� �Լ�
void swap(int *x, int *y); // �ζ� ��ȣ �������� ���Ľ� ��ġ �ٲ� �Լ�
int checkLottoNumber(int *lottoNums); // �ζ� ��ȣ�� ���ϴ� �Լ�

int main(void)
{
	int lottoNum[6];

	makeLottoNumber(lottoNum);

	checkLottoNumber(lottoNum);

}


	void makeLottoNumber(int * lottoNums) // �ζ� ��ȣ ���� 
	{
		srand((unsigned int)time((time_t*)NULL));

		int temp1;
		int temp2;

		for (int i = 0; i < 6; i++) { // �ζ� ��ȣ�� 1~45 ���� �ߺ����� ������ ����
			temp1 = rand() % 45 + 1; 
			for (int j = 0; j <= i - 1; j++)
				if (temp1 == lottoNums[j]) {
					temp2 = temp1;
					temp1 = rand() % 45 + 1;
				}
			lottoNums[i] = temp1;
		}
		
		sortLottoNumber(lottoNums); // ������������ ����

	}

	void sortLottoNumber(int *lottoNums) {
		int i, j; 
		int *min; // �迭�� ����� �������� ���� ���� ������ �ּҰ�
		for (i = 0; i < 6; i++)
		{
			min = lottoNums + i;
			for (j = i; j < 6; j++)
				if (*min > *(lottoNums + j)) // ���� ���� ������ �� ��
					min = lottoNums + j;
			swap(min, lottoNums + i); // ���� ���� ������ ���� ���� i��° �迭���� �ٲ۴�.
		}
		return;
	}

	void swap(int *x, int *y) { 
		int temp = *x; // temp ��� ���ǰ��� �����Ͽ� x,y�� ��ġ �ٲ�
		*x = *y;
		*y = temp;
		return;
	}

	int checkLottoNumber(int *lottoNums) {
		int temp[6];
		int check[6];
		int count = 0;

		for (int i = 0; i < 6; i++) { // check �迭�� ��ȣ �Է�
			printf("��ȣ �Է� : ");
			scanf("%d", &check[i]);
			temp[i] = check[i];

			if (check[i] > 0 && check[i] <= 45) // check�迭�� ���� ��ȣ �Ǵ� 
				for (int j = 0; j < i; j++) { // 1~45 �̿� ���ڸ� ����ó��
					if (temp[j] == check[i])
					{
						printf("���� ��ȣ�� �ֽ��ϴ�.\n");
						i--;
						break;
					}
				}
					else {
						printf("1~45�� ���� �Է��ϼ���.\n");
						i--;
					}
				}
		
		for (int i = 0; i< 6; i++) // �ζ� ��ȣ ���� �迭�� ���ϸ� ���� Ž��
			for (int j = 0; j< 6; j++)
			{
				if (lottoNums[i] == check[j])
					count++; // ���� ���ڰ� ���� ��, count �� ����
			}

		printf("�ζ� ��ȣ : ");
		for (int i = 0; i < 6; i++)
			printf("%5d", lottoNums[i]); // �ʱ� �ζ� ��ȣ ���� �迭 ���

		printf("\n");
		printf("�� %d�� �´� ���ڰ� �ֽ��ϴ�.\n", count); // �� �´� ���� ���
	
	}
	