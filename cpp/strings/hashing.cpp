const int A = 911382323, B = 972663749;
const int A2 = 31, B2 = 1000000009;
vector<ll> h(n), p(n);
h[0] = s[0];
p[0] = 1;
for (int i = 1; i < n; i++) {
  h[i] = (h[i - 1] * A + s[i]) % B;
  p[i] = p[i - 1] * A % B;
}
auto hash = [&](int i, int j) -> ll {
  return (h[j] - (i > 0 ? h[i - 1] * p[j - i + 1] % B : 0) + B) % B;
};