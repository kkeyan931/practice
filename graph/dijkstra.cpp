#include <bits/stdc++.h>

using namespace std;


int INF = 1000;
int V;
int start;
int cost[100][100];
int dist[100] = {INT_MAX};
int parent[100];
bool visited[100]={0};


void display(){

    for(int i=0;i<V;++i){

        int parNode = parent[i];

        while(parNode!=start){
            cout << "<-" <<parNode-1 ;
            parNode=parent[parNode-1];
        }
        cout << endl;
    }


}

int findMin(){
    
    int minVertex=-1;
    int minimum=INT_MAX;

    for(int i=0;i<V;++i){
        if(!visited[i] && dist[i]<minimum){
            minimum=dist[i];
            minVertex=i;
        }
    }
    return minVertex;
}

void init(){

    for(int i=0;i<V;++i){
        dist[i]=cost[start][i];
        parent[i]=i;
    }
    visited[start]=1;

}

void dijkstra(){

    init();
    for(int i=0;i<V;++i){
        int minVertex = findMin();
        if(minVertex==-1){
            break;
        }
        visited[minVertex]=true;

        for(int i=0;i<V;++i){
            if(!visited[i] && cost[minVertex][i]!=INF && dist[i] > dist[minVertex]+cost[minVertex][i]){
                dist[i]=dist[minVertex]+cost[minVertex][i];
                parent[i]=minVertex;
            }
        }
    }
}

int main(){

    cout  << "Enter number of matrices" << endl;

    
    cin >> V;

    cout << "Enter the adjacency matrix" << endl;

    for(int i=0;i<V;++i){
        for(int j=0;j<V;++j){
            cin >> cost[i][j];
        }
    }

    cout << "Enter the starting vertex"<< endl;
    cin >> start;

    dijkstra();

    cout << "Distance are" <<  endl;
    for(int i=0;i<V;++i){
        cout << dist[i] << " ";
    }    
    cout << endl;
    for(int i=0;i<V;++i){
        cout << parent[i] << " ";
    }    
    cout << endl;

    display();




}