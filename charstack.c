#include <stdio.h>
#include <stdlib.h>

								// Declaring the stack data type
struct
{
	int top;
	int size;
	char *array;
}typedef stack;
	
								// Functions to perform operations on stack
void init(stack *s, int size )
{
	s->top = -1;
	s->array = (char *)malloc(size * sizeof(char));
	s->size = size;
}

void push(stack *s, char num)
{
	if(s->top == s->size-1)
		return;

	s->array[++s->top] = num;
}

char pop(stack *s)
{
	return s->array[s->top--];
}
								// Functions using implementations of stack 
int reversefile(char *source, char *destination)
{
	FILE *fptrs, *fptrd;
	stack s;

	init(&s, 100);

	fptrs = fopen(source, "r");
	if(fptrs == NULL)
	{
		printf("The file wasn't accessible\n");
		return 0;
	}

	fptrd = fopen(destination, "w");
	if(fptrd == NULL)
	{
		printf("The file wasn't accessible\n");
		return 0;
	}


	char buff;

	while(!feof(fptrs))
	{
		buff = fgetc(fptrs);
//		printf("%c",buff);
		push(&s,buff);
	}

	while(s.top > -1)
		fputc(pop(&s), fptrd);

	fclose(fptrs);
	fclose(fptrd); 
	free(s.array);

	return 1;
}
