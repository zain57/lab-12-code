
 
#include <stdio.h>
#include <limits.h>
 using namespace std;

#define V 8
 
/
int minKey(int key[], bool mstSet[])
{
  
   int min = INT_MAX, min_index;
 
   for (int v = 0; v < V; v++)
     if (mstSet[v] == false && key[v] < min)
         min = key[v], min_index = v;
 
   return min_index;
}
 

int printMST(int parent[], int n, int graph[V][V])
{
   printf("Edge   Weight\n");
   for (int i = 1; i < V; i++)
      printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}
 

void primMST(int graph[V][V])
{
     int parent[V]; 
     int key[V];  
     bool mstSet[V];  
 
     
     for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;
 
     
     key[0] = 0;     
     parent[0] = -1; 
 
     
     for (int count = 0; count < V-1; count++)
     {
        
        int u = minKey(key, mstSet);
 
       
        mstSet[u] = true;
 
        
        for (int v = 0; v < V; v++)
 
           
          if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
             parent[v]  = u, key[v] = graph[u][v];
     }
 
     
     printMST(parent, V, graph);
}
 
 

int main()
{
   
   int graph[V][V] = {{1, 8, 0, 0, 0,10,0,5},
                      {8, 0, 4, 0, 4,4,0,4},
                      {0, 4, 0, 3, 0,3,0,0},
                      {0, 0, 3, 0, 1,6,2,0},
                      {0, 4, 0, 1, 0,0,3,0},
	                 {10, 4, 3, 6, 0,0,0,0},
                      {0, 0, 0, 2, 3,0,0,3},
                      {5, 4, 0, 0, 0,0,3,0},

          
		  
		  
		             };
 
  
    primMST(graph);
 
    return 0;
}

