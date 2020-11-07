#include <stdio.h>
#include <math.h>
#define ll long long // Max # is 9223372036854775807
using namespace std;

// b=base e=exponent, m=modulo
ll modCalc(ll b, ll e, ll m) {
	ll r = 1;
	while (e > 0) {
		if (e % 2 == 1)
			r = (r*b) % m;
		//The lack of this shift is why I was getting negative results
		e = e >> 1;
		b = (b*b) % m;
	}
	return r;
}

int main() {

    ll base=3,mod=17,u1pr=15,u2pr=13;
    ll u1pu=modCalc(base,u1pr,mod);
    ll u2pu=modCalc(base,u2pr,mod);

    printf("Base: %d\t\t\tMod: %d\n\n",base,mod);
    printf("User1\t\t\tUer2\n");
    printf("Private: %d\t\tPrivate: %d\n",u1pr,u2pr);
    printf("Public: %d\t\tPublic: %d\n\n",u1pu,u2pu);
    printf("Shared Secret\n");
    printf("User1: %d\t\tUser2: %d\n",modCalc(u2pu,u1pr,mod),modCalc(u1pu,u2pr,mod));

	return 0;
}
