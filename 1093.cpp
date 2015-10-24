#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Block {
	int a, b, c;
	Block(int a, int b, int c) : a(a), b(b), c(c) {
	}
	friend bool operator<(const Block& b1, const Block& b2) {
		return b1.a == b2.a ? b1.b < b2.b : b1.a < b2.a;
	}
};

int f[200];

int main()
{
	int n;
	int test_case = 1;
	while (cin >> n && n != 0) {
		int max_height = 0;
		int a, b, c, temp;
		vector<Block> blocks;
		blocks.reserve(n);
		for (int i = 0; i < n; ++i) {
			cin >> a >> b >> c;
			if (a > b) {
				temp = b; b = a; a = temp;
			}
			if (b > c) {
				temp = b; b = c; c = temp;
			}
			if (a > b) {
				temp = b; b = a; a = temp;
			}
			// a <= b <= c
			//cout << a << ' ' << b << ' ' << c << endl;

			blocks.push_back(Block(a, b, c));
			if (c != b)
				blocks.push_back(Block(a, c, b));
			if (a != b)
				blocks.push_back(Block(b, c, a));
		}

		sort(blocks.begin(), blocks.end());

		f[0] = blocks[0].c;
		max_height = f[0];
		//cout << blocks[0].a << ' ' << blocks[0].b << ' ' << blocks[0].c << " - ";
		//cout << f[0] << '\n';
		for (int i = 1; i < blocks.size(); ++i) {
			const Block& b = blocks[i];
			//cout << blocks[i].a << ' ' << blocks[i].b << ' ' << blocks[i].c <<  " - ";
			f[i] = b.c;
			for (int j = i - 1; j >= 0; --j) {
				if (b.a > blocks[j].a && b.b > blocks[j].b) {
					if (f[i] < f[j] + b.c)
						f[i] = f[j] + b.c;
				}
			}
			//cout << f[i] << '\n';
			if (max_height < f[i])
				max_height = f[i];
		}
		//cout << endl;

		cout << "Case " << test_case << ": maximum height = " << max_height << '\n';
		++test_case;
	}
	return 0;
}
