#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
vector<pair<int, int>> v;
int visit[101];

int bfs(int x)
{
	queue<pair<int, int>> q;
	q.push({ x, 0 });
	visit[x] = 0;

	while (!q.empty())
	{
		int front = q.front().first;
		int depth = q.front().second;
		q.pop();

		for (int i = 1; i <= 6; i++)
		{
			int now = front + i;
			if (now < 100)
			{
				for (int j = 0; j < v.size(); j++)
				{
					int check = v[j].first;
					if (check == now)
					{
						now = v[j].second;
					}
				}

				if (visit[now] == -1)
				{
					q.push({ now, depth + 1 });
					visit[now] = depth + 1;
				}
			}
			else if (now == 100)
			{
				return depth + 1;
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n + m; i++)
	{
		int a, b;
		cin >> a >> b;

		v.push_back({ a, b });
	}

	memset(visit, -1, sizeof(visit));
	
	int depth;
	depth = bfs(1);

	cout << depth;

	return 0;
}