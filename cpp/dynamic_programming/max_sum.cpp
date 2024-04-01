int max_subarray_sum(vi arr) {
  int x = 0, s = 0;
  for (int k = 0; k < n; k++) {
  s = max(arr[k],s+arr[k]);
  x = max(x,s);
  }
  return x;
} 