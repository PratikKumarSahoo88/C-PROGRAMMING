#include <stdio.h>
#include <string.h>

void main() {
    char s[100], p[100], d[30];
    int k, len, i;

    printf("Enter frame: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0'; // Remove the newline character from input

    printf("Enter generator: ");
    fgets(d, sizeof(d), stdin);
    d[strcspn(d, "\n")] = '\0'; // Remove the newline character from input

    k = strlen(d);  // Generator length
    len = strlen(s); // Length of the message

    // Append k-1 zeros to the message
    strcpy(p, s);
    for (i = len; i < len + k - 1; i++) {
        p[i] = '0';
    }
    p[i] = '\0';  // Null-terminate the string

    printf("Message after appending %d zero bits: ", k - 1);
    puts(p);

    printf("Order of process is:\n");

    // Perform the CRC encoding
    while (strlen(p) >= k) {
        if (p[0] == '1') {
            // XOR the generator with the message
            for (i = 0; i < k; i++) {
                p[i] = (p[i] - '0') ^ (d[i] - '0') + '0';
            }
        }
        // Shift the message left
        else{
        for (i = 0; i < strlen(p) - 1; i++) {
            p[i] = p[i + 1];
        }
        p[i] = '\0';  // Null-terminate after shifting
        puts(p);  // Print intermediate steps
    }
}

    // Append the CRC (remainder) to the original message
    strcat(s, p);
    
    // Output the final transmitted frame
    printf("Transmitted frame is:\n");
    printf("\t\t");
    puts(s);
}
