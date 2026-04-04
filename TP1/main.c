#include <stdio.h>
#include <stdlib.h>
#define BUFFER 1024

int main(){
    FILE *fp;
    char resultado[BUFFER];

    fp = popen("python getter.py", "r");
    if(fp != NULL){
        while(fgets(resultado, BUFFER, fp)!=NULL){
            printf("%s", resultado);
        }
        pclose(fp);
    }
    else{
        printf("No se pudo ejecutar el script");
        return 1;
    }
    return 0;
}