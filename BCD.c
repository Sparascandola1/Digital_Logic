#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        sprintf(&digit[0], "%1x", input & 0x01);

        // place hex in output array
        output[nibble - 1] = digit[0];

        // decrement the nibble
        nibble = nibble - 1;

        // shift the input bit 4 places
        input = input >> 4;
    }
}

int bcd2sevenSegmentDecoder(int ABCD)
{
    char output[5] = {'0', '0', '0', '0', '\0'};

    decimal2Binary(ABCD, output);

    int A = output[0];
    int B = output[1];
    int C = output[2];
    int D = output[3];

    int a = (~B * ~D) + C + (B * D) + A;
    int b = ~B + (~C * ~D) + (C * D);
    int c = ~C + D + B;
    int d = (~B * ~D) + (~B * C) + (B * ~C * D) + (C * ~D) + A;
    int e = (~B * ~D) + (C * ~D);
    int f = (~C * ~D) + (B * ~C) + (B * ~D) + A;
    int g = (~B * C) + (B * ~C) + A + (B * ~D);

    char values[9];

    values[0] = 48;
    values[1] = g + 48;
    values[2] = f + 48;
    values[3] = e + 48;
    values[4] = d + 48;
    values[5] = c + 48;
    values[6] = b + 48;
    values[7] = a + 48;
    values[8] = 0;

    int result = binary2Decimal(values);

    return result;
}

int main(int argc, char const *argv[])
{
    // decimal number
    int test, length, input = 29;

    // emtpy bit array
    char output2[3] = {'0', '0', '\0'};

    // get size of array for loop
    length = strlen(output2);

    int digit1 = bcd2sevenSegmentDecoder(input / 10);

    binary2Hex(digit1, output2);

    // print the binary code for the decimal
    for (int i = 0; i < length; i++)
    {
        printf("%c", output2[i]);
    }

    int digit2 = bcd2sevenSegmentDecoder(input % 20);

    binary2Hex(digit2, output2);

    // format
    printf("\n");

    // print the binary code for the decimal
    for (int i = 0; i < length; i++)
    {
        printf("%c", output2[i]);
    }

    // format
    printf("\n");

    return 0;
}
