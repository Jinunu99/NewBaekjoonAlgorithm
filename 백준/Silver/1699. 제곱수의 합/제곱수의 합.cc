#include <iostream>
#include <algorithm>

using namespace std;

int dp[100001] = { 0 };

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;
	cin >> num;

	for (int i = 1; i <= num; i++)
	{
		dp[i] = i;
	}

	for (int n = 2; n <= num; n++)
	{
		for (int i = 1; i * i <= n; i++)
		{
			dp[n] = min(dp[n], dp[n - i * i] + 1);
		}
	}

	cout << dp[num];

	return 0;
}