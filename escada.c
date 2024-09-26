#include <cs50.h>
#include <stdio.h>

void escada_reversa(int m);
void escada_normal(int m);

int main(void)
{
    int num = get_int("numero de andares: ");
    escada_reversa(num);
    escada_normal(num);
}

void escada_reversa(int m )
{
    int num = m;
    for (int n = num; n >= 0; n-- )
    {
        for(int j = 0; j < n;j++)
        {
            printf("*");
        }
        printf("\n");//quebra a linha para que comece o proximo andar da escada

    }
}


void escada_normal(int m )
{
    int num = m;
    for (int n = 0; n < num ; n++ )//checa se o valor de i é menor que o numero de andares requisitado e soma +1 ao fim do codigo abaixo
    {

        for(int a = 0; a <= n;a++)//enquanto j for menor menor que o valor atual de i repetira o codigo abaixo, ex: i=2 ent printara * 3 vezes
        {
            printf("*");
        }
        printf("\n");//quebra a linha para que comece o proximo andar da escada
    }
}
