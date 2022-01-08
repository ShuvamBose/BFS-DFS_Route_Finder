#include<stdio.h>
#include<stdlib.h>

int ss[4],cc=0;
int ff[100];
int sparseMatric[10][10];

void read_ints ()
{
  FILE* file = fopen("input.txt", "r");
  int i = 0;
	int counter=0,ii=0;
  
  while(!feof (file))
    {  
      fscanf (file, "%d", &i);     
	  
	  if(counter<4)
	  {
		  ss[ii]=i;++i; 
		 
		  ++ii;
	  }
	  ++counter;
	  if(counter>=4)
	  {
		  ff[counter-4]=i;++i;
	  }
    }
	
	fclose(file);

}

void array_to_matrix(int row, int col)
{
    int i,j,k=0;     

    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            sparseMatric[i][j] = ff[k+1];
            k++;
        }
    }
}


void bfs(int prev_i,int prev_j)
{
	int i=0;int j=0;
	FILE *fp;
	fp=fopen(" outbfs.txt","w");
	if(fp == NULL)
   {
      printf("Error!");   
      exit(1);             
   }
	printf("\n(%d , %d) i:,j:",i,j);
	fprintf(fp,"(%d , %d)\n",i,j);
	while(i<=9 &&i>=0)
	{
		while(j<=9 &&j >=0)
		{ 
			prev_i=i;
			prev_j=j;
			if( sparseMatric[i][j+1]==0)	++j;
			else if( sparseMatric[i][j+1]==1 && sparseMatric[i+1][j]==0)	++i;
			else {
				--j;
				if(sparseMatric[i+1][j]==0)	++i;
				
			}
			
			fprintf(fp,"(%d , %d)\n",i,j);
			printf("\n(%d , %d) i:,j:",i,j);
			if(i==9 && j==9)	{fclose(fp); break;}
		} if(i==9 && j==9)	{ printf("\nFile successefully closed .\n"); break;}
		printf("\n");
	}
}

void dfs(int prev_i,int prev_j)
{
	int i=0;int j=0;
	printf("\n(%d , %d) i:,j",i,j);
	FILE *fp;
	fp=fopen(" outdfs.txt","w");
	if(fp == NULL)
   {
      printf("Error!");   
      exit(1);             
   }
	fprintf(fp,"(%d , %d)\n",i,j);
	while(i<=9 && i>=0)
	{
		while(j<=9 && j>=0)
		{
			prev_i=i;
			prev_j=j;
			
			if(sparseMatric[i+1][j]==0)		++i;
			else if(sparseMatric[i+1][j]==1 && sparseMatric[i][j+1]==0)	++j;
			else{
				--i;
				if(sparseMatric[i][j+1]==0)	++j;
			}
			printf("\n(%d , %d) i:,j",i,j);
			fprintf(fp,"(%d , %d)\n",i,j);
			
			if(i==9 && j==9)	{fclose(fp); break;}
		}
		if(i==9 && j==9)	{ printf("\nFile successefully closed .\n"); break;}
		printf("\n");
	}
}

void main()
{
	read_ints();
	int i=4;

	array_to_matrix(10,10);
	
	printf("\nAdjacency matrix:\n"); 
		
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            printf("%d ",sparseMatric[i][j]);
            
        }
		printf("\n");
    }
	int prev_i=0,prev_j=0;
	
	printf("\n BFS implementation of path :\n");
	bfs(prev_i,prev_j);
	printf("\n DFS implementation of path :\n");
	dfs(prev_i,prev_j);
}