#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int n ;
    int *cols;
    int *rows;
} queens;

queens *queensCreate(int n)
{
    queens *q = malloc(sizeof(queens));
    q->n = n;
    q->cols = malloc(sizeof(int) * n);
    q->rows = malloc(sizeof(int) * n);
    return q;
}

bool queensPromising(queens *q, int i)
{
    int k = 1;

    while (k < i) {
        if (q->cols[i] == q->cols[k] || abs(q->cols[i] - q->cols[k]) == abs(i - k)) {
            return false;
        }
        k++;
    }
    return true;
}

void queensCheck(queens *q, int i)
{
    if (queensPromising(q, i)) {
        if (i == q->n) {
            for (int j = 1; j <= q->n; j++) {
                printf("%d ", q->cols[j]);
            }
            printf("\n");
        } else {
            for (int j = 1; j <= q->n; j++) {
                q->cols[i + 1] = j;
                queensCheck(q, i + 1);
            }
        }
    }
}

int main(int argc, char** argv)
{
    if (argc != 2) {
        printf("Usage: queens <number of queens>\n");
        return 1;
    }

    int n = atoi(argv[1]);
    printf("N is %d\n", n);

    queens *q = queensCreate(n);
    queensCheck(q, 0);

    return 0;
}
