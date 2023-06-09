#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Seq_ {
  int *dat;
  int sz;
} Seq;

Seq seq[100001];

void insert(int n, int y) {
  seq[n].dat = realloc(seq[n].dat, seq[n].sz += 1);
  seq[n].dat[seq[n].sz-1] = y;
}

int print(int n, int y) {
  int t = seq[n].dat[y % seq[n].sz];
  printf("%d\n", t);
  return t;
}

int main() {
  FILE *f = stdin;

  int n, q;
  fscanf(f, "%d %d", &n, &q);
  int lastans = 0;
  for (int i = 0; i < q; i++) {
    int op, x, y;
    fscanf(f, "%d %d %d", &op, &x, &y);
    int seq = (x ^ lastans) % n;
    if (op == 1)
      insert(seq, y);
    else // op == 2
      lastans = print(seq, y);
  }

  return 0;
}