#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;

vector<pair<int, int>> points;
vector<pair<int, int>> cluster;
double D[10001];
double dist(pair<int, int> p1, pair<int, int> p2) {
	double ans;
	ans = (double)(p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
	return sqrt(ans);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();

	int pNum;
	int clusterNum;
	cin >> pNum >> clusterNum;
	
	for (int i = 0; i < pNum; i++) {
		int x, y;
		cin >> x >> y;
		points.push_back(make_pair(x, y));
	}

	cluster.push_back(make_pair(0, 0));
	cluster.push_back(points[0]);
	for (int i = 0; i < pNum; i++) {
		D[i] = dist(points[i], cluster[1]);
	}
	for (int j = 1; j <= clusterNum; j++) {
		double maxVal = 0, maxIndex = 0;
		for (int i = 0; i < pNum; i++) {
			for (pair<int,int> a : cluster) {
				if (points[i] != a) {
					D[i] = min(D[i], dist(points[i], cluster[j]));
				}
				if (D[i] > maxVal) {
					maxVal = D[i];
					maxIndex = i;
				}
			}
		}
		cluster.push_back(points[maxIndex]);
	}


	for (int j = 1; j <= clusterNum; j++) {
		cout << cluster[j].first << ' ' << cluster[j].second << '\n';
	}
}