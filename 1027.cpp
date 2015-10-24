// http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemCode=1027
// DP 最长公共字串的变种
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
#define N 104

int f[N][N];

int score[5][5] = {
	{ 5, -1, -2, -1, -3}, 
	{-1,  5, -3, -2, -4}, 
	{-2, -3,  5, -2, -2},
	{-1, -2, -2,  5, -1},
	{-3, -4, -2, -1,  0}
};

int s1[N];
int s2[N];

int char_2_int(char ch) {
	if (ch == 'A') return 0;
	if (ch == 'C') return 1;
	if (ch == 'G') return 2;
	if (ch == 'T') return 3;
}

int max_3(int x, int y, int z) {
	if (x < y)
		return y > z ? y : z;
	return x > z ? x : z;
}

int main()
{
	int n_test;
	cin >> n_test;
	for (int i = 0; i < n_test; ++i) {
		int n1, n2;
		string str1, str2;
		cin >> n1 >> str1;
		for (int j = 0; j < n1; j++) {
			s1[j] = char_2_int(str1[j]);
		}
		cin >> n2 >> str2;
		for (int j = 0; j < n2; j++) {
			s2[j] = char_2_int(str2[j]);
		}
		//cout << str1 << ' ' << str2 << endl;

		f[n1][n2] = 0;
		f[n1][n2-1] = score[4][s2[n2-1]];
		f[n1-1][n2] = score[s1[n1-1]][4];
		//cout << f[n1][n2-1] << ' ' << f[n1-1][n2] << endl;
		for (int j = n2-1; j >= 0; --j) {
			f[n1][j] = f[n1][j+1] + score[4][s2[j]];
			//printf("f(%d, %d) = %d\n", n1, j, f[n1][j]);
		}
		for (int i = n1-1; i >= 0; --i) {
			f[i][n2] = f[i+1][n2] + score[s1[i]][4];
			//printf("f(%d, %d) = %d\n", i, n2, f[i][n2]);
		}
		for (int i = n1-1; i >= 0; --i) {
			for (int j = n2-1; j >= 0; --j) {
				f[i][j] = max_3(score[s1[i]][s2[j]] + f[i+1][j+1],
								score[s1[i]][4] + f[i+1][j],
								score[4][s2[j]] + f[i][j+1]);
				//printf("f(%d, %d) = %d[%s, %s]\n", i, j, f[i][j], str1.substr(i, n1-i).c_str(), str2.substr(j, n2-j).c_str());
			}
		}
		cout << f[0][0] << endl;
	}
	return 0;
}
