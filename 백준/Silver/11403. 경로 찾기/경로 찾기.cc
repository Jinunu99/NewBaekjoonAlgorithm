#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int arr[100][100] = { 0 };
int result[100][100] = { 0 };
int visit[100] = { 0 };
int start = 0;
vector<vector<int>> graph;

void dfs(int x)
{
	for (int i = 0; i < graph[x].size(); i++)
	{
		if (!visit[graph[x][i]])
		{
			visit[graph[x][i]] = 1;
			result[start][graph[x][i]] = 1;
			dfs(graph[x][i]);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	graph.resize(n);
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1)
			{
				graph[i].push_back(j);
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		start = i;
		dfs(i);
		memset(visit, 0, sizeof(visit));
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}