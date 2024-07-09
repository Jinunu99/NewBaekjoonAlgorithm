// 13305번

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<long long> distance;
	vector<long long> liter;

	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		long long ipt;
		cin >> ipt;

		distance.push_back(ipt);
	}
	for (int i = 0; i < n; i++)
	{
		long long ipt;
		cin >> ipt;

		liter.push_back(ipt);
	}

	long long min = liter[0];
	long long sum = 0;

	for (int i = 0; i < n - 1; i++)
	{
		if (min > liter[i])
		{
			min = liter[i];
		}

		sum += min * distance[i];
	}

	cout << sum;

	return 0;
}