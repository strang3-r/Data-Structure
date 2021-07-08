// clear_bit.cpp

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
    /*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif*/
}


bool isOdd(int n){
	return(n & 1);
}

int getBit(int n, int i){
	
	return (n&(1<<i))>0?1:0;

}

int setBit(int n, int i){

	return ((n|(1<<i)));

}

int updateBit(int &n, int i, int v){
	return (n&~(1<<i))|(v<<i);	
}

int clearBit(int n, int i){
	return n & ~(1<<i);
}


int main(int argc, char const *argv[])
{
	
	file_i_o();

	int n, i, j;
	cin>>n>>i>>j;

/*	if(isOdd(n) != 0){
		cout<<"Odd"<<endl;
	}
	else{
		cout<<"Even"<<endl;
	}
*/
	/*cout<<clearBit(n, i)<<endl;

	cout<<getBit(n, i)<<endl;

	cout<<setBit(n, i)<<endl;*/

	cout<<updateBit(n, i, j)<<endl;

	return 0;
}