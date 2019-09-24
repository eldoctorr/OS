#include<stdio.h>
#define size 50
int pop();
void push(int);
int isEmpty();
void printstack();
int s[10];
int top=-1;
void push(int vertex){
	if(top==size-1){
		printf("Stack is full");
		}
	else{
		top++;
		s[top]=vertex;}}
int pop(){
	int p;
	if(top==-1)
		printf("Stack is empty");
	else
		p=s[top--];
	return p;}
int isEmpty(){
	if(top==-1)
		return 1;
	else
		return 0;}
void printstack(){
	int q;
	printf("Stack:");
	for(q=0;q<=top;q++)
		printf("%d  ",s[q]);
	printf("\n");}
int main(){
	int i,v,j,a,b,current,flag=0,vis,x=5;
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
					
	printf("Enter 2 vertices for the path:\n");
	scanf("%d", &a);
	scanf("%d", &b);
	push(a);
	visited[a-1]=1;
	while(1){
		vis=0;
		current=pop();
		for (i=0;i<v;i++)
			if(visited[i]==0&&adj[current-1][i]==1)
				vis++;
		if(vis>0)
			push(current);
printstack();
printf("Visited vertices:");
for(i=0;i<v;i++)
if(visited[i]==1)
printf("%d ",i+1);
printf("\n");
		for(i=0;i<v;i++){
			if(visited[i]==0&&adj[current-1][i]==1){
				push(i+1);
printstack();
				prev[i]=current;
				visited[i]=1;
				if(i+1==b){
					flag=1;
				break;}
				
printf("Previous vertices:");
				for(j=0;j<v;j++)
					printf("%d ",prev[j]);
				break;}}
				
				printf("\n");	
				if(isEmpty()||flag==1)
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
