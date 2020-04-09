struct
{
	int top;
	int size;
	char *array;
}typedef stack;

void init(stack *, int);
void push(stack *, char);
char pop(stack *);
int reversefile(char *, char *);
