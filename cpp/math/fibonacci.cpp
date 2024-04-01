/*
Properties:
- Cassini's identity: f[n-1]f[n+1] - f[n]^2 = (-1)^n
- d'Ocagne's identity: f[m]f[n+1] - f[m+1]f[n] = (-1)^n f[m-n]
- Addition rule: f[n+k] = f[k]f[n+1] + f[k-1]f[n]
- k = n case: f[2n] = f[n](f[n+1] + f[n-1])
- f[n] | f[nk]
- f[n] | f[m] => n | m
- GCD rule: gcd(f[m], f[n]) = f[gcd(m, n)]
- [[1 1], [1 0]]^n = [[f[n+1] f[n]], [f[n], f[n-1]]]
- f[2k+1] = f[k+1]^2 + f[k]^2
- f[2k] = f[k](f[k+1] + f[k-1]) = f[k](2f[k+1] - f[k])
- Periodic sequence modulo p
- sum[i=1..n]f[i] = f[n+2] - 1
- sum[i=0..n-1]f[2i+1] = f[2n]
- sum[i=1..n]f[2i] = f[2n+1] - 1
- sum[i=1..n]f[i]^2 = f[n]f[n+1]
Fibonacci encoding:
1. Iterate through the Fibonacci numbers from the largest to the smallest until you find one less than or equal to n.
2. Suppose this number was F_i. Subtract F_i from n and put a 1 in the i-2 position of the code word (indexing from 0 from the leftmost to the rightmost bit).
3. Repeat until there is no remainder.
4. Add a final 1 to the codeword to indicate its end.
Closed-form: f[n] = (((1 + rt(5))/2)^n - ((1 - rt(5)) / 2)^n)/rt(5)
*/
struct matrix {
  ll mat[2][2];
  matrix friend operator *(const matrix &a, const matrix &b){
    matrix c;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        c.mat[i][j] = 0;
        for (int k = 0; k < 2; k++) c.mat[i][j] += a.mat[i][k] * b.mat[k][j];
      }
    }
    return c;
  }
};
matrix matpow(matrix base, ll n) {
  matrix ans{ {
    {1, 0},
    {0, 1}
  } };
  while (n) {
    if (n & 1) ans = ans * base;
    base = base * base;
    n >>= 1;
  }
  return ans;
}
ll fib(int n) {
  matrix base{ {
    {1, 1},
    {1, 0}
  } };
  return matpow(base, n).mat[0][1];
}
pair<int, int> fib (int n) {
  if (n == 0) return {0, 1};
  auto p = fib(n >> 1);
  int c = p.first * (2 * p.second - p.first);
  int d = p.first * p.first + p.second * p.second;
  if (n & 1) return {d, c + d};
  else return {c, d};
}