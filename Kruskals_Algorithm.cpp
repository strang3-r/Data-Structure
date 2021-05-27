// Kruskals_Algorithm.cpp

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
class edge
{
public:
	int source;
	int dest;
	int weight;	
};

bool compare(edge e1, edge e2){
	return e1.weight < e2.weight;
}

int findParent(int v, int *parent){
	if(parent[v] == v){
		return v;
	}
	return findParent(parent[v], parent);
}

void Kruskals(edge *input, int n, int E){
	//sort the input array --> ascending order
	sort(input, input+E, compare); //sort on the basis of weight
	edge *output = new edge[n-1];
	int *parent = new int[n];  //parent of edge
	for (int i = 0; i < n; ++i){
		parent[i] = i; //initialise by it's index
	}
	int count = 0; //currently how many edge we have pushed 
	int i = 0; //current position

	while(count != n-1){
		edge currentEdge = input[i];   //put sorted edge in currentEdge from input
		//check if we can add the currentEdge in MST or not 
		int sourceParent = findParent(currentEdge.source, parent); //to find the parent of source edge
		int destParent = findParent(currentEdge.dest, parent);// to find the parent of destination edge
		
		if(sourceParent != destParent){
			output[count] = currentEdge; //output[0] --> currentEdge....
			count++; //-->0 -->1 -->2 ....
			parent[sourceParent] = destParent; //update parent ka source_parent = destparent
		}
		i++;
	}
	for (int i = 0; i < n-1; ++i){
		if(output[i].source < output[i].dest){
			cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
		}
		else{
			cout<<output[i].dest<<" "<<output[i].source<<" "<<output[i].weight<<endl;
		}
	}

}


int main(int argc, char const *argv[])
{
	// file_i_o();

	int n, E ;  //n--> total number of vertices, E --> total number of Edge 	
	cin>>n>>E;
	edge *input = new edge[E];
	for (int i = 0; i < E; ++i){
		int s,d,w;  // s-->source, d--> destination, w--> weight
		cin>>s>>d>>w;
		input[i].source = s;
		input[i].dest = d;
		input[i].weight = w;
	}
	Kruskals(input, n, E);

	return 0;
}