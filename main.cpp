#include <stdio.h>
#include <math.h>
#define ll long long // Max # is 9223372036854775807
using namespace std; 

ll modCalc(ll bas, ll exp, ll mod) {
	ll result = 1;
	while (exp > 0) {
		if (exp % 2 == 1)
			result = (result*bas) % mod;
		//The lack of this shift is why I was getting negative results
		exp = exp >> 1;
		bas = (bas*bas) % mod;
	}
	return result;
}

int main() {
	for (int i = 0; i < 20; i++) {
		printf("3 ^ %2i %% 17 = %2i\t", i, modCalc(3, i, 17));
		printf("12 ^ %2i %% 17 = %2i\t", i, modCalc(12, i, 17));
		printf("6 ^ %2i %% 17 = %2i\n", i, modCalc(6, i, 17));
	}

	return 0;
}
