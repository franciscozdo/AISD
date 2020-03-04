#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

// TODO zmienic sposób losowania:
//      * można losowac ścieżke i dodatkowo wstawiać losowe krawedzie
//      * mozna jako dodatkowy arg zwrocic czy istnieje sciezka czy nie
//          -> ten arg nie będzie odczytywany przez program
//      * lub same testy ze ściezką

int main() {
  srand(time(0));
  int n = rand() % 20000 + 1;
  int r = rand() % 10000 + 1;
  
  fprintf(stderr, "%d %d\n", n, r);
  if (r > n) r = n;
  printf("%d\n", n);
  printf("0 1 ");
  n -= r;
  fprintf(stderr, "%d %d\n", n, r);
  for (int i = 1; i < r; ++i) {
    int l = rand() % 10000 + 1;
    printf("%d\n", l);
    while (rand() % 2 && n)
      printf("%d %d %d\n", rand() % 10000, n--, rand() % 10000);
    printf("%d %d ", l, rand() % 10000 + 1);
  }
  printf("0\n");
  while (n)
      printf("%d %d %d\n", rand() % 10000, n--, rand() % 10000);
  return 0;
}
