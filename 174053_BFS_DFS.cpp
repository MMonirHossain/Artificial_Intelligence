#include<bits/stdc++.h>
using namespace std;
#define limit 1000
int n,m;
pair<int,int> start,goal;

char dataa[limit][limit];
pair<int,int> parent[limit][limit];
bool visit[limit][limit];
pair<int,int> directions[4]={{-1,0},{1,0},{0,1},{0,-1} };

int visited_node_number=0;
int expanded_node_number=0;

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


void bfs(){
    queue<pair<int,int> > q;
    q.push(start);
    bool ans=false;
    expanded_node_number++;
    visit[start.first][start.second]=1;


    while(!q.empty()){
        pair<int,int> x=q.front();
        q.pop();
        visited_node_number++;


        for(int i=0;i<4;i++){
            pair<int,int> dir=directions[i];
            int a=x.first+dir.first;
            int b=x.second+dir.second;
            if(!visit[a][b] && valid(a,b) && dataa[a][b]=='1'){
                visit[a][b]=1;
                expanded_node_number++;
                q.push({a,b});
                parent[a][b]=x;
                if(visit[goal.first][goal.second]){ans=true;break;}

            }
        }
        if(ans){break;}

    }

    if(ans){
        vector<pair<int,int> > ans_path;

        pair<int,int> temp=goal;
        while(temp!=start){
            ans_path.push_back(temp);
            temp=parent[temp.first][temp.second];
        }
        ans_path.push_back(start);

        cout<<"Minimum lenngth: "<<ans_path.size()<<"\n";

        int sz=ans_path.size();
        for(int i=sz-1;i>=0;i--){
            cout<<"("<<ans_path[i].first<<","<<ans_path[i].second<<")";
            if(i!=0){cout<<"->";}
            else cout<<"\n";
        }

       cout<<"Total Visited Node: "<<visited_node_number<<"\n";
        cout<<"Total Expanded Node: "<<expanded_node_number<<"\n";
    }
    else{
        cout<<"No Valid Path Found\n";
    }

}//end of bfs

void dfs(){


    stack<pair<int,int> > st;
    st.push(start);
    bool ans=false;
    expanded_node_number++;



    while(!st.empty()){
        pair<int,int> x=st.top();
        st.pop();
        visited_node_number++;
        visit[x.first][x.second]=1;

        if(x==goal){ans=true;break;}

        for(int i=0;i<4;i++){
            pair<int,int> dir=directions[i];
            int a=x.first+dir.first;
            int b=x.second+dir.second;
            if(!visit[a][b] && valid(a,b) && dataa[a][b]=='1'){
                expanded_node_number++;
                st.push({a,b});
                parent[a][b]=x;
            }
        }
    }

    if(ans){
        vector<pair<int,int> > ans_path;

        while(goal!=start){
            ans_path.push_back(goal);
            goal=parent[goal.first][goal.second];
        }
        ans_path.push_back(start);

        cout<<"Founded path length: "<<ans_path.size()<<"\n";

        int sz=ans_path.size();
        for(int i=sz-1;i>=0;i--){
            cout<<"("<<ans_path[i].first<<","<<ans_path[i].second<<")";
            if(i!=0){cout<<"->";}
            else cout<<"\n";
        }

       cout<<"Total Visited Node: "<<visited_node_number<<"\n";
        cout<<"Total Expanded Node: "<<expanded_node_number<<"\n";
    }
    else{
        cout<<"No Valid Path Found\n";
    }


}

int main(){

freopen("in.txt","r",stdin);

cin>>m>>n;
init();
input_source_goal();
input_data_grid();

cout<<":::Output of the bfs:::\n\n";
bfs();

cout<<"\n\n\n\n\n";

visited_node_number=0;
expanded_node_number=0;
init();

cout<<":::Output of the dfs:::\n\n";
dfs();


cout<<"By Changing Source and Goal in the in.txt file...\n Characteristics of DFS and BFS Can be observed\n\n\n\n";

return 0;
}

