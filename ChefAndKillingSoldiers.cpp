// QUESTION 
// Can you help Chef..
/*

Chef is now a trained assassin, and his aim is to destroy and kill his enemy to avenge his father’s death. Being a trained assassin, Chef can easily enter into enemy’s territory.

He uses this ability to enter the area where the army is residing into their tents. There are ‘N’ number of tents in this area having ID 1,2,3..N . Some tents may be connected to each other via ropes. Chef wants to kill and injure as many warriors of army by burning the tents.

If there are ‘c’ no. of tents which are connected to each other via ropes, then Chef can light any one of these connected tents as warriors/soldiers of other ‘c-1’ tents will be alarmed by this activity. Suppose, Chef lights tent ‘X’ out of these c tents, then all the warriors of the tent ‘X’ will get killed and the warriors which are in the rest of the connected tents i.e. c-1 tents will get injured.

See sample explanation for more details.

Note –

If tent 1 is connected to tent 2, the tent 2 is also connected to tent 1.
If tent 1 is connected to tent 2 and tent 2 is connected to tent 3, then tent 1 is also connected with tent 3.

Now, Chef wants to kill maximum no. of soldiers of his enemie's army. Can you tell in advance how many soldiers will be killed and how many will get injured by this act of Chef? Also output the number (ID) of tents which will be lighten by Chef. If more than one connected tents can be lighten then CHef will choose to light the tent whose ID will be minimum.

Input:
First line contains a single integer 'T' the number of testcases.
for the next following line... 

First line will contain two space separated integers N and M, i.e. the total number of tents and total number of connections between the tents.

Second line will contain ‘N’ space separated integers denoting the number of soldiers in i’th tent 1<=i<=N.

Next ‘M’ lines contains two spaced separated ‘a’ and ‘b’ denoting Tent ‘a’ and Tent ‘b’ are connected to each other via rope.

Output:

Two space separated integers denoting number of soldiers killed and number of soldiers injured respectively.

Next line contains the space separated ID of the lighten tents in increasing order of their ID’s.

Constraints:

    1<= N<= 10000
    1<= M<= 10000
    1<= No. of soldiers in each tent <=10000
Sample Input:
6 4
3 4 3 2 4 5
1 3
3 5
5 2
4 6
Sample Output:
9 12
2 6 

Explaination:
 Chef can choose 2nd and 6th tent.

Time Limit: 1 sec
Memory Limit: 64kb

*/
#include <bits/stdc++.h>
#define pb push_back
#define ll long long int
#define f first
#define s second
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
bool compare(const pair<ll,ll>&p1,const pair<ll,ll>&p2) {
    if(p1.f==p2.f) {
        return p1.s<p2.s;
    }
    return p1.f>p2.f;
}
void solve() {
    ll n,m,i,j;
    cin>>n>>m;
    vector<pair<ll,ll>> v;
    vector<ll> v1;
    vector<ll> graph[n+1];
    for(i=0;i<n;i++) {
        ll x;
        cin>>x;
        v1.pb(x);
        v.pb({x,i+1});
    }
    sort(v.begin(),v.end(),compare);
    for(i=0;i<m;i++) {
        ll u,v;
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    vector<ll> ans;
    map<ll,ll> visited;
    ll soldiersKilled=0,soldiersinjured=0;
    for(i=0;i<n;i++) {
        if(!visited[v[i].s]) {
            stack<ll> st;
            ans.pb(v[i].s);
            st.push(v[i].s);
            visited[v[i].s]=1;
            soldiersKilled+=v[i].f;
            while(!st.empty()) {
                ll cur=st.top();
                st.pop();                
                for(j=0;j<graph[cur].size();j++) {
                    if(!visited[graph[cur][j]]) {
                        soldiersinjured+=v1[graph[cur][j]-1];
                        visited[graph[cur][j]]=1;
                        st.push(graph[cur][j]);
                    }
                }
            }
        }
    }
    sort(ans.begin(),ans.end());
    cout<<soldiersKilled<<" "<<soldiersinjured<<"\n";
    for(i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}
int main() {
    ll test;
    fast;
    cin>>test;
    while(test--) {
        solve();
    }
    return 0;
}