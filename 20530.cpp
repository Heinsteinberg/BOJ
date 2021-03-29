// BOJ 20530 양분
// Solution
// 1. 그래프내의 사이클 찾기(isCycle)
// 2. 사이클 정점들을 기준으로 집합 구분
// 3. 쿼리로 받은 두 정점이 동일한 집합내에 있으면 1, 그렇지 않으면 2를 출력(Union-Find 이용)
// Review
// 사이클에 포함되는 정점들을 찾는 과정(DFS)이 직관적이지 않아 헤맸음.

#include <bits/stdc++.h>
using namespace std;

vector<int> parent, nodes[200001], from, visited, done, isCycle;

int find(int);
void uni(int, int);
void chkCycle(int, int);
void dfs(int, int);

int main() {
	int N, Q, a, b, cur;
	queue<int> q;

	scanf("%d %d", &N, &Q);
	parent.resize(N + 1);
	from.resize(N + 1);
	visited.resize(N + 1);
	done.resize(N + 1);
	isCycle.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &a, &b);
		nodes[a].push_back(b);
		nodes[b].push_back(a);
		parent[i] = i;
	}
	dfs(0, 1);
	visited.clear();
	visited.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		if (!isCycle[i] || visited[i])
			continue;
		q.push(i);
		while (!q.empty()) {
			cur = q.front();
			q.pop();
			if (visited[cur]++)
				continue;
			uni(i, cur);
			for (int nxt : nodes[cur]) {
				if (visited[nxt] || isCycle[nxt])
					continue;
				q.push(nxt);
			}
		}
	}
	while (Q-- > 0) {
		scanf("%d %d", &a, &b);
		printf("%d\n", find(a) == find(b) ? 1 : 2);
	}
}

int find(int n) {
	if (n == parent[n])
		return n;
	return parent[n] = find(parent[n]);
}

void uni(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	parent[a] = b;
}

void chkCycle(int cur, int nxt) {
	isCycle[cur] = 1;
	if (cur == nxt)
		return;
	chkCycle(from[cur], nxt);
}

void dfs(int prev, int cur) {
	visited[cur] = 1;
	for (int nxt : nodes[cur]) {
		if (!visited[nxt]) {
			from[nxt] = cur;
			dfs(cur, nxt);
		}
		else if (nxt != prev && !done[nxt]) {
			chkCycle(cur, nxt);
		}
	}
	done[cur] = 1;
}