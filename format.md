[BOJ 13172 Σ](https://www.acmicpc.net/problem/13172)
=====
Algorithm
-----
* Mathematics
* Recursion

Solution
-----
1. N, S를 각각 최대공약수로 나눠 기약분수로 표현
2. N<sup>-1</sup> = N<sup>(1e9+7)-2</sup>
3. ```2```에서의 우항을 제한 시간내에 구하기 위해 재귀함수 이용
4. (S * N<sup>(1e9+7)-2</sup>) mod (1e9 + 7)의 값을 결과값에 추가

Code
-----

```cpp
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

typedef long long ll;

void swap(int&, int&);
int GCD(int, int);
ll getInverse(int, int);

int main() {
	int M, N, S, gcd;
	ll res = 0;

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &N, &S);
		gcd = GCD(N, S);
		N /= gcd;
		S /= gcd;
		res = (res + S * getInverse(N, mod - 2) % mod) % mod;
	}
	printf("%lld\n", res);
}

void swap(int& a, int& b) {
	int tmp = a;

	a = b;
	b = tmp;
}

int GCD(int a, int b) {
	if (b > a)
		swap(a, b);
	if (b > 0)
		return GCD(b, a % b);
	return a;
}

ll getInverse(int b, int x) {
	ll tmp;

	if (x == 1)
		return b;
	if (x % 2 == 0) {
		tmp = getInverse(b, x / 2);
		return tmp * tmp % mod;
	}
	else
		return b * getInverse(b, x - 1) % mod;
}
```

Remark
-----
* 문제를 이해하기가 어려웠음.