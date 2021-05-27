// Prims_Algorithm.cpp

#include <bits/stdc++.h>
/*#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;*/
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
/*mt19937                    rng(chrono::steady_clock::now,time_since_epoch(),count());
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
*/
    
void file_i_o(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}

int findminvertex(int* weight, bool* visited, int n){
	int minvertex = -1;
	for(int i = 0; i<n; i++){
		if(!visited[i] and (minvertex == -1 or weight[i] < weight[minvertex])){
			minvertex = i;
		}
	}
	return minvertex;
}

void prims(int** edges, int n){
	int* parent = new int[n];
	int* weight = new int[n];
	bool* visited = new bool[n];
	for(int i = 0; i<n; i++){
		visited[i] = false; //marks unvisited as false
		weight[i] = INT_MAX; //initialise weight of all vertices as infinity
	}
	parent[0] = -1; // now initialise source parent as -1
	weight[0] = 0; //and initialise source vertices's weight as 0
	for(int i = 0; i<n; i++){
		int minvertex = findminvertex(weight, visited, n); // find min_vertex
		visited[minvertex] = true; //now we have visited minimum vertex
		//explore unvisited neighbours
		for(int j = 0; j<n; j++){
			if(edges[minvertex][j] != 0 and !visited[j]){
				if(edges[minvertex][j] < weight[j]){
					weight[j] = edges[minvertex][j]; // update weights
					parent[j] = minvertex;    //update parents
				}
			}
		}
	}
	for(int i = 1; i<n; i++){
		if(parent[i] < i){
			cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
		}
		else{
			cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
		}
	}
}

int main(int argc, char const *argv[])
{
	// file_i_o();
	
	int n, e; // n -- verices , e --> edges
	cin>>n>>e;
	int** edges = new int*[n];
	for(int i = 0; i<n; i++){ // adjacency Matrix
		edges[i] = new int[n];
		for(int j = 0; j<n; j++){
			edges[i][j] == 0;// initialising Adjacency Matrix
		}
	}	
		
	for(int i = 0; i<e; i++){
		int f, s, weight; // f --> first vertices, s --> second vertices
		cin>>f>>s>>weight;
		edges[f][s] = weight;
		edges[s][f] = weight;
	}
	cout<<endl;
	prims(edges, n);
	for(int i = 0; i<n; i++){
		delete [] edges[i];
	}
	delete [] edges;
	return 0;
}