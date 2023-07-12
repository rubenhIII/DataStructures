//Linked List implementation
#include <stdio.h>
#include <stdlib.h>

//Definition of a Node type
typedef struct {
   void *next;
   int value;
} Node;

Node *head = NULL;

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
      head = current;
   }

   return current;
}

//Delete node

//Append node

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
         /* code */
         break;
      case 3:
         /* code */
         break;
      case 4:
         printList(head);
         break;
      }
   }

   return 0;
}

