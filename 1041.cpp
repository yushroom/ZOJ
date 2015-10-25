#include <iostream>
#include <cmath>
using namespace std;
#define N 200

struct Point {
	int x, y;
};

Point points[N];

inline int distance_square(int x, int y, const Point& o) {
	return (x - o.x)*(x - o.x) + (y - o.y)*(y - o.y);
}

int main()
{
	Point o;
	double r, r_square;
	while (cin >> o.x >> o.y >> r && r > 0) {
		r_square = r*r;
		int n, nn = 0;
		int x, y;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> x >> y;
			if (distance_square(x, y, o) <= r_square) {
				points[nn].x = x; points[nn].y = y;
				++nn;
			}
		}

		int count = 0;
		for (int i = 0; i < nn; i++) {
			// Ax+By+C=0
			Point& p = points[i];
			int A = p.y - o.y;
			int B = o.x - p.x;
			int C = -(A * o.x + B * o.y);

			int t_count = 1;
			for (int j = 0; j < nn; ++j) {
				if (i == j) continue;
				Point& p2 = points[j];
				if (A * p2.x + B * p2.y + C >= 0)
					t_count++;
			}
			if (count < t_count)
				count = t_count;
		}

		cout << count << '\n';
	}
	return 0;
}
