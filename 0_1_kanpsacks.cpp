// 0_1_kanpsacks.cpp

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

// Dynamic Approach
int knapsack_DP(int W, int weight[], int value[], int n) {
	
	int dp[n+1][W+1];
	// build table dp[][] in bottom approach
	loop(i, 0, n){
		loop(w, 0, W){
			if(i == 0 or w == 0)
				dp[i][w] = 0;
			else if(weight[i-1] <= w) //Including
				dp[i][w] = max(value[i-1]+dp[i-1][w-weight[i-1]], dp[i-1][w]);
			else //excluding
				dp[i][w] = dp[i-1][w]; 
		}
	}
	return dp[n][W];
}
// recursive method
int knapsack(int w, int wt[], int val[], int n) { //O(N^2)
	// base case
	if(n == 0 or w == 0)
		return 0;
	// if weight of the nth item is more than knapsack capacity w then this item cannot be 
	// included in the optimal solution
	if(wt[n-1] > w){
		return knapsack(w, wt, val, n-1);
	}

	// return the maximum of two cases 
	// 1 nth item included
	// 2 not included
	else
		return max(val[n-1]+knapsack((w-wt[n-1]), wt, val, n-1), knapsack(w, wt, val, n-1));
}

int main(int argc, char const *argv[])
{
	
	int n, w;
	cin>>n>>w;

	int weight[n], value[n];

	loop(i, 0, n-1) {
		cin>>weight[i];	
	}
	loop(i, 0, n-1){
		cin>>value[i];
	}

	cout<<knapsack_DP(w, weight, value, n)<<endl;
	cout<<knapsack(w, weight, value, n)<<endl;

	return 0;
	
}