//Binary Search Tree Implementation.
#include <stdio.h>
#include <stdlib.h>

typedef struct {
   void *lsubtree;
   void *rsubtree;
   int value;
} Node;

Node *root = NULL;

int insertNode(Node *current, int value);
int insert(int value);

int insert(int value){
   if (root == NULL){
      root->value = value;
      return 1;
   }
   else{
      insertNode(root, value);
      return 1;
   }
}

//Insert tree node
int insertNode(Node *current, int value){
   if(value < current->value){
      if(current->lsubtree == NULL){
         Node *newNode = malloc(sizeof(Node));
         newNode->value = value;
         current->lsubtree = newNode;
      }
      else{
        insertNode(current->lsubtree, value);
      }
      return 1;
   }
   else{
      if(current->rsubtree == NULL){
         Node *newNode = malloc(sizeof(Node));
         newNode->value = value;
         current->rsubtree = newNode;
      }
      else{
        insertNode(current->rsubtree, value);
      }
      return 1;
   }
}

void printMenu (){
   printf("\t1. Insert new tree node\n");
   printf("\t2. Delete tree node\n");
   printf("\t3. Search value\n");
   printf("\t4. Print list\n");
   printf("\t5. Exit\n");
}

int main(){

   return 0;
}