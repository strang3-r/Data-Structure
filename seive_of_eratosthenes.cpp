// seive_of_eratosthenes.cpp

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

//Naive Approach

bool is_Prime(int n){
	if(n==1){
		return false;
	}
	if(n==2){
		return true;
	}
	loop(i, 2, sqrt(n)){ // time complexity O(sqrt(N)) for 1 Number and O(N) for N number
		if(n%i == 0){
			return false;
		}
	}
	return true;
}

//Sieve Approach -->Generate Array Containing Prime Number
   
void Prime_Seive(int *p){

	//First Marked All Odd Number's as Prime
	for(ll i = 3; i <= 1000000; i += 2){
		p[i] = 1;
	}

	//seive code
	for(ll i = 3; i <= 1000000; i += 2){
		//If the current number is not marked (means it is Prime)
		if(p[i] == 1){
			//Marks All the Multiple of i as Not Prime
			 for(ll j = i*i; j <= 1000000; j = j + i){
			 	p[j] = 0;
			 }
		}
	}
	//Special Case
	p[2] = 1;
	p[1] = p[0] = 0;


}

int main(int argc, char const *argv[])
{
	// file_i_o();
	
	int n;
	cin>>n;

	int p[1000005] = {0};
	Prime_Seive(p);
// let's print Primes upto range n
	loop(i, 0, n-1){
		if(p[i] == 1){
			cout<<i<<" ";
		}
	}

	/*if(!is_Prime(n)){
		cout<<"NOT PRIME"<<endl;
	}
	else{
		cout<<"PRIME"<<endl;
	}*/
		
	return 0;
}