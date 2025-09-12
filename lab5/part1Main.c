#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern int pop();
extern void push(int);
extern int isEmpty();

int main(int argc, char * argv[])
{
  int ch;
  int popped;
  while ((ch = getchar()) != EOF)
  {
    if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))
    {
      continue;
    }
    else if (ch == '<')  
    {
      ch = getchar();  
      if (isalpha(ch)) 
      {
        push(ch);  
      }
      else if (ch == '/')  
      {
        ch = getchar();  
        popped = pop();  

        if (popped != ch)  
        {
          fprintf(stderr, "INVALID!\n");
          exit(1);
        }
        else 
        {
          fprintf(stdout, "VALID!\n");
          exit(0);
        }
      }
    }
  }
  exit(0);
}
