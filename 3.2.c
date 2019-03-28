#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
clock_t strat, finish;
struct Node{
	int date;
	struct Node *next;
};
typedef struct Node NODE;
typedef NODE* N;
N Creat( int n );
void Print( N head );
void Free( N head );
void PrintLots(N L,N p);
int main(int argc, char *argv[]) {
	strat = clock();
	N L = Creat(10), P = Creat(5);
	PrintLots(L,P);
	Free(L);
	Free(P);
	finish = clock();
	printf("%f  seconds.\n",(float)(finish-strat)/CLOCKS_PER_SEC);
	return 0;
}
N Creat( int n )
{
	N head = NULL, p = NULL, pre = NULL;
	int i;
	for(i=0;i<n;i++){
		p = (N)malloc(sizeof(NODE));
		printf("Please input %d date.\n",i+1);
		scanf("%d",&p->date);
		if(head==NULL){
			head = p;
			pre = p;
		}
		else{
			pre->next = p;
			pre = p;
		}
		pre->next = NULL;
	}
	return head;
}
void Print( N head )
{
	N pre = head;
	int i = 1;
	while(pre!=NULL){
		printf("The %d date is %d.\n",i,pre->date);
	}
}
void Free( N head )
{
	N p = head, pre = NULL;
	while(p!=NULL){
		pre = p;
		p = p->next;
		free(pre);
	}
	printf("Free successfully\n");
}
void PrintLots(N l,N p)
{
	int i;
	N P = p;
	N L = l;
	while(P!=NULL){
		for(i=0;i<P->date-1;i++,L=L->next){
			;
		}
		printf("The date is %d.\n",L->date);
		L = l;
		P = P->next;
	}
}
