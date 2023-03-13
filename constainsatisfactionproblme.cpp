#include<bits/stdc++.h>

using namespace std;


bool used[10];
int F=0,T=0,U=0,W=0,R=0,O=0,x1=0,x2=0,x3=0;

int temp;

bool satisfy(){
    set<int> s;
    s.insert(F);  s.insert(T); s.insert(U); s.insert(W);  s.insert(R);  s.insert(O);

    if(s.size()==6){return true;}
    else return false;
}

void choice(int cnt){
    if(cnt==3 && satisfy() ){printf("Answer::O= %d, R= %d, W= %d, U= %d, T= %d, F= %d\n",O,R,W,U,T,F);return;}
    if(cnt>=3)return;

    //cout<<"Cnt="<<cnt<<"\n";
    //printf("O= %d, W= %d, T= %d, U= %d, R= %d, F= %d\n",O,W,T,U,R,F);

    int l,r=9;
    if(cnt==2){l=6;}
    else l=0;

    for(int i=l;i<=r;i++){
        if(used[i]==0){
            if(cnt==0){O=i;R=(O+O)%10;x1=(O+O)/10;}
            else if(cnt==1){W=i;U=(W+W+x1)%10;x2=(W+W+x1)/10;}
            else if(cnt==2){T=i;temp=(T+T+x2)%10;x3=(T+T+x2)/10;   if(temp!=O || x3==0){continue;}else{F=x3;} }
            used[i]=1;
            choice(cnt+1);
            used[i]=0;
        }
    }

}



int main(){

//freopen("out.txt","w",stdout);

for(int i=0;i<10;i++){used[i]=0;}

choice(0);

return 0;
}
