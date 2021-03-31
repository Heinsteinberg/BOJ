// BOJ 1676 팩토리얼 0의 개수
// Solution
// 1. 1부터 N까지 5로 나누고, 그 몫만큼 결과값에 추가
// 2. 또는 N을 1, 25, 125로 나눈 값의 합을 바로 출력
// Review
// N!에서 항상 인수 2는 인수 5보다 충분히 많이 존재한다는 것만 인지한다면 간단하게 해결이 가능함.

#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;

	scanf("%d", &N);
	printf("%d\n", N / 5 + N / 25 + N / 125);
}