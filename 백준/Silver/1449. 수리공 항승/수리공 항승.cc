#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, l;
	cin >> n >> l;
	vector<int> v;

	for (int i = 0; i < n; i++)
	{
		int ipt;
		cin >> ipt;

		v.push_back(ipt);
	}
	
	sort(v.begin(), v.end());

	float len = 0;
	int cnt = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (len < v[i])
		{
			cnt++;
			len = v[i] + l - 0.5;
		}
	}
	cout << cnt;

	return 0;
}