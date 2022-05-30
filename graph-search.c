#include <stdio.h>
#include <stdlib.h>


/* for graph */
typedef struct graph {
	int vertex;
	struct graph *link;	//인접리스트를 연결할 link
} Graph;

/* for stack */
#define MAX_STACK_SIZE		10	//max vertex size = 10
Graph* stack[MAX_STACK_SIZE];
int top = -1;

Graph* pop();
void push(Graph* aNode);

/* for queue */
#define MAX_QUEUE_SIZE		10 //max vertex size = 10
Graph* queue[MAX_QUEUE_SIZE];
int front = -1;
int rear = -1;

Graph* deQueue();
int enQueue(Graph* aNode);

/* functions that you have to implement */
int initializeGraph(Graph** h);
void freeGraph(Graph* h);
void InsertVertex(Graph* h,int);
int InsertEdge(Graph* h,int, int);
void DFS(Graph* h, int);
void BFS(Graph* h, int);
void PrintGraph(Graph* h);
void freeVertex(Graph *ptr);


int main()
{
	char command;
	int v1,v2;
    Graph* head=NULL;
	printf("----2018038045   [SIWON JOO] ----");
	do{
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf("                         Graph search                           \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize Graph       = z                                     \n");
		printf(" Insert Vertex          = v      Insert Edge                = e \n");
		printf(" Depth First Search     = d      Breath First Search        = b \n");
		printf(" Print Graph            = p      Quit                       = q \n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			initializeGraph(&head);
			break;

        case 'q': case 'Q':
			freeGraph(head);
			break;
        
        case 'v': case 'V':
            printf("Your vertex = ");
            scanf("%d",&v1);
			InsertVertex(head,v1);
			break;

        case 'e': case 'E':
            printf("Your vertex (v1) = ");
            scanf("%d",&v1);
            printf("Your vertex (v2) = ");
            scanf("%d",&v2);
			InsertEdge(head,v1,v2);
			break;

        case 'd': case 'D':
			printf("Your vertex = ");
            scanf("%d",&v1);
			DFS(head, v1);
			break;

        case 'b': case 'B':
			printf("Your vertex = ");
            scanf("%d",&v1);
			BFS(head, v1);
			break;

        case 'p': case 'P':
			PrintGraph(head);
			break;
		
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 0;
}

int initializeGraph(Graph** h){	
    if(*h!=NULL)	//빈 그래프가 아니라면 메모리 해제
        freeGraph(*h);

    *h=(Graph*)malloc(sizeof(Graph)*10);	//10개의 헤더노드를 나타낼 배열 생성
    for(int i=0;i<10;i++){
        (*h+i)->link=NULL;
        (*h+i)->vertex=-1;	//각 헤더노드의 vertex를 -1으로 초기화
    }

    top=-1;
    front = rear = -1;

    return 1;
}

void freeVertex(Graph *ptr){	//link를 이동하면서 메모리 해제
    if(ptr){
        freeVertex(ptr->link);
        free(ptr);
    }
}

void freeGraph(Graph* h){
    for(int i=0;i<10;i++){
        if((h+i)->link){	//헤더노드에 link가 존재한다면 연결된 모든 메모리 해제
           freeVertex((h+i)->link);
        }
    }

    free(h);	//헤더노드 동적할당 배열 메모리 해제
}

void InsertVertex(Graph* h,int v1){	//헤더노드 vertex 값을 해당 vertex 값으로 초기화
   if((h+v1)->vertex==v1){	//해당 vertex가 이미 존재한다면 다음을 출력 후 종료
	   printf("\n vertex is already in graph\n");
	   return;
   }
   (h+v1)->vertex = v1;
}

int InsertEdge(Graph* h,int v1, int v2){
	if((h+v1)->vertex==-1||(h+v2)->vertex==-1){	//해당 vertex가 존재하지 않는다면 다음을 출력
		printf("\n vertex is not in graph \n");
		return 0;
	}


	Graph* temp1 =(Graph*)malloc(sizeof(Graph));		//새로운 값이 들어갈 공간 생성
	Graph* temp2 =(Graph*)malloc(sizeof(Graph));		//새로운 값이 들어갈 공간 생성
	Graph* p=(h+v1);	//헤드노드의 해당되는 인덱스와 연결.

	temp1->vertex=v1;
	temp1->link=NULL;
	temp2->vertex=v2;
	temp2->link=NULL;

	while(1){
		if(p->vertex==v2){// 이미 연결되어있다면
			printf("\n Edge already exist \n");
			return 0;
		}

		if(!p->link){	//가리키는 노드가 없다면 연결
			p->link=temp2;	//v1 이 v2 를 가리킴
			break;
		}

		if(p->link->vertex > v2){	//인접리스트를 vertex 크기 순으로 정렬
			temp2->link=p->link;
			p->link=temp2;
			break;
		}

		else p=p->link;		// 다음 노드가 존재한다면 이동
	}

	p=(h+v2);
	for(;;){
		if(!p->link){ 
			p->link=temp1;	//v2 가 v1을 가리킴
			break;
		}
		if(p->link->vertex > v1){ //인접리스트를 vertex 크기 순으로 정렬
			temp1->link=p->link;
			p->link=temp1;
			break;
		}
		else p=p->link;
	}

	return 0;
}

/*Depth First Search (iteratvie)

*/

void DFS(Graph* h,int v){
;
}
/*Breath First Search
*/
void BFS(Graph* h, int v){
;
}
/*Graph 를 출력해주는 함수.*/
void PrintGraph(Graph* h){
	Graph* p=h;
    int i=0;
	while(i<10){
		p=h+i;
		for(int j=0;j<10;j++){	//link를 통해 이동하면서 존재하는 vertex를 출력, link가 없다면 다음 헤더노드로 이동
			if(p->vertex!=-1){	//p->vertex가 -1 이라면 헤더노드에 vertex가 insert 되지 않은 상태이므로 출력하지 않는다.
				printf(" [%d] ",(p->vertex));
			}
			if(p->link){
				p=p->link;
			}
			else
				break;
		}
		printf("\n");
        i++;
	}
}

Graph* pop()	
{

}

void push(Graph* aNode)
{	
}

Graph* deQueue()	
{
	
}

int enQueue(Graph* aNode)
{

}
