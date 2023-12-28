#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    int i;
    if (argc != 2)                                               //判断输入的数量
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    for (i = 0; i < strlen(argv[1]); i++)                   //判断输入的是否是数字
    {
        if (argv[1][i] < 48 || argv[1][i] > 57)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }


    char plaintext[50] = {0};
    char ciphertext[50] = {0};
    printf("plaintext: ");
    scanf("%[^\n]", plaintext);             //保证scanf能够收入空格
    int key = atoi(argv[1]);                //将字符串转换成整形


    for (i = 0; i < strlen(plaintext); i++)
    {
        if ((plaintext[i] >= 'A') && (plaintext[i] <= 'Z'))
        {
            ciphertext[i] = 'A' + (plaintext[i] - 'A' + key) % 26;
        }
        else if ((plaintext[i] >= 'a') && (plaintext[i] <= 'z'))
        {
            ciphertext[i] = 'a' + (plaintext[i] - 'a' + key) % 26;
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    printf("ciphertext:%s\n", ciphertext);
    return 0;
}