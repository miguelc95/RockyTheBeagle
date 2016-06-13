//
//  main.cpp
//  RockyTheBeagle
//
//  Created by Miguel Cuellar on 3/31/16.
//  Copyright © 2016 Miguel Cuellar. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int V, Matriz[20][20],icont;

int minDistance(int dist[], bool sptSet[])
{
    // Initialize min value
    int min = 100000, min_index;
    
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    
    return min_index;
}

// A utility function to print the constructed distance array
void printSolution(int dist[], int n)
{
    cout<<"Case "<<icont<<":"<<max_element(dist, dist+5);
    
   /* printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);*/
}

// Funtion that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int src)
{
    int mayor=-1;
    char letra;
    int dist[V];     // The output array.  dist[i] will hold the shortest
    // distance from src to i
    
    bool sptSet[V]; // sptSet[i] will true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized
    
    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
        dist[i] = 100000, sptSet[i] = false;
    
    // Distance of source vertex from itself is always 0
    dist[src] = 0;
    
    // Find shortest path for all vertices
    for (int count = 0; count < V-1; count++)
    {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in first iteration.
        int u = minDistance(dist, sptSet);
        
        // Mark the picked vertex as processed
        sptSet[u] = true;
        
        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++){
            
            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && Matriz[u][v] && dist[u] != 100000
                && dist[u]+Matriz[u][v] < dist[v])
                dist[v] = dist[u] + Matriz[u][v];
        }
    }
    
    int lugar = 0;
    for (int iL = 0; iL<V; iL++) {
        if (mayor< dist[iL]) { //BUSCAR MAYOR
            mayor = dist[iL];
            lugar = iL;
            
            // cout << pos << " " << mayor << endl;
        }
    }
    
    letra=lugar+65;
    cout<<"Case "<<icont<<": "<<letra<<endl;

    // print the constructed distance array
   // printSolution(dist, V);
}

int main() {
    int casos, k,distancia;
    char uno,dos;
    
    
    
    cin>>casos;
    for (icont=1; icont<=casos; icont++) { //CASOS
        cin>>V>>k;
        for (int ix=0; ix<V; ix++) {
            for (int iy=0; iy<V; iy++) {
                Matriz[ix][iy]=0;
            }
        }
        
        
        for (int i=0; i<V; i++) { //LLENAR EN CEROS
            Matriz[i][i]=0;
        }
        
        for (int ix=0; ix<k; ix++) { //MATRIZ ADYACENCIAS
            cin>>uno>>dos>>distancia;
            Matriz[uno-65][dos-65]=distancia;
            Matriz[dos-65][uno-65]=distancia;
            
        }
        
        
        dijkstra(0);
        
        
  
        
        
    }//CIERRA CASOS
    
    
        return 0;
}
