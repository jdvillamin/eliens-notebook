vector<vector<vector<vector<ll>>>> dp(K + 1, vector<vector<vector<ll>>>(9 * K + 1, vector<vector<ll>>(9 * K + 1, vector<ll>(9 * K, 0))));
for (ll n = 1; n <= 9 * K; n++) dp[0][n][0][0] = 1;
ll pow10 = 1;
for (ll k = 1; k <= K; k++) {
  for (ll n = 1; n <= 9 * K; n++) {
    for (ll s = 0; s <= 9 * K; s++) {
      for (ll m = 0; m < n; m++) {
        for (ll y = 0; y <= 9; y++) {
            if (s >= y) dp[k][n][s][m] += dp[k - 1][n][s - y][((m - y * pow10) % n + n) % n];
        }
      }
    }
  }
  pow10 *= 10;
}
string N;
cin >> N;
ll n = N.length(), ans = 0;
vector<ll> g(9 * K + 1, 0);
for (ll s = 1; s <= 9 * K; s++) {
  string substring = "";
  ll pow10 = 1;
  for (ll i = 0; i < n - 1; i++) pow10 *= 10;
  for (ll i = 0; i < n; i++) {
    substring += '0';
    for (ll j = 0; j < N[i] - '0'; j++) {
      ll digit_sum = j;
      for (ll k = 0; k < i; k++) digit_sum += substring[k] - '0';
      if (s >= digit_sum) g[s] += dp[n - 1 - i][s][s - digit_sum][((-pow10 * stoll(substring)) % s + s) % s];
      substring[i]++;
    }
    pow10 /= 10;
  }
  ans += g[s];
}
auto is_good = [&](string s) -> bool {
  ll digit_sum = 0;
  for (ll i = 0; i < (ll) s.length(); i++) digit_sum += s[i] - '0';
  return stoll(s) % digit_sum == 0;
};
if (is_good(N)) ans++;
cout << ans << "\n";