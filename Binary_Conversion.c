#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Prototypes
void decimal2Binary(int inut, char output[]);
int binary2Decimal(char input[]);
void binary2Hex(int input, char output[]);

int main()
{
    // decimal number
    int input = 29;

    // array of emtpy bits
    char output1[] = {'0', '0', '0', '0', '0', '0', '0', '0', '\0'};
    char output2[3] = {'0', '0', '\0'};

    // run logic for decimal into binary
    decimal2Binary(input, output1);

    // run logic for binary into decimal
    int result = binary2Decimal(output1);

    // print input
    printf("Input: %d in binary: ", input);

    // get size of array for loop
    size_t length = strlen(output1);
    // print the binary code for the decimal
    for (int i = 0; i < length; i++)
    {
        printf("%c", output1[i]);
    }

    // format
    printf("\n");

    // print result
    printf("Result for binary to decimal: %d\n", result);

    // run logic for binary to hex
    binary2Hex(input, output2);

    // get size of array for loop
    length = strlen(output2);
    // print the binary code for the decimal
    for (int i = 0; i < length; i++)
    {
        printf("%c", output2[i]);
    }

    // format
    printf("\n");

    // exit clean
    exit(EXIT_SUCCESS);
}

void decimal2Binary(int input, char output[])
{
    //quotient will be the decimal number to convert make bit the size of the array -1
    int quotient = -1, bit = strlen(output) - 1;

    // divide the decimal number by two and place the the remainder in the output array to build the binary number
    while (quotient != 0)
    {
        // divide decimal number by 2
        quotient = input / 2;

        // grab the remainder
        int remainder = input % 2;

        // if the remainder is 1 place a 1 in the array else place a 0
        if (remainder == 1)
        {
            output[bit] = '1';
        }
        else
        {
            output[bit] = '0';
        }

        // reduce bit to move to the next most signigicant digit in the array
        bit = bit - 1;

        // replace deciaml number with new one
        input = quotient;
    }
}

// binary to decimal
int binary2Decimal(char input[])
{
    // local vars
    int output = 0, power = 1;

    // loop over the binary code and calculate the decimal
    for (int i = strlen(input) - 1; i >= 0; i--)
    {
        output = output + ((input[i] - 48) * power);

        power = power * 2;
    }

    // return decimal
    return output;
}

// turn binary to hexadecimal
void binary2Hex(int input, char output[])
{
    //local vars
    char digit[2] = "0\0";
    int nibble = strlen(output);

    // while nibble is within array bounds build Hexadecimal string
    while (nibble > 0)
    {
        // mask the binary as hex
        sprintf(&digit[0], "%1x", input & 0x0f);

        // place hex in output array
        output[nibble - 1] = digit[0];

        // decrement the nibble
        nibble = nibble - 1;

        // shift the input bit 4 places
        input = input >> 4;
    }
}