/***************************************************************/
/**                                                           **/
/**   João Pedro Frota Canabrava      Número USP : 14681160   **/
/**   Exercício-Programa 03                                   **/
/**   Professor: Cris                                         **/
/**   Turma: 02                                               **/
/**                                                           **/
/***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_PIXELS 100000
#define rand2166() (rand2166f(-1))
#define srand2166(seed) (rand2166f((seed)))
#define AA 16807
#define MM 2147483647

void output_image(int col, int row, int v_max, int image[]);
void read_image(int *col, int *row, int *v_max, int image[]);
void encode(int col, int row, int v_max, int image[], int key);
void decode(int col, int row, int v_max, int image[], int key, int decoded[]);
void decode_in_loco(int col, int row, int v_max, int image[], int key);
void decode_brute_force(int col, int row, int v_max, int image[], int max_key);
double entropy(int v_max, int N, int image[]);
int rand2166f(int seed);

int main(int argc, char *argv[]) {

    int col, row, v_max;
    int image[MAX_PIXELS];
    int option = atoi(argv[1]);
    int key = atoi(argv[2]);

    read_image(&col, &row, &v_max, image);


    /*Função codifica imagem*/
    if(option == 0){
        encode(col, row, v_max, image, key);
    }

    /*Função decodifica imagem com chave*/
    if(option == 1){
        decode_in_loco(col, row, v_max, image, key);
    }

    /*Função decodifica imagem na força bruta*/
    if(option == 2){
        decode_brute_force(col, row, v_max, image, key);
    }


    output_image(col, row, v_max, image);

    return 0;
}



void output_image(int col, int row, int v_max, int image[]){

    int i, j;

    printf("P2\n");
    printf("%d %d\n", col, row);
    printf("%d\n", v_max);

    /*Printa imagem*/

    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            printf("%03d ", image[i * col + j]);
        }
       printf("\n"); 
    }
}

void read_image(int *col, int *row, int *v_max, int image[]){

    int i, n;
    char Jogafora, Jogafora2;

    scanf("%c%c", &Jogafora, &Jogafora2);

    /*Le parametros*/

    scanf("%d %d", col, row);
    scanf("%d", v_max);

    /*Le imagem*/

    n = (*col) * (*row); /*Numero total de pixels*/

    for(i = 0; i < n; i++){
        scanf("%d", &image[i]);
    }

}

void encode(int col, int row, int v_max, int image[], int key){

    int i, n;

    n = col * row; /*Numero total de pixels*/

    srand2166(key);

    for(i = 0; i < n; i++){
        image[i] = (image[i] + (rand2166() % (v_max + 1))) % (v_max + 1);
    }

}

void decode(int col, int row, int v_max, int image[], int key, int decoded[]){

    int i, n;

    n = col * row; /*Numero total de pixels*/

    srand2166(key);

    for(i = 0; i < n; i++){
        decoded[i] = (image[i] - (rand2166() % (v_max + 1)) + (v_max + 1)) % (v_max + 1);
    }

}

void decode_in_loco(int col, int row, int v_max, int image[], int key){

    decode(col, row, v_max, image, key, image);
    
}

void decode_brute_force(int col, int row, int v_max, int image[], int max_key){

    int i, poss_key, N; /*Possível chave*/

    N = col * row;

    int image0[N], decoded[N];

    for(i = 0; i < col * row; i++){
        image0[i] = image[i];
    }

    for(poss_key = 0; poss_key <= max_key; poss_key++){

        srand2166(poss_key);
        decode_in_loco(col, row, v_max, poss_key, image);

       if(entropy(v_max, N, decoded) < entropy(v_max, N, image)){

            for(i = 0; i < col * row; i++){
                image[i] = decoded[i];
            }
        }
    }
}


double entropy(int v_max, int N, int image[]){

    int i, k, cont_fi;
    double entropia = 0, pi[v_max];

    for(i = 0; i < v_max; i++){
        cont_fi = 0;
        for(k = 0; k < N; k++){
            if(image[k] == i){
                cont_fi++;
            }
        }
        if(cont_fi > 0 && N != 0){
            pi[i] = cont_fi/(double)N; 
        } 
        else{
            pi[i] = 0;
        }
    }


    for(i = 0; i < v_max; i++){
        if(pi[i] != 0){
            entropia += (pi[i] * log(1/(pi[i])));
        }
    }

    return entropia;
}

int rand2166f(int seed) {
    static long r;
    if (seed >= 0) {
        r = seed;
        return 0;
    }
    r = (r * AA) % MM;
    return r;
}