#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

/* Struct for stack/queue nodes */

typedef struct Node
{
	int data;
	struct Node *prev;
	struct Node *next;
} Node;

/* Struct for interpreter data */

typedef struct InterpreterData
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
} InterpreterData;

/* struct for instructions */
typedef struct Instruction
{
	char *opcode;
	void (*function)(Node **stack, unsigned int line_number);
} Instruction;

/* External variable for interpreter data */
extern InterpreterData bus;

/* Function prototypes */
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char *clean_line(char *content);
void push(Node **stack, unsigned int number);
void pop(Node **stack, unsigned int counter);
void swap(Node **stack, unsigned int counter);
void add(Node **stack, unsigned int counter);
void nop(Node **stack, unsigned int counter);
void sub(Node **stack, unsigned int counter);
void div(Node **stack, unsigned int counter);
void mul(Node **stack, unsigned int counter);
void mod(Node **stack, unsigned int counter);
void pchar(Node **stack, unsigned int counter);
void pstr(Node **stack, unsigned int counter);
void rotl(Node **stack, unsigned int counter);
void rotr(Node **stack, unsigned int counter);
void queue(Node **stack, unsigned int counter);
void stack(Node **stack, unsigned int counter);

#endif
