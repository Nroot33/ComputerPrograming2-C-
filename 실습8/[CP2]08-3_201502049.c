#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


void makeBingo(int * bingoArray, int inputSize); // �������� ���� �Լ�
void printBingo(int * bingoArray, int inputSize); // �������� ��� �Լ�
int checkBingo(int * bingoArray, int inputSize); // ���� Ȯ�� �Լ�
int getRandomNumber(int * prevNumberList); // �ߺ��� ������ �ϳ��� �����ϰ� �����ؼ� ��ȯ �Լ�
int getUserSelectNumber(int * prevNumberList); // ���� ��ȣ�� �Է¹޾� ��ȯ �Լ�

int main() {
	
	srand((unsigned int)time((time_t*)NULL)); 

	int bingo[400] = { 0 }; 
	int bingoSize;

	printf("������ ����� �Է��ϼ��� : "); // ���ڿ� ���
	scanf("%d", &bingoSize); // �Է¹��� �������� size�� ����

	makeBingo(bingo, bingoSize); // makeBingo() ����
	checkBingo(bingo, bingoSize); // checkBingo() ����

	return 0;
}


void makeBingo(int * bingoArray, int inputSize) { // �������� ����
	int check[400] = { 0 }; 
	int count = 0, temp = 0; 

	while (count < inputSize * inputSize) { 
		temp = rand() % (inputSize * inputSize) + 1; // 1 ~ (inputSize * inputSize) ���� �������� temp�� ����

		if (check[temp - 1] == 0) { // �ߺ� ���� ����ó��
			++check[temp - 1]; 
			bingoArray[count++] = temp;  
		}
	}

	printf("������ ����\n"); 

	printBingo(bingoArray, inputSize); //printBingo() ����
}

void printBingo(int * bingoArray, int inputSize) { // �������� ���
	for (int i = 0; i < inputSize * inputSize; i++) { 
		if (bingoArray[i] == -2) // bingoArray[i]�� -2�� ��,
			printf("%4c", '*'); // * ���

		else 
			printf("%4d", bingoArray[i]); // bingoArray[i] ���

		if (i % inputSize == inputSize - 1) // �ٹٲ�
			printf("\n"); 
	}
}

int checkBingo(int * bingoArray, int inputSize) { // ���� Ȯ��
	int prevNum[400] = { 0 }; 
	prevNum[inputSize * inputSize] = -1; 
	int selectNum, bingoNum, checkNum = 0, bingo = 0; 

	while (1) { 
		bingoNum = 0; 

		printf("���� ���� ����� ����[1:����][2:������Է�] : "); 
		scanf("%d", &selectNum); 

		switch (selectNum) { 
		case 1: 
			bingoNum = getRandomNumber(prevNum); // getRandomNumber(prevNum)���� �� ����
			break; 

		case 2: 
			bingoNum = getUserSelectNumber(prevNum); // getUserSelectNumber(prevNum)���� �� ����
			break;
		}

		if (bingoNum == -1) // ���� ó��
			printf("�̹� �Էµ� �����Դϴ�\n"); 

		else if (bingoNum == 0) // ���� ó��
			printf("�ٽ� �Է� �ϼ���\n"); 

		else { // ���� ������ ���������� ���� ��,
			for (int i = 0; i < inputSize * inputSize; i++) { 
				if (bingoArray[i] == bingoNum) 
					bingoArray[i] = -2; 
			}

			switch (1) { // ���� ���� Ȯ��
			case 1: // ���� ���� Ȯ��
				for (int i = 0; i < inputSize * inputSize; i += inputSize) { 
					for (int j = 0; j < inputSize; j++) { 
						if (bingoArray[i + j] == -2) 
							++checkNum; 
					}

					if (checkNum == inputSize) { // ���� Ȯ��
						++bingo; // bingo �� ����
						break; 
					}

					checkNum = 0; 
				}

				if (checkNum == inputSize) // Ž�� ����
					break;

			case 2: // ���� ���� Ȯ��
				for (int i = 0; i < inputSize; i++) { 
					for (int j = 0; j < inputSize * inputSize; j += inputSize) { 
						if (bingoArray[i + j] == -2) 
							++checkNum; 
					}

					if (checkNum == inputSize) { //���� Ȯ��,
						++bingo; // bingo �� ����
						break; 
					}

					checkNum = 0; 
				}

				if (checkNum == inputSize) // Ž�� ����,
					break; 

			case 3: // �밢��1 ����Ȯ�� 
				for (int i = 0; i < inputSize * inputSize; i += inputSize + 1) { 
					if (bingoArray[i] == -2) 
						++checkNum;
				}

				if (checkNum == inputSize) { //���� Ȯ��,
					++bingo; // bingo �� ����
					break; 
				}

				checkNum = 0; // chkNum�� 0���� �ʱ�ȭ

			case 4: // �밢��2 ����Ȯ��
				for (int i = inputSize - 1; i < inputSize * inputSize; i += inputSize - 1) { 
					if (bingoArray[i] == -2) 
						++checkNum; 
				}

				if (checkNum == inputSize) { //���� Ȯ��
					++bingo; // bingo �� ����
					break; 
				}

				checkNum = 0; 
			}

			if (bingo != 0) { 
				printf("����!\n"); 
				printBingo(bingoArray, inputSize); // ���� �迭 ���
				break; 
			}
		}
	}
	return 0;
}

int getRandomNumber(int * prevNumberList) { // �ߺ��� ������ �ϳ��� �����ϰ� �����ؼ� ��ȯ
	int n = 0, size = 0;

	for (size = 0; prevNumberList[size] != -1; size++);

	while (1) {
		int check = 0;
		n = rand() % size + 1; // 1~size������ �������� n�� ����

		for (int i = 0; i < size; i++) 
			if (prevNumberList[i] == n) { 
				++check; 
				break; 
			}

		if (check == 0) 
			break; 
	}

	printf("���� ���ڸ� ���� : %d\n", n); 

	for (int i = 0; ; i++) {
		if (prevNumberList[i] == 0) {
			prevNumberList[i] = n;
			break;
		}
	}

	return n;
}

int getUserSelectNumber(int * prevNumberList) { // ���� ��ȣ�� �Է¹޾� ��ȯ
	int check = 0, size = 0, n = 0; 

	for (size = 0; prevNumberList[size] != -1; size++); 

	printf("����� ���� ���� �Է� : "); 
	scanf("%d", &n); 

	for (int i = 0; i < size; i++) 
		if (n == prevNumberList[i]) { 
			++check; 
			break; 
		}

	if (check != 0) 
		n = -1; 

	else { 
		for (int i = 0; ; i++) { 
			if (prevNumberList[i] == 0) { 
				prevNumberList[i] = n;
				break; 
			}
		}
	}

	return n; 
}