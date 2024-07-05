// 9465번
#include <iostream>
#include <algorithm>

using namespace std;

int arr[2][100000] = { 0 };
int dp[2][100000] = { 0 };

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test;
	cin >> test;
	for (int t = 0; t < test; t++)
	{
		int num;
		cin >> num;

		for (int h = 0; h < 2; h++)
		{
			for (int n = 0; n < num; n++)
			{
				cin >> arr[h][n];
			}
		}

		dp[0][0] = arr[0][0];
		dp[1][0] = arr[1][0];
		dp[0][1] = arr[1][0] + arr[0][1];
		dp[1][1] = arr[0][0] + arr[1][1];

		for (int i = 2; i < num; i++)
		{
			dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + arr[0][i];
			dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + arr[1][i];
		}

		cout << max(dp[0][num - 1], dp[1][num - 1]) << "\n";
	}

	return 0;
}