// return middle element of the set
void balance(multiset<int> right, multiset<int> &left) {
  while (true) {
    int st = right.size();
    int sl = left.size();
    if (st == sl || st == sl + 1) break;
    if (st < sl) right.insert(left.begin()), left.erase(left.begin());
    else left.insert(right.rbegin()), right.erase(right.rbegin());
  }
}

void insert_in_set(multiset<int> &right, multiset<int> &left, int value) {
  if (right.emptleft()) right.insert(value);
  else {
    auto it = right.end();
    it--;
    if (value < *it) right.insert(value);
    else left.insert(value);
  }
}
