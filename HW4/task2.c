#include <stdio.h>

int getLength(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int findSubstring(char str[], char substr[]) {
    int str_len = getLength(str);
    int substr_len = getLength(substr);

    for (int i = 0; i <= str_len - substr_len; ++i) {
        int j;
        for (j = 0; j < substr_len; ++j) {
            if (str[i + j] != substr[j]) {
                break;
            }
        }
        if (j == substr_len) {
            return i;
        }
    }

    return -1;
}

int main() {
    char str[100], substr[100];

    printf("Enter the original string: ");
    fgets(str, sizeof(str), stdin);
    int str_len = getLength(str);
    if (str[str_len - 1] == '\n') {
        str[str_len - 1] = '\0';
    }

    printf("Enter the substring to find: ");
    fgets(substr, sizeof(substr), stdin);
    int substr_len = getLength(substr);
    if (substr[substr_len - 1] == '\n') {
        substr[substr_len - 1] = '\0';
    }

    int index = findSubstring(str, substr);

    if (index != -1) {
        printf("Substring found at index: %d\n", index);
    } else {
        printf("-1\n");
    }

    return 0;
}
