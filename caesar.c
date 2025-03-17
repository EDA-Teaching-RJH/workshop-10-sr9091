#include <stdio.h>
#include <ctype.h>

// Function to encrypt a message using Caesar Cipher
void caesarEncrypt(char *message, int key) {
    int i;
    for (i = 0; message[i]; i++) {
        if (isalpha(message[i])) {
            if (islower(message[i])) {
                message[i] = ((message[i] - 'a' + key) % 26) + 'a';
            } else {
                message[i] = ((message[i] - 'A' + key) % 26) + 'A';
            }
        }
    }
}

// Function to decrypt a message using Caesar Cipher
void caesarDecrypt(char *message, int key) {
    int i;
    for (i = 0; message[i]; i++) {
        if (isalpha(message[i])) {
            if (islower(message[i])) {
                message[i] = ((message[i] - 'a' - key + 26) % 26) + 'a';
            } else {
                message[i] = ((message[i] - 'A' - key + 26) % 26) + 'A';
            }
        }
    }
}

int main() {
    char message[100];
    int key;

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = 0; 

    printf("Enter the shift key: ");
    scanf("%d", &key);

    printf("Original Message: %s\n", message);

    caesarEncrypt(message, key);
    printf("Encrypted Message: %s\n", message);

    caesarDecrypt(message, key);
    printf("Decrypted Message: %s\n", message);

    return 0;
}
