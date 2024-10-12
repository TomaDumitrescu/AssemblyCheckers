#include <stdio.h>
#include <string.h>

void checkers(int x, int y, char table[8][8]);

void readRef(char *filename, char matrix[8][8]) {
    FILE *fp;
    int i, j;
    int tmp;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    for (i = 7; i >= 0; i--) {
        for (j = 0; j < 8; j++) {
            fscanf(fp, "%d", &tmp);
            if(tmp == 0)
                matrix[i][j] = 0;
            else
                matrix[i][j] = 1;
        }
    }

    fclose(fp);
}

void readInput(char *filename, int *x, int *y) {
    FILE *fp;
    int i, j;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fscanf(fp, "%d", x);
    fscanf(fp, "%d", y);

    fclose(fp);
}

void printOutput(char *filename, char table[8][8]) {
    FILE *f = fopen(filename, "w");

    for(int i = 7; i >= 0; i--) {
        for(int j = 0; j < 8; j++) {
            fprintf(f, "%d ", table[i][j]);
        }
        fprintf(f, "\n");
    }

    fclose(f);
}

int check_table(char table[8][8], char ref[8][8]) {
    int i, j;

    for(i = 7; i >= 0; i--) {
        for(j = 0; j < 8; j++) {
            if (table[i][j] != ref[i][j])
                return 0;
        }
    }

    return 1;
}

int main() {
    int i, j, z;
    char tmp[8][8];
    char table[8][8];
    int x, y;
    char ref_file[30];
    char input_file[30];
    char output_file[30];


    printf("--------------CHECKERS TEST--------------\n");
    for(i = 1; i <= 15; i++) {
        
        memset(table, 0, sizeof(table));

        sprintf(ref_file, "ref/%d.txt", i);
        readRef(ref_file, tmp);

        sprintf(input_file, "input/%d.txt", i);
        readInput(input_file, &x, &y);

        checkers(x, y, table);

        sprintf(output_file, "output/%d.txt", i);
        printOutput(output_file, table);

        if(check_table(table, tmp) == 0) {
            printf("TEST %d..................FAILED\n", i);
        } else {
            printf("TEST %d..................PASSED\n", i);
        }

    }

    return 0;
}