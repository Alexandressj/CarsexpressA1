
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <unistd.h>

typedef struct
{
    char marca[30], modelo[30], placa[30];
    int anofab;
} Carro;

Carro cartotallist[10];

void insertionSort(Carro cartotallist[10], int n);
void mostrarveiculos(int _arraysize);
int inputveiculos();
Carro inputveiculo();

int main(void)
{

    int _arraysize;

    int comeco;

inicio:
    printf("\nBEM VINDO A CARS EXPRESS\n");
    printf("OQUE O SENHOR DESEJA FAZER?\n");
    printf("PARA SAIR DO PROGRAMA APERTE 0\n");
    printf("PARA REGISTRAR VEICULOS APERTE  1\n");
    scanf("%d", &comeco);

    if (comeco == 0)
    {
        printf("saindo do programa");
        sleep(1);
        system("cls");
        exit;
    }
    else if (comeco == 1)
    {
        printf("acessando registro de veiculos");
        sleep(1);
        system("cls");
        _arraysize = inputveiculos();
        insertionSort(cartotallist, _arraysize);
    }
    else if (comeco < 0 || comeco > 1)
    {
        printf("Opcao Invalida,tente novamente\n");
        printf("voltando pro comeco");
        sleep(1);
        system("cls");
        goto inicio;
    }

    int ini2;
label:
    printf("\n--------------------------//--------------------------\n");
    printf("Agora que ja possuimos uma quantidade de veiculos registrados em nosso sistema\n");
    printf("oque o senhor deseja fazer?\n");
    printf("--------------------------//--------------------------\n");
    printf("para sair do programa aperte 0:\n");
    printf("--------------------------//--------------------------\n");
    printf("para ver a lista de veiculos registrados aperte 2:\n");

    scanf("%d", &ini2);

    if (ini2 == 0)
    {
        printf("\nSaindo do programa");
        sleep(1);
        system("cls");
        exit;
    }
    else if (ini2 == 2)
    {
        printf("\nProcurando Lista...");
        sleep(2);
        system("cls");
        mostrarveiculos(_arraysize);
    }
}

Carro inputveiculo()
{
    Carro carroatual;

    printf("qual a placa do seu veiculo?\n");
    scanf("%s", &carroatual.placa);
    printf("qual a marca do seu veiculo?\n");
    scanf("%s", &carroatual.marca);
    printf("qual o modelo do seu veiculo?\n");
    scanf("%s", &carroatual.modelo);
    printf("qual o ano de frabricacao do seu veiculo?\n");
    scanf("%d", &carroatual.anofab);

    printf("\nO seu veiculo foi registrado\n");
    sleep(1);
    system("cls");

    return carroatual;
}

int inputveiculos()
{

    int quanticarro;
voltando:
    printf("--------------------------//--------------------------\n");
    printf("BEM VINDO AO NOSSO SISTEMA DE REGISTRO\n");
    printf("--------------------------//--------------------------\n");
    printf("NAO ACEITAMOS MAIS QUE 10 REGISTROS POR VEZ\n");
    printf("--------------------------//--------------------------\n");
    printf("Quantos veiculos voce deseja registrar:\n");
    scanf("%d", &quanticarro);

    sleep(1);
    system("cls");

    if (quanticarro > 10)
    {
        printf("voce tentou registrar carros demais\n");
        printf("nao aceitamos mais que 10 registros por vez\n");
        printf("nosso sistema ira alterar a quantidade colocada para 10");
        quanticarro = 10;
    }
    else if (quanticarro < 0)
    {
        printf("Valor invalido");
        sleep(1);
        system("cls");
        goto voltando;
    }

    Carro arrayatualcars[quanticarro];

    for (int i = 0; i < quanticarro; i++)
    {
        printf("\n--------------------------//--------------------------\n");
        printf("veiculo %d: \n", i + 1);
        Carro _carroatual = inputveiculo();
        arrayatualcars[i] = _carroatual;
    }

    for (int j = 0; j < quanticarro; j++)
    {
        cartotallist[j] = arrayatualcars[j];
    }
    return quanticarro;
}

void mostrarveiculos(int _arraysize)
{
    int listchoose;

dec:
    printf("\n--------------------------//--------------------------");
    printf("\nBem vindo a lista");
    printf("\n--------------------------//--------------------------");
    printf("\nPara sair do programa digite 0:");
    printf("\n--------------------------//--------------------------");
    printf("\nvoce deseja acessar a lista por:");
    printf("\n--------------------------//--------------------------");
    printf("\nMarca do veiculo , DIGITE 1:");
    printf("\n--------------------------//--------------------------");
    printf("\nModelo do veiculo , DIGITE 2:");
    printf("\n--------------------------//--------------------------");
    printf("\nPlaca do veiculo , DIGITE 3:");
    printf("\n--------------------------//--------------------------");
    printf("\nAno de fabricacao , DIGITE  4:\n");
    printf("--------------------------//--------------------------\n");

    scanf("%d", &listchoose);
    int anofabusuario;

    switch (listchoose)
    {
    case 0:
        printf("\nSaindo do programa");
        sleep(1);
        system("cls");
        exit;
        break;
    case 1:
        printf("\nRevelando a lista de veiculos Por marca\n");
        for (int a = 0; a < _arraysize; a++)
        {
            printf("\nMarcas Registradas: %s ", cartotallist[a].marca);
        }
        printf("\nDepois de 10 segundos o sistema ira retornar para tela de escolhas\n");
        sleep(10);
        system("cls");
        goto dec;
        break;
    case 2:
        printf("\nRevelando veiculos por Modelo\n");
        sleep(1);
        system("cls");
        for (int b = 0; b < _arraysize; b++)
        {
            printf("\nModelos registrados: %s", cartotallist[b].modelo);
        }
        printf("\nDepois de 10 segundos o sistema ira retornar para tela de escolhas\n");
        sleep(10);
        system("cls");
        goto dec;
        break;
    case 3:
        printf("\nRevelando veiculos por Placa");
        sleep(1);
        system("cls");
        for (int c = 0; c < _arraysize; c++)
        {
            printf("\nPlacas Registradas: %s", cartotallist[c].placa);
        }
        printf("\nDepois de 10 segundos o sistema ira retornar para tela de escolhas\n");
        sleep(10);
        system("cls");
        goto dec;
        break;
    case 4:

        printf("\nDeseja ver veiculos registrados por anos de fabricacao apartir de uma data ?, DIGITE 1:");
        printf("\n--------------------------//---------------------------------------------------");
        printf("\nDeseja ver todos os veiculos registrados ?, DIGITE 2\n");
        printf("\n--------------------------//---------------------------------------------------\n");

        scanf("%d", &anofabusuario);
        system("cls");
        if (anofabusuario == 1)
        {
            int userchoosingage;
            printf("deseja procurar por qual ano de fabricacao?");
            scanf("%d", &userchoosingage);
            for (int k = 0; k < _arraysize; k++)
            {
                if (cartotallist[k].anofab >= userchoosingage)
                {
                    printf("Anos de fabricacao: %d\n", cartotallist[k].anofab);
                }
            }
            printf("\nDepois de 10 segundos o sistema ira retornar para tela de escolhas\n");
            sleep(10);
            system("cls");
            goto dec;
        }
        else if (anofabusuario == 2)
        {
            printf("\nRevelando veiculos por ano de fabricacao");
            sleep(1);
            system("cls");
            for (int d = 0; d < _arraysize; d++)
            {

                printf("\nTemos com registro de: %d", cartotallist[d].anofab);
            }
            printf("\nDepois de 10 segundos o sistema ira retornar para tela de escolhas\n");
            sleep(10);
            system("cls");
            goto dec;
            break;
        }
    }
}

void insertionSort(Carro cartotallist[10], int _arraysize)
{
    int i, element, j;
    for (i = 1; i < _arraysize; i++)
    {
        element = cartotallist[i].anofab;
        j = i - 1;
        while (j >= 0 && cartotallist[j].anofab > element)
        {
            cartotallist[j + 1].anofab = cartotallist[j].anofab;
            j = j - 1;
        }
        cartotallist[j + 1].anofab = element;
    }
}