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
	int size = n1.size();
	for (int j = 0; j < size; ++j) {
		int i = 0;
		for (i = 0; i < size; ++i) {
			if (n1.d[i] != n2.d[(j+i) % size])
				break;
		}
		if (i == size)
			return true;
	}
	return false;
}

int main()
{
	string str;
	while (cin >> str && str.size() > 0) {
		//cout << str << endl;
		Number num;
		num.from_string(str);
		int n = str.size();
		for (int i = 2; i <= n; ++i) {
			Number n2 = num * i;
			//cout << n2 << endl;
			if (!is_cyclic(num, n2))
				goto not_cyclic;
		}
		cout << str << " is cyclic\n";
		continue;
not_cyclic:
		cout << str << " is not cyclic\n";
	}
	return 0;
}