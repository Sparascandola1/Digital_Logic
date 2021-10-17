#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// turn binary to hexadecimal
void binary2Hex(int input, char output[])
{   
    //local vars
    char digit[2] = {'0', '\0'};
    int nibble = strlen(output);

    // while nibble is within array bounds build Hexadecimal string
    while (nibble > 0)
    {
        sprintf(digit, "0x0F", input);
        output[nibble - 1] = digit[0];

        nibble = nibble - 1;

        input = input >> 4;
    }
}

// binary to decimal
int binary2Decimal(char input[])
{
    // local vars
    int output = 0;
    int power = 1;

    // loop over the binary code and calculate the decimal
    for (int i = strlen(input) - 1; i >= 0; i--)
    {
        output = output + ((input[i] - 48) * power);

        power = power * 2;
    }

    // return decimal
    return output;
}

void decimal2Binary(int input, char output[])
{
    //quotient will be the decimal number to convert
    int quotient = -1;

    // make bit the size of the array -1
    int bit = strlen(output) - 1;

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

int main()
{
    // decimal number
    int input = 29;

    // array of emtpy bits
    char output1[] = {'0', '0', '0', '0', '0', '0', '0', '0', '\0'};
    char output2[3] = {'0', '0', '\0'};

    // get size of array for loop
    size_t length = strlen(output1);

    // run logic and transfor a decimal into binary
    decimal2Binary(input, output1);

    int result = binary2Decimal(output1);

    // print input
    printf("Input is: %d\n", input);

    printf("%d in binary: ", input);

    // print the binary code for the decimal
    for (int i = 0; i < length; i++)
    {
        printf("%c", output1[i]);
    }

    // format
    printf("\n");

    printf("Result for binary to decimal: %d\n", result);

    binary2Hex(input, output2);

    length = strlen(output2);

    printf("Input is: %d\n", input);

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