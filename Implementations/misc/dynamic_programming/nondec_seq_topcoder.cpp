#include <bits/stdc++.h>

int main(void) {
	int V[10000];
	int dp[10000] = {0};
	int N;

	std::cin >> N;

	for (int i = 0; i < N; ++i) {
		std::cin >> V[i];
		dp[i] = 1;
	}

	for (int i = 1; i < N; ++i)
		for (int j = 0; j < i; ++j)
			if (V[j] <= V[i])
				dp[i] = std::max(dp[i], dp[j] + 1);
	std::cout << dp[N - 1] << std::endl;
	return 0;
}
