// Dijkstra_Algorithm.cpp

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

int find_min_vertex(int *distance, bool *visited, int n){
	int min_Vertex = -1;
	for(int i = 0; i<n; i++){
		if(!visited[i] and (min_Vertex == -1 or distance[i]<distance[min_Vertex])){
			min_Vertex = i; // find minimum vertex
		}
	}
	return min_Vertex;
}

void Dijkstra(int **Edges, int n){
	int* distance = new int[n]; //distance from one Edge to another edge
	bool* visited = new bool[n]; //to mark for visited edges
	for(int i = 0; i<n; i++){
		distance[i] = INT_MAX; // Initialise all corner cost as infinity
		visited[i] = false;//as not visited corner marked as false
	}
	distance[0] = 0;// initialise source as 0 instead of infinity
	for(int i = 0; i<n-1; i++){
		int min_Vertex = find_min_vertex(distance, visited, n);//find the minimum vertex from source
		visited[min_Vertex] = true; // now update visited corner as true;
		for(int j = 0; j<n; j++){
			if(Edges[min_Vertex][j] != 0 and !visited[j]){
				int dist = distance[min_Vertex] + Edges[min_Vertex][j]; // total weight from source to current point
				if(dist < distance[j]){
					distance[j] = dist; // update distance 
				}

			}
		}
	}
	for(int i = 0; i<n; i++){
		cout<<i<<" "<<distance[i]<<endl;
	}
	delete [] visited; // delete visited (it is better to delete otherwise it consume unnecessary memory)
	delete [] distance; //delete distance
 }

int main(int argc, char const *argv[])
{
	// file_i_o();
	
	int N,E;  //N --> number of Vertices, E --> number od Edges
	cin>>N>>E;

	int** Edges = new int*[N];
	for(int i = 0; i<N; i++){	//Adjacency Matrix
		Edges[i] = new int[N];
		for(int j = 0; j<N; j++){
			Edges[i][j] = 0; //initialise Adjacency Matrix with 0
		}
	}
for(int i = 0; i<E; i++){
	int f, s, weight; //f --> first edge, s --> second edge, weight --> from f to s
	cin>>f>>s>>weight; // input first second and weight
	Edges[f][s] = weight; 
	Edges[s][f] = weight; 
}
cout<<endl;
Dijkstra(Edges, N);
for(int i = 0; i<N; i++){
	delete [] Edges[i]; //delete all elements of edges
}
delete [] Edges; // delete Edge

	return 0;
}

