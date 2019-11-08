#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

int main()
{
    int flag1=0;
    int option;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
        printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario)\n");
        printf("3. Alta de empleado\n");
        printf("4. Modificar datos de empleado\n");
        printf("5. Baja de empleado\n");
        printf("6. Listar empleados\n");
        printf("7. Ordenar empleados\n");
        printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
        printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario)\n");
        printf("10. Salir\n");
        option=getInt("Ingrese una Opcion: ");
        switch(option)
        {
            case 1:
                if(flag1==0)
                {
                    if(controller_loadFromText("data.csv",listaEmpleados))
                       printf("\nCARAGA EXITOSA!!!\n\n");
                       flag1=1;
                }
                else
                {
                    printf("\nYA SE CARGO EL ARCHIVO ANTERIORMENTE\n\n");
                }
                break;
            case 2:
                if(flag1==0)
                {
                    if(controller_loadFromBinary("data.csv",listaEmpleados))
                    printf("\nCARAGA EXITOSA!!!\n\n");
                }
                else
                {
                    printf("\nYA SE CARGO EL ARCHIVO ANTERIORMENTE\n\n");
                }

                break;
            case 3:
                if(!controller_addEmployee(listaEmpleados));
                    printf("\nCARGA EXITOSA!!!\n");

                break;
            case 4:
                controller_ListEmployee(listaEmpleados);
                if(!controller_editEmployee(listaEmpleados))
                    printf("\nNO SE ENCONTRO EL ID INGRESADO!!!\n\n");
                break;
            case 5:
                controller_ListEmployee(listaEmpleados);
                if(!controller_removeEmployee(listaEmpleados))
                {
                    printf("\nNO SE ENCONTRO EL ID INGRESADO!!!\n\n");
                }
                else
                {
                    printf("\nSE HA ELIMINADO AL EMPLEADO EXITOSAMENTE\n\n");
                }

                break;
            case 6:
                controller_ListEmployee(listaEmpleados);
                break;
            case 7:
                controller_sortEmployee(listaEmpleados);
                break;
            case 8:
                if(controller_saveAsText("data.csv",listaEmpleados))
                    printf("\nSE A GUARDADO CORRECTAMENTE!!!\n\n");
                break;
            case 9:
                if(controller_saveAsBinary("data.csv",listaEmpleados))
                    printf("\nSE A GUARDADO CORRECTAMENTE!!!\n\n");
                break;
        }
        system("pause");
        system("cls");
    }while(option != 10);

    return 0;
}
