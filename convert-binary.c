#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    float nd;
    int numero_intero, resto, zero_nullo, bit[64], i, scelta, esponente, decimale, a, ascii;
    char numero[64];
    printf("              Da DECIMALE a QUALCOSA: \n- 0 Per la conversione Decimale    - Binario\n- 1 Per la conversione Decimale    - Ottale\n- 2 Per la conversione Decimale    - Esadecimale\n—————————————————————————————————————————————————— \n              Da QUALCOSA a DECIMALE: \n- 3 Per la conversione Binario     - Decimale\n- 4 Per la conversione Ottale      - Decimale\n- 5 Per la conversione Esadecimale - Decimale\n\nInserisci scelta: ");
    scanf("%d", &scelta);
    switch (scelta)
    {
    case 0:
        printf("Inserisci numero intero: ");
        scanf("%d", &numero_intero);
        printf("Inserisci il numero decimale: ");
        scanf("%f", &nd);
        do
        {
            for (i = 0; i <= 31; i++)
            {
                resto = numero_intero % 2;
                numero_intero = numero_intero / 2;
                bit[i] = resto;
            }
            zero_nullo = 0;
            for (i = 31; i >= 0; i--)
            {
                if (zero_nullo == 0 && bit[i] == 1)
                {
                    zero_nullo = 1;
                }
                if (zero_nullo == 1)
                {
                    printf("%d", bit[i]);
                }
            }
        } while (numero_intero != 0);
        if (nd != 0)
        {
            printf(".");
            do
            {
                nd = (float)nd * 2.0;
                if (nd >= 0 && nd < 1)
                {
                    printf("0");
                }
                else
                {
                    printf("1");
                    nd = nd - 1.0;
                }
            } while (nd != 0);
            return 0;
        }
        else
        {
            return 0;
        }
        break;
    case 1:
        printf("Inserisci numero intero: ");
        scanf("%d", &numero_intero);
        do
        {
            for (i = 0; i <= 31; i++)
            {
                resto = numero_intero % 8;
                numero_intero = numero_intero / 8;
                bit[i] = resto;
            }
            for (i = 31; i >= 0; i--)
            {
                if (zero_nullo == 0 && bit[i] == 1 || bit[i] == 2 || bit[i] == 3 || bit[i] == 4 || bit[i] == 5 || bit[i] == 6 || bit[i] == 7)
                {
                    zero_nullo = 1;
                }
                if (zero_nullo == 1)
                {
                    printf("%d", bit[i]);
                }
            }
        } while (numero_intero != 0);
        return 0;
        break;
    case 2:
        printf("Inserisci numero intero: ");
        scanf("%d", &numero_intero);
        do
        {
            for (i = 0; i <= 31; i++)
            {
                resto = numero_intero % 16;
                numero_intero = numero_intero / 16;
                bit[i] = resto;
            }
            for (i = 31; i >= 0; i--)
            {
                if (zero_nullo == 0 && bit[i] == 1 || bit[i] == 2 || bit[i] == 3 || bit[i] == 4 || bit[i] == 5 || bit[i] == 6 || bit[i] == 7 || bit[i] == 8 || bit[i] == 9 || bit[i] == 10 || bit[i] == 11 || bit[i] == 12 || bit[i] == 13 || bit[i] == 14 || bit[i] == 15)
                {
                    zero_nullo = 1;
                }
                if (zero_nullo == 1)
                {
                    if (bit[i] < 10)
                    {
                        printf("%d", bit[i]);
                    }
                    else
                    {
                        printf("%c", 'A' + bit[i] - 10);
                    }
                }
            }
        } while (numero_intero != 0);
        return 0;
        break;
    case 3:
        printf("Inserisci una sequenza di 0 e 1: ");
        scanf("%s", numero);
        esponente = (strlen(numero) - 1);
        a = esponente;
        for (i = 0; i <= a; i++)
        {
            if (numero[i] == '1')
            {
                decimale = pow(2, esponente) + decimale;
            }
            else if (numero[i] >= '1')
            {
                printf("Input non valido. Inserisci solo cifre binarie (0 o 1).\n");
                return 0;
            }
            esponente--;
        }
        printf("Il numero binario in decimale è %d\n", decimale);
        return 0;
    case 4:
        printf("Inserisci il numero ottale: ");
        scanf("%s", numero);
        esponente = strlen(numero) - 1;
        for (i = esponente; i >= 0; i--)
        {
            if (numero[i] == '1' || numero[i] == '2' || numero[i] == '3' || numero[i] == '4' || numero[i] == '5' || numero[i] == '6' || numero[i] == '7')
            {
                decimale += (pow(8, esponente - i) * (numero[i] - '0'));
            }
            else if (numero[i] >= '8')
            {
                printf("Input non valido\n");
                return 0;
            }
        }
        printf("Il numero ottale in decimale è %d\n", decimale);
        return 0;
        break;
    case 5:
        printf("Inserisci un numero esadecimale: ");
        scanf("%s", numero);
        esponente = strlen(numero) - 1;
        decimale = 0;
        for (i = 0; i <= esponente; i++)
        {
            ascii == 0;
            if (numero[i] >= '0' && numero[i] <= '9')
            {
                ascii = numero[i] - '0';
            }
            else if (numero[i] >= 'A' && numero[i] <= 'F')
            {
                ascii = numero[i] - 'A' + 10;
            }
            else if (numero[i] >= 'a' && numero[i] <= 'f')
            {
                ascii = numero[i] - 'a' + 10;
            }
            else
            {
                printf("Errore: Carattere non valido nel numero esadecimale.\n");
                return 0;
            }
            decimale += ascii * (pow(16, esponente - i));
        }
        printf("Il numero decimale corrispondente è: %d\n", decimale);
        return 0;
        break;
    default:
        break;
    }
    return 0;
}
