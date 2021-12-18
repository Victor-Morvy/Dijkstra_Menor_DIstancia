#include <stdio.h>
#include <stdlib.h>

#define NOS 8
#define VERTICES 13

#define MATRIXSIZE 6
#define INF 999999

int** mat;

int pertence(int* vec, int value)
{
    for(int i = 1; i < MATRIXSIZE; i++)
    {
        int val = vec[i];
        if(val == value)
            return i;
    }
    return -1;
}

//retorna o valor
int procMenorValor( int p, int* vec, int* ref_index, int* vecIN )
{
    int tmp_value = 100000;
    int tmp_value_ = 100000;

    for(int i = 1; i < MATRIXSIZE; i++)
    {
        tmp_value_ = vec[i];

        int vecValue = vec[i];
        int p1 = vecValue != -1;
        int p2 = tmp_value_ < tmp_value;
        int p3 = pertence(vecIN, i) == -1;
        if(p1 && p2 && p3)
        {
            tmp_value = tmp_value_;
            *ref_index = i;
        }
    }
    return tmp_value;
}

int procuraVazio(int* vec, int size)
{
   for(int i = 0; i < size; i++)
   {
       if(vec[i] == INF || vec[i] == -1)
           return i;
   }
   return -1;
}

int valMin(val1, val2)
{
    return val1 < val2 ? val1 : val2;
}

void printVec(char* prefix, int* vec, int vecSize)
{
/*    printf("%s ", prefix);

    for(int i = 0; i < vecSize; i++)
    {
        printf("%i ", vec[i]);
    }

    printf("\n");
*/
//    system("PAUSE");
}

void pushVec(int* vec, int value)
{
    int index = procuraVazio(vec, MATRIXSIZE);
    vec[index] = value;

    printVec("vecNow", vec, MATRIXSIZE );
}


int main()
{
//    No* knowledgeNodeListIN = NULL;
//    No* tmpZ = NULL;
//    No* tmpP = NULL;

//    int distNodeINSize = 0;
//    int* distNodeIN = NULL;

//    int lastDistance;

//    No* new1 = createNo(1, 0);
//    No* new2 = createNo(0, 1);
//    No* vecTest = createNo(0, 0);
//    pushNo(vecTest, new1);
//    pushNo(vecTest, new2);

//    No*

    mat = (int**) malloc(sizeof(int*) * MATRIXSIZE );
    for(int i = 0; i<MATRIXSIZE; i++) mat[i] = (int *)malloc(MATRIXSIZE * sizeof (int));

    mat[0][0] = INF;
    mat[1][0] = 3;
    mat[2][0] = 8;
    mat[3][0] = 4;
    mat[4][0] = INF;
    mat[5][0] = 10;

    mat[0][1] = 3;
    mat[1][1] = INF;
    mat[2][1] = INF;
    mat[3][1] = 6;
    mat[4][1] = INF;
    mat[5][1] = INF;

    mat[0][2] = 8;
    mat[1][2] = INF;
    mat[2][2] = INF;
    mat[3][2] = INF;
    mat[4][2] = 7;
    mat[5][2] = INF;

    mat[0][3] = 4;
    mat[1][3] = 6;
    mat[2][3] = INF;
    mat[3][3] = INF;
    mat[4][3] = 1;
    mat[5][3] = 3;

    mat[0][4] = INF;
    mat[1][4] = INF;
    mat[2][4] = 7;
    mat[3][4] = 1;
    mat[4][4] = INF;
    mat[5][4] = 1;

    mat[0][5] = 10;
    mat[1][5] = INF;
    mat[2][5] = INF;
    mat[3][5] = 3;
    mat[4][5] = 1;
    mat[5][5] = INF;

    //printVec("mat", mat[0], MATRIXSIZE);

    //////////////////////////////////////////////
    ///
    ///
    ///
    ///

    //from x to y (0 to 5
    int x = 0, y = 5;

    int* IN = (int*) malloc( sizeof (int) * MATRIXSIZE ); //nos conhecidos pelo caminho minimo de x

    int p; //temporarios

    int* d = (int*) malloc( sizeof (int) * MATRIXSIZE ); //para cada no, distancia em x usando nos em IN

    int* s = (int*) malloc( sizeof (int) * MATRIXSIZE ); //para cada nó, nó anterior no caminho mínimo

    int distAnterior;

    for(int i = 0; i < MATRIXSIZE; i++)
    {
        IN[i] = -1;
        s[i] = -1;
        d[i] = INF;
    }

    //inicia o conjunto in e os vetores d e s
    IN[0] = 0; //0 inicial
    d[0] = 0;

    //para todos os nós z não pertencentes a IN
    for(int i = 1; i < MATRIXSIZE; i++)
    {
        s[i] = -1;
        d[i] = mat[x][i];

    }
//    printVec("mat ", d, MATRIXSIZE);

    p = x;

//    int tmpValue = 1;
    //coloca nós em IN
//    int pertence_ = pertence(IN, y);

    while(pertence(IN, y) == -1)
    {
//            printf("%d\n", pertence_);
//        int index = pertence(d, p);
//        int tmp_index;
        int menorValor = procMenorValor(p, d, &p, IN);
        pushVec(IN, p);
        printVec("IN", IN, MATRIXSIZE);
//        pushVec(IN, menorValor)
        for(int i = 0; i < MATRIXSIZE; i++)
        {
            if(pertence(IN, i) == -1)
            {
                distAnterior = d[i];
                int distMat = mat[p][i];
                int dist = d[p];
                int val_min = valMin(d[i], (dist + distMat));
                d[i] = val_min;
                if(d[i] < distAnterior)
                {
                    s[i] = p;
                }
            }
            else
            {
                //printf("pertence %d \n", i);

            }
        }
    }

    printf("Caminho\n");

    printf("%d\n", y);

    for(int i = y; i >= 0; i--)
    {
        if(s[i] != -1)
            printf("%d\n", s[i]);
    }
    printf("%d\n", x);


	printf("\nA distancia percorrida e %d", d[y]);

//    while(pertence(IN, ))

//    while()

    //---------------------------------------------//

//    for(int i = 0; i < MATRIXSIZE; i++)
//    {
//        if(vec[i] == value)
//            return i;
//    }



//    No* novec = montarGrafo();

    //printf("Hello World!\n");
    return 0;
}
