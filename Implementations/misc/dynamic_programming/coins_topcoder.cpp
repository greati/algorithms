#include <iostream>
#include <bits/stdc++.h>
#include <limits.h>
#include <algorithm>

// #define FIRST_METHOD

int main(void) {
	int sums_dp[10000];
	int coins[100];
	int N, S;

	std::cin >> N >> S;

	for (int i = 0; i < N; ++i)
		std::cin >> coins[i];
	
	for (int i = 1; i < 10000; ++i)
		sums_dp[i] = INT_MAX;
	
	sums_dp[0] = 0;	

	#ifdef FIRST_METHOD
	for (int i = 1; i <= S; ++i)
		for (int j = 0; j < N; ++j)
			if (coins[j] <= i)
				sums_dp[i] = std::min(sums_dp[i], sums_dp[i - coins[j]] + 1);	
	#endif
	
	#ifndef FIRST_METHOD
	for (int i = 0; i < N; ++i)
		for (int j = 0; j <= S; ++j)
			sums_dp[j + coins[i]] = std::min(sums_dp[j + coins[i]], sums_dp[j] + 1);
	#endif
	std::cout << sums_dp[S] << std::endl;
	return 0;
}
