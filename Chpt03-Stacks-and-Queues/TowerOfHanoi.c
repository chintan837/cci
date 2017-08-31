/*
 * In the classic problem of the Towers of Hanoi, you have 3 towers and N disks of different sizes
 * which can slide on to anyt ower. The puzzle starts with disks sorted in ascending order of size 
 * from top to bottom (i.e., each disk sits on top of an even larger one). 
 * You have the following constraints:
 *
 * (1) Only one disk can be moved at a time.
 * (2) A disk is slid off the top of one tower onto the next tower.
 * (3) A disk can only be placed on top of a larger disk.
 *
 * Write a program to move the disksfrom the first tower to the last using stacks.
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct stack {
	int *array;
	int len;
	int index;
};

struct stack *stack_init() {
	struct stack *newstack = malloc(sizeof(struct stack));

	newstack->len = 8;
	newstack->array = malloc(newstack->len * sizeof(int));
	newstack->index = 0;

	return newstack;
}

void stack_print(struct stack *st) {
	for (int i = 0; i < st->index; i++)
		printf("%d ", st->array[i]);
	printf("\n");
}

void stack_push(struct stack *st, int data) {
	if (st->index >= st->len) {
		st->len *= 2;
		st->array = realloc(st->array, st->len * sizeof(int));
	}
	st->array[st->index] = data;
	st->index++;
}

int stack_pop(struct stack *st) {
	if (st->index <= 0) {
		return 0;
	}
	st->index--;
	return st->array[st->index];
}

int stack_isEmpty(struct stack *st) {
	if (st->index == 0)
		return 1;
	else
		return 0;
}

int stack_peek(struct stack *st) {
	if (st->index == 0) {
		return 0;
	}
	return st->array[st->index-1];
}

void TowerOfHanoi(struct stack *main, struct stack *buffer, struct stack *target, int max) {
	if (stack_isEmpty(main))
		return;

	int current = stack_pop(main);

}

int main(void) {
	struct stack *main = stack_init();
	struct stack *target = stack_init();
	struct stack *buffer = stack_init();

	stack_push(main, 4);
	stack_push(main, 3);
	stack_push(main, 2);
	stack_push(main, 1);

	printf("main: ");
	stack_print(main);
	printf("buffer: ");
	stack_print(buffer);
	printf("target: ");
	stack_print(target);

	TowerOfHanoi(main, buffer, target, INT_MAX);

}
