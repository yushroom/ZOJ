//http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemCode=1094
// Matrix
// 带括号的表达式计算
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int mat_row[26];
int mat_col[26];

struct Matrix {
	int row;
	int col;

	Matrix() : row(0), col(0) {}
	Matrix(int r, int c) : row(r), col(c) {}
};

Matrix matrix[26];

int main()
{
	int n;
	char ch;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> ch ;
		int idx = ch - 'A';
		cin >> matrix[idx].row >> matrix[idx].col; 
	}

	string expr;
	int count = 0;
	while (cin >> expr && expr.size() > 0) {
		//cout << expr << endl;
		stack<int> left_brackets;
		stack<Matrix> mat;
		//left_brackets.clear();
		count = 0;
		int size = expr.size();
		int idx = 0;
		while (idx < size) {
			while (idx < size && expr[idx] != ')') {
				if (expr[idx] == '(')
					left_brackets.push(1);
				else
					mat.push(matrix[expr[idx]-'A']);
				idx++;
			}
			if (idx < size) {
				if (left_brackets.size() < 1) goto error;
				left_brackets.pop();
				if (mat.size() < 2) goto error;
				Matrix m2 = mat.top();
				mat.pop();
				Matrix m1 = mat.top();
				mat.pop();
				if (m1.col != m2.row) goto error;
				count += m1.row * m1.col * m2.col;
				mat.push(Matrix(m1.row, m2.col));
				idx++;
			}
		}
		cout << count << '\n';
		continue;
error:
		cout << "error\n";
	}
	return 0;
}