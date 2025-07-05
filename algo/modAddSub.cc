void add (int &a, int b) {
	a += b;
	if (a >= mod) a -= mod;
}

void sub (int &a, int b) {
	a -= b;
	if (a < 0) a += mod;
}

