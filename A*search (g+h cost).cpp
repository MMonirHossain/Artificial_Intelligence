#include<bits/stdc++.h>
using namespace std;
#define limit 1000
const float inf=100005.5;
int n,m;
pair<int,int> start,goal;

int visited_node_number=0;
int expanded_node_number=0;

char dataa[limit][limit];
pair<int,int> parent[limit][limit];
bool visit[limit][limit];
pair<int,int> directions[]={{-1,0},{1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1} };
float cost[]={1,1,1,1,1.5,1.5,1.5,1.5};

void init(){
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            visit[i][j]=0;
        }
    }
}

void input_source_goal(){
    int a,b;
    cin>>a>>b;
    start={a,b};
    cin>>a>>b;
    goal={a,b};
}
void input_data_grid(){
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>dataa[i][j];
        }
    }
}

bool valid(int a,int b){
    if(a>=1&& a<=m && b>=1&& b<=n){return true;}
    else return false;
}



//g+h version
float h_cost(pair<int,int> node){
    int dx=abs(goal.first-node.first);
    int dy=abs(goal.second-node.second);
    return 0.5*(min(dx,dy))+max(dx,dy);
}

//Dijkstra part start

float dist[limit][limit];
bool operator < (pair<int,int> A, pair<int,int> B)
{
   return dist[A.first][A.second]+h_cost(A) > dist[B.first][B.second]+h_cost(B);
}

void dijkstra()
{
     for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            dist[i][j]=inf;
        }
     }

     dist[start.first][start.second] = 0.0;

     priority_queue< pair<int,int> > pq;

     pq.push(start);
     visit[start.first][start.second]=1;
     expanded_node_number++;

     while(!pq.empty())
     {
        pair<int,int> x = pq.top();
        pq.pop();
        visited_node_number++;
        if(x==goal)break;

        for(int i=0;i<8;i++){
            int a=x.first+directions[i].first;
            int b=x.second+directions[i].second;
            float now=dist[x.first][x.second];

            if( valid(a,b) && dataa[a][b]=='1' && now+cost[i]<dist[a][b]){
                dist[a][b]=now+cost[i];
                parent[a][b]=x;
                expanded_node_number++;
                pq.push({a,b});
            }
        }

     }

    //showing all the dist values

//     for(int i=1;i<=m;i++){
//        for(int j=1;j<=n;j++){
//            cout<<setw(8)<<dist[i][j]<<" ";
//        }cout<<"\n";
//     }

     cout<<"Distance of Minimmum path: "<<dist[goal.first][goal.second]<<"\n";

     vector<pair<int,int> > ans_path;

        while(goal!=start){
            ans_path.push_back(goal);
            goal=parent[goal.first][goal.second];
        }
        ans_path.push_back(start);


        int sz=ans_path.size();
        for(int i=sz-1;i>=0;i--){
            cout<<"("<<ans_path[i].first<<","<<ans_path[i].second<<")";
            if(i!=0){cout<<"->";}
            else cout<<"\n";
        }

        cout<<"Total Visited Node: "<<visited_node_number<<"\n";
        cout<<"Total Expanded Node: "<<expanded_node_number<<"\n";

}


int main(){

freopen("in.txt","r",stdin);

cin>>m>>n;


init();
input_source_goal();
input_data_grid();

//bfs();


dijkstra();

return 0;
}



