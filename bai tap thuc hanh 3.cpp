#include <stdio.h>

// Hàm hoán ð?i hai s?
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n;
    printf("Nh?p s? lý?ng ph?n t?: ");
    scanf("%d", &n); // Nh?p s? lý?ng ph?n t?

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); // Nh?p các ph?n t? c?a m?ng
    }

    // S?p x?p ð?i ch? tr?c ti?p (Selection Sort)
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // V? trí ph?n t? nh? nh?t
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j; // C?p nh?t v? trí ph?n t? nh? nh?t
            }
        }
        // Ð?i ch? ph?n t? nh? nh?t v?i ph?n t? ? v? trí i
        swap(&arr[i], &arr[minIndex]);

        // In ra tr?ng thái m?ng sau m?i bý?c
        printf("Buoc %d: ", i + 1);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }

    return 0;
}
