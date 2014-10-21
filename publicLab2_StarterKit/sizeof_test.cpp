#include <iostream>
#include <climits>   // limits.h for Integers
#include <cfloat>    // float.h for Reals

using namespace std;

int main()
{

	cout << endl << "------ Integers (Z) --------------------" << endl;
	cout << "bool:      " << sizeof(bool) << " bytes, MAX=" << endl;
	cout << "char:      " << sizeof(char) << " bytes, MAX=" << CHAR_MAX << endl;
	cout << "short:     " << sizeof(short) << " bytes, MAX=" << SHRT_MAX << endl;
	cout << "int:       " << sizeof(int) << " bytes, MAX=" << INT_MAX << endl;
	cout << "long:      " << sizeof(long) << " bytes, MAX=" << LONG_MAX;
	printf("%ld\n", LONG_MAX);
	
	cout << endl << "------ Reals (R) --------------------" << endl;
	cout << "float:       " << sizeof(float) << " bytes, MAX=";
	printf("%1.3e\n", FLT_MAX);
	cout << "double:      " << sizeof(double) << " bytes, MAX=";
	printf("%1.3Le\n", (long double)DBL_MAX);
	cout << "long double: " << sizeof(long double) << " bytes, MAX=";
	printf("%1.3Le\n", LDBL_MAX);

	cout << endl;

	return 0;
}
