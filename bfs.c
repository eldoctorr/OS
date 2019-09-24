#include<stdio.h>
#define size 50
int dequeue();
void enqueue(int);
int isEmpty();
void printqueue();
int q[50];
int front=-1,rear=-1;
void enqueue(int vertex){
	if(front==size-1){
		printf("Queue is full");
		}
	else{
		rear++;
		q[rear]=vertex;}}
int dequeue(){
	int p;
	if(front==rear)
		printf("Queue is empty");
	else
		p=q[++front];
	return p;}
int isEmpty(){
	if(front==rear)
		return 1;
	else
		return 0;}
void printqueue(){
	int i;
	printf("Queue:");
	for(i=front+1;i<=rear;i++)
		printf("%d  ",q[i]);
	printf("\n");}
int main(){
	int i,v,j,a,b,current,flag=0,rem;
	int adj[50][50];
	int visited[50];
	int prev[50];
	printf("Enter number of vertices:");
	scanf("%d",&v);
	printf("Enter adjacency matrix:\n");
	for(i=0;i<v;i++){
		for(j=0;j<v;j++)
			scanf("%d", &adj[i][j]);}
	for(i=0;i<v;i++){
		visited[i]=0;
		prev[i]=-1;}
					for(i=0;i<v;i++){
						for(j=0;j<v;j++)
							printf("%d ", adj[i][j]);
						printf("\n");}
	printf("Enter 2 vertices for the path:\n");
	scanf("%d", &a);
	scanf("%d", &b);
	enqueue( a );
printqueue();
	while(1){
printqueue();
		current=dequeue();
		visited[current-1]=1;
		rem++;
printf("Visited vertices:");
for(i=0;i<v;i++)
if(visited[i]==1)
printf("%d ",i+1);
printf("\n");
		for(i=0;i<v;i++){
			if(visited[i]==0&&adj[current-1][i]==1){
				enqueue(i+1);
				visited[i]=1;
				prev[i]=current;
				if(i+1==b){
					flag=1;
		
		break;}}}
				printf("Previous vertices:");
				for(i=0;i<v;i++)
					printf("%d ",prev[i]);
				printf("\n");
		if(flag==1||isEmpty())
				break;
		}
	if(flag==0)
		printf("No path exists");
	else{
	printf("Path from vertex %d to vertex %d:",a,b);
	printf("%d ",b);
	i=0;
	while(1){
		b=prev[b-1];
		if(b==-1)
			break;
		printf("%d ",b);
}	}		
return 0;
	}
