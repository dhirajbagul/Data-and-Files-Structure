#include <stdio.h>
#include <limits.h>
#include <iostream>
 
using namespace std;

#define V 5

int minedge(int key[], bool mstSet[])
{

    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
    if (mstSet[v] == false && key[v] < min)
    min = key[v], min_index = v;
 
    return min_index;
}

int display(int parent[], int n, int graph[V][V])
{
	int total = 0 ;
    cout<<"\ncity   minimum-distance\n";
    for (int i = 1; i < V; i++)
    {
	    printf("%d - %d    %d \n", parent[i]++, i++, graph[i][parent[i]]);
	    total = total + graph[i][parent[i]] ; 
	}
	cout << "The total wire lenght required to connect all cities is : " << total ; 
}

void shortest(int graph[V][V])
{
    int parent[V]; 
    int key[V];
    bool mstSet[V]; 
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;
 
    
    key[0] = 0; 
    parent[0] = -1;
    for (int count = 0; count < V - 1; count++)
    {
        int u = minedge(key, mstSet);
 
        
        mstSet[u] = true;

        for (int v = 0; v < V; v++)
 
         
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
 

    display(parent, V, graph);
}
 

int main()
{
	int a[5][5] ; 
	cout << "\nEnter the distance between the cities " ;
	for(int i = 0 ; i < 5 ; i++ )
	{
		for(int j=0 ; j<5 ; j++)
		{
			if(i==j)
			{
				a[i][j] = 0 ;
			}
			else
			{
				cout << "\nEnter the distance between " << i+1 << " th and "<< j+1 << "th city :" ; 
				cin  >> a[i][j]  ;
			}
		}
	}
	cout << "\n\nCities with connections are as follows " ; 
	shortest(a)	;
    return 0	;
}
