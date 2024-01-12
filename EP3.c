/***************************************************************/
/**                                                           **/
/**   João Pedro Frota Canabrava      Número USP : 14681160   **/
/**   Exercício-Programa 03                                   **/
/**   Professor: Cristina Gomes Fernandes                     **/
/**   Turma: 02                                               **/
/**                                                           **/
/***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_PIXELS 1000000
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
double entropy(int v_max, int N, int image[], int col, int row);
int rand2166f(int seed);

int main(int argc, char *argv[]) {

    int col, row, v_max;
    int *image;
    int option = atoi(argv[1]);
    int key = atoi(argv[2]);

    read_image(&col, &row, &v_max, image);

    image = malloc(col * row * sizeof(int));

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

    free (image);

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

    int N, key, key2;
    double entropia, entropia_parcial;

    /*Inicializa variáveis*/

    key = 0;
    
    N = col*row;
    
    decode_in_loco(col, row, v_max, image, key);

    entropia = entropy(v_max, N, image, col, row);

    encode(col, row, v_max, image, key);

    key2 = 0;

    /*Decodifica imagem e mede menor entropia*/

    for(key = 1; key <= max_key; key++){
        
        decode_in_loco(col, row, v_max, image, key);

        entropia_parcial = entropy(v_max, N, image, col, row);
       
        if(entropia_parcial < entropia){
            entropia = entropia_parcial;
            key2 = key;
        }
        
        encode(col, row, v_max, image, key);
    }
    
    decode_in_loco(col, row, v_max, image, key2);
}

double entropy(int v_max, int N, int image[], int col, int row){

   int cont_fi[v_max], k, pixel_value, x;
   double fi[v_max], ent[v_max], entropia = 0;

   for(k = 0; k < v_max; k++){
        cont_fi[k] = 0;
    }

    x = (N/row) * 3;

    for(k = 0; k < x; k++){
        pixel_value = image[k];
        cont_fi[pixel_value] += 1;
    }
    
    for(k = 0; k < v_max; k++){

        fi[k] = cont_fi[k];
        fi[k] /= x;

        if(fi[k] == 0){
            ent[k] = 0;
        }
        else{
            ent[k]= fi[k]*(log(1/fi[k]));
        }
        entropia += ent[k];
    }
    return  entropia;
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