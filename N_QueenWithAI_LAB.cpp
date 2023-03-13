#include<bits/stdc++.h>
using namespace std;

#define N 8
//The grid
int grid[N+1][N+1];

//To Track the conflict in row,diagonal1,and diagonal2
int conf_row[2*N+1];
int conf_dig1[2*N+1];
int conf_dig2[2*N+1];

//Contain at which row the queen placed for each column
int node_of_col_on_row[N+1];

//supporting data
int max_conf;

// This will input the initial configuration
// and the needed initial setup will cover
void input_grid(){
    char ch;
    for(int i=1;i<=8;i++){
        for(int j=1;j<=8;j++){
            cin>>ch;
            if(ch=='0'){grid[i][j]=0;}
            else grid[i][j]=1;
        }
    }

    for(int i=1;i<=8;i++){
        for(int j=1;j<=8;j++){
            if(grid[i][j]==1){
                node_of_col_on_row[i]=j;
                conf_row[i]++;
                conf_dig1[i+j]++;
                conf_dig2[N+i-j]++;
                break;
            }
        }
    }

    //for(int i=1;i<=2*N;i++){cout<<conf_row[i]<<" ";}cout<<"\n";
    //for(int i=1;i<=2*N;i++){cout<<conf_dig1[i]<<" ";}cout<<"\n";
    //for(int i=1;i<=2*N;i++){cout<<conf_dig2[i]<<" ";}cout<<"\n";
}

//This will return how many node conflicting with this
int conflict_of_node(int x){
    int i=node_of_col_on_row[x];
    int ans=0;
    if(conf_row[i]){ans=ans+conf_row[i]-1;}
    if(conf_dig1[i+x]){ans=ans+conf_dig1[i+x]-1;}
    if(conf_dig2[N+i-x]){ans=ans+conf_dig2[N+i-x]-1;}
    return ans;
}


//This function will return the huiristics of the whole state at this configuration
int huiristics(){
    int total=0;
    for(int i=1;i<=N;i++){
        total=total+conflict_of_node(i);
    }
    return total;
}

//This function for calculating the node which have maximum
//conflict with other now.
int max_conflicting_node(){
    max_conf=conflict_of_node(1);
    int conf_node=1;
    for(int i=2;i<=N;i++){
        int now=conflict_of_node(i);
        if(now>max_conf){max_conf=now;conf_node=i;}
    }
    return conf_node;
}

//This function will destroy the queen x
void destroy(int x){
    int i=node_of_col_on_row[x];
    grid[i][x]=0;
    conf_row[i]--;
    conf_dig1[i+x]--;
    conf_dig2[N+i-x]--;
    node_of_col_on_row[x]=0;
}

//This function will repair a queen in column=col and row=ro
void repair(int col,int ro){
    grid[ro][col]=1;
    conf_row[ro]++;
    conf_dig1[ro+col]++;
    conf_dig2[N+ro-col]++;
    node_of_col_on_row[col]=ro;
}


//This function will select candidate queen to move in its column
void find_answer(){
    int node=max_conflicting_node();
    int lowest_h=INT_MAX;
    int lowest_node;


    for(int i=1;i<=N;i++){
        destroy(node);
        repair(node,i);
        int local_h=huiristics();
        if(local_h<lowest_h){lowest_h=local_h;lowest_node=i;}
    }

    repair(node,lowest_node);

}


int main(){
freopen("in.txt","r",stdin);

input_grid();

for(int i=1;i<=N;i++){
find_answer();
}

return 0;
}

