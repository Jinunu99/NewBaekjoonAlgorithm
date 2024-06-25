// 11279번
using namespace std;
#include <iostream>
#include <queue>

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int> pq;
	int num;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		int x;
		cin >> x;
		if (x == 0)
		{
			if(pq.empty())
				cout << 0 << "\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else if (x > 0)
			pq.push(x);
	}

	return 0;
}