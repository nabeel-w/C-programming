#include<stdio.h>
#include<string.h>
int st[10],top=-1;
void push(char val)
{
    st[++top]=val;
}
int pop()
{
    return st[top--];
}
int op(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/') return 1;
    else return 0;
}
void main()
{
    char pre[10]={"+52"};
    int len=strlen(pre);
    char res;
    for(int i=len-1;i>=0;i--)
    {
        switch(op(pre[i]))
        {
            case 0:
                push(pre[i]);
                break;
            case 1:
                int op1=pop(),op2=pop();
                switch(pre[i])
                {
                    case '+':
                        res=op1+op2;
                        break;
                    case '-':
                        res=op1-op2;
                        break;
                    case '*':
                        res=op1*op2;
                        break;
                    case '/':
                        res=op1/op2;
                        break;
                }
                push(res);
        }
    }
    printf("Result: %c\n",res);
}