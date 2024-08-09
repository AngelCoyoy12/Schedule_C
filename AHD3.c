#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char pedirTexto[100];

void IngresarpedirTexto() {
    printf("Ingrese una cadena de pedirTexto: ");
    scanf(" %[^\n]", pedirTexto);
}

void guardarBin() {
    FILE *miPuntero = fopen("mi_archivo.bin", "wb");

    if (miPuntero == NULL) {
        printf("Error al abrir el archivo\n");
        return 1;
    }

    fwrite(pedirTexto, sizeof(char), strlen(pedirTexto), miPuntero);
    printf("Archivo .bin guardado exitosamente\n");
    fclose(miPuntero);
}

void guardarTxt() {
    FILE *archivo_1 = fopen("archivo.txt", "w");

    if (archivo_1 == NULL) {
        printf("Error al abrir el archivo\n");
        return 1;
    }

    fprintf(archivo_1, "%s", pedirTexto);
    printf("Archivo .txt guardado exitosamente\n");
    fclose(archivo_1);
}

int main() {
    int OpcionSeleccionada;

    do {
        printf("\nElija la opcion que guste\n");
        printf("1. Escribir una cadena de pedirTexto\n");
        printf("2. Guardar la cadena de pedirTexto en formato '.bin'\n");
        printf("3. Guardar la cadena de pedirTexto en formato '.txt'\n");
        printf("4. Salir\n");

        printf("Seleccione una opcion: ");
        scanf("%d", &OpcionSeleccionada);

        switch (OpcionSeleccionada) {
            case 1:
                IngresarpedirTexto();
                break;
            case 2:
                guardarBin();
                break;
            case 3:
                guardarTxt();
                break;
            case 4:
                printf("Saliendo del programa\n");
                break;
            default:
                printf("Opcion invalida. Por favor, seleccione de nuevo.\n");
        }
    } while (OpcionSeleccionada != 4);

}
