// 1931번
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second < b.second;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<pair<int, int>> v;

	for (int i = 0; i < n; i++)
	{
		int s, e;
		cin >> s >> e;
		
		v.push_back({ s, e });
	}

	sort(v.begin(), v.end(), cmp);

	int cnt = 0;
	int end = 0;

	for (int i = 0; i < n; i++)
	{
		if (v[i].first >= end)
		{
			end = v[i].second;
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}