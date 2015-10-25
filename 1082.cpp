// http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemCode=1082
// Graph
// 多源最短路径
#include <iostream>
//#include <cstdint>
using namespace std;

#define N 100 + 5
const int INT_MAX = (1<<30)-1;

int g[N][N];

int main()
{
	int n;
	while (cin >> n && n != 0) {
		//cout << n << endl;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j)
				g[i][j] = INT_MAX / 2;
		}
		
		for (int i = 0; i < n; i++) {
			int nn;
			cin >> nn;
			int idx;
			for (int j = 0; j < nn; ++j) {
				cin >> idx;
				cin >> g[i][idx-1];
			}
		}

		for (int k = 0; k < n; ++k) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if (i != j && j != k && i != k)
						if (g[i][j] > g[i][k] + g[k][j])
							g[i][j] = g[i][k] + g[k][j];
				}
			}
		}

		// for (int i = 0; i < n; ++i) {
		// 	for (int j = 0; j < n; ++j) {
		// 		cout << g[i][j] << ' ';
		// 	}
		// 	cout << endl;
		// }

		int min_time = INT_MAX;
		int min_time_id = -1;
		int max_time = -1;
		for (int i = 0; i < n; ++i) {
			max_time = -1;
			for (int j = 0; j < n; ++j) {
				if (i != j && max_time < g[i][j])
					max_time = g[i][j];
			}
			//cout << max_time << endl;
			if (max_time < min_time) {
				min_time = max_time;
				min_time_id = i;
			}
		}
		cout << min_time_id+1 << ' ' << min_time << '\n';
	}
	return 0;
}