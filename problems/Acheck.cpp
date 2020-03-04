#include "cstdio"

struct edge{
  int l, m, r;
};

edge edges[100000];
bool used[100000];
int n;

int in(edge e) {
  for (int i = 0; i < n; ++i) {
    edge a = edges[i];
    if (!used[i] && a.l == e.l && a.m == e.m && a.r == e.r)
      return i;
  }
  return -1;
}

void readin() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int l, m, r;
    scanf("%d%d%d", &l, &m, &r);
    edge e = {.l=l, .m=m, .r=r};
    edges[i] = e;
  }
}

bool check() {
  int an, prev = 0;
  getc(stdin);
  char a = getc(stdin);
  if (a == 'B') return false; // generating only correct tests
  else ungetc(a, stdin);

  scanf("%d",&an);
  //printf("%c", a);
  //printf("%d\n", an);
  if (n < an) return false;
  while (an--) {
    edge e;
    scanf("%d%d%d", &e.l, &e.m, &e.r);
    //printf("%d %d %d", e.l, e.m, e.r);
    int nr = in(e);
    //printf("i%d\n", nr);
    if (nr == -1) return false;
    else used[nr] = true;
    if (prev != e.l)
      return false;
    if (e.r == 0)
      return true;
    prev = e.r;
  }
  return false;
}

int main() {
  readin();
  return !check();
}
