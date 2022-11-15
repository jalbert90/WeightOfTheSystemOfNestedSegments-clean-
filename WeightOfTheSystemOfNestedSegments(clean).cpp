#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct point {
	int id, coordinate, weight;
};

void solve() {
	int n, m, sum = 0;
	cin >> n >> m;

	vector<point> points;

	for (int i = 1; i <= m; i++) {
		point pt;
		cin >> pt.coordinate >> pt.weight;
		pt.id = i;
		points.push_back(pt);
		sum += pt.weight;
	}

	sort(points.begin(), points.end(), [](point first, point second) {return first.weight < second.weight;});

	for (int i = 0; i < m - 2 * n; i++) {
		sum -= points[m - 1 - i].weight;
		points.pop_back();
	}

	sort(points.begin(), points.end(), [](point first, point second) {return first.coordinate < second.coordinate;});

	cout << sum << endl;

	for (int i = 0; i < n; i++) {
		cout << points[i].id << " " << points[2 * n - 1 - i].id << endl;
	}
}

int main() {
	int t;
	cin >> t;

	for (;t--;) {
		solve();
	}
}