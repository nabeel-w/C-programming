#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char st[100];
int top=-1;
int is_empty()
{
    return top==-1;
}
void push(char a)
{
    st[++top]=a;
}
char pop()
{
    return st[top--];
}
int precidence(char a)
{
    switch (a)
    {
    case '^':
        return 3;
    case '/':
    case '*':
        return 2;
    case '+':
    case '-':
        return 1;
    }
}

char* inf_to_pos(char* arr)
{
    int len=strlen(arr),siz=sizeof(char),a=((len+1)*siz),i=0,j=0;
    char* post=(char* )malloc(a);
    while (arr[i]!='\0')
    {
        if(isalnum(arr[i]))
        {
            post[j++]=arr[i++];
        }
        else 
        {
            if(precidence(arr[i]>precidence(st[top])))
            {
                push(arr[i++]);
            }
            else
            {
                char x=pop();
                post[j++]=x;
            }
        }
        
    }
    while (!is_empty())
    {
        post[j++]=pop();
    }
    post[j]='\0';
    return post;
    
} 

int main(void)
{
    char exp[100];
    char* e;
    printf("Enter your Infix expression: ");
    scanf("%s",exp);
    e=exp;
    char* result=inf_to_pos(e);
    printf("Postfix Expression: %s",result);
}