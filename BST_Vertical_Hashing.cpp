// BST_Vertical_Hashing.cpp
// Using Hashing

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
#define umap			   unordered_map<ll, ll>
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

struct Node
{
	int key;
	Node *left, *right;
};


// A utility function to create a new node
Node* newNode(int key){
	Node* node = new Node;
	node -> key = key;
	node->left = node->right = NULL;
	return node;
}

// The main function to create vertical order of a binary tree with given root
void PrintVerticalOrder(Node* root){

	// Base Case
	if(not root)
		return;
	// create a map and store vertical order in map using function getVerticalOrder()
	map<int, vector<int> > m;
	int hd = 0;
	// create queue to do level order traversal
	// Every item of queue contains node and horizantal distance
	queue<pair<Node*, int> >que;
	que.push(mp(root, hd));

	while(not que.empty()){
	
		pair<Node*, int> temp = que.front();
		que.pop();
		hd = temp.ss;
		Node* node = temp.ff;
	
		// Store this node's data in vector of Hash
		m[hd].pb(node->key);
	
		if(node->left != NULL)
			que.push(mp(node->left, hd-1));
		if(node->right != NULL)
			que.push(mp(node->right, hd+1));
	}
	// Traverse the map and print at every horizontal distance(hd)
	map<int, vector<int> >::iterator it;
	for(it = m.begin(); it != m.end(); it++){
		for(int i = 0; i < it->ss.size(); ++i){
			cout<<it->ss[i]<<" ";
		}
		cout<<endl;
	}
}

int main(int argc, char const *argv[])
{
	Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
    root->right->right->left = newNode(10);
    root->right->right->left->right = newNode(11);
    root->right->right->left->right->right = newNode(12);
    cout << "Vertical order traversal is \n";
    PrintVerticalOrder(root);

		
	return 0;
}