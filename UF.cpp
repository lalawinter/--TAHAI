class UF {
  vector<int> parents;
  vector<int> size;
  int count;
  UF(int n) {
    count = n;
    for(int i = ; i < n; i++) {
      parents[i] = i;
      size[i] = 1;
    }
  }
  int find(int x) {
    while(parents[x] != x) {
      parents[x] = parents[parents[x]];
      x = parents[x];
    }
    return x;
  }
  
  bool connected(int p, int q) {
    int rootP = find(p);
    int rootQ = find(q);
    return rootP == rootQ;
  }
  
  void unite(int p, int q) {
    int rootP = find(p);
    int rootQ = find(q);
    if(size[rootP] > size[rootQ]) {
      parents[rootQ] = rootP;
      size[rootP] += size[rootQ];
    }else {
      parents[rootP] = rootQ;
      size[rootQ] += size[rootP];
    }
    count--;
  }
};
