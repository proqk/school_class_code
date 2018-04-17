#pragma once

typedef char element; //char을 element형 지정

typedef struct _Node { //노드 구조체
	element data;  //리스트 원소의 값
	struct _Node *prev; //이전 노드에 대한 포인터
	struct _Node *next; //다음 노드에 대한 포인터
}Node;

typedef struct _DLinkedList{ //연결리스트 구조체
	int count; //연결리스트 항목수
	Node *head; //head 포인터 - head 더미 노드를 가리키는 포인터
	Node *tail; //tail 포인터 - tail 더미 노드를 가리키는 포인터
}DLinkedList;

typedef DLinkedList List; 

void Init(List *list); //리스트 초기화
int Length(List *list); //리스트 항목 수 반환
int isEmpty(List *list); //리스트가 비어있는지 확인

void Insert(List *list, int position, element item); //리스트의 원하는 위치에 데이터 삽입
void Delete(List *list, int position); //리스트의 원하는 위치의 데이터 삭제
void Retrieve(List *list, int position, element *result); //리스트의 원하는 위치의 값 탐색
void Display(List *list); //리스트 내용 출력

void Delete_item(List *list, element item); //선택과제 1 - 리스트에서 원하는 내용의 데이터 삭제
void Delete_all(List *list); //선택과제 2 - 리스트의 모든 데이터 삭제, 삭제하는 데이터를 출력하여 삭제 상황을 보여줌

void Display_R(List *list); //리스트의 내용을 역순으로 보여줌
