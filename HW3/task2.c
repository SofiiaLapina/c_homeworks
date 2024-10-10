#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, key;
    char ch;

    srand(time(0));

    printf("Enter the number of characters to encrypt: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Program will exit.\n");
        return 1;
    }

    key = (rand() % 513) - 256;
    printf("Generated encryption key: %d\n", key);

    for (int i = 0; i < n; ++i) {
        printf("Enter character %d: ", i + 1);
        scanf(" %c", &ch); 

        if (isalpha(ch)) { 

            if (islower(ch)) {
                ch = (ch - 'a' + key) % 26;
                if (ch < 0) ch += 26; 
                ch += 'a';
            }

            else if (isupper(ch)) {
                ch = (ch - 'A' + key) % 26;
                if (ch < 0) ch += 26; 
                ch += 'A';
            }

            printf("Encrypted character: %c\n", ch);
        } else {
            printf("Invalid input: must be a valid alphabetic character\n");
            i--; 
        }
    }

    return 0;
}
