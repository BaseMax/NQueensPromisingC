/**
 *
 * @Name:N-Queens Promising C
 * @Author: Max Base
 * @Date: 2022/12/10
 * @Repository: https://github.com/BaseMax/NQueensPromisingC
 *
 **/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

typedef struct {
    int n;
    int *row;
    int **answers;
    int answerCount;
} queens;

queens *queensCreate(int n)
{
//    size_t MAX_SIZE = n * n * n * n * n; // Upper bound on number of answers
    queens *q = malloc(sizeof(queens));
    q->n = n;
    q->row = malloc(sizeof(int) * (n + 1));
//    q->answers = malloc(sizeof(int *) * MAX_SIZE);
//    for (int i = 0; i < MAX_SIZE; i++) {
//        q->answers[i] = malloc(sizeof(int) * (n + 1));
//    }
//    q->answerCount = 0;
    return q;
}

bool queensPromising(queens *q, int i)
{
    int k = 0;

    while (k < i) {
        if (q->row[i] == q->row[k] || abs(q->row[i] - q->row[k]) == abs(i - k)) return false;
        k++;
    }
    return true;
}

void queensCheck(queens *q, int i)
{
    int j;

    if (queensPromising(q, i)) {
        if (i == q->n) {
            for (j = 1; j <= q->n; j++) {
//                q->answers[q->answerCount][j - 1] = q->row[j];
                printf("%d ", q->row[j]);
            }
            printf("\n");
//            q->answerCount++;
        } else {
            for (j = 1; j <= q->n; j++) {
                q->row[i + 1] = j;
                queensCheck(q, i + 1);
            }
        }
    }
}

void queensPrint(queens *q)
{
    for (int i = 0; i < q->answerCount; i++) {
        // printf("Answer %d: ", i + 1);
        for (int j = 0; j < q->n; j++) {
            printf("%d ", q->answers[i][j]);
        }
        printf("\n");
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

//    printf("Number of answers: %d\n", q->answerCount);
//    if (q->answerCount > 0) {
//        printf("List of answers:\n");
//        queensPrint(q);
//    }

    return 0;
}
