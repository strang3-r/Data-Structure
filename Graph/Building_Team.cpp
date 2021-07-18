// Building_Team.cpp

// Graph Theory :- Bipartite Graph,  Color Problem

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
/* <!-- #ifndef ONLINE_JUDGE
			freopen("input.txt", "r", stdin);
			freopen("output.txt", "w", stdout);
		#endif --> */
}

int n, m;
vector<vector<int>> g;
vector<int>color;
vector<bool> vis;

bool dfs(int u, int c, int par) {
	vis[u] = true;
	color[u] = c;

	for(auto v: g[u]){
		if(v == par) continue;
		if(color[v] == 0){
			if(not dfs(v, (color[u]^3), u))
				return false;
		}
		if(color[v] == color[u])
			return false;
	}
	return true;
}

bool color_all() {
	for (int i = 0; i <= n; ++i)
	{
		if(not vis[i])
			if(not dfs(i, 1, -1))
				return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{

	file_i_o();

	clock_t start, end;
    start = clock();

    cin>>n>>m;
    g.resize(n+1);
    color.resize(n+1);
    vis.resize(n+1);

    for (int i = 0; i < m; ++i)
    {
    	int u, v;
    	cin>>u>>v;
    	g[u].pb(v);
    	g[v].pb(u);
    }

    bool ans = color_all();

    if(not ans){
    	cout<<"IMPOSSIBLE"<<endl;
    }


    for (int i = 1; i <= n; ++i)
    {
    	cout<< color[i] << " ";
    }
	

	end = clock();
	
	double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
    cerr<<"\nTime : "<<fixed<<time_taken<<setprecision(5)<<" s \n";
    cerr<<"Coded By Black Devil"<<endl;
	return 0;
}