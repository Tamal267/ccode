int power(int base, int n, int m = mod) {
  if (n == 0) return 1;
  if (n & 1) {
    int x = power(base, n / 2);
    return ((x * x) % m * base) % m;
  }
  else {
    int x = power(base, n / 2);
    return (x * x) % m;
  }
}