// Frac_Knapsack.cpp
// Programs to solve fractional knapsacks Problems

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

// Structure for an item which stores weight and corresponding value of Item

 struct Item
 {
 	int value, weight;
 	// constructure
 	Item(int value, int weight){
 		this->value = value;
 		this->weight = weight;
 	}
 	
 };

 // Comparision function to sort Item according to value/weight ratio
 bool comp(struct Item a, struct Item b) {
 	double r1 = (double)a.value/(double)a.weight;
 	double r2 = (double)b.value/(double)b.weight;
 	return r1 > r2;
 }

 // Main Greedy Function to solve Problem 
 // Time Complexity O(nlog(n))

 double fractionalKnapsack(int W, struct Item arr[], int n){
 	// Sorting on the basis of ratio
 	sort(arr, arr+n ,comp);

 	for(int i = 0; i<n; i++){
 		cout<<arr[i].value<<" "<<arr[i].weight<<" : "<<((double)arr[i].value/arr[i].weight)<<endl;
 	}
 	int curWeight = 0; //current weight of Knapsack
 	double finalValue = 0.0;  //Result (Value in Knapsacks)

 	for (int i = 0; i < n; ++i)
 	{
 		// If adding item won't overflow add it completely
 		if(curWeight+arr[i].weight <= W){
 			curWeight += arr[i].weight;
 			finalValue += arr[i].value;
 		}
 		// if we can't add current item, add fractional part of it
 		else{
 			int remain = W - curWeight;
 			finalValue += arr[i].value*((double)remain / (double)arr[i].weight);
 			break;
 		}
 	}
 	// returning final value
 	cout<<finalValue<<endl;

 }

int main(int argc, char const *argv[])
{
	// file_i_o();
	
	int W = 50;
	Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
	int n = sizeof(arr)/sizeof(arr[0]);
	/*for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}*/

	fractionalKnapsack(W, arr, n);
		
	return 0;
}