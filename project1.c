#include <stdio.h> 
#include <stdlib.h>  
#include "bnlist.h"
#include "functions.c"
#include <string.h>

typedef struct bnlist node;

void main(){
  node *root;
  root=NULL;
  char name[20];
  char Lname[20];
  int selection=0;
 menu:
  selection = menu();

  switch(selection){
  case '1':
    printf("complete name of employee: ");
    scanf(" %s",name);
    scanf(" %s",Lname);
    add(name,Lname,&root);
    goto menu;
 
  case'2':
    printf("Delete employee");
    scanf(" %s",name);
    scanf(" %s",Lname);
    delete(name,Lname,&root);
    goto menu;

  case'3':
    printList(root);
    goto menu;

  case'4':
    printf("Writing on file....\n");
    cleanFile();
    writeToFile(root);
    printf("Done.\n");
    goto menu;
  case '5':
    printf("Reading from a file...\n");
    readFile();
    goto menu;
  case'6':
    exit(1);
  default:
    printf("Not a valid option\n");
    goto menu;


  }
  
  
}

