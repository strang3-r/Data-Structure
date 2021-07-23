// High_Score.cpp

/*Bellaman Ford's Algorithm*/

/*<!-- Created By Black Devil -->*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ff                 first
#define ss                 second
#define endl               "\n"
#define ll                 long long
#define ld                 long double
#define loop(a, b, c)      for(ll (a) = (b); (a)<=(c); (a)++)
#define looprev(a, b, c)   for(ll (a) = (b); (a)>=(c); (a)--)
#define pb                 push_back
#define mp                 make_pair
#define pii                pair<ll, ll>
#define vi                 vector<ll>
#define mii                map<ll, ll>
#define pqb                priority_queue<ll>
#define pqs                priority_queue<int, vi, greater<ll> >
#define setbits(x)         __builtin_popcountll(x)
#define zrobits(x)         __builtin_ctzll(x)
#define mod                1000000007
#define inf                1e18
#define ps(x, y)           fixed<<setprecision(y)<<x
#define mk(arr,n,type)     type *arr = new type[n];
#define w(t)               int x; cin>>x; while(x--)
// mt19937                    rng(chrono::steady_clock::now,time_since_epoch(),count());
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> pbds;

    
void file_i_o(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 	#ifndef ONLINE_JUDGE
		freopen("C:\\Users\\singh\\OneDrive\\Desktop\\input.txt", "r", stdin);
		freopen("C:\\Users\\singh\\OneDrive\\Desktop\\output.txt", "w", stdout);
	#endif
}

const int mxN=2.5e3;
int n, m;
ll ans[mxN];
ll d[mxN];
vector<array<ll, 2>>adj[mxN];
vector<int> adj2[mxN];
bool vis[mxN], vis2[mxN];

void dfs(int u){
	vis[u]=1;
	for(int v: adj2[u])
		if(not vis[v])
			dfs(v);
}

void dfs2(int u){
	vis2[u]=1;
	for(array<ll, 2> v: adj[u])
		if(not vis2[v[1]])
			dfs2(v[1]);
}

int main(int argc, char const *argv[])
{

	file_i_o();

	clock_t start, end;
    start = clock();

	cin >> n >> m;
	loop(i, 0, m-1){
		int a, b, c;
		cin>>a>>b>>c, --a, --b;
		adj[a].pb({c, b});
		adj2[b].pb(a);
	}
	// priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>>pq;

	// pq.push({0, 0});

	dfs(n-1);
	dfs2(0);

	memset(d, 0xc0, sizeof(d));
	d[0] = 0;

	for(int i = 0; i<2*n; ++i){
		bool ch = 0; 
		loop(j, 0, n-1)
			for(array<ll, 2> a: adj[j]){
				// d[a[1]] = max(d[a[1]], d[j]+a[0]);
				/*if(a[1]==n-1)
					cout<<j<<" "<<d[j]+a[0]<<endl;*/
				if(d[j]+a[0]>d[a[1]]){
					if(vis[a[1]] and vis2[a[1]])
						ch = 1;
					d[a[1]]=d[j]+a[0];
					// cout<<a[1]<<" "<<d[a[1]]<<endl;
				}
			}
		if(i>=n-1 and ch){
			cout<<-1;
			return 0;
		}
		// ans[i] = d[n-1];
	}

	/*if(n>1 and ans[n-1]<ans[n-1])
		cout<<-1;
	else
		cout<<ans[n-1];*/

	cout<<d[n-1];


	end = clock();
	
	double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
    cerr<<"\nTime : "<<fixed<<time_taken<<setprecision(5)<<" s \n";
    cerr<<"Coded By Black Devil"<<endl;
	return 0;
}