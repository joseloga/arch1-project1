#include <stdio.h> 
#include <stdlib.h>  
#include "bnlist.h"
#include "functions.c"

typedef struct bnlist node;

void main(){
  node *root;                    //root of the BST
  root=NULL;
  char name[20];
  char Lname[20];
  int selection=0;
 menu:
  selection = menu();

  switch(selection){
  case '1':
    //add employoyee
    printf("complete name of employee: ");
    scanf(" %s",name);
    scanf(" %s",Lname);
    add(name,Lname,&root);
    goto menu;
 
  case'2':
    // remove employee
    printf("Delete employee (not working properly): ");
    scanf(" %s",name);
    scanf(" %s",Lname);
    delete(name,Lname,&root);
    goto menu;

  case'3':
    //print list
    printList(root);
    goto menu;

  case'4':
    //write into a file
    printf("Writing on file....\n");
    cleanFile();
    writeToFile(root);
    printf("Done.\n");
    goto menu;
  case '5':
    // reading a file
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

