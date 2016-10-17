#include <cstdio>
int const phy_cycle = 23;
int const emo_cycle = 28;
int const itl_cycle = 33;
int const cycles[3] = {phy_cycle, emo_cycle, itl_cycle};
int const peak_cycle = 21252;

const char output[] = "Case %d: the next triple peak occurs in %d days.\n";

int inline min3rank(int a[3]) {
	return (a[0] < a[1])?((a[0] < a[2])?0:2):((a[1] < a[2])?1:2);
}

int deal(int phy, int emo, int itl, int days) {
	phy %= phy_cycle;
	emo %= emo_cycle;
	itl %= itl_cycle;
	int data[3] = {phy, emo, itl};
	while (data[0] != data[1] || data[1] != data[2]) {
		int r = min3rank(data);
		data[r] += cycles[r];
	}
	while (data[0] <= days) data[0] += peak_cycle;
	return data[0] - days;
}

int deal2(int phy, int emo, int itl, int days) {
	 int x = (phy * 5544 + emo * 14421 + itl * 1288 + 21252 - days) % 21252;
	 return x?x:21252;
}

int main() {
	int p, e, i, d;
	int count = 0;
	while (1) {
		scanf("%d%d%d%d", &p, &e, &i, &d);
		// printf("debug for input: %d %d %d %d\n", p, e, i, d);
		if (p == -1 && e == -1 && i == -1 && d == -1) break;
		printf(output, ++count, deal2(p, e, i, d));
	}
}
