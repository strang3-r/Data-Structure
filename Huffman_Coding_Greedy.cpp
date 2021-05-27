#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;

#define ff                 first
#define ss                 second
#define ll                 long long int
#define ld                 long double
#define pb                 push_back
#define mp                 make_pair
#define pii                pair<ll, ll>
#define vi                 vector<ll>
#define vs                 vector<string>
#define mii                map<ll, ll>
#define ump                unordered_map<ll, ll>
#define all(n)			   n.begin(),n.end()
#define mid(l,r)           (l+(r-l)/2)
#define pq_max             priority_queue<ll>
#define pq_min             priority_queue<int, vi, greater<ll> >
#define setbits(x)         __builtin_popcountll(x)
#define zrobits(x)         __builtin_ctzll(x)
#define mod                1000000007
#define inf                1e18
#define ps(x, y)           fixed<<setprecision(y)<<x
#define mk(arr,n,type)     type *arr = new type[n];
#define w(x)               int x; cin>>x; while(x--)
//mt19937                    rng(chrono:steady_clock::now.time_since_epoch().count());
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void file_i_o(){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}     

// A Huffman Node
struct MinHeapNode{
	// One of the input character 
	char data;

	// frequency of the character
	unsigned freq;

	// left and right child 
	MinHeapNode *left, *right;

	// Constructer
	MinHeapNode(char data, unsigned freq){
		left = right = NULL;
		this->data = data;
		this->freq = freq;
	}
};


// for comparision of two heap node (needed in minheap)
struct compare{
	bool operator()(MinHeapNode* l, MinHeapNode* r){
		return (l->freq > r->freq);
	}
};

// Print Huffman codes from root of Huffman tree
void printcodes(struct MinHeapNode* root, string str) {
	if(not root) {
		return;
	}

	if(root->data != '$') {
		cout<<root->data<<":"<<str<<endl;
	}
	printcodes(root->left, str+"0");
	printcodes(root->right, str+"1");
}

// The Main function that builds a Huffman Tree and 
// print codes by traversing the built Huffman Tree

void HuffmanCodes(char data[], int freq[], int size) {
	struct MinHeapNode *left, *right, *top;

	// Create a min Heap and insert all character of data[]
	priority_queue<MinHeapNode*, vector<MinHeapNode*>,compare> minHeap;

	for (int i = 0; i < size-1; ++i){
		minHeap.push(new MinHeapNode(data[i], freq[i]));
	}

	// Iterate while size of heap doesn't become 1
	while(minHeap.size() != 1){

		// Extract the two minimum frequency item from min Heap
		left = minHeap.top();
		minHeap.pop();

		right = minHeap.top();
		minHeap.pop();

		// Create a new interval node withfrequency equal to the sum of the 
		// Two nodes frequencies. Make the two extracted nodes as left and 
		// right children of this node. Add this node  to the min heap 
	    // '$' is a spacial value for internal node not used

	    top = new MinHeapNode('$', left->freq+right->freq);

	    top->left = left;
	    top->right = right;

	    minHeap.push(top); 
	}

	// Print Huffman coding using Huffman tree built above

	printcodes(minHeap.top(), "");
}



int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	char arr[n];
	int freq[n];

	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin>>freq[i];
	}

	HuffmanCodes(arr, freq, n+1);

	return 0;
}