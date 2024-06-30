#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <numeric>
using namespace std;

int n, m;
vector<vector<int>> realation;
int visit[101] = { 0 };
int total = 0;

void bfs(int x)
{
	queue<pair<int, int>> q;
	q.push({ x, 0 });
	visit[x] = 1;

	while (!q.empty())
	{
		int front = q.front().first;
		int depth = q.front().second;
		q.pop();

		for (int i = 0; i < realation[front].size(); i++)
		{
			int now = realation[front][i];
			if (!visit[now])
			{
				q.push({ now, depth + 1 });
				visit[now] = depth + 1;
			}
		}
	}

	total = accumulate(visit + 1, visit + n + 1, 0) - 1;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	realation.resize(n + 1);

	for (int i = 0; i < m; i++)
	{
		int a, b;

		cin >> a >> b;
		realation[a].push_back(b);
		realation[b].push_back(a);
	}

	int mini = 987654321;
	int result = 0;
	for (int i = 1; i <= n; i++)
	{
		bfs(i);

		if (mini > total)
		{
			mini = total;
			result = i;
		}

		memset(visit, 0, sizeof(visit));
	}

	cout << result;

	return 0;
}