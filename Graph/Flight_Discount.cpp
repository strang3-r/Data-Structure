// Flight_Discount.cpp

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
#define ar			   	   array
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

const int mxN = 1e5;
int n, m;
vector<ar<ll, 2>> adj1[mxN], adj2[mxN];
ll d1[mxN], d2[mxN];

void solve(int u, vector<ar<ll, 2>> adj[mxN], ll d[mxN]){
	memset(d, 0x3f, sizeof(d1));
	d[u] = 0;
	priority_queue<ar<ll, 2>, vector<ar<ll, 2>>, greater<ar<ll, 2>>> pq;
	pq.push({0, u});
	while(pq.size()){
		ar<ll, 2> u = pq.top();
		pq.pop();
		if(u[0]>d[u[1]])
			continue;
		for(ar<ll, 2> v: adj[u[1]]) {
			if(d[v[1]]>u[0]+v[0]) {
				d[v[1]] = u[0]+v[0];
				pq.push({d[v[1]], v[1]}); 
			}
		}
		
	}
}

int main(int argc, char const *argv[])
{

	file_i_o();

	clock_t start, end;
    start = clock();

	cin>>n>>m;
	loop(i, 0, m-1){
		ll a, b, c;
		cin>>a>>b>>c, --a, --b;
		adj1[a].pb({c, b});
		adj2[b].pb({c, a});
	}

	solve(0, adj1, d1);
	solve(n-1, adj2, d2);

	ll ans = inf;

	loop(i, 0, n-1){
		for(ar<ll, 2> j : adj1[i])
			ans = min(ans, d1[i] + d2[j[1]] + j[0]/2);
	}

	cout<<ans;


	end = clock();
	
	double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
    cerr<<"\nTime : "<<fixed<<time_taken<<setprecision(5)<<" s \n";
    cerr<<"Coded By Black Devil"<<endl;
	return 0;
}