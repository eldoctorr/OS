#include<stdio.h>
int adj[50][50];
int tv[50];
int viscount(int);
int iszero(int);
int viscount(int v){
	int i,count=0;
	for(i=0;i<v;i++)
		if(tv[i]==1)
			count++;
	printf("%d \n",count);
return count;}
int iszero(int v){
	int c=0,i,j;
	for(i=0;i<v;i++)
		for(j=0;j<v;j++)
			if(adj[i][j]>0)
				c++;
	printf("%d \n",c);
	if(c>0)
		return 0;
	else
return 1;}
int main(){
	int nadj[50][50];
	int t[50];
	int min,i,j,m1,m2,flag,v;
	printf("Enter number of vertices:");
	scanf("%d",&v);
	printf("Enter adjacency matrix:\n");
	for(i=0;i<v;i++)
		for(j=0;j<v;j++){
			scanf("%d", &adj[i][j]);
			nadj[i][j]=0;}
	for(i=0;i<v;i++){
		tv[i]=0;
		t[i]=-1;}
		tv[0]=1;
	while(!(iszero(v))&& viscount(v)!=v){
		min=1000;
		flag=0;
		for(i=0;i<v;i++){
			for(j=0;j<v;j++){
				if(adj[i][j]<min && adj[i][j]>0 && tv[i]==1 && tv[j]==0){
					flag=1;
					min=adj[i][j];
					m1=i;
					m2=j;}}}
		if(flag==0)
			break;
		adj[m1][m2]=0;
		adj[m2][m1]=0;
		tv[m2]=1;
		nadj[m1][m2]=min;
		nadj[m2][m1]=min;
		printf("MIN:%d \n",min);
		printf("\nvisited:");
		for(i=0;i<v;i++)
			if(tv[i]==1)
				printf("%d ",i+1);
		printf("\nadj:\n");
		for(i=0;i<v;i++)
		{
			for(j=0;j<v;j++)
				printf("%d ",adj[i][j]);
			printf("\n");
		}
		printf("\n nadj:\n");
		for(i=0;i<v;i++)
		{
			for(j=0;j<v;j++)
				printf("%d ",nadj[i][j]);
			printf("\n");
		}
	nadj[m2][m1]=min;}
	if(viscount(v)!=v)
		printf("Spanning tree not possible");
	else{
		for(i=0;i<v;i++)
		{
			for(j=0;j<v;j++)
				printf("%d ",nadj[i][j]);
			printf("\n");
		}
	}
}
					
		
	