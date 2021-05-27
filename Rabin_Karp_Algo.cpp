// Rabin_Karp_Algo.cpp
// Rabin - Karp Algorithm using Rolling Hash Technique

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

#define prime 119

void file_i_o(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}

ll createHashValue(string str, int n){   //O(m)
	ll result = 0;
	for(int i = 0; i<n; i++){
		result += (ll)(str[i]*(ll)pow(prime, i));
	}

	return result;
}

ll recalculateHash(string str, int oldIndex, int newIndex, ll oldHash, int patlength){ //O(!)
	ll newHash = oldHash - str[oldIndex];
	newHash/=prime;
	newHash+=(ll)(str[newIndex]*(ll)(pow(prime, patlength-1)));
	return newHash;
}

bool checkEqual(string str1, string str2, int start1, int end1, int start2, int end2){
	if(end1-start1 != end2-start2){
		return false;
	}
	while(start1<=end1 and start2<=end2){
		if(str1[start1] != str2[start2]){
			return false;
		}
		start1++;
		start2++;
	}
	return true;

}

int main(int argc, char const *argv[])
{

		string str, pat;
		getline(cin, str);
		getline(cin, pat);

		ll patHash = createHashValue(pat, pat.length());
		ll strHash = createHashValue(str, pat.length());

		for(int i = 0; i<=str.length()-pat.length(); i++){
			if(patHash == strHash and checkEqual(str, pat, i, i+pat.length()-1, 0, pat.length()-1)){
				cout<<"Pattern found at Position ";
				cout<<i+1<<endl;
				return 0;
			}
			if(i<str.length()-pat.length()){
				strHash = recalculateHash(str, i, i+pat.length(), strHash, pat.length());
			}
		}

		
	return 0;
}