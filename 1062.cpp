// http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemCode=1062
// Catalan数
// 二分法
#include <iostream>
#include <fstream>
using namespace std;
#define N 20

int catalan[] = {1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012,
 742900, 2674440, 9694845, 35357670, 129644790, 477638700, 1767263190, -2025814172};

//ofstream fout("out.txt");

void get_left_and_right(int n, int idx) {
	//fout << n << ", " << idx << endl;
	if (n == 0)
		return;
	if (n == 1) {
		cout << "X";
		return;
	}
	int j;
	for (j = 0; j < n; ++j) {
		int t = catalan[j] * catalan[n-j-1];
		//cout << "t = " << t << endl;
		if (idx > t) {
			idx -= t;
		} else {
			break;
		}
	}
	int n_left = j, n_right = n-j-1;
	//fout << ' ' << n_left << ' ' << n_right << endl;
	// print left_tree
	if (n_left > 0) {
		cout << '(';
		get_left_and_right(n_left, (idx-1) / catalan[n-j-1] + 1);
		cout << ')';
	}
	cout << 'X';
	// print right tree
	if (n_right > 0) {
		cout << '(';
		get_left_and_right(n_right, (idx-1) % catalan[n-j-1] + 1);
		cout << ')';
	}
}

int main()
{
	// cout << "int catalan[] = {1, 1";
	// for (int i = 2; i <= N; ++i) {
	// 	for (int j = 0; j < i; ++j)
	// 		f[i] += f[j] * f[i-1-j];
	// 	cout << ", " << f[i];
	// }
	// cout << "}";
	int n = 0;
	while (cin >> n && n != 0) {
		//cout << n << ' ';
		int m = 1;
		while (n > catalan[m]){
			n -= catalan[m++];
		}
		//cout << m << ", " << n << endl;

		//fout << endl;
		get_left_and_right(m, n);
		cout << endl;
	}
	return 0;
}
