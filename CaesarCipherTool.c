#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a file using Caesar cipher
void encryptFile(const char* inputFile, const char* outputFile, int key) {
    FILE *input = fopen(inputFile, "r");
    FILE *output = fopen(outputFile, "w"); 

    char ch; // Variable to store each character

    // Check if files opened correctly
    if (input == NULL || output == NULL) {
        printf("Error opening files!\n");
        return;
    }

    // Read file character by character
    while ((ch = fgetc(input)) != EOF) {
        // Encrypt lowercase letters
        if (ch >= 'a' && ch <= 'z')
            ch = 'a' + (ch - 'a' + key) % 26;
        // Encrypt uppercase letters
        else if (ch >= 'A' && ch <= 'Z')
            ch = 'A' + (ch - 'A' + key) % 26;

        // Write the encrypted character
        fputc(ch, output);
    }

    // Close files
    fclose(input);
    fclose(output);

    printf("File encrypted successfully!\n");
}

// Function to auto-decrypt a Caesar cipher file
void decryptFile(const char* inputFile, const char* outputFile) {
    FILE *input = fopen(inputFile, "r"); // Open encrypted file
    if (!input) {
        printf("Error opening file!\n");
        return;
    }

    char buffer[10000]; // Buffer to store file content

    // Read entire file into buffer
    int size = fread(buffer, 1, sizeof(buffer) - 1, input);
    buffer[size] = '\0'; // Null-terminate string
    fclose(input);

    // Common English words to score decrypted text
    const char* commonWords[] = {
        "the", "and", "is", "to", "of", "in", "that", "it", "as"
    };

    int bestScore = -1;       // Highest score found
    int bestKey = 0;          // Key that produced the best result
    char bestText[10000];     // Best decrypted text

    // Try all possible keys
    for (int key = 0; key < 26; key++) {
        char temp[10000];
        strcpy(temp, buffer); // Copy original text

        // Decrypt text using current key
        for (int i = 0; temp[i] != '\0'; i++) {
            char ch = temp[i];

            if (ch >= 'a' && ch <= 'z')
                temp[i] = 'a' + (ch - 'a' - key + 26) % 26;
            else if (ch >= 'A' && ch <= 'Z')
                temp[i] = 'A' + (ch - 'A' - key + 26) % 26;
        }

        // Score decrypted text based on common words
        int score = 0;
        for (int i = 0; i < 9; i++) {
            if (strstr(temp, commonWords[i]) != NULL)
                score += 5;
        }

        // Keep the best result
        if (score > bestScore) {
            bestScore = score;
            bestKey = key;
            strcpy(bestText, temp);
        }
    }

    // Write the best decrypted text to output file
    FILE *output = fopen(outputFile, "w");
    fprintf(output, "%s", bestText);
    fclose(output);

    printf("Auto-decryption complete!\n");
    printf("Best key found: %d\n", bestKey);
}

int main() {
    int choice, key;
    char inputFile[100], outputFile[100];

    while (1) { // Infinite loop for menu
        printf("\n===== Caesar Cipher Tool =====\n");
        printf("1. Encrypt a file\n");
        printf("2. Auto-Decrypt a file\n");
        printf("3. Exit\n");
        printf("Choose an option (1-3): ");

        // Validate menu choice
        if (scanf("%d", &choice) != 1 || choice < 1 || choice > 3) {
            printf("Invalid choice! Please enter a number between 1 and 3.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue; // Go back to menu
        }

        switch (choice) {
            case 1:
                printf("Enter input filename: ");
                scanf("%s", inputFile);
                printf("Enter output filename: ");
                scanf("%s", outputFile);

                // Validate key input
                while (1) {
                    printf("Enter encryption key (any number): ");
                    if (scanf("%d", &key) != 1) {
                        printf("Invalid input! Please enter a number.\n");
                        while (getchar() != '\n'); // Clear input buffer
                    } else {
                        break; // Valid key
                    }
                }

                key = key % 26; // Ensure key is between 0-25
                encryptFile(inputFile, outputFile, key);
                break;

            case 2:
                printf("Enter input filename: ");
                scanf("%s", inputFile);
                printf("Enter output filename: ");
                scanf("%s", outputFile);
                decryptFile(inputFile, outputFile);
                break;

            case 3:
                printf("Goodbye!\n");
                exit(0);
        }
    }

    return 0;
}
