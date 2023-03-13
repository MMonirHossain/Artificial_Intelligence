#include<bits/stdc++.h>
using namespace std;
#define limit 10

int n,m;
vector<int> graph[limit];
bool visit[limit];
int color[limit];
bool option[limit];


void init_graph(){
    int a,b;
    for(int i=0;i<=n;i++){visit[i]=0;color[i]=-1;option[i]=0;}

    for(int i=0;i<m;i++){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

}


void graph_color(int nod,int parent){
    if(visit[nod]){return;}

    cout<<nod<<" ";
    //visit[nod]=1;
    for(int i=0;i<3;i++){
        if(color[parent]!=i){color[nod]=i;cout<<color[nod]<<" "<<i<<"\n";break;}
    }

    for(int i=0;i<graph[nod].size();i++){
        graph_color(graph[nod][i],nod);
    }

}




int main(){

    freopen("in.txt","r",stdin);
    cin>>n>>m;
    init_graph();

    cout<<"\n";
    for(int i=1;i<=n;i++){
        cout<<i<<" "<<color[i]<<"\n";
    }

    graph_color(1,0);


    cout<<"\n";
    for(int i=1;i<=n;i++){
        cout<<i<<" "<<color[i]<<"\n";
    }


return 0;
}
