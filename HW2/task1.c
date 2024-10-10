#include <stdio.h>

int main() {
    int number, key, encrypted, decrypted;
    printf("Enter the value: ");
    scanf("%d", &number);

    printf("Enter the number of bits for XOR. Key: ");
    scanf("%d", &key);

    encrypted = number ^ key;
    decrypted = encrypted ^ key;

    printf("original: %d\n", number);
    printf("encrypted: %d\n", encrypted);
    printf("decrypted: %d\n", decrypted);
    return 0;
}
