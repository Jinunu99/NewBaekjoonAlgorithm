#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
char arr[600][600];
int visit[600][600] = { 0 };
int cnt = 0;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int s_x, int s_y)
{
	queue<pair<int, int>> q;
	q.push({ s_x, s_y });
	visit[s_x][s_y] = 1;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;

			if (!visit[nx][ny])
			{
				if (arr[nx][ny] == 'X')
					continue;

				if (arr[nx][ny] == 'P')
					cnt++;


				q.push({ nx, ny });
				visit[nx][ny] = 1;
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

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = str[j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 'I')
			{
				bfs(i, j);
				break;
			}
		}
	}

	if (cnt == 0)
		cout << "TT";
	else
		cout << cnt;


	return 0;
}