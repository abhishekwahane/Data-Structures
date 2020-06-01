//203165
//Abhishek Wahane
//A4 Batch
//Stack

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

char stack[20][20];                                            //declaring stack
int top=-1;
char stack1[20];

void postfixtoprefix(char* );                                //function declearation
void postfixtoinfix(char* );
void infixtopostfix(char str[20]);
char pop();
int isp(char);                                                //in stack priority
int icp(char);                                                //incoming priority
int isp1(char);
int icp1(char);
int main(){
    char exp[20];
    int m=0,z;
    while(m!=8)
    {
        printf("\nchoose:");                                                  
        printf("\n1.Infix to Postfix  ");
        printf("\n2.Postfix to Infix  ")  ;
        printf("\n3.Postfix to Prefix ");
        printf("\n4.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&m);
        switch(m){
            case 1:
                printf("Enter Infix exp:");
                scanf("%s",exp);
                infixtopostfix(exp);
                break;

            case 2:
                printf("Enter postfix exp:");
                scanf("%s",exp);
                postfixtoinfix(exp);
                break;
            case 3:
                printf("Enter postfix exp:");
                scanf("%s",exp);
                postfixtoprefix(exp);
                break;

            case 4:
                return 0;
            default:
                return 0;
        }
    }
    return 0;
}
char pop(){                                                    //pop operation
    char temp;
    temp=stack1[top];
    top--;
    return(temp);
}


void infixtopostfix(char str[20])                    //infix to postfix conversion
{
    char postfix[20];
    int k=0;
    char ch;
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]=='(')                                        
        {
            top++;
            stack1[top]='(';
        }
        else if(str[i]==')')
        {
            while((ch=pop())!='(')
            {
                postfix[k]=ch;                                
                k++;
            }
        }
        else if(str[i]=='+' ||str[i]=='-' ||str[i]=='*' ||str[i]=='/' ||str[i]=='^')
        {
            while(top>=0 && isp(stack1[top])>=icp(str[i]))
            {
                postfix[k]=pop();
                k++;
            }
            top++;
            stack1[top]=str[i];
        }
        else
        {
            postfix[k]=str[i];
            k++;
        }
    }
    while(top>=0)
    {
        postfix[k]=pop();
        k++;
    }
    printf("\nThe infix to postfix exp is:%s",postfix);
}
int isp(char ch)                                            //instack priority
{
    if(ch=='+' || ch=='-')
        return (1);
    if(ch=='(')
        return 0;
    if(ch=='*' || ch=='/')
        return (2);
    if (ch=='^')
        return(3);
    else
        return(-1);
}
int isp1(char ch)                                            //instack priority
{
    if(ch=='+' || ch=='-')
        return (1);
    if(ch=='(')
        return 0;
    if(ch=='*' || ch=='/')
        return (2);
    if (ch=='^')
        return(4);
    else
        return(-1);
}
int icp(char ch)                                            //incoming priority
{
    if(ch=='+' || ch=='-')
        return (1);
    if(ch=='*' || ch=='/')
        return (2);
    if (ch=='^')
        return(4);
    if (ch=='(')
        return (5);
    else
        return(-1);
}
int icp1(char ch)                                            //incoming priority
{
    if(ch=='+' || ch=='-')
        return (1);
    if(ch=='*' || ch=='/')
        return (2);
    if (ch=='^')
        return(3);
    if (ch=='(')
        return (5);
    else
        return(-1);
}
void postfixtoinfix(char* exp)
{
    char str[20],op1[20],op2[20],str1[20];
    int l;
    for(int i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='+' || exp[i]=='-' ||exp[i]=='*' ||exp[i]=='/' ||exp[i]=='^')
        {                                                    
            strcpy(op1,stack[top]);                            //copy string operation
            top--;
            strcpy(op2,stack[top]);                           
            top--;
            str[0]='(';
            str[1]='\0';
            strcat(str,op2);                               
            l=strlen(str);
            str[l]=exp[i];
            str[l+1]='\0';
            strcat(str,op1);
            l=0;
            l=strlen(str);
            str[l]=')';
            str[l+1]='\0';
            top++;
            strcpy(stack[top],str);                            //pushing into stack
        }
        else{
            top++;                                            
            char st[20];
            strcpy(st,"");                                   
            st[0]=exp[i];                                    
            st[1]='\0';
            strcpy(stack[top],st);
        }
    }
    strcpy(str1,stack[top]);
    top--;
    printf("\nThe postfix to infix conversion is:%s",str1);
}
void postfixtoprefix(char* exp)                                //postfix to prefix operation
{
    char str[20],op1[20],op2[20],str1[20];
    for(int i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='+' || exp[i]=='-' ||exp[i]=='*' ||exp[i]=='/' ||exp[i]=='^')
        {                                                   
            strcpy(op1,stack[top]);                            
            top--;
            strcpy(op2,stack[top]);
            top--;
            str[0]=exp[i];                                    
            str[1]='\0';
            strcat(str,op2);
            int l;
            l=strlen(str);
            str[l]='\0';
            strcat(str,op1);
            top++;
            strcpy(stack[top],str);
        }
        else
        {
            top++;                                            //push if operand
            char st[20];
            strcpy(st,"");                                    
            st[0]=exp[i];
            st[1]='\0';
            strcpy(stack[top],st);
        }
    }
    strcpy(str1,stack[top]);
    top--;
    printf("\nThe postfix to prefix conversion is:%s",str1);
}

/*

OUTPUT:

choose:
1.Infix to Postfix     
2.Postfix to Infix  
3.Postfix to Prefix 
4.Exit
Enter your choice:1
Enter Infix exp:a-b

The infix to postfix exp is:ab-
choose:
1.Infix to Postfix     
2.Postfix to Infix  
3.Postfix to Prefix 
4.Exit
Enter your choice:2
Enter postfix exp:ab-

The postfix to infix conversion is:(a-b)
choose:
1.Infix to Postfix     
2.Postfix to Infix  
3.Postfix to Prefix 
4.Exit
Enter your choice:3
Enter postfix exp:ab-

The postfix to prefix conversion is:-ab

*/
