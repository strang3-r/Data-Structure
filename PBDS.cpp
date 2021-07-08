 // PBDS.cpp

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


using namespace std;

using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> PBDS;

int main(int argc, char const *argv[])
{
	PBDS st;
	st.insert({1, 0});
	st.insert({3, 1});
	st.insert({4, 2});
	st.insert({10, 3});
	st.insert({6, 4});
	st.insert({15, 5});
	st.insert({15, 6});

	// kth largest element at till now O(log(n))

	for (int i = 0; i < st.size(); ++i)
	{
		cout<<i<<" -> "<<st.find_by_order(i)->first<<" -> "<<st.find_by_order(i)->second<<endl;
	}

	// cout<<st.order_of_key(6)<<endl;

	return 0;
}