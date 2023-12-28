#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    string input = get_string("Enter a string: ");

    
    for (int i = 0; i < strlen(input); i++)
    {
        char c = input[i];


        int ascii = (int)c;


        for (int j = BITS_IN_BYTE - 1; j >= 0; j--)
        {

            int bit = (ascii >> j) & 1;


            print_bulb(bit);
        }

        printf("\n");
    }

    return 0;
}

void print_bulb(int bit)
{
    if (bit == 0)
    {

        printf("\U000026AB");
    }
    else if (bit == 1)
    {

        printf("\U0001F7E1");
    }
}