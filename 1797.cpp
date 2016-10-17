#include <cstdio>
#include <cstring>
#define MAXN (1005)
#define inf (1000000000)
using namespace std;

int netmap[MAXN][MAXN];
bool vis[MAXN];
int cap[MAXN];
int T, N, M;

int inline MAX2(int a, int b) {
	return (a > b)?(a):(b);
}

int inline MIN2(int a, int b) {
	return (a < b)?(a):(b);
}

void djs(int src) {
//	memset(cap, 0, sizeof(cap));
	memset(vis, 0, sizeof(vis));
	// cap[src] = inf; // error 1
	for (int i = 1; i <= N; i++) {
		cap[i] = netmap[src][i];
	}
	cap[src] = inf;
	vis[src] = true;
	for (int i = 1; i < N; i++) {
		int tmp = 0, k = src;
		// error 2: should find a minimum vectex to expend in a loop
		/* if (vis[i]) continue;
		if (cap[i] > tmp) {
			tmp = cap[i];
			k = i;
		}
		vis[k] = true;*/
		
//		for (int ii = 1; ii <= N; ii++) {
//			printf("%d ", cap[ii]);
//		}
//		printf("\n");
		
		for (int j = 1; j <= N; j++) {
			if (vis[j]) continue;
			if (tmp < cap[j]) {
				tmp = cap[j];
				k = j;
			}
		}
//		printf("k is %d and tmp is %d\n", k, tmp);
		vis[k] = true;
		if (vis[N]) return; // optimize 1: calculation can be finished if capacity of vectex N is known.
		for (int j = 1; j <= N; j++) {
			if (vis[j]) continue;
			cap[j] = MAX2(cap[j], MIN2(cap[k], netmap[k][j]));
		}
	}
}

int main() {
	int u, v, c;
	scanf("%d", &T);
	for (int ak = 1; ak <= T; ak++) {
		memset(netmap, 0, sizeof(netmap));
		scanf("%d %d", &N, &M);
		for (int i = 0; i < M; i++) {
			scanf("%d %d %d", &u, &v, &c);
			// error 3: ignore the postion that not only one edge between two vectex.
			netmap[u][v] = netmap[v][u] = c;
		}
//		for (int i = 1; i <= N; i++) {
//			for (int j = 1; j <= N; j++) {
//				printf("%d ", netmap[i][j]);
//			}
//			printf("\n");
//		}
		djs(1);
		printf("Scenario #%d:\n%d\n\n", ak, cap[N]);
	}
}
