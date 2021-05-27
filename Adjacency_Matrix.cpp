// Adjacency_Matrix.cpp
//Implementation of Adjacency Matrix

#include <iostream>
using namespace std;

int verarr[20][20]; //the adjacency matix initially 0
// int count = 0;


void Add_Edge(int u, int v){
	verarr[u][v] = 1;
	verarr[v][u] = 1;
}


int main(int argc, char const *argv[])
{
	int v = 6;

	Add_Edge(0, 4);
	Add_Edge(0, 2);
	Add_Edge(1, 3);
	Add_Edge(1, 2);
	Add_Edge(2, 3);
	Add_Edge(2, 4);
	Add_Edge(3, 4);
	Add_Edge(5, 3);
	Add_Edge(5, 4);
	for(int i = 0; i<v; i++){
		for (int j = 0; j < v; j++)
		{
			cout<<verarr[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}