const int sieve_size = 10000006;
bitset<sieve_size> sieve;

void Sieve() {
  sieve.flip();
  int finalBit = sqrt(sieve.size()) + 1;
  for (int i = 2; i < finalBit; ++i) {
    if (sieve.test(i))
      for (int j = 2 * i; j < sieve_size; j += i) sieve.reset(j);
  }
}