#include <stdio.h>
#define MAX_VAL 30001 // Giá tr? t?i da trong d?y
#define MAX_N 100     // S? ph?n t? t?i da

int main() {
    int n, a[MAX_N];
    int freq[MAX_VAL] = {0}; // M?ng luu t?n su?t các giá tr?
    int i, maxFreq = 0, maxValue = -1;

    printf("Nhap so phan tu cua day (khong qua 100): ");
    scanf("%d", &n);

    printf("Nhap cac phan tu trong day (khong qua 30000):\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] >= 0 && a[i] < MAX_VAL) {
            freq[a[i]]++; // Tang t?n su?t c?a giá tr? a[i]
        }
    }

    // T?m giá tr? xu?t hi?n nhi?u nh?t
    for (i = 0; i < MAX_VAL; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            maxValue = i;
        }
    }

    if (maxFreq > 1) {
        printf("So xuat hien nhieu lan nhat la: %d voi tan suat %d lan.\n", maxValue, maxFreq);
    } else {
        printf("Khong co so nao xuat hien nhieu lan nhat.\n");
    }

    return 0;
}
