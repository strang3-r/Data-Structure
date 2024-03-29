// Labyrinth.cpp

// BFS on Grid

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


const int mxN =1e3, di[4] = {1, 0, -1, 0}, dj[4]= {0, 1, 0, -1};
int n, m, si, sj, ti, tj, d[mxN][mxN];
const char dc[4] = {'D', 'R', 'U', 'L'};
string s[mxN], p[mxN];

bool e(int i, int j){
	return i>=0 and i<n and j>=0 and j<m and s[i][j] == '.';
}



int main(int argc, char const *argv[])
{

	file_i_o();

	clock_t start, end;
    start = clock();

    cin>>n>>m;
    loop(i, 0, n-1){
    	cin>>s[i];
    	loop(j, 0, m-1){
    		if(s[i][j] == 'A')
    			si=i, sj=j; //s[i][j] = '.';
    		if(s[i][j]=='B')
    			ti=i, tj=j, s[i][j] = '.';
    	}
    	p[i] = string(m, 0);
    }

    queue<array<int, 2>> qu;
    qu.push({si, sj});
    while(qu.size()){
    	array<int, 2> u=qu.front();
    	qu.pop();
    	// s[u[0]][u[1]]='#';
    	for(int k = 0; k<4; ++k){
    		int ni=u[0]+di[k], nj = u[1]+dj[k];
    		if(not e(ni, nj))
    			continue;
			qu.push({ni, nj});
			s[ni][nj] = '#';
			d[ni][nj] = k;
			p[ni][nj]=dc[k]; 
    	}
    }
    if(p[ti][tj]){
    	cout<<"YES\n";
    	string t;
    	while(ti^si or tj^sj){
    		t += p[ti][tj];
    		int dd=d[ti][tj]^2;
    		ti+=di[dd];
    		tj+=dj[dd];
    	}
    	reverse(t.begin(), t.end());
    	cout<<t.size()<<"\n";
    	cout<<t;
    }else{
    	cout<<"NO\n";
    }
	

	end = clock();
	
	double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
    cerr<<"\nTime : "<<fixed<<time_taken<<setprecision(5)<<" s \n";
    cerr<<"Coded By Black Devil"<<endl;
	return 0;
}