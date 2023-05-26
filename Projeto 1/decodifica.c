/*============================================================================*/
/* CSF13 - 2023-1 - TRABALHO 1                                                */
/*----------------------------------------------------------------------------*/
/* Joao Guilherme Menegassi Silva - joaosilva.2005@alunos.utfpr.edu.br        */
/*============================================================================*/
/* Implementa��o da fun��o decodifica. */
/*============================================================================*/

#include"trabalho1.h"

//Declara��o da fun��o do trabalho.
void decodificaStreamRBD (int n_bits, int preenche);

//Fun��es Auxiliares.
unsigned int pegaProximoByteRBD ();
void enviaPixel (unsigned char pixel);

void decodificaStreamRBD (int n_bits, int preenche)
{
    // Declara��o das variaveis.
    int byte;
    int aux;
    int i, moveBits = 8 - n_bits;

    // Armazena o primeiro byte.
    byte = pegaProximoByteRBD();

    while (byte != 0xFFFFFFFF)
    {
        /* O loop ir� rodar at� o 0, pois iremos usar o 0 na conta, vendo que no ultimo conjunto de n_bits
        o byte n�o deveria mover nenhuma casa para a direita, pensei em usar a variavel i para essa fun��o.*/
        for (i = 8 / n_bits - 1; i >= 0 ; i--)
        {
            // Move para a direita at� i = 0;
            aux = byte >> n_bits * i;
            aux = aux << moveBits;
            enviaPixel(aux);
        }
        byte = pegaProximoByteRBD();
    }
}
