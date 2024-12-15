#include <stdio.h>
#include <stdlib.h>

#define MAXNUM 1000000

void collatz_calc(int num, int* cnt, int* seq_len);


int main(void)
{
    FILE* fp = fopen("collatz_data.csv", "w+");
    if (!fp) {
        fprintf(stderr, "ERROR: FILE ALLOC FAILED");
        exit(EXIT_FAILURE);
    }

    // Label cols
    fprintf(fp, "num, stoptime, maxnum\n");
    int cnt; int seq_len;

    // Iterate digits up to 10^6
    for (int i = 1; i <= MAXNUM; i++) {
        cnt = seq_len = 0;
        collatz_calc(i, &cnt, &seq_len);
        fprintf(fp, "%d, %d, %d\n", i, cnt, seq_len);
    }

    fclose(fp);
}


void collatz_calc(int num, int* cnt, int* seq_len)
{
    while (num > 1) {
        // Calc Collatz nums iteratively until = 1
        if (num%2 == 0) {
            num /= 2;
        }
        else {
            num = 3*num + 1;
        }
        (*cnt)++;
        // Store max num in sequence
        *seq_len = num > *seq_len ? num : *seq_len;
    }
}


