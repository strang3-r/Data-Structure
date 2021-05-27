// CircularArr_Search.cpp
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

int CircularArr_Search(vi &arr, int n, int x) {
	int low = 0;
	int high = n-1;
	while(low <= high){
		int mid = (low + high)/2;

		if(x == arr[mid])
			return mid+1;
		if(arr[mid] <= arr[high]){
			if(x > arr[mid] and x <= arr[high])
				low = mid+1;   //Search in right Sorted half
			else
				high = mid-1;  //Search in left sorted half
		}
		else{
			if(arr[low] <= x and x < arr[mid])
				high = mid-1;
			else
				low = mid+1;
		}
	}
}

int main(int argc, char const *argv[])
{
	
	int n, x;
	cin>>n>>x;

	vi arr(n);

	loop(i, 0, n-1){
		cin>>arr[i];
	}


	cout<<CircularArr_Search(arr, n, x)<<endl;
	
	return 0;
}