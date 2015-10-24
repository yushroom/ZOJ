#include <iostream>
#include <vector>
using namespace std;

struct Number {
	vector<int> d;

	int size() const {
		return d.size();
	}

	void from_string(const string& str) {
		d.resize(str.size());
		for (int i = 0; i < str.size(); ++i)
			d[i] = str[i] - '0';
	}

	Number operator*(int val) {
		int s = 0;
		Number n;
		n.d.resize(d.size());
		for (int i = d.size()-1; i >= 0; --i) {
			s = d[i] * val + s;
			n.d[i] = s % 10;
			s = s / 10;
		}
		if (s != 0)
			n.d.push_back(s);
		return n;
	}

	friend ostream& operator<<(ostream& os, const Number& n) {
		for (int i = 0; i < n.size(); ++i) {
			cout << n.d[i];
		}
		return os;
	}
};

bool is_cyclic(const Number& n1, const Number& n2) {
	if (n1.size() != n2.size())
		return false;
	int size = n1.szie();
	for (int i = 0; i < size; ++i) {
		for (int j = i; j)
	}
}

int main()
{
	string str;
	while (cin >> str && str.size() > 0) {
		cout << str << endl;
		Number num;
		num.from_string(str);
		int n = str.size();
		for (int i = 1; i <= n; ++i) {
			Number n2 = num * i;
			cout << n2 << endl;
			if (is_cyclic())
				goto cyclic;
		}

		continue;
cyclic:
		cout << ' is cyclic\n';
	}
	return 0;
}