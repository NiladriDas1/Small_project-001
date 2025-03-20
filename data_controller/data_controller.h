#ifndef DATACONTROLLER_H
#define DATACONTROLLER_H
    #ifndef LIBC_H  
        #include "lib/lib_c.h"
    #else
        #include<stdlib.h>
        #include<string.h>
        #include<stdio.h>
        #include<stdbool.h>
        #include<ctype.h>
    #endif
// Enum to define different data types
typedef enum {
    CHAR_TYPE = 0,
    FLOAT_DATATYPE = 1,
    STRING_TYPE = 2,
    INT_DATATYPE = 3,
    DEFAULTNODE = 4
} DATATYPE;

// Bit-field structures for integer types
typedef struct {
    unsigned long long int u_int64:64;
    unsigned int u_int32:32;
    unsigned short int u_s_int16:16;
    unsigned int uint8:8;
    unsigned int uint4:4;
    unsigned int uint2:2;
} POS_INT_STRUCT;

typedef struct {
    signed long long int sll_int64:64;
    signed int s_int32:32;
    signed short int ss_int16:16;
    signed int s_int8:8;
    signed int s_int4:4;
    signed int s_int2:2;
} NEG_INT_STRUCT;

// Union for integer types
typedef union {
    POS_INT_STRUCT POS_INT;
    NEG_INT_STRUCT NEG_INT;
} INT_UNION;

// Union for float types
typedef union {
    float FINT;
    double DINT;
} FLOAT_UNION;

// Structure for character types
typedef struct {
    unsigned char pos_256[256];
    unsigned char pos_64[64];
    unsigned char pos_32[32];
    unsigned char pos_16[16];
    unsigned char pos_8[8];
    unsigned char pos_4[4];
    unsigned char pos_2[2];
} CHAR_STRUCT;

typedef union {
    CHAR_STRUCT CH_TYPE;
} CHAR_UNION;

/*Data type :   */
typedef struct {
    DATATYPE TYPE;
    INT_UNION INT_DATATYPE;
    char *STRING;
    FLOAT_UNION FLOAT_DATATYPE;
    CHAR_UNION CHAR_TYPE;
} DATASET;







// Function to check if input is an integer
bool isInteger(const char *str) {
    for (size_t i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) return false;
    }
    return true;
}

// Function to check if input is a float or double
bool isFloatOrDouble(const char *str) {
    bool hasDot = false;
    for (size_t i = 0; i < strlen(str); i++) {
        if (str[i] == '.') {
            if (hasDot) return false;
            hasDot = true;
        } else if (!isdigit(str[i])) {
            return false;
        }
    }
    return hasDot;
}

// Function to classify input and allocate memory accordingly
DATASET *processInput(const char *input) {
    // Allocate memory for the result dataset
    DATASET *result = (DATASET *)malloc(sizeof(DATASET));
    if (result == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    result->STRING = NULL;

    if (strlen(input) == 1) {
        char c = input[0];
        memset(&result->CHAR_TYPE, 0, sizeof(CHAR_UNION));
        result->CHAR_TYPE.CH_TYPE.pos_2[0] = c;
        result->TYPE = isalnum(c) ? CHAR_TYPE : DEFAULTNODE;
    } else if (isInteger(input)) {
        memset(&result->INT_DATATYPE, 0, sizeof(INT_UNION));
        result->INT_DATATYPE.POS_INT.u_int64 = atoll(input);
        result->TYPE = INT_DATATYPE;
    } else if (isFloatOrDouble(input)) {
        memset(&result->FLOAT_DATATYPE, 0, sizeof(FLOAT_UNION));
        result->FLOAT_DATATYPE.DINT = atof(input);
        result->TYPE = FLOAT_DATATYPE;
    } else {
        result->STRING = (char*)malloc(strlen(input) + 1);
        if (result->STRING == NULL) {
            printf("Memory allocation failed for string.\n");
            free(result); // Clean up before returning
            return NULL;
        }
        strcpy(result->STRING, input);
        result->TYPE = STRING_TYPE;
    }
    return result;
}
// Function to print the allocated data
void printAllocatedData(DATASET *result) {
    switch (result->TYPE) {
        case INT_DATATYPE:
            printf("Type: Integer, Value: %llu\n", result->INT_DATATYPE.POS_INT.u_int64);
            break;
        case FLOAT_DATATYPE:
            printf("Type: Double, Value: %lf\n", result->FLOAT_DATATYPE.DINT);
            break;
        case CHAR_TYPE:
            printf("Type: Character, Value: %c\n", result->CHAR_TYPE.CH_TYPE.pos_2[0]);
            break;
        case STRING_TYPE:
            printf("Type: String, Value: %s\n", result->STRING);
            break;
        default:
            printf("Unknown Type\n");
    }
    free(result->STRING);
}

DATASET *input(char *arg) {
    char buffer[100];
    if (arg == NULL) {
        printf("Enter input: ");
        scanf("%99s", buffer);
        arg = buffer;
    }

    DATASET *result = processInput(arg);
    //printAllocatedData(result);
    return result;
}

/*   DATASET { THE DATA OF MAIN STRUCTURE };
*    input(char *arg);
*    printAllocatedData(DATASET result)
*    processInput();
*/    


#endif


