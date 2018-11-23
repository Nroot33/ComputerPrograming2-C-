#include <stdio.h>

int main() {
	int distance, speed, hour, min; //시간, 속도, 시간, 분 변수설정
	double sec, setTime; //초, setTime 변수 설정

	printf("거리와 속력을 입력하시오 : ");
	scanf("%d %d", &distance, &speed);

	setTime = (double)distance / (double)speed; //거리와 속력을 시간에 대한 식으로 계산

	hour = (int)setTime;  //정수형으로 변환해 시간 부분 환산 및 계싼
	setTime = setTime - hour;
	setTime = setTime * 60.0;

	min = (int)setTime; //정수형으로 변환해 분 부분 환산 및 게산
	setTime = setTime - min;
	setTime = setTime * 60.0;

	sec = (double)setTime; //실수형으로 변환해 초 부분 환산 및 계산

	printf("소요시간은 %d시간 %d분 %.3lf초입니다. \n", hour, min, sec);

}