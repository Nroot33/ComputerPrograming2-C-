#include <stdio.h>


void main() {

	//실습1
	int arr1[4];
	printf("수학 점수를 입력하세요 : ");
	scanf("%d", &arr1[0]);
	printf("영어 점수를 입력하세요 : ");
	scanf("%d", &arr1[1]);
	printf("국어 점수를 입력하세요 : ");
	scanf("%d", &arr1[2]);

	arr1[3] = arr1[0] + arr1[1] + arr1[2];
	printf("\n");
	printf("수학 : %d\n",arr1[0]);
	printf("영어 : %d\n", arr1[1]);
	printf("국어 : %d\n", arr1[2]);
	printf("합계 : %d\n", arr1[3]);
	printf("평균 : %2.f\n", arr1[3]/3.0);

	printf("\n");
	// 실습2 
	int arr2[5];
	int i, sum = 0;

	for (i = 1; i <= 5; i++) {
		printf("%d  번째 학생들의 성적 : ", i);
		scanf("%d", &arr2[i - 1]);
	}

	printf("<< 입력한 학생들의 성적 >>\n");
	for (i = 0; i < 5; i++) {
		printf("%d ", arr2[i]);
	}

	printf("\n");
	for (i = 0; i<5; i++) {
		sum += arr2[i];
	}

	printf("학생들의 총 합계 : %d\n", sum);
	printf("학생들의 평균 점수 : %2.f\n", sum / 5.0);

	return 0;
}