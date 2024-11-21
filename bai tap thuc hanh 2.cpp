#include <stdio.h>

void sapXepTangDan(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int a[100], chan[100], le[100];
    int n, i, soChan = 0, soLe = 0;

    printf("Nhap so phan tu cua mang (n < 100): ");
    scanf("%d", &n);

    printf("Nhap cac phan tu cua mang:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] % 2 == 0) {
            chan[soChan++] = a[i];
        } else {
            le[soLe++] = a[i];
        }
    }

    // S?p x?p m?ng ch?n và l?
    sapXepTangDan(chan, soChan);
    sapXepTangDan(le, soLe);

    printf("Mang sau khi sap xep:\n");
    printf("Phan tu chan: ");
    for (i = 0; i < soChan; i++) {
        printf("%d ", chan[i]);
    }
    printf("\nPhan tu le: ");
    for (i = 0; i < soLe; i++) {
        printf("%d ", le[i]);
    }
    printf("\n");

    return 0;
}	
