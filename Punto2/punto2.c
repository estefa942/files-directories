#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>


#define PATH_MAX 4096

int main(int argc, char* argv[]){

    if(argc > 4){
        printf("Se han ingresado demasiados parámetros.\n");
        return 1;
    }

    DIR *directorio;
    struct dirent *archivo;


    // Sin argumentos
    if(argc == 1){
        directorio = opendir(".");
        while((archivo = readdir(directorio)) != NULL){
            printf("%s\t", archivo->d_name);
        }    
        printf("\n");
        closedir(directorio);
        return 0;
    }

    // Único parámetro es -l, se hace uso del punto anterior
    if(argc == 2 && strcmp(argv[1],"-l") == 0) {

        directorio = opendir(".");
        char buffer[PATH_MAX];

        while((archivo = readdir(directorio)) != NULL){
            sprintf(buffer, "%s/%s", argv[1], archivo->d_name);    
            char file[100];
            strcpy(file, "./punto1.out ");
            strcat(file, archivo->d_name);
            int status = system(&file);
        }
        printf("\n");
        closedir(directorio);
        return 0;
    }

    // Cuando se le pasa un directorio unicamente
    if(argc == 2 && strcmp(argv[1],"-l") != 0) {
        directorio = opendir(argv[1]);
        while((archivo = readdir(directorio)) != NULL){
            printf("%s\n", archivo->d_name);
        }    
        printf("\n");
        closedir(directorio);
        return 0;
    }

    // Cuando se le pasa un directorio y -l
    if(argc == 3 && strcmp(argv[1],"-l") == 0){
        directorio = opendir(argv[2]);
        char buffer[PATH_MAX];

        while((archivo = readdir(directorio)) != NULL){
            sprintf(buffer, "%s/%s", argv[1], archivo->d_name);
            char file[100];
            strcpy(file, "./punto1.out ");
            strcat(file, argv[2]);
            strcat(file, "/");
            strcat(file, archivo->d_name);
            int status = system(&file);
        }   
        closedir(directorio);
        return 0;
    }
}