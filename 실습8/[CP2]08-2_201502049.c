#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void makeLottoNumber(int *lottoNums); // 로또 번호 생성 함수
void sortLottoNumber(int *lottoNums); // 로또 번호 오름차순 정렬 함수
void swap(int *x, int *y); // 로또 번호 오름차순 정렬시 위치 바꿈 함수
int checkLottoNumber(int *lottoNums); // 로또 번호와 비교하는 함수

int main(void)
{
	int lottoNum[6];

	makeLottoNumber(lottoNum);

	checkLottoNumber(lottoNum);

}


	void makeLottoNumber(int * lottoNums) // 로또 번호 생성 
	{
		srand((unsigned int)time((time_t*)NULL));

		int temp1;
		int temp2;

		for (int i = 0; i < 6; i++) { // 로또 번호를 1~45 사이 중복없는 난수로 생성
			temp1 = rand() % 45 + 1; 
			for (int j = 0; j <= i - 1; j++)
				if (temp1 == lottoNums[j]) {
					temp2 = temp1;
					temp1 = rand() % 45 + 1;
				}
			lottoNums[i] = temp1;
		}
		
		sortLottoNumber(lottoNums); // 오름차순으로 정렬

	}

	void sortLottoNumber(int *lottoNums) {
		int i, j; 
		int *min; // 배열에 저장된 난수값이 가장 작은 원소의 주소값
		for (i = 0; i < 6; i++)
		{
			min = lottoNums + i;
			for (j = i; j < 6; j++)
				if (*min > *(lottoNums + j)) // 가장 작은 원소의 값 비교
					min = lottoNums + j;
			swap(min, lottoNums + i); // 가장 작은 원소의 값과 현재 i번째 배열값을 바꾼다.
		}
		return;
	}

	void swap(int *x, int *y) { 
		int temp = *x; // temp 라는 임의값을 선언하여 x,y의 위치 바꿈
		*x = *y;
		*y = temp;
		return;
	}

	int checkLottoNumber(int *lottoNums) {
		int temp[6];
		int check[6];
		int count = 0;

		for (int i = 0; i < 6; i++) { // check 배열에 번호 입력
			printf("번호 입력 : ");
			scanf("%d", &check[i]);
			temp[i] = check[i];

			if (check[i] > 0 && check[i] <= 45) // check배열에 같은 번호 또는 
				for (int j = 0; j < i; j++) { // 1~45 이외 숫자를 예외처리
					if (temp[j] == check[i])
					{
						printf("같은 번호가 있습니다.\n");
						i--;
						break;
					}
				}
					else {
						printf("1~45의 수만 입력하세요.\n");
						i--;
					}
				}
		
		for (int i = 0; i< 6; i++) // 로또 번호 생성 배열과 비교하며 순차 탐색
			for (int j = 0; j< 6; j++)
			{
				if (lottoNums[i] == check[j])
					count++; // 같은 숫자가 있을 시, count 값 증가
			}

		printf("로또 번호 : ");
		for (int i = 0; i < 6; i++)
			printf("%5d", lottoNums[i]); // 초기 로또 번호 생성 배열 출력

		printf("\n");
		printf("총 %d의 맞는 숫자가 있습니다.\n", count); // 총 맞는 숫자 출력
	
	}
	