#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 100000   // S? k? t? t?i ða cho input
#define MAX_NUMBERS 10000  // S? lý?ng s? t?i ða

// Struct lýu tr? s? và s? l?n xu?t hi?n
typedef struct {
    char number[10];
    int count;
} NonDecreasing;

// Hàm ki?m tra s? không gi?m
int isNonDecreasing(const char *num) {
    for (int i = 0; num[i + 1] != '\0'; i++) {
        if (num[i] > num[i + 1]) return 0;
    }
    return 1;
}

// Hàm so sánh ð? s?p x?p theo s? l?n xu?t hi?n gi?m d?n
int compare(const void *a, const void *b) {
    NonDecreasing *x = (NonDecreasing *)a;
    NonDecreasing *y = (NonDecreasing *)b;
    if (x->count != y->count) {
        return y->count - x->count; // S? l?n xu?t hi?n gi?m d?n
    }
    return strcmp(x->number, y->number); // S?p x?p s? tãng d?n n?u s? l?n b?ng nhau
}

// Hàm lo?i b? k? t? không mong mu?n (ví d?: \n ho?c kho?ng tr?ng)
void cleanInput(char *str) {
    size_t len = strlen(str);
    while (len > 0 && (str[len - 1] == '\n' || str[len - 1] == '\r' || str[len - 1] == ' ')) {
        str[len - 1] = '\0';
        len--;
    }
}

int main() {
    char input[MAX_INPUT];             // Lýu toàn b? input
    NonDecreasing results[MAX_NUMBERS]; // M?ng lýu các s? không gi?m
    int resultCount = 0;               // S? lý?ng s? không gi?m trong m?ng

    // Ð?c toàn b? input
    printf("Nh?p các s?: ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        fprintf(stderr, "L?i khi ð?c input.\n");
        return 1;
    }

    // Tokenize input b?ng kho?ng tr?ng ho?c xu?ng d?ng
    char *token = strtok(input, " \n");
    while (token != NULL) {
        // Lo?i b? k? t? không mong mu?n trong token
        cleanInput(token);

        // Ki?m tra n?u là s? không gi?m
        if (isNonDecreasing(token)) {
            // Ki?m tra n?u s? ð? t?n t?i trong danh sách
            int found = 0;
            for (int i = 0; i < resultCount; i++) {
                if (strcmp(results[i].number, token) == 0) {
                    results[i].count++;
                    found = 1;
                    break;
                }
            }
            // N?u không t?n t?i, thêm vào danh sách
            if (!found) {
                if (resultCount >= MAX_NUMBERS) {
                    fprintf(stderr, "Quá nhi?u s? không gi?m.\n");
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

    // S?p x?p danh sách
    qsort(results, resultCount, sizeof(NonDecreasing), compare);

    // In k?t qu?
    for (int i = 0; i < resultCount; i++) {
        printf("%s %d\n", results[i].number, results[i].count);
    }

    return 0;
}
