#include <iostream>
#include <vector>

using std::vector;
using std::pair;
size_t n, m;
vector<bool>visited;

void explore(vector<vector<int> > &adj, int v){
	visited[v] = true;
	for (int i = 0; i < adj[v].size(); i++){
		if (!visited[adj[v][i]])
			explore(adj, adj[v][i]);
	}
}
int reach(vector<vector<int> > &adj, int x, int y) {
	//write your code here
	explore(adj, x);
	if (visited[y])
		return 1;

	return 0;
}

int main() {
	//size_t n, m;
	std::cin >> n >> m;
	vector<vector<int> > adj(n, vector<int>());
	visited.resize(n);
	//visited.resize(n);
	for (size_t i = 0; i < m; i++) {
		int x, y;
		std::cin >> x >> y;
		adj[x - 1].push_back(y - 1);
		adj[y - 1].push_back(x - 1);
	}

	int x, y;
	std::cin >> x >> y;
	for (int i = 0; i < n; i++)
		visited[i] = false;
	std::cout << reach(adj, x - 1, y - 1);
	//system("pause");
}
