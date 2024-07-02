#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;

	cin >> n >> m;
	set<string> s;
	vector<string> result;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;

		s.insert(str);
	}

	for (int i = 0; i < m; i++)
	{
		string str;
		cin >> str;

		if (s.find(str) != s.end())
		{
			result.push_back(str);
		}
	}

	sort(result.begin(), result.end());

	cout << result.size() << "\n";
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << "\n";
	}

	return 0;
}