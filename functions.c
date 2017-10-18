#include "bnlist.h"                       //
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct bnlist node;

//menu of all the options to create an employee list
int menu(){
 char option =0;
  
  printf("______________________________\n");
  printf("1) add employee\n");
  printf("2) remove employee\n");
  printf("3) print List of employees\n");
  printf("4) write list to e file\n");
  printf("5) read list from a file\n");
  printf("6) exit\n");
  printf("______________________________\n");
  printf("selection:");
  scanf(" %c",&option);
  return option;
}
//add new node to the BST
void add(char name[],char Lname[], node** iterator){
  node * newNode=NULL;
  if((*iterator)==0){
    newNode= (node*)malloc(sizeof(node));
    newNode->left=NULL;
    newNode->right=NULL;
    strcpy(newNode->name,name);
    strcpy(newNode->last,Lname);
    *iterator =newNode;
    return;
  }
  int cmpLast = strcmp((*iterator)->last,Lname);    // comprare the last name of the BST node with the new last name and determine if goes to the left or right.

  // if cmpLast is =0 means that the last name is the same, if is <0 it means that goes after, and if is >0 it goes before.
  if(cmpLast<0){
    add(name,Lname,&(*iterator)->right);
  }
  else if(cmpLast >=0){
    add(name,Lname,&(*iterator)->left);
  }

}


//it should delete nodes
node* delete(char name[],char Lname[],node ** iterator){

  if((*iterator)==0){                                       //checks if the root is empty
    return (*iterator);
  }


  
  printf("---- %s\n",(*iterator)->name);
  int cmpName =strcmp((*iterator)->name,name);
  int cmpLast =strcmp((*iterator)->last,Lname);
  
  if(cmpLast<0){
    delete(name,Lname,&(*iterator)->right);
  }
  else if(cmpLast >=0){
    delete(name,Lname,&(*iterator)->left);
   }
 

  // case if both childs are null.
  if((cmpName==0 && cmpLast==0)){

    if((*iterator)->left ==0 && (*iterator)->right==0){
      //   printf("Both NULL\n")                          debug purposes;
      node *temp = NULL;
      temp=(node*)malloc(sizeof(node));
     free((*iterator));
      return temp;
    }

    //if left child is null replace it with the next right child
  if((*iterator)->left ==0){
    printf("left\n");
    node *temp = NULL;
      temp=(node*)malloc(sizeof(node));
      temp=(*iterator)->right;
      free((*iterator));
      return temp;
     }

//if right child is null replace it with the next left child
    if((*iterator)->right ==0){
      node *temp = NULL;
      temp=(node*)malloc(sizeof(node));
      temp=(*iterator)->left;
      free((*iterator));
      return temp;
    }
  } 
  return(*iterator);
    
}


 // print the list an inorder  left, root , right
void printList(node* iterator){        
  if(iterator){
    printList(iterator->left);
    printf("%s",iterator->name);
    printf("%s\n",iterator->last);
    printList(iterator->right);
  }
}


// cleans the file if exist or it creates the new file.
void cleanFile(){
  FILE *noteFile;
  if(noteFile!=NULL){
    noteFile=fopen("employeeTable.txt","w"); // w mode to create or re write
    fclose(noteFile);                        // a file. 
  }
  else{
    printf("No file to clean.");
  }
}

//write in the file.
void writeToFile(node *iterator){

 FILE *noteFile;
 noteFile =fopen("employeeTable.txt","a");    // a mode to write on file 

 if(noteFile != NULL){
   if(iterator){
     writeToFile(iterator->left);
     fprintf(noteFile,"employee Name: %s ",iterator->name);
     fprintf(noteFile,"%s\n",iterator->last);
     fclose(noteFile);
    writeToFile(iterator->right);
    }
}
 else{
   printf("Not file found.\n");
 }
}

// read all the content of the file.
void readFile(){
  char line[200];
  FILE *noteFile;
  noteFile=fopen("employeeTable.txt","r"); // r mode to read only
  if(noteFile!=NULL){
    while(!feof(noteFile)){
      fgets(line,200,noteFile);
      printf("%s",line);
    }
  }
  else{
    printf("Not file found.\n");
  }
}
