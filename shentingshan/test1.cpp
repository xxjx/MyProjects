#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <utility>
#include <functional>
using namespace std;
#define  pb push_back
const int maxn = 110;
const int N=100;
const int inf = 0x3f3f3f3f;
typedef vector<int> vi;
bool circle(vi v){
    if(v.size()<=1) return false;
    return v[0]==v[v.size()-1];
}
vi s,e;
int n,m;
int tot;
int head[N];
struct Edge{
    int to,nxt;
}edge[N*N*2];
void addEdge(int u,int v){
    edge[tot].to=v;
    edge[tot].nxt=head[u];
    head[u]=tot++;
}
int in[N],out[N];
void init(){
    s.clear();
    e.clear();
    tot=0;
    memset(head,-1,sizeof head);
    memset(in,0,sizeof in);
    memset(out,0,sizeof out);
}
vector<vi> ans;
queue<vi> q;
vi tmp;
bool isEnd(vi v){
    if(v.size()==0) return false;
    for(int i=0;i<v.size();i++)
    if(v[i]==e[0]) return true;
    return false;
}
bool ok(vi v,int val){
vi tmp=v;

    if(v.size()<=2) return true;

     for(int i=1;i<v.size();i++) if(v[i]==val) return false;

     return true;
}
bool isSub(vi v,vi u){
        int l1=v.size(),l2=u.size();
        if(l1>=l2) return  false;
        for(int i=0;i+l1-1<l2;i++){
            bool same=true;
            for(int j=0;j<l1 && same;j++) if(v[j]!=u[j+i]) same=false;
            if(same) return true;
        }
        return false;
}
void prime_path(){
     ans.clear();
     while(!q.empty()) q.pop();
     for(int a=1;a<=n;a++){
           tmp.clear();
           tmp.pb(a);
           q.push(tmp);
     }
     while(!q.empty()){
           vi now=q.front();q.pop();
           if(circle(now) || isEnd(now)){
            ans.pb(now);continue;
           }
           int u=now[now.size()-1];
           bool fi=false;
           for(int k=head[u];~k;k=edge[k].nxt){
                    int v=edge[k].to;
                    vi tmp=now;
                    if(ok(tmp,v)) {
                        fi=true;
                        tmp.pb(v);
                        q.push(tmp);
                    }
           }
           if(!fi) ans.pb(now);
     }
     int cnt=0;
     for(int i=0;i<ans.size();i++){
        bool sub=false;
        for(int k=0;k<ans.size() && sub==false;k++) if(k!=i && isSub(ans[i],ans[k]))  sub=true;
        if(sub) continue;
        cnt++;
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
     }
     cout<<"whole number: "<<cnt<<endl;
}
int main()
{
//#ifndef ONLINE_JUDGE
   // freopen("aaa","r",stdin);
//#endif
    init();
    cin>>n>>m;
    for(int b=1;b<=m;b++){
        int u,v;
        cin>>u>>v;
        addEdge(u,v);
        in[v]++;out[u]++;
    }
    for(int i=1;i<=n;i++){
        if(out[i]==0) e.pb(i);
        if(in[i]==0) s.pb(i);
    }
    prime_path();
    return 0;
}


