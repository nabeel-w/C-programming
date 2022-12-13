#include<stdio.h>
#include<limits.h>
#include<ctype.h>
#include<string.h>
int top=-1,a[100];
void push(char x)
{
    a[++top]=x;
}
char pop()
{
    if(top==-1) return CHAR_MIN;
    return a[top--];
}
int precidence(char x)
{
    if(x==')') return 0;
    else if(x=='+'||x=='-') return 1;
    else if(x=='/'||x=='*') return 2;
}
void prefix(char inf[100],char pre[100])
{
    char tmp,x;
    int i=0,j=0;
    strrev(inf);
    while(inf[i]!='\0')
    {
        tmp=inf[i];
        if(isalnum(tmp))
        {
            pre[j++]=tmp;
        }
        else if(tmp==')') push(tmp);
        else if(tmp=='(')
        {
            while(x=pop()!=')')
            {
                pre[j++]=x;
            }
        }
        else 
        {
            while(precidence(a[top])>=precidence(tmp))
            {
                pre[j++]=pop();
            }
            push(tmp);
        }
        i++;
    }
    while(top!=-1)
        {
            pre[j++]=pop();
        }
    pre[j]='\0';
    strrev(pre);
}
int main(void)
{
    char inf[100]={"a+b*c"},pre[100];
    prefix(inf,pre);
    printf("postfix expression: %s\n",pre);
}