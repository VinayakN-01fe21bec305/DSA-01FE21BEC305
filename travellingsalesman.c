#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define MIN 1000

int matrix[MAX][MAX], visited[MAX], path[MAX];
int n, cost = MIN;

void getdata(char *filename)
 {
  FILE *fp = fopen(filename, "r");

  fscanf(fp, "%d", &n);

  for (int i = 0; i < n; i++)
    {
    for (int j = 0; j < n; j++)
    {
      fscanf(fp, "%d", &matrix[i][j]);
    }
    visited[i] = 0;
  }

  visited[0] = 1;
  path[0] = 0;

  fclose(fp);
}

void tsp(int city, int sum, int count)
 {
  if (count == n && matrix[city][0])
    {
    if (sum + matrix[city][0] < cost)
    {
      cost = sum + matrix[city][0];

      for (int i = 0; i < n; i++)
        {
        printf("%d ", path[i]);
      }
      printf("%d\n", 0);
    }
    return;
  }

  for (int i = 0; i < n; i++)
    {
    if (!visited[i] && matrix[city][i])
    {
      visited[i] = 1;
      path[count] = i;
      tsp(i, sum + matrix[city][i], count + 1);
      visited[i] = 0;
    }
  }
}

int main() {
  char *filename = "input.txt";
  getdata(filename);

  printf("The cycle is:\n");
  tsp(0, 0, 1);

  printf("The cost of the cycle is %d\n", cost);

  return 0;
}

