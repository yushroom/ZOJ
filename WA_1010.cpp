#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;

struct float2 {
	float x, y;
	float2(float x, float y) : x(x), y(y) {
	}
	float2 operator-(const float2& f2) const {
		return float2(x - f2.x, y - f2.y);
	}
};

typedef float2 Point;
typedef float2 Vec2;

inline float cross(const Vec2& v1, const Vec2& v2) {
	return v1.x * v2.y - v1.y * v2.x;
}

inline bool bbox_overlap(const Point& p1, const Point& p2, const Point& q1, const Point& q2) {
	float min_x_1, min_x_2, min_y_1, min_y_2;
	float max_x_1, max_x_2, max_y_1, max_y_2;
	min_x_1 = min(p1.x, p2.x); min_x_2 = min(q1.x, q2.x);
	min_y_1 = min(p1.y, p2.y); min_y_2 = min(q1.y, q2.y);
	max_x_1 = max(p1.x, p2.x); max_x_2 = max(q1.x, q2.x);
	max_y_1 = max(p1.y, p2.y); max_y_2 = max(q1.y, q2.y);
	return max_x_1 - min_x_1 + max_x_2 - min_x_2 < max(max_x_1, max_x_2) - min(min_x_1, min_x_2) &&
		max_y_1 - min_y_1 + max_y_2 - min_y_2 < max(max_y_1, max_y_2) - min(min_y_1, min_y_2);
}

inline bool segment_crossed(const Point& p1, const Point& p2, const Point& q1, const Point& q2) {
	if (!bbox_overlap(p1, p2, q1, q2))
		return false;
	Point qq = q2 - q1;
	return cross(p2 - p1, qq) * cross(q2 - p1, qq) < 0;
}

int main()
{
    int n;
    vector<Point> p;

    // ifstream fin("input.txt");
    // streambuf *backup = cin.rdbuf();
    // cin.rdbuf(backup);
    cin.sync_with_stdio(false);

    //cin >> n;
    int idx = 0;
    while ((cin >> n) && n > 0) {
    	//cout << "n == " << n << endl;
    	p.clear();
    	p.reserve(n);
    	float x, y;
    	for (int i = 0; i < n; ++i) {
    		cin >> x >> y;
    		//cout << x << y << endl;
    		p.push_back(Point(x, y));
    	}

    	float area = 0;
    	int j = 0;
    	if (n < 3)
    		goto print;

    	for (int i = 0; i < n; ++i) {
    		j = (i+1) % n;
    		area += cross(p[i], p[j]);
    		for (int m = 0; m < i-1; ++m) {
	    		if (segment_crossed(p[i], p[j], p[m], p[m+1])) {
	    			area = 0;
	    			goto print;
	    		}
    		}
    	}
    	//cout << area << endl;

print:  
		idx ++;
    	area = fabsf(area) / 2.f;
    	printf("Figure %d: ", idx);
    	if (area < 1e-8f) {
    		//cout << "Impossible\n";
    		printf("Impossible\n");
    	}
    	else {
    		printf("%.2f\n", area);
    	}
    	//cin >> n;
    }
    return 0;
}
