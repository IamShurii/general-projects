#include <stdio.h>
#include <cs50.h>

int termo_pa(pri, raz, termo);

int main(void)
{
    const int prim = get_int("Primeiro termo: );
    const int raz = get_int("Razão: );
    int x = get_int("Digite um numero: ");
    num = termo_pa(prim, raz, x);
    printf("Termo %i = %i\n", x, num);
}

int termo_pa(pri, raz, termo)
{
    nm_procurado = pri + (termo-1) * raz;
    return nm_procurado;
#