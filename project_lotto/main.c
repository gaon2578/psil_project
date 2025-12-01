#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "linkedlist.h"
#include <stdlib.h>
#include <time.h>


int main() {
	char yourid[10];		//사용자 아이디
	char yourpass[10];		//사용자 비밀번호
	char yourname[10];		//사용자 이름을 저장하는 문자열 변수
	char userid[10];		
	char userpass[10];
	char username[10];		//참여자 아이디, 비번, 이름을 저장하는 문자열 변수
	int usernum;			//참여자 수
	int winnernum;			//당첨자 수
	srand((unsigned int)time(NULL));

	printf("당신의 아이디를 입력해주세요 :");	//yonsei
	scanf("%s", &yourid);
	printf("당신의 비밀번호를 입력해주세요 :");	//1234@
	scanf("%s", &yourpass);

	if (strcmp(yourid, id_you) != 0 || strcmp(yourpass, pass_you) != 0) {	//아이디나 비번이 틀리면 프로그램 종료
		printf("아이디 또는 비밀 번호가 틀렸습니다.\n");
		return 0;
	}
	else {
		printf("환영합니다!, 당신의 이름을 적어주세요 :");	
		scanf("%s", &yourname);
	}
	printf("참여자는 몇명으로 설정할까요?(본인포함) :");
	scanf("%d", &usernum);
	printf("당첨자는 몇명으로 설정할까요? :");
	scanf("%d", &winnernum);

	linkedlist* list1;		//참여자를 저장할 연결 리스트 포인터
	list1 =  makelist();	//연결리스트 생성

	insertFirst(list1, yourid, yourpass, yourname);		//사용자 정보를 노드에 작성

	for (int i = 1; i <= usernum-1; i++) {					//참여자 수-1 만큼 반복 (사용자 제외)
		sprintf(userid, "user%d", i);						//참여자의 아이디 생성
		sprintf(userpass, "pass%04d", rand()%usernum+1);	//참여자 비밀번호 생성
		sprintf(username, "name%d", i);						//참여자 이름 생성
		insertLast(list1, userid, userpass, username);		//참여자 정보 참여자 리스트에 저장
	}
	printf("\n추첨자 목록: \n");			//참여자 목록을 출력함
	display(list1);

	printf("\n추첨시작!\n");
	linkedlist* list2;				//당첨자를 저장할 연결 리스트 포인터
	list2 = makelist();				//연결 리스트 생성
	lotto(list1,list2,winnernum);	//당첨자 추첨

	printf("\n당첨자 목록 :\n");
	display(list2);					//당첨자 목록 출력
	printf("\n축하합니다!!\n");


	return 0;
}