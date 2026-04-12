#include <stdio.h>
#include <string.h>

int main() {
    char message[100], transmitted[100];
    int choice, i, len, parityBit = 0, count = 0;
    char errorOption;
    int errorPos;

    // ************ SENDER ************
    printf("************ SENDER ************\n");
    printf("Enter Message  : ");
    scanf("%s", message);

    len = strlen(message);

    // Count number of 1s
    for (i = 0; i < len; i++) {
        if (message[i] == '1')
            count++;
    }

    printf("1. ODD parity (0)\n2. EVEN parity (1)\n");
    printf("Enter a option : ");
    scanf("%d", &choice);

    // Decide parity bit
    if (choice == 1) {  // Odd parity
        parityBit = (count % 2 == 0) ? 1 : 0;
    } else {            // Even parity
        parityBit = (count % 2 == 0) ? 0 : 1;
    }

    // Form transmitted message
    strcpy(transmitted, message);
    transmitted[len] = parityBit + '0';
    transmitted[len + 1] = '\0';

    printf("Message to be Transmitted : %s\n", transmitted);

    // Error introduction
    printf("Do You Want to Introduce error(Y/N) : ");
    scanf(" %c", &errorOption);

    if (errorOption == 'Y' || errorOption == 'y') {
        printf("Enter the Position : ");
        scanf("%d", &errorPos);

        if (errorPos >= 1 && errorPos <= strlen(transmitted)) {
            // Flip the bit at errorPos
            transmitted[errorPos - 1] = 
                (transmitted[errorPos - 1] == '0') ? '1' : '0';
        }
    }

    // ************ RECEIVER ************
    printf("\n************ RECEIVER ************\n");
    printf("Message received at the Receiver : %s\n", transmitted);

    // Check parity
    count = 0;
    for (i = 0; i < strlen(transmitted); i++) {
        if (transmitted[i] == '1')
            count++;
    }

    if (choice == 1) { // Odd parity
        if (count % 2 == 1)
            printf("NO ERROR in MESSAGE\n");
        else
            printf("ERROR in MESSAGE\n");
    } else { // Even parity
        if (count % 2 == 0)
            printf("NO ERROR in MESSAGE\n");
        else
            printf("ERROR in MESSAGE\n");
    }

    return 0;
}
