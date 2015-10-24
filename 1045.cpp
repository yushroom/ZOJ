#include <iostream>
using namespace std;

int main()
{
	double length = 0;
	while (cin >> length && length != 0) {
		int k = 2;
		while (length > 0) {
			length -= 1.0 / double(k);
			k ++; 
		}
		cout << k-2 << " card(s)\n";
	}
	return 0;
}