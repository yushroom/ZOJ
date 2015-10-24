#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Number {
	vector<int> d;

	Number() {
		d.push_back(0);
	}

	size_t size() const {
		return d.size();
	}

	void operator/=(int n) {
		int r = 0;
		int s = 0;
		for (int i = 0; i < d.size(); i++) {
			s = r * 10 + d[i];
			d[i] = s / n;
			r = s % n;
		}
		while (r != 0) {
			s = r * 10;
			d.push_back(s / n);
			r = s % n;
		}
	}

	void operator+=(const Number& n) {
		int s = 0;
		const Number* n1 = this, *n2 = &n;
		if (n1->size() < n2->size())
		{
			n1 = &n;
			n2 = this;
			this->d.resize(n1->size());
		}
		size_t size1 = n1->size(), size2 = n2 ->size();
		for (int i = size1 - 1; i >= 0; --i) {
			if ( i >= size2) {
				this->d[i] = n1->d[i];
			} else {
				s = n1->d[i] + n2->d[i] + s;
				this->d[i] = s % 10;
				s /= 10;
			}
		}
	}

	friend ostream& operator<<(ostream& os, const Number& n) {
		int size = n.size() - 1;
		while (n.d[size] == 0)
			--size;
		cout << 0;
		if (size > 1)
			cout << '.';
		for (int i = 1; i <= size; ++i)
			os << n.d[i];
		//cout << '\n';
		return os;
	}
};

struct oct_number{
	int base;
	int d;

	oct_number(int d, int base) : d(d), base(base){
	}

	Number to_Number() {
		Number n;
		n.d[0] = d;
		for (int i = 0; i < -base; ++i) {
			n /= 8;
		}
		return n;
	}
};

int main()
{
	string str;
	while (cin >> str) {
		cout << str << " [8] = ";
		int base = -1;
		Number result;
		for (int i = 2; i < str.size(); ++i) {
			//cout << "[" << oct_number(str[i]-'0', base).to_Number() << "]\n";
			result += oct_number(str[i]-'0', base).to_Number();
			--base;
		}
		cout << result << " [10]\n";
	}
	return 0;
}
