/*
    DOAÇÃO DE ANIMAIS vs VENDA DE PRODUTOS
        Ganha o que chegar em 10 primeiro.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void mostrar_placar(int * pts_doacao_animais, int * pts_venda_produtos); //mostrar o placar (resultado)
void mostrar_placar_final(int * pts_doacao_animais, int * pts_venda_produtos);
//void sorteador(int * pts_doacao_animais, int * pts_venda_produtos, int * num_sorteado);

//---

int main(int argc, char * argv[]){
    int pts_doacao_animais = 0;
    int pts_venda_produtos = 0;
    int num_sorteado = 0;

    int tecla = 0;   

    srand(time(NULL)); //"semente" para função rand() para que gere numeros aleatorios

    while(pts_doacao_animais < 10 && pts_venda_produtos < 10){

        do{
            mostrar_placar(&pts_doacao_animais, &pts_venda_produtos);

            printf("\n\tTecle ESPACO para sortear... ");
            tecla = getch();

            //SORTEIO
            if(tecla == 32){ //32 = espaço
                do{
                    num_sorteado = rand() % 3;
                    if(num_sorteado == 1){
                        pts_doacao_animais++;
                    } else if(num_sorteado == 2){
                        pts_venda_produtos++;
                    }
                }while(num_sorteado == 0);                
            }

        } while(tecla != 32);

        printf("%d ", num_sorteado); //mostrar número sorteado
        getch();
    }

    mostrar_placar_final(&pts_doacao_animais, &pts_venda_produtos);
    printf("\t");
    do{
        tecla = getch();
    }while(tecla != 27); //13 = ESC

    return 0;
}

//---

void mostrar_placar(int * pts_doacao_animais, int * pts_venda_produtos){
    system("cls");
    printf("QUAL SISTEMA?\n\n");
    printf("\t1. DOACAO DE ANIMAIS: %d\n", *pts_doacao_animais);
    printf("\t2. VENDA DE PRODUTOS: %d\n", *pts_venda_produtos);
}

void mostrar_placar_final(int * pts_doacao_animais, int * pts_venda_produtos){
    system("cls");
    printf("QUAL SISTEMA?\n\n");
    
    if(*pts_doacao_animais == 10){
        printf("\t1. DOACAO DE ANIMAIS: %d [VENCEDOR!]\n", *pts_doacao_animais);
        printf("\t2. VENDA DE PRODUTOS: %d\n", *pts_venda_produtos);
    } else {
        printf("\t1. DOACAO DE ANIMAIS: %d\n", *pts_doacao_animais);
        printf("\t2. VENDA DE PRODUTOS: %d [VENCEDOR]\n", *pts_venda_produtos);
    }
    printf("\n");
}

/*
void sorteador(int * pts_doacao_animais, int * pts_venda_produtos, int * num_sorteado){
    do{
        *num_sorteado = rand() % 3;
        if(*num_sorteado == 1){
            *pts_doacao_animais++;
        } else if(*num_sorteado == 2){
            *pts_venda_produtos++;
        }
    }while(*num_sorteado == 0);
}
*/