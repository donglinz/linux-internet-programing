#include <cstdio>
#include "sub.h"
#include "add.h"
using namespace std;

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d\n", add_int(a, b));
	printf("%f\n", add_float(a, b));
	printf("%d\n", sub_int(a, b));
	printf("%f\n", sub_float(a, b));
	return 0;
}
