struct Node { struct Node* parent, child[2]; };
struct BinaryTrie {
  Node* root;
  BinaryTrie() {
    root = new Node();
    root->parent = NULL;
    root->child[0] = NULL;
    root->child[1] = NULL; 
  }
  void insert_node(int x) {
    Node* cur = root;
    for (int place = 29; place >= 0; place--) {
      int bit = x >> place & 1;
      if (cur->child[bit] != NULL) cur = cur->child[bit];
      else {
        cur->child[bit] = new Node();
        cur->child[bit]->parent = cur;
        cur = cur->child[bit];
        cur->child[0] = NULL;
        cur->child[1] = NULL;
      }
    }
  }
  void remove_node(int x) {
    Node* cur = root;
    for (int place = 29; place >= 0; place--) {
      int bit = x >> place & 1;
      if (cur->child[bit] == NULL) return;
      cur = cur->child[bit];
    }
    while (cur->parent != NULL && cur->child[0] == NULL && cur->child[1] == NULL) {
      Node* temp = cur;
      cur = cur->parent;
      if (temp == cur->child[0]) cur->child[0] = NULL;
      else cur->child[1] = NULL;
      delete temp;
    }
  }
  int get_min_xor(int x) {
    Node* cur = root;
    int minXor = 0;
    for (int place = 29; place >= 0; place--) {
      int bit = x >> place & 1;
      if (cur->child[bit] != NULL) cur = cur->child[bit];
      else {
        minXor ^= 1 << place;
        cur = cur->child[1 ^ bit];
      }
    }
    return minXor;
  }
};