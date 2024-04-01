/*
Matrix exponentation:
f[n] = af[n-1] + bf[n-2] + cf[n-3]
Use:
|f[n]  | |a b c||f[n-1]|
|f[n-1]|=|1 0 0||f[n-2]|
|f[n-2]| |0 1 0||f[n-3]|
To get:
|f[n]  | |a b c|^(n-2)|f[2]|
|f[n-1]|=|1 0 0|      |f[1]|
|f[n-2]| |0 1 0|      |f[0]|
*/
struct Matrix { int mat[MAX_N][MAX_N]; };
Matrix matrix_mul(Matrix a, Matrix b) {
  Matrix ans; int i, j, k;
  for (i = 0; i < MAX_N; i++)
  for (j = 0; j < MAX_N; j++)
  for (ans.mat[i][j] = k = 0; k < MAX_N; k++)
    ans.mat[i][j] += a.mat[i][k] * b.mat[k][j];
  return ans; 
}
Matrix matrix_pow(Matrix base, int p) {
  Matrix ans; int i, j;
  for (i = 0; i < MAX_N; i++) 
    for (j = 0; j < MAX_N; j++)
      ans.mat[i][j] = (i == j);
  while (p) {
    if (p & 1) ans = matrix_mul(ans, base);
    base = matrix_mul(base, base);
    p >>= 1;
  }
  return ans; 
}