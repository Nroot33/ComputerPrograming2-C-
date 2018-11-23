#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int sortIndex(char *str, char *res_str); // 입력 받은 단어를 사전 순서대로 이어 붙이는 함수

int main() {
	char res[200] = { 0 };  
	int size = 0; 
	// 배열 res 생성 및 사이즈 변수 초기화

	while (1) { 
		char str[16] = { 0 }; // 배열 str 생성 및 초기화

		printf("단어 입력 : "); 

		if (!scanf_s("%s", str, sizeof(str))) // 크기 15 초과로 문자열 예외처리 (조건)
			printf("길이가 너무 깁니다.\n"); 

		else { 
			if (!strcmp(str, "end")) // end 입력 시 종료
				break; 

			else {
				if (!sortIndex(str, res)) 
					break; 

				printf("현재까지 문자열 : %s\n", res); 
			}
		}

		while (getchar() != '\n'); // 버퍼 초기화
	}
}

	int sortIndex(char *str, char *res_str) { // 입력 받은 단어를 사전 순서대로 이어 붙이는 함수 )

		char temp_res[200] = { 0 }; // 배열 temp_str 생성 후 초기화

		char *temp = NULL; // 포인터 temp 생성 후 NULL로 초기화

		if (strlen(str) + strlen(res_str) > 200) { // 입력받은 문자열 길이와 현재 저장된 문자열 길이의 합이 200을 넘을 때 예외처리
			printf("더 이상 입력받을 수 없습니다.\n"); 
			return 0; 
		}

		else { 
			temp = strtok(res_str, " "); // temp에 " "를 키워드로 res_str을 잘라낸 문자열의 주소값을 저장

			while (temp != NULL) { 
				if (strcmp(str, temp) != 1) // strcmp 사용
					break; 

				strcat(temp_res, temp); //temp_res 문자열 뒤에 temp 이어붙임
				strcat(temp_res, " ");

				temp = strtok(NULL, " "); // temp에 " "를 키워드로 잘라낸 다음부분을 잘라낸 문자열의 주소값을 저장
			}

			strcat(temp_res, str); // temp_res 문자열 뒤에 str 이어붙임

			if (temp != NULL) { 
				strcat(temp_res, " "); 
				strcat(temp_res, temp); // temp_res 문자열 뒤에 temp 이어붙임
			}

			while ((temp = strtok(NULL, " ")) != NULL) {  
				strcat(temp_res, " "); 
				strcat(temp_res, temp); // temp_str 문자열 뒤에 temp 이어붙임
			}

			strcpy(res_str, temp_res); // res_str에 temp_str을 복사

			return 1; 
		}
	}