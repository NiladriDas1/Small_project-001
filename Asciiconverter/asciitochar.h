#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ascii_Converter{
    int *Iarray;
    size_t size;
    void(*Converter)(void(*fun1)(),void(*fun2)());
}ascii_Converter;
// Function to convert string to integer array (ASCII values)
void storeStringAsIntArray(const char *str, int *iarr, size_t *size) {
    *size = strlen(str);
    for (size_t i = 0; i < *size; i++) {
        iarr[i] = (int)str[i]; // Store ASCII values
    }
}

// Function to convert integer array back to a string
void retrieveStringFromIntArray(int *iarr, size_t size, char *str) {
    for (size_t i = 0; i < size; i++) {
        str[i] = (char)iarr[i]; // Convert ASCII back to character
    }
    str[size] = '\0'; // Null-terminate the string
}

// Function that acts as a converter
void ConverterFunction(void (*fun1)(), void (*fun2)()) {
    if (fun1) fun1();
    if (fun2) fun2();
}

// Main Function
void Converter(const char *input_str) {
    if (!input_str) return;

    ascii_Converter *convert = (ascii_Converter *)malloc(sizeof(ascii_Converter));
    if (!convert) {
        printf("Memory allocation failed!\n");
        return;
    }

    convert->size = strlen(input_str);
    convert->Iarray = (int *)malloc(convert->size * sizeof(int));
    if (!convert->Iarray) {
        printf("Memory allocation for Iarray failed!\n");
        free(convert);
        return;
    }

    // Store the string as ASCII values
    storeStringAsIntArray(input_str, convert->Iarray, &convert->size);
    
    // Assign function pointer
    convert->Converter = ConverterFunction;

    // Print the stored ASCII values
    printf("Stored ASCII values: ");
    for (size_t i = 0; i < convert->size; i++) {
        printf("%d ", convert->Iarray[i]);
    }
    printf("\n");

    // Convert back to string and print
    char *output_str = (char *)malloc((convert->size + 1) * sizeof(char));
    if (!output_str) {
        printf("Memory allocation for output_str failed!\n");
        free(convert->Iarray);
        free(convert);
        return;
    }
    retrieveStringFromIntArray(convert->Iarray, convert->size, output_str);
    printf("Retrieved string: %s\n", output_str);

    // Cleanup
    free(output_str);
    free(convert->Iarray);
    free(convert);
}


