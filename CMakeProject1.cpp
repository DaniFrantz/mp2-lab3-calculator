// CMakeProject1.cpp : Defines the entry point for the application.
//

#include "CMakeProject1.h"

using namespace std;

int main()
{
	int goyda = 0;
	double goyd;
	string abc = "(12 + 23 * 34) * (45 / 26 - 17)"; // пример сысоева
	Calculator(abc, goyda);
	string ab = "3 * (4 + 5) / 3 + 1";  // пример нестерова
	Calculator(ab, goyd);
	cout << goyda << "\n\n\n" << goyd << "\n\n\n";
	string abcd = "45^2+13*(s78+83*2)";
	Calculator(abcd, goyd);
	cout << goyd;
	return 0;
}
