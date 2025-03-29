vector<pair<ll, ll>> dp(1 << n, {INF, 0});
dp[0] = {1, 0};
for (ll mask = 1; mask < (1 << n); mask++)
  for (ll i = 0; i < n; i++)
    if (mask & (1 << i)) {
      ll prev_mask = mask ^ (1 << i);
      auto [best, last_sum] = dp[prev_mask];
      if (last_sum + w[i] <= x) {
        dp[mask] = min(dp[mask], {best, last_sum + w[i]});
      } else {
        dp[mask] = min(dp[mask], {best + 1, w[i]});
      }
    }
cout << dp[(1 << n) - 1].first << "\n";