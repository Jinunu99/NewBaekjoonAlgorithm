// 10026
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int n;
char arr[100][100];
int visit[100][100];
int cnt = 0;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void dfs(int x, int y)
{
	if (visit[x][y] != 0)
		return;

	visit[x][y] = 1;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n)
			continue;

		if (arr[x][y] == arr[nx][ny])
			dfs(nx, ny);
	}
}

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++)
		{
			arr[i][j] = str[j];
		}
	}
	
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (visit[j][k] == 0)
				{
					dfs(j, k);
					++cnt;
				}
			}
		}
		cout << cnt << "\n";

		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (arr[j][k] == 'G')
					arr[j][k] = 'R';
			}
		}

		memset(visit, 0, sizeof(visit));
		cnt = 0;
	}


	return 0;
}