#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>


int main(){

int i,j,border,count=0,answer=0,flag=0,*ptr;
char key[1][10]={"dragon"};

char array[10],temp;
char digit='_';
system("cls");
border=strlen(&key[0][0]);

printf("\n\n\t\t\t**HANGMAN GAME** \n");
printf("\n\t\t\t**************\t\t\t");
printf("\n\t\t\t..............\n\n\t\t\t  ");
for(j=0;j<border;j++)
 { printf("%c ",digit);
 array[j]=digit;}

 printf("\n\n\t\t\t..............\t\t\t");
printf("\n\n\t\t\t**************");


while (count<6)//||(ans<c))
 {
 flag=0;
  printf("\n\n\n\n\n\n\t Please enter a character");
temp=getche();
 
for(i=0;i<border;i++)
{
if (temp==key[0][i])
  { array[i]=key[0][i];
  flag=1;
answer++; }
}

system("cls");
printf("\n\n\t\t ** HANGMAN GAME ** \n");
printf("\n\t\t\t**************\t\t\t");
printf("\n\t\t\t..............\n\n\t\t\t  ");
for(i=0;i<border;i++)
printf("%c ",array[i]);
printf("\n\n\t\t\t..............\t\t\t");
printf("\n\n\t\t\t**************");

if(flag==0)
{count++;
printf("\n\n\n\n\t\t%c is a wrong guess",temp);
printf("\n\n\t\t ( You have %d more guesses)",6-count);}

else{
printf("\n\n\t\t u r correct!!");
  printf("\n\t\t( u have %d more words to go)",border-answer);}
 
if(answer==border) break;
 }
 if(answer==border) printf("\n\n\n\t Congratz! YOU WON ! ");
 else printf("\n\n\n\t\t  u lose.\n\n \t\t **SORRY  U R HANGED**");


getch();}
