#define id_you "yonsei"			//사용자 아이디
#define pass_you "1234@"		//사용자 비밀번호


typedef struct Listnode {		//참여자, 당첨자의 노드(아이디, 비번, 이름)
	char id[20];
	char pass[20];
	char name[20];
	struct Listnode* link;		//다음 노드를 가리키는 주소 노드
}listnode;

typedef struct Linkedlist {	
	listnode* head;		//헤드 노드
	int length;			//노드 길이
}linkedlist;

linkedlist* makelist();			//리스트를 만드는 함수

void insertFirst(linkedlist*, char* id, char* pass, char* name);	//헤드 노드 뒤에 노드를 연결하는 함수

void insertLast(linkedlist*, char* id, char* pass, char* name);		//마지막 노드 뒤에 노드를 연결하는 함수

void display(linkedlist*);		//리스트의 노드 요소를 모두 출력함

void lotto(linkedlist* list1, linkedlist* list2, int winnernum);	//list1에서 winnernum만큼 랜덤한 노드를 list2에 저장함
