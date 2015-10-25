#include <iostream>
#include <string>
using namespace std;

//char p[4][30];
string p[4];
string IP;
string initial_disp;
string plain_text;
string ciphertext;

int main()
{
	int n_test_case;
	cin >> n_test_case;
	for (int nt = 1; nt <= n_test_case; nt++) {
		cin >> p[0] >> p[1] >> p[2] >> p[3];
		cin >> IP >> initial_disp >> plain_text >> ciphertext;
		cout << p[0] << '\n' << p[1] << '\n' << p[2] << '\n' << p[3] << '\n';
		cout << IP << '\n' << initial_disp << '\n';
		cout << plain_text << '\n' << ciphertext << '\n';

		cout << "Scenario #" << nt << ":\n";
	}
	return 0;
} 