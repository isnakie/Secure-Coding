/*
Useless error value coding in C/C++
*/

char dest[19]; // Will hold an 18 byte character, with 1 byte reserved for null-terminator
char *p = strncpy(dest, szSomeLongDataFromAHax0r, 19); // if szSomeLongDataFromAHx0r is longer than 
// 19 bytes, dest may not be null-terminated, leading to buffer overflow or undefined behavior.

// Checking if p returned a pointer to the start of the 'dest' buffer, but it's useless/redundant.
// Dev probably thinks an error (like a string longer than 19 bytes) will result in NULL,
// But it doesn't
if (p) {
    // everything worked fine, party on dest or p
}

/*
An example of wrong useage of assert
*/

DWORD OpenFileContents(char *szFilename) {
    assert(szFilename != NULL);
    assert(strlen(szFilename) > 3);
    FILE *f = fopen(szFilename,′r′);
    assert(f);

    // Do work on the file

    return 1;
 }


/*
Better example of same concept
*/

#include <cstring>
#include <cstdio>

#define DEST_SIZE 19

int main() {
    char dest[DEST_SIZE];
    // Assume szSomeLongDataFromAHax0r is defined elsewhere
    const char *szSomeLongDataFromAHax0r = "Potentially long string from untrusted source";

    // Use strncpy while subtracting one for the null-terminator
    std::strncpy(dest, szSomeLongDataFromAHax0r, DEST_SIZE - 1);

    // Ensure null-termination
    dest[DEST_SIZE - 1] = '\0';

    // Safe to use dest now
    printf("Copied string: %s\n", dest);

    return 0;
}