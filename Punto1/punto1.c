#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

char *formatTime(time_t time);

int main(int argc, char *argv[])
{
    if(argc != 2) {
        printf("El número de argumentos es inválido\n");
        return 1;
    }   

    struct stat stat_st;


    if(stat(argv[1],&stat_st) < 0){
        printf("Ha ocurrido un error obteniendo la información del archivo.\n");
        return 1;
    }    
 
    printf("###### ACERCA DEL ARCHIVO: ######\n");
    printf("Nombre del archivo: %s\n", argv[1]);
    printf("Tamaño del archivo: %d bytes\n",stat_st.st_size);
    printf("Número de bloques que contiene el archivo: %d\n",stat_st.st_blocks);
    printf("Tamaño por bloque: %d\n",stat_st.st_blksize);
    printf("Número de links: %d\n",stat_st.st_nlink);
    printf("Último acceso al archivo: \t\t\t\t%s", formatTime(stat_st.st_atime));
    printf("Última modificación al archivo: \t\t\t%s", formatTime(stat_st.st_atime));
    printf("ID Usuario: %d\n",stat_st.st_uid);
    printf("ID Grupo: %d\n",stat_st.st_gid); 
    printf("Permisos que posee el archivo: ");
    printf( (S_ISDIR(stat_st.st_mode)) ? "d" : "-");
    printf( (stat_st.st_mode & S_IRUSR) ? "r" : "-");
    printf( (stat_st.st_mode & S_IWUSR) ? "w" : "-");
    printf( (stat_st.st_mode & S_IXUSR) ? "x" : "-");
    printf( (stat_st.st_mode & S_IRGRP) ? "r" : "-");
    printf( (stat_st.st_mode & S_IWGRP) ? "w" : "-");
    printf( (stat_st.st_mode & S_IXGRP) ? "x" : "-");
    printf( (stat_st.st_mode & S_IROTH) ? "r" : "-");
    printf( (stat_st.st_mode & S_IWOTH) ? "w" : "-");
    printf( (stat_st.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n");
 
 
    return 0;
}

char *formatTime(time_t t)
{
    char *c_time_string;
    c_time_string = ctime(&t);
    return c_time_string;
}