// 16953
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;
	cin >> a >> b;

	int cnt = 0;

	while (a < b)
	{
		if (b % 10 == 1)
			b /= 10;

		else if (b % 2 == 1) {
			cout << -1;
			return 0;
		}

		else
			b /= 2;
		cnt++;
	}

	if (a == b)
		cout << cnt + 1;
	else
		cout << -1;

	return 0;
}