//Linked List implementation
#include <stdio.h>
#include <stdlib.h>

//Definition of a Node type
typedef struct {
   void *next;
   int value;
} Node;

Node *head = NULL;
Node *tail = NULL;

//Add new node
Node *addNode (int value){
   Node *current = malloc(sizeof(Node));
   if(current == NULL)
      return NULL;

   current->value = value;
   if(head == NULL){
      head = current;
      current->next = NULL;
   }
   else{
      current->next = head;
      tail = head;
      head = current;
   }

   return current;
}

//Delete node
int deleteNode(){
   if (head->next == NULL){
      //It is the unique node
      head = NULL;
      return 1;
   }
   else{
      //Remove head node from the list
      Node *current = malloc(sizeof(Node));
      if(current == NULL)
         return 0;
      current = head->next;
      free(head);
      head = current;
      return 1;
   }
}

//Insert node from head
int insertNode(int pos, int value){
   int counter = pos;
   Node *current = malloc(sizeof(Node));
   if(current == NULL)
         return 0;

   current = head;
   while(current!=NULL && counter>0){
      counter--;
      current = current->next;
   }
   if(current == NULL){
      printf("Position out of the range of the list!");
      return 0;
   }
   Node *node = malloc(sizeof(Node));
   if(node == NULL)
         return 0;

   node->value = current->value;
   current->value = value;
   node->next = current->next;
   current->next = node;

   if(head == current)
      head = node;
   if(tail == current)
      tail =node;

   return 1;
}

//Print node

//Print list
void printList (Node *node){
   while(node != NULL){
      printf("%d -> ", node->value);
      node = node->next;
   }
   printf("\n");
}

//Print test menu
void printMenu (){
   printf("\t1. Add new node\n");
   printf("\t2. Delete node\n");
   printf("\t3. Append node\n");
   printf("\t4. Print list\n");
   printf("\t5. Exit\n");
}

int main (){
   int menuResp = 1, readSize, nodeVal;
   while (menuResp != 5 && menuResp > 0 && menuResp <=5){
      printMenu();
      readSize = scanf("%d", &menuResp);
      if (readSize > 1)
         continue;
      switch (menuResp){
      case 1:
         printf("Node value: ");
         scanf("%d", &nodeVal);
         Node *node = addNode(nodeVal);
         if (node == NULL)
            printf("Node creation failed!\n");
         break;
      case 2:
         if (head == NULL){
            printf("The list is empty!\n");
            break;
         }
         if (!deleteNode())
            printf("Node deletion failed!\n");
         break;
      case 3:
         if (head == NULL){
            printf("The list is empty!\n");
            break;
         }
         int nodePos;
         printf("Node value: ");
         scanf("%d", &nodeVal);
         printf("Node position: ");
         scanf("%d", &nodePos);
         if(!insertNode(nodePos, nodeVal)){
            printf("Node insertion failed!");
         }

         break;
      case 4:
         printList(head);
         break;
      }
   }

   return 0;
}

