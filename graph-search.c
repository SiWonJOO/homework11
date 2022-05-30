#include <stdio.h>

typedef struct node{
int vertax;
struct GraphNode* link;
}GraphNode;

typedef struct type{
   int n;
   GraphNode* list[10];
}GraphType;
void Initialize()
{

}

void InsertVertex()
{

}
void InsertEdge()
{

}
void DFS()
{

}
void BFS(){

}
void FreeGraph()
{

}
int main()
{
   char command;
   int key;
   
   do{
      printf("\n");
      printf("[----- [주시원] [2018038045] -----]\n");
      printf("\n\n");
      printf("----------------------------------------------------------------\n");
      printf("                   Binary Search Tree #2                        \n");
      printf("----------------------------------------------------------------\n");
      printf(" Initialize Graph     = z                                       \n");
      printf(" Insert Vertex        = v      Insert Edge                  = e \n");
      printf(" Depth First Search   = d      Breath First Search          = b \n");
      printf(" print Graph          = p      Quit                         = q \n");
      printf("----------------------------------------------------------------\n");

      printf("Command = ");
      scanf(" %c", &command);

      switch(command) {
      case 'z': case 'Z':
         break;
      case 'q': case 'Q':
         break;
      case 'v': case 'V':
         printf("Your Key = ");
         scanf("%d", &key);
         break;
      case 'e': case 'E':
         printf("Your Key = ");
         scanf("%d", &key);
         break;
      case 'd': case 'D':
         break;
      case 'b': case 'B':
         break;
      case 'p': case 'P':
         break;

      default:
         printf("\n       >>>>>   Concentration!!   <<<<<     \n");
         break;
      }

   }while(command != 'q' && command != 'Q');

   return 1;
}
