#include <stdio.h>
#include <stdlib.h>

// Function Prototypes
void gateAND(int x[], int y[]);
void gateOR(int x[], int y[]);
void gateNOT(int x[]);
void gateNAND(int x[], int y[]);
void gateNOR(int x[], int y[]);
void gateXOR(int x[], int y[]);
void gateNXOR(int x[], int y[]);

int main(int argc, char const *argv[])
{
    // bit arrays
    int x[] = {0, 1, 1, 0, 1};
    int y[] = {1, 1, 0, 0, 1};

    // function calls
    gateAND(x, y);
    gateOR(x, y);
    gateNOT(x);
    gateNAND(x, y);
    gateNOR(x, y);
    gateXOR(x, y);
    gateNXOR(x, y);

    return EXIT_SUCCESS;
}

void gateAND(int x[], int y[])
{

    // local vars
    int i, result;

    printf("\nGATE AND:\n");
    printf("INPUT  OUTPUT\n");

    for (i = 0; i < 5; i++)
    {
        // The product of two bits (& is the bitwise AND operator)
        result = x[i] & y[i];

        printf("|%d|%d| = |%d|\n", x[i], y[i], result);
    }
}

void gateOR(int x[], int y[])
{

    //local vars
    int i, result;

    printf("\nGATE OR:\n");
    printf("INPUT  OUTPUT\n");

    for (i = 0; i < 5; i++)
    {
        // the sum of two bits (| is the bitwise OR operator)
        result = x[i] | y[i];

        printf("|%d|%d| = |%d|\n", x[i], y[i], result);
    }
}

void gateNOT(int x[])
{
    // local vars
    int i, result;

    printf("\nGATE NOT:\n");
    printf("INPUT  OUTPUT\n");

    for (i = 0; i < 5; i++)
    {
        //what ever the bits opposite is
        if (x[i] == 1)
        {
            result = 0;
        }
        else
        {
            result = 1;
        }

        printf("|%d    |    %d|\n", result, x[i]);
    }
}

void gateNAND(int x[], int y[])
{
    // local vars
    int i, result;

    printf("\nGATE NAND:\n");
    printf("INPUT  OUTPUT\n");

    for (i = 0; i < 5; i++)
    {
        // the inverse of the product of two bits (& is the bitwise AND operator)
        result = !(x[i] & y[i]);

        printf("|%d|%d| = |%d|\n", x[i], y[i], result);
    }
}

void gateNOR(int x[], int y[])
{
    //local vars
    int i, result;

    printf("\nGATE NOR:\n");
    printf("INPUT  OUTPUT\n");

    for (i = 0; i < 5; i++)
    {
        // the inverse of the sun of two bits (| is the bitwise OR operator)
        result = !(x[i] + y[i]);

        printf("|%d|%d| = |%d|\n", x[i], y[i], result);
    }
}

void gateXOR(int x[], int y[])
{

    // local vars
    int i, result;

    printf("\nGATE XOR:\n");
    printf("INPUT  OUTPUT\n");

    for (i = 0; i < 5; i++)
    {
        // the sum of two bits (^ is the bitwise XOR operator)
        result = x[i] ^ y[i];

        printf("|%d|%d| = |%d|\n", x[i], y[i], result);
    }
}

void gateNXOR(int x[], int y[])
{
    //local vars
    int i, result;

    printf("\nGATE NXOR:\n");
    printf("INPUT  OUTPUT\n");

    for (i = 0; i < 5; i++)
    {
        // the inverse of the sum of two bits (^ is the bitwise XOR operator)
        result = !(x[i] ^ y[i]);

        printf("|%d|%d| = |%d|\n", x[i], y[i], result);
    }
}
