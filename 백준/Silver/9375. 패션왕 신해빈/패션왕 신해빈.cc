// 9375
#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

int main(void)
{
	int t_case;
	cin >> t_case;

	for (int c = 0; c < t_case; c++)
	{
		int num;
		cin >> num;

		map<string, int> m;

		for (int n = 0; n < num; n++)
		{
			string name, type;
			cin >> name >> type;
			
			if (m.find(type) == m.end())
				m[type] = 2;
			else
				m[type]++;
		}

		int sum = 1;

		for (auto i : m)
		{
			sum *= i.second;
		}
		cout << sum - 1 << "\n";
	}

	return 0;
}