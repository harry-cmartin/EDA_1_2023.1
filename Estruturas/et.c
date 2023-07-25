
#include <stdio.h>
#define TAM_MAX 30
#include <string.h>

int main()
{
  char nomes[TAM_MAX];

  while (scanf("%s", nomes) > 0)
  {
    if (strcmp(nomes, "marte") == 0)
    {
      printf("Leonardo Cicero Marciano\n");
      return 0;
    }
  }

  printf("none\n");
  return 0;
}