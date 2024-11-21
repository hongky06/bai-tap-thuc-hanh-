#include <stdio.h>

// H�m ho�n �?i hai s?
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n;
    printf("Nh?p s? l�?ng ph?n t?: ");
    scanf("%d", &n); // Nh?p s? l�?ng ph?n t?

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); // Nh?p c�c ph?n t? c?a m?ng
    }

    // S?p x?p �?i ch? tr?c ti?p (Selection Sort)
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // V? tr� ph?n t? nh? nh?t
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j; // C?p nh?t v? tr� ph?n t? nh? nh?t
            }
        }
        // �?i ch? ph?n t? nh? nh?t v?i ph?n t? ? v? tr� i
        swap(&arr[i], &arr[minIndex]);

        // In ra tr?ng th�i m?ng sau m?i b�?c
        printf("Buoc %d: ", i + 1);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }

    return 0;
}
