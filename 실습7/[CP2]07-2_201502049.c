#include <stdio.h>
#include <string.h>

void invertedOutput(char str[]); // 문자열을 거꾸로 출력하는 함수 선언

void invertedOutput(char str[]) {  // 문자열을 거꾸로 출력하는 함수 
	int i, length;
	char temp;

	length = strlen(str); // 문자열의 길이를 length 변수에 저장

	for (i = 0; i < length / 2; i++) { // 반복문을 통한 문자열의 문자들의 위치를 변화 시킴
		temp = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = temp;

	}
	printf("위에서 입력한 문자열을 거꾸로 출력합니다. \n");
	printf("%s\n", str);
}


int main() {

	char str[100] = { 0 }; // 처음 문자열 선언 및 초기화

	printf("한 줄을 입력하세요. >>\n");
	gets(str);  // 문자열 한 줄 입력 받는 get 사용
	invertedOutput(str);

	return 0;
}