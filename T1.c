#include <stdio.h>

int main(void)
{
    int precios[4]; //declaramos los 4 precios para los 4 tipos de cajas
    printf("Ingrese el valor como numero entero para los precios de las cajas de alfajores;\n");
    printf("\nPrecio para la caja de solo chocolates = ");
    scanf("%d", &precios[0]);
    printf("\nPrecio para la caja de solo dulce de leche = ");
    scanf("%d", &precios[1]);
    printf("\nPrecio para la caja de solo fruta = ");
    scanf("%d", &precios[2]);
    printf("\nPrecio para la caja de mixto = ");
    scanf("%d", &precios[3]);
    //guardamos todos los precios para las cajas de alfajores en el vector;
    
    printf("Acontinuacion le pedimeros los datos de cada venta, esto incluye operario, el tipo de alfajor que vendio, y la cantidad\n");
    int venta_total = 0; // declaramos las ventas totales para cuando finalicemos la primer venta;
    int continuar = 1; //declaramos una variables de tipo entera para usarla como referencia si se desea seguir ingresando producciones;
    int operario; //declaramos los operarios como un numero entero;
    int cantidad_alfa_vendidos; //declaramos la cantidad de alfajores vendidos
    int tipo_alfajor_vendido; //declaramos el tipo de alfajor que vendio como un numero entero;
    int ganancias[4] = {0}; // declaramos las ganancias
    int alfajores_cada_operario[6][4] = {0};// declaramos la cantidad de alfajores vendidos por operacio dentro de listas dentro de listas
    int alfajores_f_produccion_operario[6] = {0}; // declaramos la cantidad de alfajores fuera de produccion por operario


    while(continuar == 1) { //mientrras que contunuar sea 1, se seguiran pidiendo datos; 
    
    printf("\nIngrese el operario, teniendo en cuenta que hay de 1 a 6\n");
    scanf("%d", &operario); //guardamos el operario seleccionado

    printf("Ingrese el tipo de alfajor vendido ingresando un numero del 1 al 4, teniendo en cuenta lo siguiente.\n1 = chocolate\n2 = dulce de leche\n3 = fruta\n4 = mixto\n");
    scanf("%d", &tipo_alfajor_vendido); //guardamos el tipo de alfajor que vendio;

    printf("Ingrese la cantidad de alfajores vendidos\n");
    scanf("%d", &cantidad_alfa_vendidos); // guardamos la cantidad de alfajores vendidos


    int cajas_completas = cantidad_alfa_vendidos / 6; //declaramos las cajas completas
    int fuera_produccion = cantidad_alfa_vendidos % 6; // declaramos los alfajores que quedaron fuera de produccion
    
    venta_total++; // sumamos 1 a venta total por cada venta completada;
    
    ganancias[tipo_alfajor_vendido - 1] += cajas_completas * precios[tipo_alfajor_vendido - 1];        
    alfajores_cada_operario[operario - 1][tipo_alfajor_vendido] += cantidad_alfa_vendidos;
    alfajores_f_produccion_operario[operario - 1] += fuera_produccion;

    int respuesta; // declaramos una respusta de tipo entero para luego decida si se seguira pidiendo datos
    printf("Desea continuar ingresando datos de ventas?(Ingrese 1 para si o 2 para no)");
    scanf("%d", &respuesta); // guardamos la respuesta ingresada
    continuar = respuesta;




    } // fin del ciclo while si ya no desean seguir ingresando datos;

    printf("Cantidad total de entregas: %d\n", venta_total);
    printf("Ganancia por tipo de alfajor:\n");
    for (int i = 0; i < 4; i++) {
        printf("Tipo de alfajor %d: $%d\n", i + 1, ganancias[i]);
    }
    return 0;

}
