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