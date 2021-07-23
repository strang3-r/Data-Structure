// ShortestRoutesII.cpp

/*Floyd Warshalls Algorithm, All Source Shortest Path*/

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

const int mxN=500;
int n, m, q; 
ll d[mxN][mxN];

int main(int argc, char const *argv[])
{

	file_i_o();

	clock_t start, end;
    start = clock();

	cin>>n>>m>>q;
	memset(d, 0x3f, sizeof(d));

	loop(i, 0, m-1){
		ll a, b, c;
		cin>>a>>b>>c, --a, --b;
		d[a][b]=min(d[a][b], c);
		d[b][a]=min(d[b][a], c);

	}
	loop(i, 0, n-1){
		d[i][i] = 0;
	}
	loop(k, 0, n-1){
		loop(i, 0, n-1){
			loop(j, 0, n-1){
				d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
			}
		}
	}
	while(q--){
		int a,b;
		cin>>a>>b, --a, --b;
		cout<<(d[a][b]>=1e18 ? -1 : d[a][b])<<endl;
	}

	end = clock();
	
	double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
    cerr<<"\nTime : "<<fixed<<time_taken<<setprecision(5)<<" s \n";
    cerr<<"Coded By Black Devil"<<endl;
	return 0;
}