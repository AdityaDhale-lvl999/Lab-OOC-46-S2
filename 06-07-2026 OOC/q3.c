#include <stdio.h>

int main() {
    int arr[4];
    int sum = 0;

    printf("Enter 4 numbers: ");
    for (int i = 0; i < 4; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < 4; i++) {
        sum += arr[i];
    }

    printf("Sum of all elements = %d\n", sum);
    return 0;
}
