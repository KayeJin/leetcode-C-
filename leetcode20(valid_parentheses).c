#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//if valid ,return 1, else return 0;
typedef struct stack* stack_p;
typedef struct node* node_p;
typedef struct stack
{
    node_p top;
}stack;
typedef struct node
{
    char p;
    node_p next;
}node;
void  stackInit(stack_p ins);
void stackPush(stack_p ins, char p);
char stackPop(stack_p ins);
int isEmpty(stack_p ins);

int isValid(char* s);
int main()
{
    char str[2]={'(',')'};
    int t = isValid(str);
    printf("%d",t);
    return 0;
}
void stackInit(stack_p s)
{
    s->top = NULL;
}
void stackPush(stack_p ins, char p)
{
    node_p newnode=(node_p)malloc(sizeof(node));
    newnode->p = p;
    newnode->next = ins->top;
    ins->top = newnode;
}
char stackPop(stack_p ins )
{
    node_p temp = ins->top;
    char data =ins->top->p; 
    ins->top = temp->next;
    free(temp);
    return data;
}
int isEmpty(stack_p ins)
{
    return ins->top == NULL;
}
int isValid(char* s)
{
    stack_p ins;
    stackInit(ins);
    int len = strlen(s);
    if(len == 1 && s[0] == ' ') return 1;

    if(s[0] == ')' || s[0] == ']' || s[0] == '}') return 0;
    for(int i=0;i<len;i++)
    {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') stackPush(ins,s[i]);
        else 
        {
            if(isEmpty(ins))return 0;
            switch(s[i])
            {
                case ')':
                    if(stackPop(ins) != '(') return 0;
                case '}':
                    if(stackPop(ins) != '{') return 0;
                case ']':
                    if(stackPop(ins) != '[') return 0;
            }
        } 
    }
    if(ins->top == NULL) return 1;
    else return 0;
}
