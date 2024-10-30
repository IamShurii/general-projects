#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void converter(string f, int KEY);
bool only_digits(char input[]);

int main(int argc, char *argv[])
{
    int KEY;

    if (argc > 2) // checa se o input veio sem a chave
    {
        printf("Erro comand line arguments\n");
        return 1;
    }
    if (argc == 2) // se tiver a chave e somente a chave
    {
        if (only_digits(argv[1]) == false) // checa se a chave é um numero
        {
            printf("./ceasar key\n");
            return 1;
        }
        KEY = atoi(argv[1]); // transforma o input do terminal em um inteiro e assimila isso a
                             // variavel chave
    }
    else
    {
        printf("./ceasar key\n");
        return 1;
    }

    string fra = get_string("Frase: ");

    converter(fra, KEY);
}

void converter(string f, int key)
{
    while (key > 26)
    {
        key -= 26;
    }

    printf("ciphertext:  ");
    for (int i = 0, len = strlen(f); i < len; i++)
    {
        if (isalpha(f[i])) // se o char atual da frase é uma letra que podemos transformar
        {
            if (isupper(f[i])) // checa se esta em maiusculo ( A = 65 a Z = 90 no ASCII)
            {
                if ((int) (f[i] + key) >
                    90) // se o numero for maior que a ultima letra sera necessario voltar 26
                {
                    printf("%c", (f[i] + key - 26));
                }
                else
                {
                    printf("%c", (f[i] + key));
                }
            }
            else if (islower(f[i])) // checa se esta em minusculo
            {
                if ((int) (f[i] + key) > 122)
                {
                    printf("%c", (f[i] + key - 26));
                }
                else
                {
                    printf("%c", (f[i] + key));
                }
            }
        }
        else
        {
            printf("%c", f[i]);
        }
    }
    printf("\n");
}

bool only_digits(char input[])
{
    for (int i = 0, len = strlen(input); i < len; i++)
    {
        if (isdigit(input[i]) == 0)
        {
            return false;
        }
    }
    return true;
}
