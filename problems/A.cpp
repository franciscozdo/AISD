// Franciszek Zdobylak, nr ind. xxxxxx, grupa: PGAW
#include <cstdio>
#include <vector>
#define N 10001 // max number of nodes (lengths)
#define E 200001 // max number of edges

using namespace std;

struct edge {
  int l, m, r;
};

edge edges[E];
vector <int> ne[N];
vector <int> ans;
bool vis[N];

void read(int n) {
  for (int i = 0; i < n; ++i) {
    int l, m, r;
    scanf("%d%d%d", &l, &m, &r);
    edges[i] = {l, m, r};
    ne[l].push_back(i);
  }
}

bool dfs(int v) {
  for (int i = 0; i < ne[v].size(); ++i) {
    edge e = edges[ne[v][i]];
    int next = e.r;
    if (next == 0) {
      ans.push_back(ne[v][i]);
      return true;
    }
    if (!vis[next]) {
      vis[next] = true;
      if (dfs(next)) {
        ans.push_back(ne[v][i]);
        return true;
      }
    }
  }
  return false;
}

void printans() {
  int s = ans.size();
  if (s == 0) {
    puts("BRAK");
    return;
  }
  printf("%d\n", s);
  for (s -= 1; s >= 0; s--) {
    edge e = edges[ans[s]];
    printf("%d %d %d\n", e.l, e.m, e.r);
  }
}

int main() {
  int n; 
  scanf("%d", &n);
  read(n);
  vis[0] = true;
  dfs(0);
  printans();
  return 0;
}
