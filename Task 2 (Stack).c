/*
 ============================================================================
 Name        : Task.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : implementing stack
 ============================================================================
 */
#include <stdio.h>
#include "string.h"


typedef unsigned char uint8;

uint8 MAXSIZE = 8;
uint8 stack[8];
uint8 top = -1;

uint8 isempty() {

   if(top == -1)
      return 1;
   else
      return 0;
}

uint8 isfull() {

   if(top == MAXSIZE)
      return 1;
   else
      return 0;
}

uint8 peek() {
   return stack[top];
}

uint8 pull() {
	uint8 data;

   if(!isempty()) {
      data = stack[top];
      top = top - 1;
      return data;
   } else {
      printf("Could not retrieve data, Stack is empty.\n");
   }
}

void push(uint8 u8_data) {

   if(!isfull()) {
      top = top + 1;
      stack[top] = u8_data;
   } else {
      printf("Could not insert data, Stack is full.\n");
   }
}

void printStack()
{
	while(!isempty())
	{
		uint8 data = pull();
	      printf("%d\n",data);

	}
}



int main() {

/*
	// push items on to the stack
   push(3);
   push(5);
   push(9);
   push(1);
   push(12);
   push(15);

   printf("Element at top of the stack: %d\n" ,peek());
   printf("Elements: \n");

   // print stack data
   printStack();

   printf("Stack full: %s\n" , isfull()?"true":"false");
   printf("Stack empty: %s\n" , isempty()?"true":"false");

*/


uint8 str[100];
gets(str);
uint8 length=strlen(str);


uint8 x;
uint8 flag=0;
uint8 count_open=0;
uint8 count_close=0;
          if(length%2!=0)
          {
              flag=1;

          }
          else
          {
          for(int j=0;j<length;j++)
          {
              push(str[j]);

              if(peek()==')')
              {
                  count_close++;
                  x=pull();
                  if(isempty())
                  {
                   flag=1;
                   break;
                  }
                  else if(peek()!='(')
                  {
                      flag=1;
                      break;
                  }

                  else
                  x=pull();
              }
              else if(peek()=='}')
              {
                  count_close++;
                  x=pull();
                  if(isempty())
                  {
                   flag=1;
                   break;
                  }
                  else if(peek()!='{')
                  {
                      flag=1;
                      break;
                  }
                  else
                  pull();
              }
              else if(peek()=='>')
              {
                  count_close++;
                  x=pull();
                  if(isempty())
                  {
                   flag=1;
                   break;
                  }
                  else if(peek()!='<')
                  {
                      flag=1;
                      break;
                  }
                  else
                  x=pull();
              }
              else if(peek()==']')
              {
                  count_close++;
                  x=pull();
                  if(isempty())
                  {
                   flag=1;
                   break;
                  }
                  else if(peek()!='[')
                  {
                      flag=1;
                      break;
                  }
                  else
                  x=pull();
              }
              else
              {
                  count_open++;
              }


          }
          }
          if(flag==0&&(count_open==count_close))
        	 printf("Balanced");
          else
         	 printf("Not Balanced");

   return 0;

}


