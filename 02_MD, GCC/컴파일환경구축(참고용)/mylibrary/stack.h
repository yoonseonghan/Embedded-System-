#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100	// 스택의 최대 크기
#define MAZE_SIZE 6

typedef struct {		// 교체!
	short r;
	short c;
} element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// 스택 초기화 함수
void init_stack(StackType* s);
// 공백 상태 검출 함수
int is_empty(StackType* s);
// 포화 상태 검출 함수
int is_full(StackType* s);
// 삽입 함수
void push(StackType* s, element item);
// 삭제 함수
element pop(StackType* s);
// 피크 함수
element peek(StackType* s);

