typedef int Item;

typedef struct {
  int size;
  Item *v;
} Heap;

Heap *Heap_New(int capacity) {
  Heap *newHeap = malloc(sizeof(Heap));
  newHeap->v = malloc(sizeof(Item) * (capacity + 1));
  newHeap->size = 0;
}

void fixUp(Heap *h, int i) {
  while (i > 1 && h->v[i / 2] < h->v[i]) {
    Item tmp = h->v[i / 2];
    h->v[i / 2] = h->v[i];
    h->v[i] = tmp;

    i = i / 2;
  }
}

void insert(Heap *h, Item i) {
  h->v[h->size + 1] = i;
  h->size++;
  fixUp(h, h->size);
}

int isEmpty(Heap *h) { return h->size == 0; }

Item top(Heap *h) { return h->v[1]; }

void fixDown(Heap *h, int i) {
  int child;
  while (i * 2 <= h->size) {
    child = 2 * i;
    if (child != h->size && h->v[child] < h->v[child + 1]) {
      child++;
    }

    if (h->v[i] < h->v[child]) {
      Item tmp = h->v[child];
      h->v[child] = h->v[i];
      h->v[i] = tmp;

      i = child;
    } else {
      break;
    }
  }
}

void pop(Heap *h) {
  // Exch(root, last)
  Item tmp = h->v[1];
  h->v[1] = h->v[h->size];
  h->v[h->size] = tmp;
  h->size--;

  fixDown(h, 1);
}

void heapfy(Heap *h) {
  for (int i = 1; i > h->size; i++) {
    fixUp(h, i);
  }
}

int main() {
  Item a[] = {4, 3, 2, 1};
  int n = 4;

  Heap minhaHeap;
  minhaHeap.v = a - 1;
  minhaHeap.size = n;

  heapfy(&minhaHeap);
  while (!isEmpty(&minhaHeap)) {
    pop(&minhaHeap);
  }

  for (int i = 0; i < 4; i++) {
    printf("%d ", a[i]);
  }
}