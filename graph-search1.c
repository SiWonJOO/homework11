#include <stdio.h>

typedef struct node{ // 그래프노드 구조체 형성
int vertax; // 정점
struct GraphNode* link; // 정점과 연결된 링크
}GraphNode;

typedef struct type{ // 헤드 구조체 형성
   int n; // 정점 개수
   GraphNode* list[10]; // 정점의 헤드노드 
}GraphType;
void Initialize(GraphType* h);

void InsertVertex(GraphType *h, int v);
void InsertEdge(GraphType *h, int v1, int v2);
void DFS()
{

}
void BFS(){

}
void PrintGraph(GraphType* h);
void FreeGraph()
{

}
int main()
{
   char command;
   GraphType* h; // 정점의 헤드노드 생성
   h = malloc(sizeof(GraphType));
   int v;
   int v1,v2;
   int n;
   
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
      Initialize(h);
         break;
      case 'q': case 'Q':
         break;
      case 'v': case 'V':
         printf("Insert Vertax = ");
         scanf("%d", &v);
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

void Initialize(GraphType* h){
   int v;
   h->n = 0;
   for(v=0;v<10;v++)
   h->list[v] = NULL;
}

void InsertVertex(GraphType *h, int v)
{
   if(((h->n)+1) <10){ // 정점개수가 10보다 많아지면 오류메세지 출력
   printf("ERROR");
   return;
   }
  h->n++; // 정점을 늘려준다.

}