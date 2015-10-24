#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

#define PI 3.141592653589793

int main()
{
	const double _2_PI = 2 * PI;
	double x1, y1, x2, y2, x3, y3;
	while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3) {
		if (y2 == y1)
		{
			double temp = y1; y1 = y3; y3 = temp;
			temp = x1; x1 = x3; x3 = temp;
		} else if (y3 == y1) {
			double temp = y1; y1 = y2; y2 = temp;
			temp = x1; x1 = x2; x2 = temp;
		}
		double k1 = (x1 - x2) / (y2 - y1);
		double b1 = (y1 + y2)/2 - k1 * (x1 + x2)/2;
		double k2 = (x1 - x3) / (y3 - y1);
		double b2 = (y1 + y3)/2 - k2 * (x1 + x3)/2;
		//printf("%lf %lf  %lf %lf\n", k1, b1, k2, b2);
		double ox = (b1-b2) / (k2-k1);
		double oy = k1 * ox + b1;
		double r = sqrt((ox - x1) * (ox - x1) + (oy - y1) * (oy - y1));
		printf("%.2lf\n", _2_PI * r); 
	}
	return 0;
}