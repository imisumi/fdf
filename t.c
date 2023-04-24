# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <memory.h>
# include <math.h>
# include <stdbool.h>
# include <limits.h>
# include <ctype.h>

#include <stdio.h>
#include <stdint.h>
#include <string.h>

uint32_t hexStringToUInt32(char* hexString)
{
    uint32_t result = 0;
    size_t length = strlen(hexString);
    int i;
        
    for (i = 2; i < length; i++) {
        char c = hexString[i];
        int value;
        
        if (c >= '0' && c <= '9') {
            value = c - '0';
        } else if (c >= 'a' && c <= 'f') {
            value = c - 'a' + 10;
        } else if (c >= 'A' && c <= 'F') {
            value = c - 'A' + 10;
        } else {
            // Invalid character in hex string
            return 0;
        }
        // printf("%d\n", value);
        result = (result << 4) | value;
    }
    result = (result << 4) | 15;
    result = (result << 4) | 15;
    return result;
}

int main()
{
    char* hexString = "0xFF0000";
    uint32_t result = hexStringToUInt32(hexString);
    // printf("%d\n", result);
    return 0;
}
