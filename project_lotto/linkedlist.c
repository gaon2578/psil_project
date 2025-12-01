#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

//연결 리스트를 생성하는 함수
linkedlist* makelist() {
	linkedlist* L;									//linkedlist 자료형의 주소를 가리키는 L
	L = (linkedlist*)malloc(sizeof(linkedlist));	//linkedlist* 자료형 크기의 메모리 할당
	L->head = NULL;									//헤드 노드가 NULL을 가리키게함
	L->length = 0;
	return L;					
}

//헤드 노드 뒤에 노드를 연결하는 함수
void insertFirst(linkedlist* L, char* id, char* pass, char* name) {
	listnode* Lp;
	Lp = (listnode*)malloc(sizeof(listnode));
	strcpy(Lp->id, id);							//Lp의 노드 요소들을 입력받은 정보로 저장
	strcpy(Lp->pass, pass);
	strcpy(Lp->name, name);
	Lp->link = L->head;							//Lp를 헤드 노드가 가리키는 노드를 가리키게함
	L->head = Lp;								//헤드 노드가 Lp를 가리키게함
}

//마지막 노드 뒤에 노드를 연결하는 함수
void insertLast(linkedlist*L, char* id, char* pass, char* name) {	
	listnode* Lp;
	listnode* tmp;
	Lp = (listnode*)malloc(sizeof(listnode));
	tmp = (listnode*)malloc(sizeof(listnode));
	strcpy(Lp->id, id);				
	strcpy(Lp->pass, pass);
	strcpy(Lp->name, name);

	if (L->head == NULL) {			//리스트가 비어있다면
		L->head = Lp;				//헤드 노드가 Lp를 가리키게함
		Lp->link = NULL;			//Lp가 NULL을 가리켜 마지막 노드
	}
	else {							
		tmp = L->head;				
		while (tmp->link != NULL) {	//마지막 노드를 찾을때까지 반복
			tmp = tmp->link;		//노드를 넘김(현재 가리켜지는 노드를 현재 가리키는 노드로 바꿔 노드를 넘어감)
		}
		tmp->link = Lp;				//마지막 노드에 Lp 노드의 요소 저장
		Lp->link = NULL;			//Lp가 NULL을 가리켜 마지막 노드
	}
}

//리스트의 노드 요소를 모두 출력함
void display(linkedlist*L) {		
	listnode* tmp;
	tmp = (listnode*)malloc(sizeof(listnode));
	tmp->link = L->head;					//첫 노드부터
	while (tmp->link != NULL) {				//마지막 노드까지
		tmp = tmp->link;
		printf("%s %s %s\n", tmp->id, tmp->pass, tmp->name);	//노드의 요소를 출력함
	}
}

//list1에서 winnernum만큼 랜덤한 노드를 list2에 저장함
void lotto(linkedlist* L1, linkedlist* L2,int winnernum) {
	listnode* tmp;
	tmp = (listnode*)malloc(sizeof(listnode));
	tmp->link = L1->head;						//헤드노드부터
	int sum=0;

	while (tmp->link != NULL) {					//마지막 노드까지
		tmp = tmp->link;						//노드 넘겨가며
		if (sum<winnernum && rand() % 2) {		//당첨자 수가 당첨자수(사용자 지정)보다 작고 1/2 확률로 당첨되면
			sum++;
			insertLast(L2, tmp->id, tmp->pass, tmp->name);	//당첨자 리스트에 당첨자 정보 저장
		}
	}
	return;
}
