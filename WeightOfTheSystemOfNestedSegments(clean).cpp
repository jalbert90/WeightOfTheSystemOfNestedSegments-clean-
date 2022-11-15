#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct point {
	int id, coordinate, weight;
};

void solve() {
	int n, m, sum;
	cin >> n >> m;

	vector<point> points;

	for (int i = 1; i <= m; i++) {
		point pt;
		cin >> pt.coordinate >> pt.weight;
		pt.id = i;
		points.push_back(pt);
	}

	sort(points.begin(), points.end(), [](point first, point second) {return first.weight < second.weight;});

	cout << endl;

	for (int i = 0; i < m; i++) {
		cout << points[i].id << " " << points[i].coordinate << " " << points[i].weight << endl;
	}
}

int main() {
	int t;
	cin >> t;

	for (;t--;) {
		solve();
	}
}