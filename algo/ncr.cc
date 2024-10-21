int inverseMod(int a, int m) { return power(a, m - 2); }

int nCr(int n, int r, int m = mod){
   if(r==0) return 1;
   if(r>n) return 0;
   return (fact[n] * inverseMod((fact[r] * fact[n-r]) % m , m)) % m;
}