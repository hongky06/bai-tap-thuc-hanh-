#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 100000   // S? k? t? t?i �a cho input
#define MAX_NUMBERS 10000  // S? l�?ng s? t?i �a

// Struct l�u tr? s? v� s? l?n xu?t hi?n
typedef struct {
    char number[10];
    int count;
} NonDecreasing;

// H�m ki?m tra s? kh�ng gi?m
int isNonDecreasing(const char *num) {
    for (int i = 0; num[i + 1] != '\0'; i++) {
        if (num[i] > num[i + 1]) return 0;
    }
    return 1;
}

// H�m so s�nh �? s?p x?p theo s? l?n xu?t hi?n gi?m d?n
int compare(const void *a, const void *b) {
    NonDecreasing *x = (NonDecreasing *)a;
    NonDecreasing *y = (NonDecreasing *)b;
    if (x->count != y->count) {
        return y->count - x->count; // S? l?n xu?t hi?n gi?m d?n
    }
    return strcmp(x->number, y->number); // S?p x?p s? t�ng d?n n?u s? l?n b?ng nhau
}

// H�m lo?i b? k? t? kh�ng mong mu?n (v� d?: \n ho?c kho?ng tr?ng)
void cleanInput(char *str) {
    size_t len = strlen(str);
    while (len > 0 && (str[len - 1] == '\n' || str[len - 1] == '\r' || str[len - 1] == ' ')) {
        str[len - 1] = '\0';
        len--;
    }
}

int main() {
    char input[MAX_INPUT];             // L�u to�n b? input
    NonDecreasing results[MAX_NUMBERS]; // M?ng l�u c�c s? kh�ng gi?m
    int resultCount = 0;               // S? l�?ng s? kh�ng gi?m trong m?ng

    // �?c to�n b? input
    printf("Nh?p c�c s?: ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        fprintf(stderr, "L?i khi �?c input.\n");
        return 1;
    }

    // Tokenize input b?ng kho?ng tr?ng ho?c xu?ng d?ng
    char *token = strtok(input, " \n");
    while (token != NULL) {
        // Lo?i b? k? t? kh�ng mong mu?n trong token
        cleanInput(token);

        // Ki?m tra n?u l� s? kh�ng gi?m
        if (isNonDecreasing(token)) {
            // Ki?m tra n?u s? �? t?n t?i trong danh s�ch
            int found = 0;
            for (int i = 0; i < resultCount; i++) {
                if (strcmp(results[i].number, token) == 0) {
                    results[i].count++;
                    found = 1;
                    break;
                }
            }
            // N?u kh�ng t?n t?i, th�m v�o danh s�ch
            if (!found) {
                if (resultCount >= MAX_NUMBERS) {
                    fprintf(stderr, "Qu� nhi?u s? kh�ng gi?m.\n");
                    return 1;
                }
                strcpy(results[resultCount].number, token);
                results[resultCount].count = 1;
                resultCount++;
            }
        }
        // L?y token ti?p theo
        token = strtok(NULL, " \n");
    }

    // S?p x?p danh s�ch
    qsort(results, resultCount, sizeof(NonDecreasing), compare);

    // In k?t qu?
    for (int i = 0; i < resultCount; i++) {
        printf("%s %d\n", results[i].number, results[i].count);
    }

    return 0;
}
