#include <stdio.h>
#include "grafo_matrizadj.h"

void lerArquivo(FILE *arquivo, int *consultas, Grafo *g)
{
    //Grafo g;
    int numVertices = 0;
    int arestas = 0;
    int v1 = 0;
    int v2 = 0;
    double peso = 0;
    if (arquivo == NULL) // Se houve erro na abertura
    {
        printf("ERROR: Problemas na abertura do arquivo\n");
        return;
    }
    fscanf(arquivo, "%d%d%d", &numVertices, &arestas, consultas);
    // printf("%d %d\n", vertices, arestas);
    inicializaGrafo(g, numVertices);
    imprimeGrafo(g);
    for (int i = 0; i < arestas; i++)
    {
        fscanf(arquivo, "%d%d%lf", &v1, &v2, &peso);
        if (v1 >= v2)
        {
            printf("ERRO: Os vértices devem ser inseridos de forma crescente");
            return;
        }

        printf("%d %d %lf\n", v1, v2, peso);
        insereArestaNDirecional(v1, v2, (peso*10), g);
    }

    for (int i = 0; i < *consultas; i++)
    {
        fscanf(arquivo, "%d%d", &v1, &v2);
       // printf("%d %d\n", v1, v2);
    }
}
int main()
{
    int consultas = 0; 
    FILE *file;

    file = fopen("entrada.txt", "rt");

    Grafo g;
    Grafo g1;
    int numVertices;
    int v1, v2;
    Peso peso;
 

    //inicializaGrafo(&g1, numVertices);
    
    lerArquivo(file, &consultas, &g);
    // printf("\n%d",consultas);
    imprimeGrafo(&g);
    return 0;
}