//inclusao de bibliotecas para informar ao compilador que especificacoes externas serao utilizadas
#include <stdio.h>   //biblioteca para uso de funcoes de entrada e saida de dados
#include <stdlib.h>  //biblioteca para uso de comandos de controle de processos como o exit, system cls, etc.
#include <math.h>    //biblioteca para uso de funcoes matematicas

# define TAM_ARRAY

float array[], resultado, original; //array sem tamanho definido para nao limitar o historico da calculadora
int contador = 0; //usar como indice do array
int expoente;

int main(void){
    int opcao; //Variável do menu
    int numero1, numero2, numero3; //Números da operação
    
    /*estrutura de repeticao while abaixo utilizada para que o programa continue retornando ao menu e 
    realizando operacoes enquanto o usuario nao escolher a opcao 10 (condicao do while) que representa
    a saida do programa*/

    while (opcao != 10){           
        printf("\n<1> Somar");      
        printf("\n<2> Subtrair");
        printf("\n<3> Multiplicar");
        printf("\n<4> Dividir");
        printf("\n<5> Exponenciar");
        printf("\n<6> Racionalizar");
        printf("\n<7> Equacao 2 Grau");
        printf("\n<8> Equacao 3 Grau");
        printf("\n<9> Fatorial");
        printf("\n<10> Sair");
        printf("\n<11> Historico");
        printf("\n\nEscolha a operacao: ");
        scanf("%d", &opcao);                    //scanf recebe e atribui um valor pra variavel opcao
        
        if((opcao >= 1) && (opcao <= 6)){       //if usado apenas para as opçoes que operam pelo menos um numero
            printf("Digite um numero: ");
            scanf("%d", &numero1);
            if (opcao <= 4){                    //if usado para as opçoes que operam dois numeros
                printf("Digite um numero: ");
                scanf("%d",&numero2);
            }
            
        }

        switch (opcao){ 
        /*no comando switch o conteudo da variavel opcao vai ser comparado com os possiveis resultados
        solicitados no menu, o comando case ira operar de acordo com o valor alocado a variavel opcao*/
        case 1:
            somar(numero1,numero2); //chama a funcao somar
            break; //break usado para sair do comando switch case sem ter que realizar as outras instrucoes
        case 2:
            subtrair(numero1,numero2);
            break;
        case 3:
            multiplicar(numero1,numero2);
            break;
        case 4:
            dividir(numero1,numero2);
            break;
        case 5: 
            printf("Escolha o expoente: ");
            scanf("%d", &expoente);
            potencia(numero1,expoente);
            break;
        case 6:
            raiz(numero1);
            break;
        case 7:
            printf("Digite o A da equacao: ");
            scanf("%d", &numero1);
            printf("Digite o B da equacao: ");
            scanf("%d", &numero2);
            printf("Digite o C da equacao: ");
            scanf("%d", &numero3);
            funcao2Grau(numero1,numero2,numero3);
            break;
        case 8:
    
            break;
        case 9:
            printf("Digite um numero: ");
            scanf("%d", &numero1);
            fatorar(numero1);
            break;
        case 10:
            exit(0); //para saida do programa, sem erro, caso a opcao 10 (case 10) seja selecionada
            break;
        case 11:     // historico
            for (int i = 0; i < contador; i++){
                printf("%.2f\n", array[i]);
            } 
            /*o laco de repeticao for acima servirá para o historico da calculadora. Na primeira parte eh atribuido um valor inicial
            igual a zero para o laço de repeticao, depois a condiçao de controle desse laço e por fim um incremento no indice do loop.
            Nesse caso, enquanto a variavel i for menor que a variavel contador(que ira conter os resultados das operacoes da calculadora)
            ela sofrera incremento e sera armazenada no array i para ser exibida quando a opcao historico for selecionada.*/
            
            break;
        default: //palavra-chave reservada para caso o usuario digite um valor invalido no menu.
            printf("Opcao invalida. Digite novamente.");   //mensagem que sera exibida.
            break;
        }
        if ((opcao >= 1) && (opcao <= 6) || (opcao == 9)){ //if que incrementa os resultados das operacoes no   
            contador++;                                    //array contador para ser usado no historico acima.
        }
        printf("\n");
        system("pause"); //executa o comando pause do S.O. e espera o usuario apertar alguma tecla para continuar.
        system("cls");   //limpa a tela de saida do programa. 
    }
}

//funcoes fora da main

int somar(numero1,numero2){              //funcao que sera chamada pela main.
    resultado = numero1 + numero2;       //operacao e armazenamento na variavel resultado.
    array[contador] = resultado;         //armazena o resultado no array contador para o historico.
    printf("%.2f", resultado);           //saida do resultado da operacao.
}

int subtrair(numero1,numero2){
    resultado = numero1 - numero2;
    array[contador] = resultado;
    printf("%.2f", resultado);
}

int multiplicar(numero1,numero2){
    resultado = numero1 * numero2;
    array[contador] = resultado;
    printf("%.2f", resultado);
}

int dividir(numero1,numero2){
    if (numero2 == 0){                              //if para caso o divisor for igual a zero.
        printf("Nao eh possivel dividir por zero"); //Nesse caso eh impresso uma mensagem que nao se pode dividir por zero
        contador--;                                 //e o contador decrementa esse resultado para nao sair no historico.
    }else{
        resultado = numero1 / numero2;
        array[contador] = resultado;
        printf("%.2f", resultado);
    }
}

int potencia(numero1,expoente){                     //Potencia sem a funcao pow como requisitado.
    if(expoente == 0){                              //If para o expoente igual a zero, retornando resultado 1.
            resultado = 1;
            array[contador] = resultado;
        }else if(expoente == 1){                    //Else if para expoente igual a um, retornando como resultado o proprio numero.
            resultado = numero1;
            array[contador] = resultado;
        }else{
            original = numero1;
            for (int i = 1; i < expoente; i++){     //for para operar uma potencia sem uso da funcao pow
                numero1 = numero1 * original;       //o novo numero sera igual a ele mesmo multiplicado por seu valor original ate que a
            }                                       //variavel i alcance o valor da variavel expoente, encontrando o resultado da potenciação
            resultado = numero1;                    
            array[contador] = resultado;
        }
        printf("%.2f",resultado);
    
}

int raiz(numero1){
    resultado = sqrt(numero1); //Uso da funcao sqrt para realizar raiz quadrada.
    array[contador] = resultado;
    printf("%.2f", resultado);
}

int funcao2Grau(numero1,numero2,numero3){
    float delta = (numero2*numero2)-4*numero1*numero3; // delta = b²-4.a.c
    if(delta>=0){ 
        float x1 = ((numero2*(-1))+sqrt(delta))/(2*numero1); //x1 = -b + (raiz de delta)/2a
        float x2 = ((numero2*(-1))-sqrt(delta))/(2*numero1); //x2 = -b - (raiz de delta)/2a
        printf("x' eh: %f",x1);
        printf("\nx'' eh: %f",x2);
    }
    else{ //Else porque quando o delta eh menor que zero, nao existem raizes reais
        printf("A raiz nao eh real, tente com novos valores");
    }
}
/*
// int funcao3Grau(){
    
// }
*/
int fatorar(numero1){
    int fatorial;
    if (numero1 == 0){ //if para o fatorial de zero que, por definição, eh igual a 1.
        fatorial = 1;
        resultado = fatorial;
        array[contador] = resultado;
        printf("%.2f", resultado);
    }else{
        for(fatorial = 1; numero1 > 1; numero1 = numero1 - 1){//Algoritmo para a realizacao de fatorial.
            fatorial = fatorial * numero1;                    //Digita-se uma entrada para o numero1, enquanto o numero1 for maior que 1
        }                                                     //subtrai-se 1 dele, e multiplica-se pelo seguinte, ate que a variavel numero1
        resultado = fatorial;                                 //alcance o valor 2 quando faz-se a ultima multiplicacao e encontra-se o fatorial.
        array[contador] = resultado;
        printf("%.2f", resultado);
    }
}
