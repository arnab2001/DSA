//Problem Link:https:https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/D

#include <bits/stdc++.h>
using namespace std;


void solve()
{
	long long int n, k;
	cin >> n;

	long long int a[n];

	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);

	cin >> k;

	while (k--)
	{
		long long int x, y;
		cin >> x >> y;

		long long int l = -1;
		long long int r = n;

		while (r > l + 1)
		{
			long long int m = (r + l) / 2;

			if (a[m] < x)
				l = m;
			else
				r = m;
		}

		long long int t1 = r + 1;

		l = -1;
		r = n;

		while (r > l + 1)
		{
			long long int m = (r + l) / 2;

			if (a[m] <= y)
				l = m;
			else
				r = m;
		}

		long long int t2 = l + 1;

		cout << t2 - t1 + 1 << " ";
	}
}

int main()
{
	long long int tt = 1;
	while (tt--)
		solve();

	return 0;
}