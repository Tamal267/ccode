const int N = 26;
class Node {
 public:
  int EoW;
  Node* child[N];
  Node() {
    EoW = 0;
    for (int i = 0; i < N; i++) child[i] = NULL;
  }
};

void insert(Node* node, string s) {
  for (size_t i = 0; i < s.size(); i++) {
    int r = s[i] - 'A';
    if (node->child[r] == NULL) node->child[r] = new Node();
    node = node->child[r];
  }
  node->EoW += 1;
}

int search(Node* node, string s) {
  for (size_t i = 0; i < s.size(); i++) {
    int r = s[i] - 'A';
    if (node->child[r] == NULL) return 0;
  }
  return node->EoW;
}

void print(Node* node, string s = "") {
  if (node->EoW) cout << s << "\n";
  for (int i = 0; i < N; i++) {
    if (node->child[i] != NULL) {
      char c = i + 'A';
      print(node->child[i], s + c);
    }
  }
}

bool isChild(Node* node) {
  for (int i = 0; i < N; i++)
    if (node->child[i] != NULL) return true;
  return false;
}

bool isJunc(Node* node) {
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    if (node->child[i] != NULL) cnt++;
  }
  if (cnt > 1) return true;
  return false;
}

int trie_delete(Node* node, string s, int k = 0) {
  if (node == NULL) return 0;
  if (k == (int)s.size()) {
    if (node->EoW == 0) return 0;
    if (isChild(node)) {
      node->EoW = 0;
      return 0;
    }
    return 1;
  }
  int r = s[k] - 'A';
  int d = trie_delete(node->child[r], s, k + 1);
  int j = isJunc(node);
  if (d) delete node->child[r];
  if (j) return 0;
  return d;
}

void delete_trie(Node* node) {
  for (int i = 0; i < 15; i++) {
    if (node->child[i] != NULL) delete_trie(node->child[i]);
  }
  delete node;
}