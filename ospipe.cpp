/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C/C++.
Code, Compile, Run and Debug online from anywhere in world.

Kaustubh Patil
Roll No:059
PRN:0120180264
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>


void processA(int);
void processB(int);

void processA(int writefd)
{
    int len;
    char buff[100];
    printf("Enter input string: ");
    fgets (buff,100,stdin);
    len=strlen(buff);
    if(buff[len-1]=='\n')
    {
        len--;
    }
    write(writefd,buff,len);
}


void processB(int readfd)
{
    int n,i,j;
    char str[100],temp;
    n=read(readfd,str,100);
    str[n]='\0';
    i=0;
    while(str[i]!='\0')
    {
        if(str[i]>'A' && str[i]<'Z')//check if upper
        {
            str[i]=str[i]+32;
            i++;
            continue;
        }
        else if(str[i]>'a' && str[i]<'z')//check if lower
        {
            str[i]=str[i]-32;
            i++;
            continue;
        }
        else//ignore other characters
        {
            i++;
            continue;
        }
        
    }
    printf("Toggled string: %s\n",str);
}


int main(void) 
{	
    int pipe1[2];
    pid_t childpid;
    pipe(pipe1);
    childpid = fork();
    if (childpid==0)
    {
        close (pipe1[1]);
        processB (pipe1[0]);
    }
    else
    {
        close (pipe1[0]);
        processA (pipe1[1]);
    }
    return EXIT_SUCCESS;
}

