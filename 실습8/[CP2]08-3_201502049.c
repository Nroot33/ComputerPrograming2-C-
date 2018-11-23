#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


void makeBingo(int * bingoArray, int inputSize); // 빙고판을 생성 함수
void printBingo(int * bingoArray, int inputSize); // 빙고판을 출력 함수
int checkBingo(int * bingoArray, int inputSize); // 빙고 확인 함수
int getRandomNumber(int * prevNumberList); // 중복을 제외한 하나를 랜덤하게 추출해서 반환 함수
int getUserSelectNumber(int * prevNumberList); // 빙고 번호를 입력받아 반환 함수

int main() {
	
	srand((unsigned int)time((time_t*)NULL)); 

	int bingo[400] = { 0 }; 
	int bingoSize;

	printf("빙고판 사이즈를 입력하세요 : "); // 문자열 출력
	scanf("%d", &bingoSize); // 입력받은 정수값을 size에 저장

	makeBingo(bingo, bingoSize); // makeBingo() 실행
	checkBingo(bingo, bingoSize); // checkBingo() 실행

	return 0;
}


void makeBingo(int * bingoArray, int inputSize) { // 빙고판을 생성
	int check[400] = { 0 }; 
	int count = 0, temp = 0; 

	while (count < inputSize * inputSize) { 
		temp = rand() % (inputSize * inputSize) + 1; // 1 ~ (inputSize * inputSize) 사이 랜덤값을 temp에 저장

		if (check[temp - 1] == 0) { // 중복 숫자 예외처리
			++check[temp - 1]; 
			bingoArray[count++] = temp;  
		}
	}

	printf("빙고판 생성\n"); 

	printBingo(bingoArray, inputSize); //printBingo() 실행
}

void printBingo(int * bingoArray, int inputSize) { // 빙고판을 출력
	for (int i = 0; i < inputSize * inputSize; i++) { 
		if (bingoArray[i] == -2) // bingoArray[i]가 -2일 때,
			printf("%4c", '*'); // * 출력

		else 
			printf("%4d", bingoArray[i]); // bingoArray[i] 출력

		if (i % inputSize == inputSize - 1) // 줄바꿈
			printf("\n"); 
	}
}

int checkBingo(int * bingoArray, int inputSize) { // 빙고 확인
	int prevNum[400] = { 0 }; 
	prevNum[inputSize * inputSize] = -1; 
	int selectNum, bingoNum, checkNum = 0, bingo = 0; 

	while (1) { 
		bingoNum = 0; 

		printf("숫자 추출 방법을 선택[1:랜덤][2:사용자입력] : "); 
		scanf("%d", &selectNum); 

		switch (selectNum) { 
		case 1: 
			bingoNum = getRandomNumber(prevNum); // getRandomNumber(prevNum)실행 후 저장
			break; 

		case 2: 
			bingoNum = getUserSelectNumber(prevNum); // getUserSelectNumber(prevNum)실행 후 저장
			break;
		}

		if (bingoNum == -1) // 예외 처리
			printf("이미 입력된 숫자입니다\n"); 

		else if (bingoNum == 0) // 예외 처리
			printf("다시 입력 하세요\n"); 

		else { // 숫자 추출을 정상적으로 했을 때,
			for (int i = 0; i < inputSize * inputSize; i++) { 
				if (bingoArray[i] == bingoNum) 
					bingoArray[i] = -2; 
			}

			switch (1) { // 빙고 조건 확인
			case 1: // 가로 빙고 확인
				for (int i = 0; i < inputSize * inputSize; i += inputSize) { 
					for (int j = 0; j < inputSize; j++) { 
						if (bingoArray[i + j] == -2) 
							++checkNum; 
					}

					if (checkNum == inputSize) { // 빙고 확인
						++bingo; // bingo 값 증가
						break; 
					}

					checkNum = 0; 
				}

				if (checkNum == inputSize) // 탐색 종료
					break;

			case 2: // 세로 빙고 확인
				for (int i = 0; i < inputSize; i++) { 
					for (int j = 0; j < inputSize * inputSize; j += inputSize) { 
						if (bingoArray[i + j] == -2) 
							++checkNum; 
					}

					if (checkNum == inputSize) { //빙고 확인,
						++bingo; // bingo 값 증가
						break; 
					}

					checkNum = 0; 
				}

				if (checkNum == inputSize) // 탐색 종료,
					break; 

			case 3: // 대각선1 빙고확인 
				for (int i = 0; i < inputSize * inputSize; i += inputSize + 1) { 
					if (bingoArray[i] == -2) 
						++checkNum;
				}

				if (checkNum == inputSize) { //빙고 확인,
					++bingo; // bingo 값 증가
					break; 
				}

				checkNum = 0; // chkNum을 0으로 초기화

			case 4: // 대각선2 빙고확인
				for (int i = inputSize - 1; i < inputSize * inputSize; i += inputSize - 1) { 
					if (bingoArray[i] == -2) 
						++checkNum; 
				}

				if (checkNum == inputSize) { //빙고 확인
					++bingo; // bingo 값 증가
					break; 
				}

				checkNum = 0; 
			}

			if (bingo != 0) { 
				printf("빙고!\n"); 
				printBingo(bingoArray, inputSize); // 빙고 배열 출력
				break; 
			}
		}
	}
	return 0;
}

int getRandomNumber(int * prevNumberList) { // 중복을 제외한 하나를 랜덤하게 추출해서 반환
	int n = 0, size = 0;

	for (size = 0; prevNumberList[size] != -1; size++);

	while (1) {
		int check = 0;
		n = rand() % size + 1; // 1~size사이의 랜덤값을 n에 저장

		for (int i = 0; i < size; i++) 
			if (prevNumberList[i] == n) { 
				++check; 
				break; 
			}

		if (check == 0) 
			break; 
	}

	printf("랜덤 숫자를 추출 : %d\n", n); 

	for (int i = 0; ; i++) {
		if (prevNumberList[i] == 0) {
			prevNumberList[i] = n;
			break;
		}
	}

	return n;
}

int getUserSelectNumber(int * prevNumberList) { // 빙고 번호를 입력받아 반환
	int check = 0, size = 0, n = 0; 

	for (size = 0; prevNumberList[size] != -1; size++); 

	printf("사용자 선택 숫자 입력 : "); 
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