// http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemCode=1088
// Josephus Problem
// DP
#include <iostream>
using namespace std;
// J(n, m) = (J(n-1, m) + m - 2) % (n-1) + 2
// <==> J(n+1, m) = (J(n, m) + m - 2) % n + 2
// J(3, m)  = 2, m is even
//			= 3, m is odd

int main()
{
	int n; 
	while (cin >> n && n != 0) {
		int J = 2; // J(3, 2) = 2;
		int m = 2;
		bool found = false;
		while (!found) {
			J = m & 1 == 1 ? 3 : 2; // J(3, m)
			for (int nn = 3; nn < n; nn++) {
				J = (J + m - 2) % nn + 2;
			}
			if (J == 2)
				found = true;
			else
				++m;
		}
		//cout << n << " ";
		cout << m << '\n';
	}
	return 0;
}
