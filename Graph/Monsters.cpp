// Monsters.cpp

// Lava Flow, Problem Multi-Source BFS

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
/* <!-- #ifndef ONLINE_JUDGE
			freopen("input.txt", "r", stdin);
			freopen("output.txt", "w", stdout);
		#endif --> */
}

int n, m;
vector<pair<int, int>>monster;
vector<vector<int>> g;
map<pair<int, int>, pair<int, int>> par_mp;
pair<int, int> si, se;
vector<pair<int, int>> moves = {{-1,0}, {1,0}, {0,1}, {0, -1}};

bool isValid(int x, int y, int timer){
	if(x<0 or y<0 or x>=n or y>=m)
		return false;
	if(g[x][y] <= timer)
		return false;
	return true;
}


bool isEscape(int x, int y, int timer) {
	if(not isValid(x,y,timer))
		return false;
	if(x == 0 or y == 0 or x == n-1 or y == m-1)
		return true;
	return false;
}

bool bfs_escape(){
	queue<pair<pair<int,int>,int>> q;
  q.push(make_pair(si,0));
  par_mp[si] = {-1,-1};
  while(!q.empty())
  {
    int cx = q.front().first.first;
    int cy = q.front().first.second;
    int timer = q.front().second; 
    timer++; q.pop();
    for(auto mv: moves)
    {
      int tx = cx+mv.first;
      int ty = cy+mv.second;
      if(isEscape(tx,ty,timer))
      {
       par_mp[{tx,ty}] = {cx,cy};
       se = {tx,ty}; return true; 
      }
      if(isValid(tx,ty,timer))
      {
        par_mp[{tx,ty}] = {cx,cy};
        g[tx][ty] = timer;
        q.push({{tx,ty},timer});
      }
    }
  }
  return false;
}

void preprocess_lava_flow(){
	queue<pair<pair<int,int>,int>> q;
  for(auto m: monster)
  {
    q.push(make_pair(m,0));
  }
  while(!q.empty())
  {
    int cx = q.front().first.first;
    int cy = q.front().first.second;
    int timer = q.front().second; 
    timer++; q.pop();
 
    for(auto mv: moves)
    {
      int tx = cx+mv.first;
      int ty = cy+mv.second;
      if(isValid(tx,ty,timer))
      {
        g[tx][ty] = timer;
        q.push({{tx,ty},timer});
      }
    }
  }
}


int main(int argc, char const *argv[])
{

	file_i_o();

	clock_t start, end;
    start = clock();

	cin >> n >> m;
  g.resize(n);
  for(int i = 0; i < n; ++i)
  {
    g[i].resize(m);
  }
 
  for(int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      g[i][j] = INT_MAX;
    }
  }  
 
  for(int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      char c; cin >> c;
      if(c == '#')
      {
        g[i][j] = 0;
      }
      else if(c == 'M')
      {
        g[i][j] = 0;
 
          monster.push_back({i,j});
      }
      else if(c == 'A')
      {
        g[i][j] = 0;
        si = {i,j};
      }
      else
      {
        g[i][j] = INT_MAX;
      }
    }
  }
  if(si.first == 0 or si.second == 0 or si.first == n-1 or si.second == m-1) 
  {
    cout << "YES" << endl;
    cout << 0;
    return 0;
  }
  preprocess_lava_flow();
 
  if(!bfs_escape())
  {
    cout << "NO";
    return 0;
  }
  cout << "YES" << endl;
  pair<int,int> tmp = se;
  pair<int,int> tmp1 = par_mp[se];
  pair<int,int> ed = {-1,-1}; 
  vector<char> ans;
  while(tmp1 != ed)
  {
 
    if((tmp.second - tmp1.second) == 1 and (tmp.first - tmp1.first) == 0)
    {
      ans.push_back('R');
    }
    if((tmp.second - tmp1.second) == -1 and (tmp.first - tmp1.first) == 0)
    {
      ans.push_back('L');
    }
    if((tmp.second - tmp1.second) == 0 and (tmp.first - tmp1.first) == 1)
    {
      ans.push_back('D');
    }
    if((tmp.second - tmp1.second) == 0 and (tmp.first - tmp1.first) == -1)
    {
      ans.push_back('U');
    }
    tmp = par_mp[tmp];
    tmp1 = par_mp[tmp];
  }
  reverse(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for(auto c: ans)	
  {
    cout << c;
  }

	end = clock();
	
	double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
    cerr<<"\nTime : "<<fixed<<time_taken<<setprecision(5)<<" s \n";
    cerr<<"Coded By Black Devil"<<endl;
	return 0;
}