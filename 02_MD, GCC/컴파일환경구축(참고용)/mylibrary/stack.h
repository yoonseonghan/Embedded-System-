#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100	// ������ �ִ� ũ��
#define MAZE_SIZE 6

typedef struct {		// ��ü!
	short r;
	short c;
} element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// ���� �ʱ�ȭ �Լ�
void init_stack(StackType* s);
// ���� ���� ���� �Լ�
int is_empty(StackType* s);
// ��ȭ ���� ���� �Լ�
int is_full(StackType* s);
// ���� �Լ�
void push(StackType* s, element item);
// ���� �Լ�
element pop(StackType* s);
// ��ũ �Լ�
element peek(StackType* s);

