#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <Windows.h>
#include <conio.h>

// Samuel Gulart - 10/03

void geraSenha(unsigned int q, FILE *arquivo, char c);

void main(void){

    setlocale(LC_ALL, "Portuguese");
    unsigned int quant;
    char c;

    printf("        ,--.                                                              ,--.");
    Sleep(100);
    printf("\n    ,--/  /|    ,---,.                       ,----..       ,---,.       ,--.'|");
    Sleep(100);
    printf("\n ,---,': / '  ,'  .' |        ,---,         /   /   \\    ,'  .' |   ,--,:  : |");
    Sleep(100);
    printf("\n :   : '/ / ,---.'   |       /_ ./|        |   :     : ,---.'   |,`--.'`|  ' :");
    Sleep(100);
    printf("\n |   '   ,  |   |   .' ,---, |  ' :        .   |  ;. / |   |   .'|   :  :  | |");
    Sleep(100);
    printf("\n '   |  /   :   :  |-,/___/ \\.  : |        .   ; /--`  :   :  |-,:   |   \\ | :");
    Sleep(100);
    printf("\n |   ;  ;   :   |  ;/| .  \\  \\ ,' '        ;   | ;  __ :   |  ;/||   : '  '; |");
    Sleep(100);
    printf("\n :   '   \\  |   :   .'  \\  ;  `  ,'        |   : |.' .'|   :   .''   ' ;.    ;");
    Sleep(100);
    printf("\n |   |    ' |   |  |-,   \\  \\    '         .   | '_.' :|   |  |-,|   | | \\   |");
    Sleep(100);
    printf("\n '   : |.  \\'   :  ;/|    '  \\   |         '   ; : \\  |'   :  ;/|'   : |  ; .'");
    Sleep(100);
    printf("\n |   | '_\\.'|   |    \\     \\  ;  ;         '   | '/  .'|   |    \\|   | '`--'");
    Sleep(100);
    printf("\n '   : |    |   :   .'      :  \\  \\        |   :    /  |   :   .''   : |");
    Sleep(100);
    printf("\n ;   |,'    |   | ,'         \\  ' ;         \\   \\ .'   |   | ,'  ;   |.'");
    Sleep(100);
    printf("\n '---'      `----'            `--`           `---`     `----'    '---'    \n\n\n");
    Sleep(100);
    system("COLOR 1F");
    printf(" Entre com o tamanho de senha desejado  ");
    scanf("%ld", &quant);
    system("@cls||clear");
    printf("        ,--.                                                              ,--.");
    printf("\n    ,--/  /|    ,---,.                       ,----..       ,---,.       ,--.'|");
    printf("\n ,---,': / '  ,'  .' |        ,---,         /   /   \\    ,'  .' |   ,--,:  : |");
    printf("\n :   : '/ / ,---.'   |       /_ ./|        |   :     : ,---.'   |,`--.'`|  ' :");
    printf("\n |   '   ,  |   |   .' ,---, |  ' :        .   |  ;. / |   |   .'|   :  :  | |");
    printf("\n '   |  /   :   :  |-,/___/ \\.  : |        .   ; /--`  :   :  |-,:   |   \\ | :");
    printf("\n |   ;  ;   :   |  ;/| .  \\  \\ ,' '        ;   | ;  __ :   |  ;/||   : '  '; |");
    printf("\n :   '   \\  |   :   .'  \\  ;  `  ,'        |   : |.' .'|   :   .''   ' ;.    ;");
    printf("\n |   |    ' |   |  |-,   \\  \\    '         .   | '_.' :|   |  |-,|   | | \\   |");
    printf("\n '   : |.  \\'   :  ;/|    '  \\   |         '   ; : \\  |'   :  ;/|'   : |  ; .'");
    printf("\n |   | '_\\.'|   |    \\     \\  ;  ;         '   | '/  .'|   |    \\|   | '`--'");
    printf("\n '   : |    |   :   .'      :  \\  \\        |   :    /  |   :   .''   : |");
    printf("\n ;   |,'    |   | ,'         \\  ' ;         \\   \\ .'   |   | ,'  ;   |.'");
    printf("\n '---'      `----'            `--`           `---`     `----'    '---'    \n\n\n");
    printf(" Selecione uma configuração de senha:\n\n");
    printf(" 1  Caracteres especiais + Numeros + Letras\n\n");
    printf(" 2  Caracteres especiais + Numeros\n\n");
    printf(" 3  Caracteres especiais + Letras\n\n");
    printf(" 4  Letras + Numeros\n\n ");
    c = getch();

    FILE *arquivo = fopen("senha.txt", "w");

    if(arquivo == NULL) exit(-1);

    geraSenha(quant, arquivo, c);

    fclose(arquivo);

    char mensagem[] = {'s', 'u', 'a', ' ', 's', 'e', 'n', 'h', 'a', ' ', 'f', 'o', 'i', ' ', 'g', 'e', 'r', 'a', 'd', 'a', ' ',
    'e', 'm', ' ', 'u', 'm', ' ', 'a', 'r', 'q', 'u', 'i', 'v', 'o', ' ', 't', 'x', 't', '!'};

    for(int i = 0; i < 40; ++i){
        printf("%c", mensagem[i]);
        Sleep(50);
    }

    Sleep(2000);
    system("@cls||clear");

    exit(0);
}

void geraSenha(unsigned int q, FILE *arquivo, char c){
    int index = 0, dado;
    srand(time(NULL));

    do{
        if(c == '1'){
            dado = 48 + (rand() % 74);
            fprintf(arquivo, "%c", dado);
            ++index;
        }else if(c == '2'){
            dado = 33 + (rand() % 24);
            fprintf(arquivo, "%c", dado);
            ++index;
        }else if(c == '3'){
            dado = 58 + (rand() % 68);
            fprintf(arquivo, "%c", dado);
            ++index;
        }else if(c == '4'){
            dado = 48 + (rand() % 74);
            if((dado > 57 && dado < 66) || (dado > 90 && dado < 97)) continue;
            fprintf(arquivo, "%c", dado);
            ++index;
        }
    } while(index != q);
}
