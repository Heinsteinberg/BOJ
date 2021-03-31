// BOJ 6064 카잉 달력
// Solution
// 1. <x:y>에서 x는 고정시키고 y는 N씩 증가(M 초과시 나머지 처리)
// 2. k <= lcm(N, M)도 고려
// Review
// 시뮬레이션은 TLE이고, 본 풀이는 발상이 쉽지 않았음.

#include <bits/stdc++.h>
using namespace std;

int gcd(int, int);
int lcm(int, int);

int main() {
	int T, M, N, x, y, tmp, limit, k;

	scanf("%d", &T);
	while (T-- > 0) {
		scanf("%d %d %d %d", &M, &N, &x, &y);
		k = x;
		if (!(tmp = k % N))
			tmp = N;
		limit = lcm(M, N);
		while (tmp != y && k <= limit) {
			if (!(tmp = (tmp + M) % N))
				tmp = N;
			k += M;
		}
		printf("%d\n", k > limit ? -1 : k);
	}
}

int gcd(int a, int b) {
	int tmp;

	while (b) {
		tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}