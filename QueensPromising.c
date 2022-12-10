#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int n ;
    int *cols;
    int *rows;
} queens;

queens *createQueens(int n)
{
    queens *q = malloc(sizeof(queens));
    q->n = n;
    q->cols = malloc(sizeof(int) * n);
    q->rows = malloc(sizeof(int) * n);
    return q;
}

bool promising(queens *q, int i)
{
    int k = 1;

    while (k < i) {
        if (q->cols[i] == q->cols[k] || abs(q->cols[i] - q->cols[k]) == abs(i - k)) {
            return false;
        }
        k++;
    }
    return true;
    // int k = 1;
    // bool flag = true;

    // while (k < i && flag) {
    //     if (cols[i] == cols[k] || abs(cols[i] - cols[k]) == abs(i - k)) {
    //         flag = false;
    //     }
    //     k++;
    // }
    // return flag;
}

void checkQueens(queens *q, int i)
{
    int j;

    if (promising(q, i)) {
        if (i == q->n) {
            for (j = 1; j <= q->n; j++) {
                printf("%d ", q->cols[j]);
            }
            printf("\n");
        } else {
            for (j = 1; j <= q->n; j++) {
                q->cols[i + 1] = j;
                checkQueens(q, i + 1);
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
    queens *q = createQueens(n);
    checkQueens(q, 0);

    return 0;
}
