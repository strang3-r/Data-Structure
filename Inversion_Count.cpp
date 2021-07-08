// Inversion_Count.cpp

// PBDS -> Policy Based Data Structure

// i < j --> a[i] > a[j]
		// \left of j in the array (0...j-1)
// 1 -> Using Merge Sort Tech.
// 2 -> Using PBDS


#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> PBDS;

int main(int argc, char const *argv[])
{ 

	int n;
	cin>>n;
	int a[n];

	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}

	PBDS st;

	int invs_count = 0;

	for (int i = 0; i < n; ++i){
		invs_count += (st.size() - st.order_of_key(a[i]));
		st.insert(a[i]);
	}

	cout<<invs_count<<endl;

	return 0;
}